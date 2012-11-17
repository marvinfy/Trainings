#include "workerthread.h"
#include <cstdlib>
#include <cmath>


WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent),
    m_waitForTask(0), //semaforo iniciado com Zero (que ja e o valor default)
    m_status(false) // inicialmente ocioso
{
}


void WorkerThread::run()
{
    m_canRun = true;

    qulonglong thId = qulonglong(currentThreadId());

    while (m_canRun)
    {
        m_waitForTask.acquire(1); // bloqueia aqui
        if (m_canRun)
        {
            enum { LoopCount = 10 * 1000 * 1000 };
            double temp;

            for (int n = 0; n <= LoopCount; ++n)
            {
                temp = n * qrand() * sqrt(qrand()) * thId + thId;
            }

            m_status = false;

            emit taskDone(QString("Thread #%1 - result=%2").arg(thId).arg(temp), m_status);


        }
    }

}
