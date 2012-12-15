#include <QtCore/QCoreApplication>

#include <QDebug>
#include <QLibrary>

#include <MinhaLib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	 // MÉTODO 1: LINKAGEM IMPLÍCITA (usa a "implib")

	 // usa a classe exportada:
	 MinhaLib libObj;
	 qDebug() << "======= Usando linkagem IMPLICITA\n";
	 qDebug( ) << "MinhaLib::func0: " << libObj.func0();
	 qDebug() << "global func1: " << func1();
	 qDebug() << "global func2: " << func2();

	 // func3 NÃO FOI EXPORTADA:
//	 qDebug() << "global func3: " << func3();


	 // MÉTODO 2: LINKAGEM EXPLÍCITA (NÃO usa a "implib")

	 qDebug() << "\n======= Usando linkagem EXPLICITA\n";

	QLibrary lib;
#ifdef _DEBUG
	lib.setFileName("MinhaLibd");
#else
	lib.setFileName("MinhaLib");
#endif

	if (! lib.load())
	{
		qDebug() << "falha ao carregar a biblioteca " << lib.errorString();
		return 0;
	}
	typedef int ( * func_t)();
	func_t func1 = reinterpret_cast<func_t>(lib.resolve("func1"));
	func_t func2 = reinterpret_cast<func_t>(lib.resolve("func2"));
	func_t func3 = reinterpret_cast<func_t>(lib.resolve("func3"));

	if (!func1)
	{
		qDebug() << "falha ao resolver func1 " << lib.errorString() <<"\n";
	}
	else
		qDebug() << "func1 " << func1();

	if (!func2)
	{
		qDebug() << "falha ao resolver func2 " << lib.errorString()<<"\n";
	}
	else
		qDebug() << "func2 " << func2();

	if (!func3)
	{
		qDebug() << "falha ao resolver func3 " << lib.errorString()<<"\n";
	}
	else
		qDebug() << "func3 " << func3();
	 return 0;
}
