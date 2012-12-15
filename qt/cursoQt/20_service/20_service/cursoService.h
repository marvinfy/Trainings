#ifndef CURSOSERVICE_H
#define CURSOSERVICE_H

#include <qtservice.h>
#include "TcpServer.h"

class cursoService : public QtService<QCoreApplication>
{
public:
	 explicit cursoService(int argc, char * argv[]);
	 static const QString m_servName;
	 static const QString m_servDescription;

protected:
	 void start();
	 void stop();

private:
		TcpServer * m_tcpServer;

 };

#endif // CURSOSERVICE_H
