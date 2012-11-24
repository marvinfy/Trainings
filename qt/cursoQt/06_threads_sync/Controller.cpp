#include "Controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) :
    QObject(parent)
{
	m_threadCount = QThread::idealThreadCount() * 4;
	m_clientsWithMessagesCount = m_threadCount * 5;

	for (int t=0; t<m_threadCount; ++t)
	{
		WorkerThread * newThread = new WorkerThread(this);
		m_idleThreads.enqueue(newThread);
		newThread->start();

		connect (newThread, SIGNAL(taskDone(QString,bool)),
					this, SLOT(taskDone(QString,bool)));
	}

	m_dataVector.resize( m_clientsWithMessagesCount);
}

void Controller::startProcess()
{
	for ( int n=0; n<m_clientsWithMessagesCount;++n)
	{
		m_dataVector[n] = QString::number(rand());
		if ( m_idleThreads.isEmpty()) // SEM THREADS OCIOSOS (quantidade de threads
																																// mal dimensionada)
		{
			qDebug() << "sem threads ociosos vou aguardar";
			m_waitForIdleThread.acquire(1); // só sai daqui quando (em taskdone)
																								// aparecer um thread ocioso

			qDebug () << "Ótimo- apareceu um thread ocioso, vou continuar";
		}

		if (!m_idleThreads.isEmpty()) // um pouquinho de paranóia...
		{
			WorkerThread * thread = m_idleThreads.dequeue();
			thread->startTask(&m_dataVector[n]); // endereço da QString correpondente
																												// ao cliente que mandou mensagem
		}
		else
			qDebug() << "DEIXEI DE ATENDER UM CLIENTE!!!!";
	}
}
void Controller::taskDone(const QString &data, bool status)
{
	WorkerThread * thread = qobject_cast<WorkerThread*>(sender());
	if ( !thread ) // quem mandou o sinal não era um "WorkerThread"
		return;

	if (!status) // se ocioso
	{
		bool release = m_idleThreads.isEmpty();
		m_idleThreads.enqueue(thread);

		if ( release )
			m_waitForIdleThread.release(1); // caso a startProcess esteja esperando
																							// por threads ociosos, ela vai acordar
	}

	emit newTaskDone(data); // o controller emite seu próprio
			// signal para o mundo externo.
}
