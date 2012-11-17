#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "processar_processevents.h"
#include "workerthread.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cpusEdit->setText(QString::number(QThread::idealThreadCount()));
    enum { LoopCountDefault = 10*1000*1000 };
    ui->loopCountEdit->setText(QString::number(LoopCountDefault));
    ui->progressBar->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_processEventsButton_clicked()
{
    beginProcess();
    Processar_ProcessEvents* processEvents =new Processar_ProcessEvents(this);
    processEvents->setObjectName("pe");
    connect(processEvents, SIGNAL(progress(quint32)), this, SLOT(progress(quint32)));

    // Bastaria chamar "endProcess apos retorno de startProcess, ja que ela bloqueia
    // ate o encerramento
    connect(processEvents, SIGNAL(finished()), this, SLOT(endProcess()));
    processEvents->startProcess(ui->loopCountEdit->text().toULong());

}
void MainWindow::on_threadButton_clicked()
{
    beginProcess();
    WorkerThread* wthread =new WorkerThread(this);
<<<<<<< HEAD
    wthread->setObjectName("wt");
=======
    wthread->setObjectName("meu_filhinho_threadizado");
>>>>>>> ee02519f3da198dbf43eb5bbc7b458cd146c190b

    connect(wthread, SIGNAL(progress(quint32)), this, SLOT(progress(quint32)));
    connect(wthread, SIGNAL(finished()), this, SLOT(endProcess()));

    wthread->startProcess(ui->loopCountEdit->text().toULong());
}
void MainWindow::beginProcess()
{
    ui->processEventsButton->setEnabled(false);
    ui->threadButton->setEnabled(false);
    ui->progressBar->setRange(1, 100);
    ui->progressBar->setValue(1);
    ui->progressBar->show();
    m_elapsedTime.start();
}

void MainWindow::endProcess()
{
    ui->processEventsButton->setEnabled(true);
    ui->threadButton->setEnabled(true);
    ui->progressBar->hide();
    ui->elapsedEdit->setText(QString::number(m_elapsedTime.elapsed()));

    Processar_ProcessEvents* processEvents = findChild<Processar_ProcessEvents*>("pe");
    if (processEvents)
    {
        //delete processEvents;
        processEvents->deleteLater();
    }

    WorkerThread* wthread = findChild<WorkerThread*>("wt");
    if (wthread)
    {
        //delete wthread;
        wthread->stopProcess(1000);

        // Posterga delecao para o eventLoop
        wthread->deleteLater();
    }

    WorkerThread* wthread = findChild<WorkerThread*>("meu_filhinho_threadizado");
    if (wthread)
    {
        delete wthread;
    }
}

void MainWindow::progress(quint32 progressCount)
{
    ui->progressBar->setValue(progressCount);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    Processar_ProcessEvents* pe = findChild<Processar_ProcessEvents*>("pe");
    WorkerThread* wt = findChild<WorkerThread*>("wt");

    if (pe || wt)
    {
        int res = QMessageBox::question(
            this, "Sair", "Processamento pendente. Sair mesmo assim?",
            QMessageBox::Yes, QMessageBox::No);


        if (res == QMessageBox::No)
        {
            event->ignore();
            return;
        }

        if (pe)
        {
            pe->stopProcess();
            while (QApplication::hasPendingEvents())
            {
                QApplication::processEvents();
            }
        }

        if (wt)
        {
            if (wt->stopProcess(5000))
            {
                QMessageBox::warning(this, "Aviso", "Thread nao parou no tempo esperado");
            }
        }
    }

}
