#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);

		void startProcess(quint32 loopCount);
		bool stopProcess(int timeout);
protected:
		void run(); // o novo thread rodará nesta função

signals:
		void progress(quint32 progressCount);
		// o signal abaixo já existe na base:
//		void finished();

private:
		quint32 m_loopCount;
		bool m_canRun;
};

#endif // WORKERTHREAD_H
