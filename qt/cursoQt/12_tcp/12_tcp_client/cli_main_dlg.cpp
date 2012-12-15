#include "cli_main_dlg.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>


cli_main_dlg::cli_main_dlg(QWidget *parent, Qt::WFlags flags)
    : QDialog(parent, flags)
	 ,  m_nextBlockSize(0)
{
    setupUi(this);

	 // signal 'connected' é emitido por QTcpSocket quando a conexão é estabelecida
	 // isso permitiria aguardar a conexão assincronamente:
	connect(&m_tcpSocket, SIGNAL(connected()),
			this, SLOT(sendRequest()));
    
	// para desconexão (causada por este cliente ou pelo servidor):
	connect(&m_tcpSocket, SIGNAL(disconnected()),
				this, SLOT(connectionClosed()));

	// signal  'readyRead': emitido quando há dados disponíveis para leitura:
	connect(&m_tcpSocket, SIGNAL(readyRead()),
            this, SLOT(clientRead()));
	
	// signal  'error': algum erro ocorreu:
	 connect(&m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
				this, SLOT(errorOccurred()));

	 // alimenta a combobox com os pedidos que podem ser enviados ao server:

	 requestCombo->clear();

	  requestCombo->addItem( 
				  QString::number(TcpDataProtocol::showMessage)
                                + " - Exibir Mensagem"  , // texto
                                 TcpDataProtocol::showMessage // valor interno associado a este item da combo box
											 );																				// para recuperação futura

	 requestCombo->addItem( QString::number(TcpDataProtocol::startProcess)
												+ " - ExecutarPrograma"  , // texto
                                                TcpDataProtocol::startProcess // valor interno associado a este item da combo box
                                );																				// para recuperação futura

	 requestCombo->model()->sort(Qt::AscendingOrder); // classifica para que as opções apareçam para o usuário seguindo a ordem
																				// de 'TcpDataProtocol', já que os valores dos pedidos possiveis foram adicionados
																					// no início de dada string adicionada à combo.

	 // valores default para host e porta:
	hostEdit->setText( "localhost");
	portEdit->setText("6666");

}
cli_main_dlg::~cli_main_dlg()
{
}

// iniciar uma conexão (click no botão 'startButton'):
void cli_main_dlg::on_startButton_clicked()
{
	// recupera o texto do nome (ou IP no formato pontos) do host:
	QString host = hostEdit->text();
	// recupera o número da porta TCP onde o server já deve estar aguardando conexões:
	quint16 nport = portEdit->text().toUShort();

	// se 'localhost', adapta o nome:
	if ( host == "localhost" )
		m_tcpSocket.connectToHost(QHostAddress::LocalHost, nport );
	else
        m_tcpSocket.connectToHost(host, nport );

	// desabilita o botão "begin":
	startButton->setEnabled(false);

	// Vou saber se a conexão foi estabelecida assincronamente no slot "sendRequest"
	// (conectada ao signal  "connected").
	// Mas posso tambem esperar a conexão de forma síncrona, com timeout:
	if ( m_tcpSocket.waitForConnected( 3000 ) ) // 3 segundos para timeout
	{
		// OK: conexão estabelecida
		// desabilita o 'stopButton'
		stopButton->setEnabled(true);

		// e habilita a combo de pedidos, o edit de argumentos e o botão de envio:
		requestCombo->setEnabled(true);
		requestArgEdit->setEnabled(true);
		sendRequestButton->setEnabled(true);
	}
	else // falhou
	{
        QMessageBox::critical( this , "tcpServer", "Falha na conexão"
                                               + m_tcpSocket.errorString());
		startButton->setEnabled(true);
	}
		
}

// encerrar a conexão (clik no botão 'stopButton'):
void cli_main_dlg::on_stopButton_clicked()
{
	  // desabilita o botão 'stop', e os widgets de pedidos:
		stopButton->setEnabled(false);
		sendRequestButton->setEnabled(false);
		requestCombo->setEnabled(false);
		requestArgEdit->setEnabled(false);

		// e habilita o botão 'start':
		startButton->setEnabled(true);

		if ( m_tcpSocket.isOpen() )
			m_tcpSocket.close() ; // fecha conexão
}

