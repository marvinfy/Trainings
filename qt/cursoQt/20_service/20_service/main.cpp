#include <QtCore/QCoreApplication>
#include "cursoService.h"
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
	int ret = 0;
	{
		// QCoreApplication a(argc, argv);
		 cursoService service(argc, argv);
		 //return a.exec();
		ret = service.exec();
	}

	if ( argc > 1 && strncmp(argv[1], "-i",2)==0)
	{
		// serviço está sendo instalado:
		QtServiceController svcCtl(cursoService::m_servName);
		if ( svcCtl.startupType() == QtServiceController::AutoStartup )
		{
			if ( !svcCtl.isRunning())
			{
				std::cout <<"iniciando cursoService pela primeira vez.\n";
				if ( svcCtl.start() )
					std::cout <<"cursoService iniciado com sucesso.\n";
				else
					std::cout <<"falha ao iniciar cursoService pela primeira vez.\n";
			}
		}
	}
	return ret;
}
