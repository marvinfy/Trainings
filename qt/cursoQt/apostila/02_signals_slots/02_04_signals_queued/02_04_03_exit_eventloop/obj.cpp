#include <QCoreApplication>

#include "obj.h"

int main(int argc, char *argv[])
{
	QCoreApplication app (argc, argv);

	TestObj * pobj_1 = new TestObj( 0 );
	TestObj * pobj_2 = new TestObj(pobj_1);
	TestObj * pobj_3 = new TestObj( 0 );
	
	pobj_1->setObjectName( "pobj_1" );
	pobj_2->setObjectName( "pobj_2" );
	pobj_3->setObjectName( "pobj_3" );


	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_1, SLOT(on_Nothing(TestObj*) ), Qt::QueuedConnection);
	
	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_2, SLOT(on_Nothing(TestObj*) ), Qt::QueuedConnection);

	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_3, SLOT(on_Nothing(TestObj*) ), Qt::QueuedConnection);

	QObject::connect( pobj_3, SIGNAL(doNothing(TestObj*) ), 
					  pobj_1, SLOT(on_Nothing(TestObj*) ), Qt::QueuedConnection);
						
	QObject::connect( pobj_1, SIGNAL(quit() ), 
					  &app  , SLOT(quit() ), Qt::QueuedConnection);

	pobj_1->func();
	pobj_3->func();

	pobj_1->exit();

	QCoreApplication::exec();

	// "signals" foram agendados para execução no "event-loop".
	// "QCoreApplication::exec()" entra no "event-loop"
	// e bloqueia aguardando eventos.
	// Os "signals" serão então executados
	// e o "event-loop" será encerrado quando
	// o "signal" "quit" de "pobj_1" for executado
	// na chamada a "pobj_1->exit()".

	delete pobj_1;
	delete pobj_3;

	std::cout << "main - fim" << std::endl;
	return 0;
}

