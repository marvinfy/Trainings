#include "WorkerThread.h"

WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent)
{
}

void WorkerThread::startProcess(quint32 loopCount)
{
	m_canRun = true;
	m_loopCount = loopCount;
	/*QThread::*/ start();
}

bool WorkerThread::stopProcess(int timeout)
{
	m_canRun = false;
	return /*QThread::*/ wait(timeout);
}

// o novo thread É a função run
// tudo o que for criado ou chamado DENTRO de "run"
// estará nesse novo thread.
void WorkerThread::run()
{
	quint32 progressCount;
	quint32 previousProgress=0;

	for (quint32 n=1; n<=m_loopCount && m_canRun; ++n)
	{
		// AQUI não temos que usar isto:
	//		QApplication::processEvents();

		progressCount = quint32( (double(n)/m_loopCount) * 100);
		if ( progressCount > previousProgress)
		{
			previousProgress  = progressCount;
			emit progress(progressCount);
		}
	}
	// isso já é feito pela base QThread, quando "run" retorna:
	//	emit finished();
}