// slot conectado ao signal "connected" (conexão estabelecida)
void cli_main_dlg::sendRequest()
{
	// conexão concluída com sucesso;
	// alguma requisição inicial?  Enviar aqui.
	qDebug() << "conexão estabelecida";
}

// enviar um pedido ao servidor (botão  'sendRequestButton'):
void cli_main_dlg::on_sendRequestButton_clicked()
{
	// O server em questão espera apenas dois tipos de pedido:
	// 1: exibir uma mensagem;
	// 2: executar um programa.

	// Para enviar o pedido, recuperar a linha selecionada na comboBox:
	int row= requestCombo->currentIndex();
	// e em seguida recupera o número de pedido associado a essa linha da combo:
	TcpDataProtocol::requestType request =
					 requestCombo->itemData(row).toUInt();
	// número "escondido" no item da combo(ver "addItem" na construtora)

	// argumento para esse pedido:
	// um texto de mensagem(se pedido==1)
	// ou um nome de executável(se pedido==2)
	QString requestArgument = requestArgEdit->text();

	// Podemos formatar o pedido completo em "baixo nível"
	// usando a função 'write':
	// QString requestText ( QString("%1\n%2").arg(request).arg(requestArgument) );
	// m_tcpSocket.write( requestText.toAscii() );

	// ou em nível mais alto, com 'QDataStream' (ou 'QTextStream': analise o caso de uso...):
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_6);


	out << TcpDataProtocol::requestSizeType(0) << request << requestArgument;  // QDataStream suporta uma variedade de tipos... ver sua documentação
	out.device()->seek(0);
	out << TcpDataProtocol::requestSizeType(block.size() - sizeof(TcpDataProtocol::requestSizeType));
	m_tcpSocket.write(block);
}

// "clienteRead": slot conectado ao signal 'readyRead':
// há dados disponíveis para leitura (resposta do server a um pedido):
void cli_main_dlg::clientRead()
{	
	// Podemos recuperar os dados em nível mais baixo com 'read , 'readAll' ou 'readLine':
	//	QByteArray servReply = m_tcpSocket.readAll();
	//	QMessageBox::information( this, "client",
	//		QString ( "Resposta do server:\n" ) + servReply.data()  );

		// ou em nível mais alto com 'QDataStream': (ou 'QTextStream': analise o caso de uso...):
		QDataStream in (&m_tcpSocket);
		in.setVersion(QDataStream::Qt_4_6);

	if (m_nextBlockSize == 0)
	{
		if (m_tcpSocket.bytesAvailable() < sizeof(TcpDataProtocol::requestSizeType))
			return;  // não completou a leitura do início do stream(tamanho total do stream); espera a próxima chamada.

		in >> m_nextBlockSize;
	}

	if (m_tcpSocket.bytesAvailable() <	m_nextBlockSize)
		 return;  // não completou leitura da resposta; espera a próxima chamada.

  m_nextBlockSize = 0;  // já recebeu uma resposta completa
	QString servReply;
	in >> servReply;

	QMessageBox::information( this, "client",
		QString ( "Resposta do server:\n" ) + servReply  );
}

// signal 'disconnected' foi emitido:
void cli_main_dlg::connectionClosed()
{
	// a conexão pode ser encerrada pelo servidor
	// ou pelo usuário desta aplicação(botão "stop")

	if ( isVisible() && stopButton->isEnabled() ) // o servidor encerrou a conexão
	{
		QMessageBox::warning( this, "client", "conexão encerrada pelo servidor");
		// habilitar/desabilitar botões:
		on_stopButton_clicked() ;
	}
	else // usuário encerrou conexão
		QMessageBox::warning( this, "client", "conexão encerrada pelo usuário");
}

// signal 'error' foi emitido:
void cli_main_dlg::errorOccurred()
{
	// recupera informações sobre o erro:
	 qDebug() << m_tcpSocket.error() << " : " << m_tcpSocket.errorString();
	 if ( m_tcpSocket.isOpen() )
		 m_tcpSocket.close(); // encerra
}












