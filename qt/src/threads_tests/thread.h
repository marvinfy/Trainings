#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class MyThread: public QThread
{

public:
    MyThread();
    virtual ~MyThread();
    void run();

};


#endif // THREAD_H
