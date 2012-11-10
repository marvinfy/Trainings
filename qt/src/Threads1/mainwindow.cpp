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
    processEvents->setObjectName("meu_filhinho");
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
    wthread->setObjectName("meu_filhinho_threadizado");

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

    Processar_ProcessEvents* processEvents = findChild<Processar_ProcessEvents*>("meu_filhinho");
    if (processEvents)
    {
        delete processEvents;
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
