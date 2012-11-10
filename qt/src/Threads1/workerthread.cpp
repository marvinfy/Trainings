#include "workerthread.h"

WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent)
{
}

void WorkerThread::startProcess(quint32 loopCount)
{
    m_canRun = true;
    m_loopCount = loopCount;
    start();
}

bool WorkerThread::stopProcess(int timeout)
{
    m_canRun = false;

    // Aguarda o fim de um thread
    return wait(timeout);
}


void WorkerThread::run()
{
    quint32 progressCount;
    quint32 previousProgress = 0;

    for (quint32 i = 1; i <= m_loopCount && m_canRun; i++)
    {
        // Aqui nao precisa
        //QApplication::processEvents();

        progressCount = quint32((double(i)/m_loopCount) * 100);
        if (progressCount > previousProgress)
        {
            previousProgress = progressCount;
            emit progress(progressCount);
        }
    }

    emit finished();
}
