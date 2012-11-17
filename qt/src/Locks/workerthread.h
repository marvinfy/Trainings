#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QSemaphore>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);
    void startTask()
    {
        m_waitForTask.release(1);
    }

    void finish()
    {
        m_canRun = false;
        startTask();
    }
protected:
    void run();
signals:
    void taskDone(const QString& result, bool status);
    
public slots:

private:
    QSemaphone m_waitForTask;
    bool m_status;
    
};

#endif // WORKERTHREAD_H
