#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include <AppProtocol.h>

class TcpClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
		bool start(const QString & host, quint16 portNumber);
		void stop();
		void sendData(AppProto::RequestType_t request, const QString & requestArgument);

signals:
		void newData(const QString & data);
		void tcpError();
		void tcpDisconnected();
		
public slots:
		void readNewData();
		void onError(QAbstractSocket::SocketError);
		void connectionOpened();
		void connectionClosed();

private:
		AppProto::BlockSize_t m_nextBlockSize;
		QString m_bytesReceived; //@@ acrescentado para leitura cumulativa		
};

#endif // TCPCLIENT_H
