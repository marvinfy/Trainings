#include <QApplication>

#include "MainDlg.h"

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);

	MainDlg * dlg = new MainDlg;
	dlg->show();
	
	app.exec();
	return 0;
}

