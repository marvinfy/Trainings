#include <QCoreApplication>

#include "ftp.h"

int main(int argc , char ** argv)
{	
	QCoreApplication app(argc, argv);

	qt_test_ftp1 test_ftp;

	// conecta o signal "endSession" da classe que criamos
	// ao slot "quit" de "app":
	QObject::connect( &test_ftp	,
					  SIGNAL( endSession() ) ,
						&app	, SLOT( quit() ) );

	// inicia a sessão ftp:
	test_ftp.beginSession();
	
	QCoreApplication::exec();

	return 0;
}


