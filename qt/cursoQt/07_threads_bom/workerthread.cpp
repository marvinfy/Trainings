#include "workerthread.h"
#include <QTime>

WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent)
{
}

void WorkerThread::run()
{
	msleep(2);
	qsrand(QTime::currentTime().msec());

	for ( int n=1; n<=1000; ++n)
	{
		int result = n *10*(qrand()+1);
		ulong thId = ulong(currentThreadId());
	 emit logMessage(QString( "Thread #%1 - %2").arg(thId).arg(result));
	}
}
