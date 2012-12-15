#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
	, m_tcpServer(this)
 {
    ui->setupUi(this);
	 
	 connect ( &m_tcpServer, SIGNAL(logMessage(QString)), 
				  this, SLOT(newLogMessage(QString)));

	 ui->startStopBtn->setText("Iniciar");
	 ui->portEdit->setText("6666");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startStopBtn_clicked()
{
	if ( ui->startStopBtn->text().left(1) == "I")
	{
		if ( m_tcpServer.begin( ui->portEdit->text().toUShort()) )	
			ui->startStopBtn->setText("Parar");
		else
			newLogMessage( "FALHA ao iniciar o servidor");
	}
	else
	{
		m_tcpServer.stop();
		ui->startStopBtn->setText("Iniciar");
	}
}

void Widget::newLogMessage(const QString &msg)
{
	ui->listWidget->addItem( msg );
	ui->listWidget->setCurrentRow( ui->listWidget->count()-1);
}
