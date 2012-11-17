#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	 MainWindow w(0);
	 qDebug() << "w - objectName: " << w.objectName();

	 // QMainWindow::QMainWindow(&w, 0);
	 // ou...
	 // push 0
	 // push &w
	 // call QMainWindow::MainWindow

//	 MainWindow w2(0);
	 // QMainWindow::QMainWindow(&w2,0);

	 //w2.setWindowTitle("CLONE de mainwindow");
		// QMainWindow::setWindowTitle(&w2, "CLONE de mainwindow");
	 w.show();
	// w2.show();
	 // QMainWindow::show( &w );
	 // QMainWindow::show( &w2 );
	 return a.exec();
}
