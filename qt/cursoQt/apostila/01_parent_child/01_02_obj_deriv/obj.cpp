#include <QObject>
#include <iostream>

class TestObj : public QObject
{
	public:
		TestObj( QObject * p=0) : QObject( p ){}

		~TestObj()
		{
			std::cout << objectName().toStdString().c_str() 
					  << " -> sendo destruido" << std::endl ;
		}
};

int main()
{
	TestObj * pobj_1 = new TestObj(0);		// "pobj_1" não tem "parent"
	TestObj * pobj_2 = new TestObj(pobj_1); // "pobj_1" é o "parent" de "pobj_2"
	TestObj * pobj_3 = new TestObj(pobj_2); // "pobj_2" é o "parent" de "pobj_3"

	pobj_1->setObjectName("pobj_1 : pai de pobj_2");
	pobj_2->setObjectName("pobj_2 : filho de pobj_1 : pai de pobj_3");
	pobj_3->setObjectName("pobj_3 : filho de pobj_2");
	
	delete pobj_1;
	// - em consequência:
	std::cout <<"1. a destrutora de 'pobj_1' deletou 'pobj_2'\n";
	std::cout <<"2. a destrutora de 'pobj_2' deletou 'pboj_3'\n";

	return 0;
}

/*
	RESULTADO: será impresso:

		pobj_1 : pai de pobj_2 -> sendo destruido
		pobj_2 : filho de pobj_1 : pai de pobj_3 -> sendo destruido
		pobj_3 : filho de pobj_2 -> sendo destruido

*/

