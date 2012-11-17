#include "maindlg.h"
#include "ui_maindlg.h"
#include <QMessageBox>
#include <QCloseEvent>

MainDlg::MainDlg(QWidget *parent)
    : QDialog(parent), ui(new Ui::MainDlgClass)
{
    ui->setupUi(this);

	// conectar signals -> slots:

	// o signal "clicked" do botão "btnTask" é conectado
	// ao slot "on_doTask" do workerThread;
	// neste exemplo, é assim que o thread irá trabalhar:
	connect ( ui->btnTask , SIGNAL ( clicked() ),
					&workThread, SLOT (on_doTask() ) );

	// o signal "taskDone" do workerThread
	// poderia ser conectado diretamente ao slot "setText" do "textResult"
	// para imprimir os resultados da tarefa executada;
	// mas queremos tratar o texto e o aspecto do "textResult";
	// assim, conectamos esse signal ao slot "on_taskDone" desta classe:
	connect ( &workThread , SIGNAL ( taskDone( const QString & ) ) ,
						this, SLOT( on_taskDone( const QString &) ) );

	// agenda o thread:
	workThread.start();

}

MainDlg::~MainDlg()
{
    delete ui;
}

// slot que recebe resultados do trabalho do "workThead"
void MainDlg::on_taskDone( const QString & taskResult )
{
	// mantem os resultados anteriores dentro do textEdit
	// acrescentando o novo resultado:
	const QString & oldText = ui->textResult->toPlainText();

	if ( oldText.isEmpty() )
		ui->textResult->setText( taskResult );
	else
		ui->textResult->setText( oldText + "\n" + taskResult );

	// força um scroll para que esta nova linha esteja sempre visível
	// mesmo que o textEdit tenha toda a área visível já preenchida:
	ui->textResult->moveCursor( QTextCursor::End );
}

// trata o fechamento da janela:
void MainDlg::closeEvent ( QCloseEvent  * event )
{
	// encerrar o "event-loop" do workerThread:
	workThread.quit() ;

	// aguarda encerramento:
	if ( workThread.wait(5000) )  // ou sai por timeout...
		QMessageBox::information ( this, "close",
					"O workerThread encerrou normalmente");
	else
		QMessageBox::critical ( this, "close",
					"O workerThread não encerrou: TIMEOUT");

	event->accept(); // aceita fechamento da janela.
}
