#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QByteArray>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

	// função auxiliar que coloca todos os "dockWidgets"
	// em uma mesma "tabBar", cada um deles em uma "aba"
	// (as abas poderão estar acima ou abaixo, conforme o parâmetro "tabPosition"):
	void tabify_(  QTabWidget::TabPosition tabPosition  );

	// função auxiliar que coloca todos os "dockWidgets"
	// lado a lado em um "splitter"
	// (vertical ou horizontal, de acordo com o parametro "orientation"):
	void split_ ( Qt::Orientation orientation);

	// armazenará o estado inicial da disposição dos "dockWidgets"
	// (permitindo restaurar esse estado posteriormente):
	QByteArray m_state;

	// lista dos "dockWidgets" criados
	// (permitirá acessar todos eles em laços):
	QList < QDockWidget *> m_dockWidgets;
	// mas será que essa lista é mesmo necessária ???

private slots:

	// slot para o signal "triggered" da action "actionAppQuit":
	void on_actionAppQuit_triggered(); // fecha a "MainWindow" e encerra a aplicacão

	// slot para o signal "activated" da comboBox que será inserida na toolBar
	// - permitirá a seleção do modo de visualização:
	void selectViewMode(int index);
};

#endif // MAINWINDOW_H

