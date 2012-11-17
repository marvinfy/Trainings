
#include "obj.h"

int main(int argc, char *argv[])
{
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
	
	// sinais foram agendados para o event-loop;
	// mas não há event-loop; 
	// logo, nada será executado...

	delete pobj_1;
	delete pobj_3;

	std::cout << "main - fim" << std::endl;
	return 0;
}

