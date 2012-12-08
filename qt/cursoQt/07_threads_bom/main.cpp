#include <QtCore/QCoreApplication>

#include "threadscontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	  ThreadsController tc;
	  tc.start(20);

    return a.exec();
}
