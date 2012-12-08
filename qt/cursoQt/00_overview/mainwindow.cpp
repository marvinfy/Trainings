#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutdlg.h"
#include <QTime> // trata horários
	// não confundir com QTimer que é um "despertador"

#include <QMessageBox>

MainWindow::MainWindow(/* QMainWindow * this, */ QWidget *parent)
	: QMainWindow(parent)
	,  ui(new Ui::MainWindow)
	, m_progressBar(0)
{
	 ui->setupUi(this); // this: endereço do objeto "w" instanciado em "main()"

	 ui->menuExibir->addSeparator();
	ui->menuExibir->addAction(ui->mainToolBar->toggleViewAction());
	ui->menuExibir->addAction(ui->dockWidget->toggleViewAction());
	ui->dockWidget->toggleViewAction()->setIcon(
																			QIcon(":/imagens/favorites.png"));

	m_timer.start(1000); // timeout a cada 1 segundo (1000 milisegundos)
	connect ( &m_timer, SIGNAL(timeout()),
				 this, SLOT(showTime()));

	// irá exibir a hora daqui a um segundo e depois repetidamente
	// mas quero exibir JÁ:
	showTime();
}

MainWindow::~MainWindow(/* QMainWindow * this, */ )
{
	// não e necessário pois o 'this' é assumido por default para os membros:
	// delete this->ui;
	delete ui;
}

void MainWindow::on_webButton_clicked()
{
	// faz uma cópia do texto do webEdit, retirando brancos no início e no fim.
	QString text(ui->webEdit->text().trimmed());
	int posProto = text.indexOf("://");
	if (posProto < 3 )
	{
		if ( posProto >= 0)
			text.remove("://");

		text = "http://" + text;
		ui->webEdit->setText(text);
	}

	QUrl url ( ui->webEdit->text() );
	ui->webView->setUrl (url);
}

void MainWindow::on_webView_loadStarted()
{
	if ( !m_progressBar)
	{
		m_progressBar = new QProgressBar;
		m_progressBar->setRange(0, 100);
		ui->statusBar->addWidget(m_progressBar,1);
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
	if ( ok )
		ui->statusBar->showMessage("Página carregada com sucesso");
	else
		ui->statusBar->showMessage("Falha na carga da página");
}

void MainWindow::on_actionSair_triggered()
{
	close();
}

void MainWindow::on_actionToggleBrowser_toggled(bool show)
{
	ui->webFrame->setVisible(show);
}

void MainWindow::on_actionSobre_triggered()
{
	AboutDlg dlg(this);
	dlg.exec();
}

void MainWindow::showTime()
{
	QTime now ( QTime::currentTime());
	QString nowStr ( now.toString("hh:mm:ss"));
	ui->digitalClock->display(nowStr);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	int canClose = QMessageBox::question(this, // parent da MessageBox
													 "Fechar",  // título (barra de título)
													 "Deseja mesmo fechar?", // mensagem
						 QMessageBox::Yes | QMessageBox::No // botões padrão
													 );

	if ( canClose != QMessageBox::Yes)
		event->ignore();  // não fecha a janela (ignora o evento close)
	// else
	//	event->accept();  // aceita o evento e fecha a janela
										// mas não precisa, pois "accept" já é o estado
										// default do evento.
}




