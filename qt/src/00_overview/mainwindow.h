#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_webButton_clicked();

    void on_webView_loadStarted();

    void on_webView_loadProgress(int progress);

    void on_webView_loadFinished(bool arg1);

    void on_actionExit_triggered();

    void on_actionShow_Hide_broser_toggled(bool arg1);

    void on_actionSobre_triggered();

    void on_actionActionFavoritos_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
    QProgressBar* m_progressBar;
};

#endif // MAINWINDOW_H
