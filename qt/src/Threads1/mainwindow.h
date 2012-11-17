#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
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
    
private slots:
    void on_processEventsButton_clicked();
    void on_threadButton_clicked();

    void beginProcess();
    void endProcess();
    void progress(quint32 progressCount);
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QTime m_elapsedTime;
};

#endif // MAINWINDOW_H
