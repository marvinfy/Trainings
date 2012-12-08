#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QSemaphore>

#include "TaskEvent.h"

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);

	protected:
		void run();
		bool event(QEvent* event);

signals:
		void taskDone(const QString & result, bool status);

public slots:
		void startTask (QString *  taskData);
		void finish();

	private:
		bool m_canRun;
		QSemaphore m_waitForTask;
		bool m_status;
		QString * m_taskData;
};

#endif // WORKERTHREAD_H
