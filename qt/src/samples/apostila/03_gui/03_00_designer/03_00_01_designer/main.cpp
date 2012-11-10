
/* 
// primeira versão: usando o "Ui::Dialog
// diretamente em main:

#include "ui_designer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QDialog *window = new QDialog;
	Ui::Dialog ui;
	ui.setupUi(window);

	window->show();
	return app.exec();
}

*/

// segunda versão, usando uma classe derivada de Ui::Dialog:

#include "dlg.h" // classe derivada...
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Dlg *window = new Dlg; // classe derivada...
	
	window->show();
	
	return app.exec();
}
