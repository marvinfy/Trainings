#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
	class MainWindow;
}
class QMdiSubWindow;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;

	// ponteiros membro para duas das subWindows;
	// esses ponteiros permitirão saber se uma subWindow
	// já está instanciada ou não:
	QMdiSubWindow * m_subwinForm1;
	QMdiSubWindow * m_subwinForm2;

	// função auxiliar que cria nova instância de uma "subWindow",
	// já definindo qual será o "internal widget" dessa "subWindow":
	QMdiSubWindow * createSubWindow_( QWidget * internalWidget );

	// função auxiliar que exibe cada uma das "subWindows":
	void showSubWindow_( QMdiSubWindow * subWin);

	// função auxiliar que conecta um signal de "Form1" a um slot de "Form2"
	// (o signal enviará o texto do "lineEdit" de "Form1"
	//  o qual sera adicionado na "comboBox" de "Form2":
	void connectForm1ToForm2_();

private slots:

	// slots para o signal "triggered" das "actions"
	// inseridas no menu (menuBar) e na toolbar;
	void on_actionAbout_triggered();
	void on_actionBrowser_triggered();
	void on_actionForm2_triggered();
	void on_actionForm1_triggered();
	void on_actionQuit_triggered();

	// slot para o signal "subWindowActivated" do objeto "mdiArea";
	// será chamada quando uma subWindow for ativada:
	void on_mdiArea_subWindowActivated(QMdiSubWindow* );

	// slots para o signal "destroyed" as subWindows "Form1" e "Form2".
	// Nesses slots simplesmente atribuímos zero aos ponteiros
	// para as subWindows, e desse modo a aplicação saberá
	// se uma subWindow está criada ou não
	// (e, por isso mesmo, esses ponteiros devem também
	//  ser inicializados com zero na construtora):
	void subWinForm1Destroyed()
	{
		m_subwinForm1 = 0;
	}
	void subWinForm2Destroyed()
	{
		m_subwinForm2 = 0;
	}
	// Observar que, neste exemplo, os 2 slots acima só são necessários
	// para aquelas subwindows que não devem ter mais que uma instância criada simultaneamente.
	// Já para a terceira subwindow (o webBrowser) não criamos esse tipo de slot
	// pois o webBrowser podera ter múltiplas instâncias simultâneas.

	// slot para o signal "activated" da comboBox
	// para seleção do modo de visualização das subWindows:
	void selectViewMode(int index);

protected:
	//  closeEvent - quando a mainWindow receber o evento "close":
	void closeEvent(QCloseEvent * event);
};

#endif // MAINWINDOW_H
