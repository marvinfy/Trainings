#include "WorkerThread.h"
#include <cstdlib>
#include <cmath>
#include <QCoreApplication>
#include <QDebug>

WorkerThread::WorkerThread(QObject *parent)
	: QThread(parent)
	, m_waitForTask(0) // semáforo iniciado com ZERO (que aliás já é o valor default)
	, m_status(false) // inicialment ocioso
{
}

void WorkerThread::startTask(QString *taskData)
{
	m_status = true;
	m_taskData = taskData;
	m_waitForTask.release(1);
}
void WorkerThread::finish()
{
	m_canRun = false;
	qDebug() << "Worker Finish: " << objectName();
	m_waitForTask.release(m_waitForTask.available()+1);
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
				double temp =0 ;  //@@ não estava inicializada

				// trabalho real com os dados:
				for ( int n=1; m_canRun && n< m_taskData->length(); ++n)
					temp += int(m_taskData->at(n).toAscii()) * n;

				// trabalho inútil só para o thread ficar mais tempo ocupado:
				for ( int n = 1;m_canRun &&  n <=LoopCount; ++n )
					temp += n*qrand()*sqrt(double(qrand())) * thId + thId;

				if ( m_canRun)
				{
					m_status = false;
					emit taskDone ( QString("Thread #%1 - result=%2").arg(thId).arg(temp)
																												, m_status);
				}
			}
	}
}

bool WorkerThread::event(QEvent *event)
{
	if ( event->type() == TaskEvent::taskType())
	{
		TaskEvent * taskEvent = static_cast<TaskEvent*>(event);
		// neste caso, podia eliminar a função "startTask"
		// e colocar o seu conteudo aqui:
		startTask(taskEvent->taskData());
		return true;
	}
	return false;
}
