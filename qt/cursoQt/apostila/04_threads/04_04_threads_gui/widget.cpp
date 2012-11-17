#include "widget.h"
#include "ui_widget.h"
#include <QApplication>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
//	, m_thread() // por default
	, m_thread( this )
	, m_doProcess(false)
{

    ui->setupUi(this);

    ui->progressBar->hide();
	enum { MAX_LOOP = 10*1000*1000};
        ui->maxloopEdit->setText( QString::number(MAX_LOOP) );

	// signal da classe QThread(base)
	connect( &m_thread, SIGNAL(finished()),
					this, SLOT(posProcess()));

	// signal da minha derivada:
	connect( &m_thread , SIGNAL(progress() ),
					this, SLOT (onProcess()) );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_processEventsButton_clicked()
{
	preProcess();
	for ( int n=1; m_doProcess && n<=m_maxLoop; ++n )
	{
		m_progress= int ( double(n)/m_maxLoop *100) ;
		if ( m_progress > m_prevProgress )
		{
			m_prevProgress = m_progress;
			ui->progressBar->setValue(m_progress);
		}

		// checa se há eventos e se houver processa
		// para não congelar a interface:
				QApplication::processEvents();
	}
	posProcess();
}
void Widget::on_threadButton_clicked()
{
	preProcess();
	m_thread.start();
}

void Widget::onProcess()
{
	ui->progressBar->setValue(m_progress);
}

void Widget::preProcess()
{
	m_doProcess = true;
	ui->processEventsButton->setEnabled(false);
	ui->threadButton->setEnabled(false);
	m_maxLoop = ui->maxloopEdit->text().toInt();
	ui->progressBar->setRange(1, 100);
	ui->progressBar->setValue(1);
	ui->progressBar->show();
	m_elapsed.start();
	m_prevProgress = 0;
}
void Widget::posProcess()
{
	ui->processEventsButton->setEnabled(true);
	ui->threadButton->setEnabled(true);
	ui->progressBar->hide();
	m_doProcess = false;
	ui->timeElapsedEdit->setText(QString::number(m_elapsed.elapsed() ) );
}
void Widget::closeEvent(QCloseEvent * event)
{
	m_doProcess = false;
	if ( m_thread.wait(1000 ) )
		QMessageBox::information(this, "Close",
								 "Thread encerrou normalmente");
	else
		QMessageBox::information(this, "Close",
								 "Thread não encerrou (wait-TIMEOUT)" );
}

// ============ class WorkerThread
void WorkerThread::run()
{
	for ( int n=1; m_widget->m_doProcess &&
								n<=m_widget->m_maxLoop; ++n )
	{
		m_widget->m_progress= int ( double(n)/m_widget->m_maxLoop *100) ;
		if ( m_widget->m_progress > m_widget->m_prevProgress )
		{
			m_widget->m_prevProgress = m_widget->m_progress;

			// isto não:
                        // m_widget->ui->progressBar->setValue(m_widget->m_progress);
			// e sim isto:
                       emit progress();
		}
	}
}
