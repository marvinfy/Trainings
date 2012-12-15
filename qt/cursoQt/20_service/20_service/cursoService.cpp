#include "cursoService.h"
#include <iostream>

const QString cursoService::m_servName("CursoService");
const QString cursoService::m_servDescription("Serviço para teste - curso Qt");

cursoService::cursoService(int argc, char * argv[]) :
	 QtService<QCoreApplication>(argc, argv, m_servName)
	 , m_tcpServer(0)
{
	// description;
	setServiceDescription(m_servDescription);

	// flags (vai usar "pause"? )
	setServiceFlags(QtServiceBase::Default); // não pode ser pausado, mas pode ser terminado
//	setServiceFlags(QtServiceBase::CanBeSuspended); // poderia ser pausado

	// modo de 'startup' ('AutoStartup' ou  'ManualStartup')
	setStartupType (QtServiceController::AutoStartup);
}

// função start:
// aqui o serviço inicia. a partir daí
// estará o código de um serviço específico.
void cursoService::start()
{
	quint16 portNum = 5555;
	m_tcpServer = new TcpServer( application());
	m_tcpServer->listen( QHostAddress::Any,  portNum ) ;
}

void cursoService::stop()
{
	if ( m_tcpServer )
	{
		if ( m_tcpServer->isListening())
			m_tcpServer->close();

		delete m_tcpServer;
		m_tcpServer = 0;
	}
}


