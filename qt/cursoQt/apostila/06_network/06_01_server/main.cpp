#include <QtGui/QApplication>
#include "svr_maindlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    svr_mainDlg w;
    w.show();
    return a.exec();
}
