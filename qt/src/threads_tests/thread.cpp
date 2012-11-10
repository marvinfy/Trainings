#include "thread.h"
#include <iostream>

extern bool g_stop;

MyThread::MyThread()
{
}

MyThread::~MyThread()
{
}

void MyThread::run()
{
    while (true)
    {
        std::cout << g_stop << std::endl;
    }
}


