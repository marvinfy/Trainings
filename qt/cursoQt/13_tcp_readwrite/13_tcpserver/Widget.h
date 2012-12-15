#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "TcpConnectionServer.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

	private slots:
		void on_startStopBtn_clicked();
		void newLogMessage(const QString & msg);
		
	private:
    Ui::Widget *ui;
	 
	TcpConnectionServer m_tcpServer;
};

#endif // WIDGET_H
