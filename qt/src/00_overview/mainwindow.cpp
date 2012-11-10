#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include "aboutdlg.h"
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_progressBar(NULL)
{
    ui->setupUi(this);

    ui->menuShow->addSeparator();
    ui->menuShow->addAction(ui->mainToolBar->toggleViewAction());
//    ui->menuShow->addSeparator();
//    ui->menuShow->addAction(ui->mainToolBar->toggleViewAction());

    m_timer.start(1000);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(showTime()));

    // para que nao demore 1s para exibir pela primeira vez
    showTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int canClose = QMessageBox::question(this, "Sair?", "Deseja realmente sair?", QMessageBox::Yes | QMessageBox::No);

    if (canClose == QMessageBox::No)
    {
        event->ignore();
    }
//    else
//    {
//        event->accept(); // Implicito
//    }
}

void MainWindow::on_webButton_clicked()
{
    QString text(ui->webEdit->text());
    if (text.indexOf("://") == -1)
    {
        text.prepend("http://");
    }

    QUrl url(text);
    ui->webView->setUrl(url);
}

void MainWindow::on_webView_loadStarted()
{
    if (m_progressBar == NULL)
    {
        m_progressBar = new QProgressBar();
        m_progressBar->setRange(0, 100);
        ui->statusBar->addWidget(m_progressBar, 1);
        //m_progressBar->setParent(ui->statusBar);
    }
    ui->statusBar->showMessage("");
    m_progressBar->setValue(0);
    m_progressBar->show();
}

void MainWindow::on_webView_loadProgress(int progress)
{
    m_progressBar->setValue(progress);
}

void MainWindow::on_webView_loadFinished(bool ok)
{
    m_progressBar->hide();
    if (ok)
    {
        ui->statusBar->showMessage("Success");
    }
    else
    {
        ui->statusBar->showMessage("Failure");
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionShow_Hide_broser_toggled(bool show)
{
    ui->webFrame->setVisible(show);
}

void MainWindow::on_actionSobre_triggered()
{
    AboutDlg dlg(this);
    dlg.exec();
}

void MainWindow::on_actionActionFavoritos_toggled(bool arg1)
{
    ui->dockWidget_2->setVisible(arg1);
}

void MainWindow::showTime()
{
    QTime curTime = QTime::currentTime();
    QString timeStr = curTime.toString("hh:mm:ss");
    ui->digitalClock->display(timeStr);
}
