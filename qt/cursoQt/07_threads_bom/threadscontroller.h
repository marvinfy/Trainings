#ifndef THREADSCONTROLLER_H
#define THREADSCONTROLLER_H

#include <QObject>
#include <QVector>
#include "workerthread.h"
#include "logthread.h"
#include <QCoreApplication>

class ThreadsController : public QObject
{
    Q_OBJECT
public:
		explicit ThreadsController(QObject *parent = 0);
		void start(int threadsCount);

signals:
		void exit();
public slots:
		void threadFinished();

	private :
		int m_threadsCount;
		int m_finishedThreads;

		QVector <WorkerThread*> m_threads;
		LogThread m_logThread;
};

#endif // THREADSCONTROLLER_H
