#include "DataExchangeSocket.h"
#include <QProcess>
#include <QtEndian>

DataExchangeSocket::DataExchangeSocket(QObject *parent) :
    QTcpSocket(parent)
 , m_nextBlockSize(0)
{
	
	// SIGNAL da BASE , SLOT da BASE
	connect (this, SIGNAL(disconnected()) , 
				this, SLOT(deleteLater())); // será deletado na próxima entrada no event-loop
																					// quando tudo o que estiver pendente já estará
																					// resolvido
	
	// SIGNAL da BASE, SLOT da DERIVADA
	connect (this, SIGNAL(readyRead()) ,
				this, SLOT(readNewData()));

	// SIGNAL da BASE, SLOT da DERIVADA
	connect(this, SIGNAL(error(QAbstractSocket::SocketError)),
			  this, SLOT(onError(QAbstractSocket::SocketError)));
}

/*
void DataExchangeSocket::readNewData()
{
	QDataStream in (this);

	if ( m_nextBlockSize == 0)
	{
		if ( bytesAvailable() < sizeof(AppProto::BlockSize_t))
			return;

		in >> m_nextBlockSize;
	}
	
	if ( bytesAvailable() < m_nextBlockSize ) // ainda não chegou tudo....
		return;   // já poderia acumular os dados que chegaram
	
	//  |   block-size |  request-id |  string-argumento | 
	m_nextBlockSize = 0;
	quint16 request;
	QString m_bytesReceived;
	in >> request >> m_bytesReceived ;
	
	QString reply;
	switch (request)
	{
		case AppProto::showMessage:
			emit logMessage(QString("Mensagem a exibir: %1").arg(m_bytesReceived));
			reply = QString("Server: Mensagem exibida: %1").arg(m_bytesReceived);
			break;
			
		case AppProto::execProcess:
			if ( QProcess::startDetached(m_bytesReceived) )
			{
				emit logMessage(QString("Executei processo: %1").arg(m_bytesReceived));
				reply = QString("Server: Processo executado: %1").arg(m_bytesReceived);
			}
			else
			{
				emit logMessage(QString("Falha: processo: %1").arg(m_bytesReceived));
				reply = QString("Server: Processo não executado: %1").arg(m_bytesReceived);
				
			}
			break;
	
		default:
			emit logMessage("recebi comando não suportado");
			reply = "Server: comando invalido";
			request = AppProto::invalidCommand;
	}
	
	QDataStream out(this);
	out <<  AppProto::BlockSize_t(reply.length()) << reply;
	
	if ( request == AppProto::invalidCommand)	
		close(); // encerra a conexão com esse cliente
}
*/
void DataExchangeSocket::readNewData()
{
	// recebe:
	//  |   block-size |  request-id |  string-argumento | 
	
	if ( m_nextBlockSize == 0)
	{
		if ( bytesAvailable() < sizeof(AppProto::BlockSize_t))
			return;
	
		 char bytes[sizeof(AppProto::BlockSize_t)+1];
		 readData(bytes, sizeof(AppProto::BlockSize_t));
		 bytes[sizeof(AppProto::BlockSize_t)] = 0;
		 
		// recupera o tamanho do bloco de dados, convertendo da ordem de bytes da rede para a ordem de bytes do host
		 m_nextBlockSize = 
                AppProto::BlockSize_t (qFromBigEndian<quint32>
                                                ((uchar*)bytes));

		m_bytesReceived.clear(); //@@ limpa a string que acumulará dados que chegarem
		m_request = 0xFFFF;
	}
	
	if ( m_request == 0xFFFF)
	{
		qint64 bytesToRead = bytesAvailable();
		if ( bytesToRead < sizeof(AppProto::RequestType_t))
			return; // não recebeu ainda os 2 bytes da "request"

		// lê a request:	
		char bytes[sizeof(AppProto::RequestType_t)+1];
        readData(bytes, sizeof(AppProto::RequestType_t));
		bytes[sizeof(AppProto::RequestType_t)] = 0;
         m_request = qFromBigEndian<AppProto::RequestType_t>
                                                    ((uchar*)bytes);
         m_nextBlockSize -= sizeof(AppProto::RequestType_t);
                                                           // isto já foi lido;
	 }
	
	qint64 bytesToRead = bytesAvailable();  // quanto temos agora para ler...
	if ( bytesToRead < m_nextBlockSize ) // ainda não chegou tudo....
	{
		m_bytesReceived += read(bytesToRead);
		return;   // acumulou os dados que já chegaram, mas ainda há mais para chegar.
	}
	
	// agora vai ler o que estava faltando.
	// lê apenas a quantida que falta para este bloco:
	bytesToRead = m_nextBlockSize - m_bytesReceived.length();
	if ( bytesToRead > 0)
		m_bytesReceived += read(bytesToRead); // lê o argumento(string) da "request"
	
	m_nextBlockSize = 0; // zera o indicador de tamanho
	
	// analisa a request e prepara a resposta:
	QString reply;
	switch (m_request)
	{
		case AppProto::showMessage:
			emit logMessage(QString("Mensagem a exibir: %1").arg(m_bytesReceived));
			reply = QString("Server: Mensagem exibida: %1").arg(m_bytesReceived);
			break;

		case AppProto::execProcess:
			if ( QProcess::startDetached(m_bytesReceived) )
			{
				emit logMessage(QString("Executei processo: %1").arg(m_bytesReceived));
				reply = QString("Server: Processo executado: %1").arg(m_bytesReceived);
			}
			else
			{
				emit logMessage(QString("Falha: processo: %1").arg(m_bytesReceived));
				reply = QString("Server: Processo não executado: %1").arg(m_bytesReceived);
				
			}
			break;
	
		default:
			emit logMessage("recebi comando não suportado");
			reply = "Server: comando invalido";
			m_request = AppProto::invalidCommand;
	}
	
	// envia:
	//  |   block-size |  string-argumento | 
	
	unsigned char blockSize[ sizeof(AppProto::BlockSize_t)+1 ];
	// converte o tamanho dos dados para a ordem de bytes da rede:
    qToBigEndian<quint32>(AppProto::BlockSize_t(reply.length())
                                                       , blockSize);

	// grava o tamanho do bloco de dados:
	writeData((char*)blockSize, sizeof(AppProto::BlockSize_t));
	
	// grava os dados:
    write(reply.toAscii(), reply.length());

	// tudo isso seria mais simples se eu fizesse :
	//QString data( QString("%1%2").arg(reply.length(), 8, 16, '0').arg(reply));
	//write(data.toAscii(), data.length());
	
	if ( m_request == AppProto::invalidCommand)	
		close(); // encerra a conexão com esse cliente

	m_bytesReceived.clear();
}

void DataExchangeSocket::onError(QAbstractSocket::SocketError socketError)
{
	qDebug() << "ERRO: #" << socketError << " / " << errorString();
}






