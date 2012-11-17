#include <QApplication>

#include "Editor.h"

int main(int argc , char ** argv)
{
	QApplication app(argc, argv);
	
	Editor * edit = new Editor;
	edit->show();

	app.exec();
	return 0;
}

