#include "WorkerThread.h"
#include <cstdlib>
#include <cmath>
#include <QCoreApplication>

WorkerThread::WorkerThread(QObject *parent)
	: QThread(parent)
	, m_waitForTask(0) // semáforo iniciado com ZERO (que aliás já é o valor default)
	, m_status(false) // inicialment ocioso
{
}

void WorkerThread::run()
{
	m_canRun = true;
	qulonglong thId = qulonglong(currentThreadId());

	while ( m_canRun )
	{
			m_waitForTask.acquire(1); // bloqueia aqui em wait
			if ( m_canRun )  // pode ter mudado de valor enquanto eu "dormia"
			{
				enum { LoopCount = 10*1000*1000 };
				double temp;

				QCoreApplication::processEvents(); // ?????

				// trabalho real com os dados:
				for ( int n=1; n< m_taskData->length(); ++n)
					temp += int(m_taskData->at(n).toAscii()) * n;

				// trabalho inútil só para o thread ficar mais tempo ocupado:
	//			for ( int n = 1; n <=LoopCount; ++n )
		//			temp += n*qrand()*sqrt(double(qrand())) * thId + thId;

				m_status = false;
				emit taskDone ( QString("Thread #%1 - result=%2").arg(thId).arg(temp)
																												, m_status);
			}
	}
}
