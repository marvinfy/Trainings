#ifndef TCPCONNECTIONSERVER_H
#define TCPCONNECTIONSERVER_H

#include <QTcpServer>
#include <TcpDataExchangeSocket.h> // <- classe para intercambio de dados com cada cliente conectado


// ===========  CLASSE TcpConnectionServer (derivada de QTcpServer) ===============
// ======  sua única função é aguardar conexões (ou encerrá-las):

class TcpConnectionServer : public QTcpServer
{
	Q_OBJECT

	public:
		TcpConnectionServer() {}

		// virtuais da base:
	protected:

		// incomingConnection: chamada pela base quando uma nova conexão
		// com um cliente foi estabelecida:
			void incomingConnection(int socketDescriptor)
			{
                                // um novo cliente se conectou...
				 emit logMessage("Connection Server: novo cliente");

				// Se uma nova conexão foi estabelecida,
				// cria um novo objeto "TcpDataExchangeSocket" (derivada de QTcpSocket)
				// para troca de dados com o cliente que se conectou,
				 // atribuindo-lhe o "socketDescriptor" que identifica endereço e porta de dados para cada cliente.
				// Assim, haverá um "TcpDataExchangeSocket" para cada cliente que se conectar,
				// cada qual com o seu próprio socket.
				TcpDataExchangeSocket *socket = new TcpDataExchangeSocket(this);
				socket->setSocketDescriptor(socketDescriptor);

				// Conecta o signal "logMessage" do objeto apontado por socket (TcpDataExchangeSocket)
				// ao signal "logMessage" do objeto "TcpConnectionServer".
				// ISTO, PORQUE:
				// O objeto apontado por "socket" só e conhecido aqui.
				// Quando tem novas mensagens de 'log' ele emite um signal.
				// Mas quem vai aproveitar esse signal, se esse objeto só é conhecido aqui?
				// Então ele faz com que o objeto "TcpConnectionServer"
				// que é único e é conhecido por quem o criou, também emita o mesmo signal.
				// Desse modo o criador do objeto "TcpConnectionServer"
				// poderá conectar o signal deste a qualquer slot.
				connect( socket, SIGNAL(logMessage(const QString &)),
									this, SIGNAL(logMessage(const QString&)));

				// Feito isso, o objeto 'TcpConnectionServer' continuará aguardando novas conexões.

				// uma outra alternativa, seria dispara um thread aqui
				// e passar para ele o "socketDescriptor".
				// DENTRO da função "run" do thread (isto é realmente DENTRO
				// desse thread), seria instanciado o TcpSocket, que seria tratado
				// nesse thread.

				// Mas SÓ use isso em casos muito especiais, em que seja obrigatorio
				// completar uma comunicação.

			}

		public:
		signals:
				// um sinal para enviar mensagens de 'log'
				// que poderão ser recebidas por quem estiver interessado:
				void logMessage(const QString& msg);
};

#endif // TCPCONNECTIONSERVER_H
