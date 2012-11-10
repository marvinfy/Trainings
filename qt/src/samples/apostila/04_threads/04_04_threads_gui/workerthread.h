#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

class Widget;
#include <QThread>

class WorkerThread : public QThread
{
	Q_OBJECT

public:
	WorkerThread( Widget * widget )
			: m_widget( widget )
	{}

	protected:
		void run(); // virtual da base
	private:
		Widget *m_widget;

	signals:
			void progress();
};
#endif // WORKERTHREAD_H
