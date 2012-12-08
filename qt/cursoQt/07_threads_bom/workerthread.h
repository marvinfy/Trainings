#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);

	protected :
		void run();

signals:
		void logMessage(const QString & msg);

public slots:

};

#endif // WORKERTHREAD_H
