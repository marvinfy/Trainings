#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_progressBar(NULL)
{
    ui->setupUi(this);

    ui->menuShow->addSeparator();
    ui->menuShow->addAction(ui->mainToolBar->toggleViewAction());
}

MainWindow::~MainWindow()
{
    delete ui;
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

}
