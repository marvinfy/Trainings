#include <QtCore/QCoreApplication>
#include "writefile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	 WriteFile wf;

	 wf.generateData(99);
	 wf.writeTxt();

	 return 0; // a.exec();
}
