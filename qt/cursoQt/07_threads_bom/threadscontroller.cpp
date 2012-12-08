#include "threadscontroller.h"

ThreadsController::ThreadsController(QObject *parent)
	: m_threadsCount(0)
{
	connect ( this, SIGNAL(exit()) ,
													&m_logThread, SLOT(quit()));

	connect (this, SIGNAL(exit()), qApp, SLOT(quit()),
																Qt::QueuedConnection);
}
void ThreadsController::start(int threadsCount)
{
	if ( !m_logThread.isRunning())
		m_logThread.start();

	m_finishedThreads = 0;
	m_threadsCount = threadsCount;
	qDeleteAll(m_threads);
	m_threads.clear();

	m_threads.resize(m_threadsCount);
	for ( int n=0; n< m_threadsCount ; ++n)
	{
		m_threads[n] = new WorkerThread(this);

		connect (m_threads[n], SIGNAL(finished()),
					this, SLOT(threadFinished()));

		connect( m_threads[n], SIGNAL(logMessage(QString))  ,
					&m_logThread, SLOT(logMessage(QString)));

		m_threads[n]->start();
	}
}

void ThreadsController::threadFinished()
{
	++m_finishedThreads;
	if ( m_finishedThreads>= m_threadsCount)
	{
		for ( int n=0; n<m_threadsCount ; ++n)
			m_threads[n]->wait(); // garante que todos encerraram

		qDeleteAll(m_threads);
		m_threads.clear();
		qApp->processEvents();
		emit exit();
		m_logThread.wait();
	}
}

