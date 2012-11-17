#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQueue>
#include "workerthread.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    
signals:
    
public slots:

private:
    int m_threadCount;
    QQueue <WorkerThread*> m_idleThreads;
};

#endif // CONTROLLER_H
