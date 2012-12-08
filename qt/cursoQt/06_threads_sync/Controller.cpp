#include "Controller.h"
#include <QDebug>
#include <QCoreApplication>

#include "TaskEvent.h"

Controller::Controller(QObject *parent) :
	 QThread(parent)
{
	m_threadCount = QThread::idealThreadCount() * 4; // se temos 2 cpus teremos 8 threads
	m_clientsWithMessagesCount = m_threadCount * 5; // neste caso para atender 40 clientes...

	for (int t=0; t<m_threadCount; ++t)
	{
		WorkerThread * newThread = new WorkerThread(this);
		m_threads.append(newThread);
		newThread->setObjectName(QString("newThread%1").arg(t+1));

		connect (newThread, SIGNAL(taskDone(QString,bool)),
					this, SLOT(taskDone(QString,bool)));

		connect (this, SIGNAL(finished()),	newThread, SLOT(finish()));

		newThread->start();
	}

	m_dataVector.resize( m_clientsWithMessagesCount);
}
void Controller::startProcess()
{
	m_waitForStart.release(1);
}
void Controller::finish()
{
	m_canRun = false;
	m_idleThreads.clear();
	m_waitForStart.release(1);
	m_waitForIdleThread.release(1);

	bool doLoop = true;
	while( doLoop)
	{
		qApp->processEvents();
		if ( doLoop )
			doLoop = !wait(100); // espera o fim da "run"
	}
	qDebug() <<  "controller fim" << isFinished();

	emit finished(); // a base deveria ter feito isso...

	foreach(WorkerThread * thread, m_threads)
	{
		bool doLoop = true;
		while( doLoop)
		{
			qApp->processEvents();
			if ( doLoop )
				doLoop = !thread->wait(100); // já foi o "finished" para todos
		}

		qDebug() << "Thread Fim" << thread->objectName();
		delete thread;
	}
}

void Controller::run() // isto e o thread
{
	m_canRun = true;
	while ( m_canRun )
	{
		m_waitForStart.acquire(1);
		if ( m_canRun )
		{
			m_idleThreads.clear();
			foreach(WorkerThread * thread, m_threads)
				m_idleThreads.enqueue(thread);

			static int count = 0;
			for ( int n=0; m_canRun && n<m_clientsWithMessagesCount;++n)
			{
				m_dataVector[n] = QString::number(rand());

				while ( m_canRun && m_idleThreads.isEmpty()) // SEM THREADS OCIOSOS (quantidade de threads
																																		// mal dimensionada)
				{
					qDebug() << "sem threads ociosos vou aguardar : " << ++count;
					m_waitForIdleThread.acquire(1); // só sai daqui quando (em taskdone)
																										// aparecer um thread ocioso

					qDebug () << "Ótimo- apareceu um thread ocioso, vou continuar";
				}

				if (!m_canRun )
					break;

				if (!m_idleThreads.isEmpty()) // um pouquinho de paranóia...
				{

					WorkerThread * thread = m_idleThreads.dequeue();
//					thread->startTask(&m_dataVector[n]); // endereço da QString correpondente
																														// ao cliente que mandou mensagem

					// ao invés de uma chamada de função do "WorkerThread"
					// vou postar um evento para ele:
					qApp->postEvent(thread, new TaskEvent(&m_dataVector[n]));
					// OBS: postEvent é assíncrona: vai para a fila de eventos
					// NÃO USE o obeto "Event" instanciado, pois ele será DELETADO após uso.

					/*
					// para Eventos sincronos use:
					TaskEvent taskEvent(&m_dataVector[n]);
					qApp->sendEvent(thread, &taskEvent); // enviado IMEDIATAMENTE
																// sendEvent BLOQUEIA ate que o evento seja tratado
					// a liberacão do objeto "taskEvent" passa a ser de responsabilidade
					// de quem o criou (ao contrario de "postEvent");
					// MAS NUNCA USE "sendEvent" entre diferentes threads
					*/
				}
				else
					qDebug() << "DEIXEI DE ATENDER UM CLIENTE!!!!";
			}
		}
	}
}
void Controller::taskDone(const QString &data, bool status)
{
	if ( !m_canRun)
		return;

	WorkerThread * thread = qobject_cast<WorkerThread*>(sender());
	if ( !thread ) // quem mandou o sinal não era um "WorkerThread"
		return;

	if (!status) // se ocioso
	{
		bool release = m_idleThreads.isEmpty();
		m_idleThreads.enqueue(thread);

		if ( release )
			m_waitForIdleThread.release(1); // caso a "run" esteja esperando
																							// por threads ociosos, ela vai acordar
	}

	emit newTaskDone(data); // o controller emite seu próprio
														// signal para o mundo externo.
}

