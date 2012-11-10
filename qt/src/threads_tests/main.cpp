#include <QtCore/QCoreApplication>
#include <iostream>
#include "thread.h"

bool g_stop = false;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    MyThread threads[8];

    for (int i = 0; i < 8; i++)
    {
        threads[i].start();
    }

    std::cin.get();

    g_stop = true;

    std::cin.get();

    return 0; //a.exec();
}
