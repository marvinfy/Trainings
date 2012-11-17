#ifndef MAINDLG_H
#define MAINDLG_H

#include <QtGui/QDialog>
#include "thread.h"

namespace Ui
{
    class MainDlgClass;
}

class MainDlg : public QDialog
{
    Q_OBJECT

public:
    MainDlg(QWidget *parent = 0);
    ~MainDlg();

private:
    Ui::MainDlgClass *ui;

	// um "workerThread" que irá executar tarefas
	// mantendo o thread de interface gráfica livre
	// para tratar eventos da interface:
	workerThread workThread;
	int m_pendingTasks;

private slots:

		// este slot (conectado ao botão "btnTask")
		// solicita ao thread a execução de sua tarefa
		void on_btnTask_clicked();

		// este slot permitirá que o thread
		// notifique os resultados do seu trabalho:
		void on_taskDone( const QString & taskResult );

	protected:
		void closeEvent ( QCloseEvent * event );
};

#endif // MAINDLG_H
