#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << w.objectName();
 //   MainWindow w2;

    w.show();

 //   w2.setWindowTitle("w2");
 //   w2.show();
    
    return a.exec();
}
