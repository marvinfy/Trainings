#ifndef TCPDATAEXCHANGESOCKET_H
#define TCPDATAEXCHANGESOCKET_H

#include <QTcpSocket>

#include "TcpDataProtocol.h" // <- protocolo de aplicação para troca de dados

// ============= CLASSE TcpDataExchangeSocket (derivada de QTcpSocket) =============
// === responsável pelo  intercambio de dados com cada cliente conectado
// ===  um novo objeto dessa classe será criado em 'TcpConnectionServer::incomingConnection'
// === para cada cliente que se conectar;

class TcpDataExchangeSocket : public  QTcpSocket
{
	Q_OBJECT

	public:
		TcpDataExchangeSocket(QObject * parent);

	private slots:

	// slot 'readClient': será conectado ao signal 'readyRead'
	// o qual é emitido quando existem dados disponíveis para leitura
	// (um pedido enviado por um cliente, neste exemplo)
		void readClient();

		// capturar erros:
		void onError(QAbstractSocket::SocketError);

public:
signals:
		// um sinal para enviar mensagens de 'log'
		// que poderão ser recebidas por quem estiver interessado:
		void logMessage(const QString& msg);

 private:
		TcpDataProtocol::requestSizeType m_nextBlockSize;
};

#endif // TCPDATAEXCHANGESOCKET_H
