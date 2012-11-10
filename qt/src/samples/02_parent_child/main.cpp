#include <QtCore/QCoreApplication>
#include <iostream>

class TestObj : public QObject
{ public:
	 TestObj(QObject * parent, QString objName = QString())
		  : QObject(parent) {
		  setObjectName(objName);
	 }
	 ~TestObj() {
		  std::cout << "TestObj::destrutora - objeto: " <<
										objectName().toStdString() << '\n';
	 } // aqui será chamada ~QObject (destrutora base)
};
int main(int argc, char *argv[])
{
	 QCoreApplication a(argc, argv);

{
	 TestObj ob1 (0, "ob1"); // ob1 não tem "parent" (zero)
	 TestObj * ob2 = new TestObj(&ob1, "ob2");
																				//o "parent"  de "ob2" é "ob1"
	 TestObj * ob3 = new TestObj(&ob1, "ob3");
																				//o "parent"  de "ob3" é "ob1"
	 TestObj * ob4 = new TestObj(ob2, "ob4");
																				//o "parent"  de "ob4" é "ob2"
	 TestObj * ob5 = new TestObj(ob2, "ob5");
																				//o "parent"  de "ob5" é "ob2"
	 delete ob5;

//	 TestObj * ob6 = ob2;
//	 ob6->setParent(ob3);
	// delete ob6;


	} // destrutora de "ob1" será chamada aqui (fim do seu escopo)

	 std::cout <<  "<enter> p/sair\n";
	 std::cin.get();  //exclua no linux
		 // (apenas para rodar em console no Windows a partir do QtCreator)

	 return 0;
	 // return a.exec(); // não vou usar o "event-loop"

}
