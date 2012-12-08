#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQueue>
#include "WorkerThread.h"
#include <QVector>
#include <QSemaphore>

class Controller : public QThread
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
protected:
		void run();

signals:
		void newTaskDone (const QString & data);

public slots:
		void startProcess();
		void finish();
		void taskDone(const QString & data, bool status)	;

private:
		int m_threadCount;
		int m_clientsWithMessagesCount;

		QList < WorkerThread *> m_threads;
		QQueue < WorkerThread *> m_idleThreads;
		QVector < QString > m_dataVector;

		QSemaphore m_waitForStart;
		QSemaphore m_waitForIdleThread;

		bool m_canRun;
};

#endif // CONTROLLER_H
