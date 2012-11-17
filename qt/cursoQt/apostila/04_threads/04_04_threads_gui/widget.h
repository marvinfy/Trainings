#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTime>

#include <WorkerThread.h>

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

friend class WorkerThread;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
	void closeEvent(QCloseEvent * event);

 private slots:
	void on_processEventsButton_clicked();
	void on_threadButton_clicked();

	void onProcess(); // para o signal "progress" do WorkerThread

	void posProcess(); // para o signal "finished" do WorkerThread
	// tambem usada como função por on_processEventsButton_clicked()

 private:
	void preProcess();
	WorkerThread m_thread;

	QTime m_elapsed;
	bool m_doProcess;
	int m_maxLoop;
	int m_progress;
	int m_prevProgress;

public:
	int maxLoop() const { return m_maxLoop; }
};

#endif // WIDGET_H
