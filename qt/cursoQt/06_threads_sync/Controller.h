#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQueue>
#include "WorkerThread.h"
#include <QVector>
#include <QSemaphore>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);

signals:
		void newTaskDone (const QString & data);

public slots:
		void startProcess();
		void taskDone(const QString & data, bool status)	;

private:
		int m_threadCount;
		int m_clientsWithMessagesCount;

		QQueue < WorkerThread *> m_idleThreads;
		QVector < QString > m_dataVector;

		QSemaphore m_waitForIdleThread;
};

#endif // CONTROLLER_H
