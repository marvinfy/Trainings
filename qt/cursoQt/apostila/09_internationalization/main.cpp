#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

		// ==== a) traduzir strings da própria Qt:

	// == a.1) primeiro método:
	QTranslator qtTranslator;
//	qtTranslator.load("qt_" + QLocale::system().name(),
//		QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//	a.installTranslator(&qtTranslator);


	// == a.2) segundo método (usando um arquivo próprio):
	qtTranslator.load(":/translations/qt_" + QLocale::system().name());
	a.installTranslator(&qtTranslator);

	// ==== b) traduzir strings da aplicação
	// (no código, essas strings devem usar a estática QObject::tr):
	QTranslator myappTranslator;
	myappTranslator.load(":/translations/app_"+
											 QLocale::system().name());
	a.installTranslator(&myappTranslator);


	Dialog w;
    w.show();
    return a.exec();
}
