#include <QApplication>
#include "MainWin.h"

int main(int argc , char * argv[])
{
    QApplication app(argc, argv);

	MainWin win;
	win.show();

    app.exec();
    return 0;
}
