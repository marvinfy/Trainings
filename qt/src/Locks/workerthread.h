#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QSemaphore>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);
    void startTask(QString* taskData)
    {
        m_status = true;
        m_taskData = taskData;
        m_waitForTask.release(1);
    }

    void finish()
    {
        m_canRun = false;
        startTask(0);
    }
protected:
    void run();
signals:
    void taskDone(const QString& result, bool status);
    
public slots:

private:
    bool m_canRun;
    QSemaphore m_waitForTask;
    bool m_status;
    QString* m_taskData;
    
};

#endif // WORKERTHREAD_H
