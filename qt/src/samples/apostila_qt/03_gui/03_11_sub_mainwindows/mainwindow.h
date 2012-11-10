#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindow;
}
class QCloseEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
	void on_actionSair_triggered();
	void on_actionSubMainWindow_2_triggered();
	void on_actionSubMainWindow_1_triggered();

	void on_actionTelhas_triggered();
	void on_actionCascata_triggered();
	void on_actionAbas_retangulares_triggered();
	void on_actionAbas_triangulares_triggered();

protected:
	void closeEvent(QCloseEvent * event);
};

#endif // MAINWINDOW_H
