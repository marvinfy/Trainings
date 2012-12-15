#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "TcpClient.h"

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

	private slots:
		void on_startStopBtn_clicked();
		void on_sendButton_clicked();
		void tcpData(const QString & msg);
			void tcpClosedOrError();
		
	private:
    Ui::MainWidget *ui;
    TcpClient m_tcpClient;
};

#endif // MAINWIDGET_H
