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
					  pobj_1, SLOT(on_Nothing(TestObj*) ),
					  Qt::QueuedConnection);
	
	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_2, SLOT(on_Nothing(TestObj*) ),
					  Qt::QueuedConnection);

	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_3, SLOT(on_Nothing(TestObj*) ),
					  Qt::QueuedConnection);

	QObject::connect( pobj_3, SIGNAL(doNothing(TestObj*) ), 
					  pobj_1, SLOT(on_Nothing(TestObj*) ),
					  Qt::QueuedConnection);
						

	pobj_1->Func();
	pobj_3->Func();


	QCoreApplication::exec();

	// "signals" foram agendados para execução no "event-loop".
	// "QCoreApplication::exec()" entra no "event-loop"
	// e bloqueia aguardando eventos.
	// Os "signals" serão então executados
	// mas o "event-loop" não será encerrado
	// pois não há nenhuma chamada a "QApplication::exit"
	// ou um "signal" conectado ao "slot" "QApplication::quit".

	delete pobj_1;
	delete pobj_3;

	// ... e esta mensagem não será impressa...
	std::cout << "main - fim" << std::endl;
	return 0;
}

