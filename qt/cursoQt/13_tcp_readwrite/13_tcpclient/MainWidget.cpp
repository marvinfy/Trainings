#include "MainWidget.h"
#include "ui_MainWidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->requestInfoCtn->setEnabled(false);
	 ui->hostEdit->setText("localhost");
	 ui->portEdit->setText("6666");
	 
	 connect (&m_tcpClient, SIGNAL(newData(QString)),
				 this, SLOT(tcpData(QString)));
	 
	 connect(&m_tcpClient, SIGNAL(tcpDisconnected()), 
				this, SLOT(tcpClosedOrError()));

	 connect(&m_tcpClient, SIGNAL(tcpError()), 
				this, SLOT(tcpClosedOrError()));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_startStopBtn_clicked()
{
	if ( ui->startStopBtn->text().left(1)=="C")
	{
		ui->startStopBtn->setText("Desconectar");
		ui->requestInfoCtn->setEnabled(true);
		m_tcpClient.start(ui->hostEdit->text(), ui->portEdit->text().toUShort());
	}
	else
	{
		tcpClosedOrError();
	}
}

void MainWidget::on_sendButton_clicked()
{
	m_tcpClient.sendData( AppProto::RequestType_t(
																ui->requestCombo->currentIndex()+1),
								 ui->argEdit->text());	
}

void MainWidget::tcpData(const QString &msg)
{
	ui->listWidget->addItem(msg);
	ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
}

void MainWidget::tcpClosedOrError()
{
	m_tcpClient.stop();
	ui->startStopBtn->setText("Conectar");		
	ui->requestInfoCtn->setEnabled(false);
}
