#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "mainwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QTranslator qtTranslator;

	qtTranslator.load("qt_" + QLocale::system().name(),
			QLibraryInfo::location(QLibraryInfo::TranslationsPath));

	a.installTranslator(&qtTranslator);

	MainWidget w;
    w.show();
    return a.exec();
}
