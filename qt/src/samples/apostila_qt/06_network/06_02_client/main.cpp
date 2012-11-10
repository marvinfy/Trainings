#include <QtGui/QApplication>
#include "cli_main_dlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cli_main_dlg w;
    w.show();
    return a.exec();
}
