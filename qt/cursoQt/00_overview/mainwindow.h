#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>
#include <QCloseEvent>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
	void closeEvent(QCloseEvent * event);

	private slots:
		// acrescentados via "goto Slot" (Designer):
		void on_webButton_clicked();
		void on_webView_loadStarted();
		void on_webView_loadProgress(int progress);
		void on_webView_loadFinished(bool arg1);
		void on_actionSair_triggered();
		void on_actionToggleBrowser_toggled(bool arg1);
		void on_actionSobre_triggered();

		// acrescentados manualmente:
		void showTime();

	private:
    Ui::MainWindow *ui;

	 QProgressBar * m_progressBar;
	 QTimer m_timer;
};

#endif // MAINWINDOW_H
