#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMdiSubWindow>
#include "sub_mainwindow_1.h"
#include "sub_mainwindow_2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	// disposição inicial das subWindows:
	on_actionAbas_triangulares_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSubMainWindow_1_triggered()
{
	// new sub_mainwindow_1:
	// instancia a primeira subwindow e a define como "internal widget" da nova subwindow
	QMdiSubWindow * subWin = ui->mdiArea->addSubWindow( new sub_mainwindow_1 );
	subWin->setAttribute(Qt::WA_DeleteOnClose);

	// checa se a "subWindow" está minimizada
	// ou se ainda não foi exibida:
	if ( ui->mdiArea->viewMode() == QMdiArea::SubWindowView && subWin->isMinimized())
		subWin->showNormal(); // restaura se estiver minimizada
	else if ( !subWin->isVisible() )
		subWin->show(); // exibe (se não está visível é porque foi criada agora);

	// Coloca essa "subWindow" no primeiro plano da mdiArea:
	ui->mdiArea->setActiveSubWindow(subWin);

}

void MainWindow::on_actionSubMainWindow_2_triggered()
{
	// new sub_mainwindow_2:
	// instancia a segunda subwindow e a define como "internal widget" da nova subwindow
	QMdiSubWindow * subWin = ui->mdiArea->addSubWindow( new sub_mainwindow_2 );
	subWin->setAttribute(Qt::WA_DeleteOnClose);

	// checa se a "subWindow" está minimizada
	// ou se ainda não foi exibida:
	if ( ui->mdiArea->viewMode() == QMdiArea::SubWindowView && subWin->isMinimized())
		subWin->showNormal(); // restaura se estiver minimizada
	else if ( !subWin->isVisible() )
		subWin->show(); // exibe (se não está visível é porque foi criada agora);

	// Coloca essa "subWindow" no primeiro plano da mdiArea:
	ui->mdiArea->setActiveSubWindow(subWin);
}

void MainWindow::on_actionAbas_triangulares_triggered()
{
	ui->mdiArea->setViewMode(QMdiArea::TabbedView);
	ui->mdiArea->setTabShape(QTabWidget::Triangular);
}

void MainWindow::on_actionAbas_retangulares_triggered()
{
	ui->mdiArea->setViewMode(QMdiArea::TabbedView);
	ui->mdiArea->setTabShape(QTabWidget::Rounded);
}

void MainWindow::on_actionCascata_triggered()
{
	QList<QMdiSubWindow*> subWindows = ui->mdiArea->subWindowList();
	// antes de modificar modo de exibição, checa se há alguma "subWindow" minimizada:
	foreach ( QMdiSubWindow* subWin, subWindows )
	{
		if ( ui->mdiArea->viewMode() == QMdiArea::SubWindowView && subWin->isMinimized())
			subWin->showNormal(); // restaura se estiver minimizada
	}
	ui->mdiArea->setViewMode(QMdiArea::SubWindowView);
	ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actionTelhas_triggered()
{
	QList<QMdiSubWindow*> subWindows = ui->mdiArea->subWindowList();
	// antes de modificar modo de exibição, checa se há alguma "subWindow" minimizada:
	foreach ( QMdiSubWindow* subWin, subWindows )
	{
		if ( ui->mdiArea->viewMode() == QMdiArea::SubWindowView && subWin->isMinimized())
			subWin->showNormal(); // restaura se estiver minimizada
	}

	ui->mdiArea->setViewMode(QMdiArea::SubWindowView);
	ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionSair_triggered()
{
	close(); // irá chamar "closeEvent" (redefinida abaixo)
}

void MainWindow::closeEvent(QCloseEvent * event)
{
	ui->mdiArea->closeAllSubWindows();
}


