#include "MainWidget.h"
#include "ui_MainWidget.h"
#include "Processar_ProcessEvents.h"
#include "WorkerThread.h"
#include <QMessageBox>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
	 ui->cpusEdit->setText( QString::number(QThread::idealThreadCount()));
	 enum { LoopCountDefault = 10*1000*1000 };
	 ui->loopCountEdit->setText(QString::number(LoopCountDefault));
	 ui->progressBar->hide();
}
MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget::on_processEventsButton_clicked()
{
	beginProcess();
	Processar_ProcessEvents * processEvents = new Processar_ProcessEvents(this);
	processEvents->setObjectName("processEvents");
	connect(processEvents, SIGNAL(progress(quint32)),
												  this, SLOT(progress(quint32)), Qt::QueuedConnection);

	// isto será necessário para o thread. Aqui bastaria chamar "endProcess"
	// após o retorno de "starProcess" já que ela bloqueia até o encerramento:
	connect(processEvents, SIGNAL(finished()), this, SLOT(endProcess()), Qt::QueuedConnection);
	processEvents->startProcess(ui->loopCountEdit->text().toULong());

}
void MainWidget::on_threadButton_clicked()
{
	beginProcess();
	WorkerThread * workerThread = new WorkerThread(this);
	workerThread->setObjectName("workerThread");

	connect(workerThread, SIGNAL(progress(quint32)), this, SLOT(progress(quint32)));
	connect(workerThread, SIGNAL(finished()), this, SLOT(endProcess()));

	workerThread->startProcess(ui->loopCountEdit->text().toULong());

}
void MainWidget::beginProcess()
{
	ui->processEventsButton->setEnabled(false);
	ui->threadButton->setEnabled(false);
	ui->progressBar->setRange(1,100);
	ui->progressBar->setValue(1);
	ui->progressBar->show();
	m_elapsedTime.start();
}
void MainWidget::endProcess()
{
	ui->processEventsButton->setEnabled(true);
	ui->threadButton->setEnabled(true);
	ui->progressBar->hide();
	ui->elapsedEdit->setText(QString::number(m_elapsedTime.elapsed()));

	//Aqui tudo bem. Mas nunca use funções como "findChild", "findChildren"
	// e similares em loops, principalmente se prolongados:
	// (por exemplo use ponteiros membros da classe "parent"):
	Processar_ProcessEvents * processEvents =
															findChild<Processar_ProcessEvents*>("processEvents");
	if ( processEvents )
		processEvents->deleteLater();

	WorkerThread * workerThread =
															findChild<WorkerThread*>("workerThread");
	if ( workerThread )
	{
		workerThread->stopProcess(1000);
		workerThread->deleteLater();
	}
}

void MainWidget::progress(quint32 progressCount)
{
	ui->progressBar->setValue(progressCount);
}

void MainWidget::closeEvent(QCloseEvent *event)
{
	//Aqui tudo bem. Mas nunca use funções como "findChild", "findChildren"
	// e similares em loops, principalmente se prolongados
	// (por exemplo use ponteiros membros da classe "parent"):
	Processar_ProcessEvents * processEvents =
															findChild<Processar_ProcessEvents*>("processEvents");
	WorkerThread * workerThread =
															findChild<WorkerThread*>("workerThread");

	if ( processEvents || workerThread )
	{
		int response = QMessageBox::question(this, "Aviso",
														 "Há um processamento em execução. Sair mesmo assim?"
														 , QMessageBox::Yes | QMessageBox::No);

		if ( response != QMessageBox::Yes)
		{
			event->ignore();
			return;
		}

		if ( processEvents)
		{
			processEvents->stopProcess();
			while (QApplication::hasPendingEvents())
				QApplication::processEvents();
		}

		if ( workerThread)
		{
			if ( !workerThread->stopProcess(5000))  // fator de timeout para o thread encerrar
				QMessageBox::warning(this, "Aviso", "Thread não encerrou. Timeout");
		}
	}
}
