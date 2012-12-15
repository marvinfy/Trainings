#ifndef DATAEXCHANGESOCKET_H
#define DATAEXCHANGESOCKET_H

#include <QTcpSocket>
#include <AppProtocol.h>

class DataExchangeSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit DataExchangeSocket(QObject *parent = 0);

signals:
		void logMessage(const QString & msg);
		
public slots:
		void readNewData();
		void onError( QAbstractSocket::SocketError socketError );
		
private:
		AppProto::BlockSize_t m_nextBlockSize;
		QString m_bytesReceived; //@@ acrescentado para leitura cumulativa
		AppProto::RequestType_t m_request; //@@ acrescentado para leitura cumulativa
};

#endif // DATAEXCHANGESOCKET_H
