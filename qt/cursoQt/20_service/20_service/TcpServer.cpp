#include "TcpServer.h"
#include <QDateTime>
#include <QTextStream>

// ==================================================

// ==== TcpServer: classe que irá aguardar conexões:

TcpServer::TcpServer(QObject * parent)
	: QTcpServer(parent)
{

}

// nova conexão foi estabelecida:
void	TcpServer::incomingConnection ( int socketDescriptor )
{
	// Quando um novo cliente é conectado, este server('QTcpServer') constrói um objeto 'QTcpSocket'
	// e toda a comunicação com esse cliente é feita através desse objeto 'QTcpSocket'.
	// 'QTcpSocket' trabalha assincronamente, ou seja, toda a comunicação é feita
	// nos slots 'readClient' (novos dados recebidos do cliente)
	// e 'discardClient' (o cliente desconectou).
        DataExchangeSocket* dataExchangeSocket = new DataExchangeSocket(this);

	// conecta os signals de 'DataExchangeSocket' aos slots desta classe:

	// Signal da base(QTcpSocket), slot da derivada(DataExchangeSocket)
	// Novos dados chegaram, prontos para leitura
	// (neste exemplo, é uma nova requisição de um cliente conectado):
	connect(dataExchangeSocket, SIGNAL(readyRead()),
						dataExchangeSocket, SLOT(newRequest()));

	// Signal da base(QTcpSocket), slot da base(QTcpSocket)
	// Ao desconectar, agenda o 'delete' desse objeto para o 'event-loop':
	connect(dataExchangeSocket, SIGNAL(disconnected()),
						dataExchangeSocket, SLOT(deleteLater()));

	// Define para o objeto 'dataExchangeSocket' o 'socket' recebido como argumento nesta função.
	// O 'socket'(um inteiro) identifica o endereço do cliente e a porta para intercâmbio de dados:
	dataExchangeSocket->setSocketDescriptor(socketDescriptor);
}

// ==================================================

// ==== DataExchangeSocket: classe para troca de dados.
//			Um objeto desta classe será criado especificamente
//			para cada cliente que se conectou e fará a troca de dados
//			(ler pedidos / enviar respostas) no slot  'newRequest'
DataExchangeSocket::DataExchangeSocket(QObject *parent)
	: QTcpSocket(parent)
{
}

void DataExchangeSocket::newRequest()
{
    QDataStream in(this);
    QString request;
    in >> request;

    if ( request == "GET DATE TIME")
    {
            QDataStream out (this);
            out << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    }
    else
    {
            // pedido não suportado:
            close();
    }
}
