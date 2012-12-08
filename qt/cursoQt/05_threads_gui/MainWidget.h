#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTime>
#include <QCloseEvent>

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
signals:
		void quitProcess();
protected:
		void closeEvent(QCloseEvent * event);

	private slots:
		void on_processEventsButton_clicked();
		void on_threadButton_clicked();

		void beginProcess();
		void endProcess();
		void progress(quint32 progressCount);

	private:
    Ui::MainWidget *ui;
		QTime m_elapsedTime;
};

#endif // MAINWIDGET_H
