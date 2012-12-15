#ifndef TCPCONNECTIONSERVER_H
#define TCPCONNECTIONSERVER_H

#include <QTcpServer>
#include <AppProtocol.h>

class TcpConnectionServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpConnectionServer(QObject *parent = 0);
		bool begin(quint16 portNumber);
		void stop();
		
protected:	
		void incomingConnection(int socketDescriptor);
		
signals:
		void logMessage(const QString & msg);
		
public slots:

};

#endif // TCPCONNECTIONSERVER_H
