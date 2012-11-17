
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
                             pobj_1, SLOT(on_Nothing(TestObj*) ) );

	
	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_2, SLOT(on_Nothing(TestObj*) ) );

	QObject::connect( pobj_1, SIGNAL(doNothing(TestObj*) ), 
					  pobj_3, SLOT(on_Nothing(TestObj*) ) );

	QObject::connect( pobj_3, SIGNAL(doNothing(TestObj*) ), 
					  pobj_1, SLOT(on_Nothing(TestObj*) ) );
						

	pobj_1->Func();
	pobj_3->Func();
	
	delete pobj_1;
	delete pobj_3;

	std::cin.get();
	return 0;
}

