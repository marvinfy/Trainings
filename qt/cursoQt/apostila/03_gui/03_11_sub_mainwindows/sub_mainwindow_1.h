#ifndef SUB_MAINWINDOW_1_H
#define SUB_MAINWINDOW_1_H

#include <QtGui/QMainWindow>

namespace Ui {
    class sub_mainwindow_1;
}

class sub_mainwindow_1 : public QMainWindow {
    Q_OBJECT
public:
    sub_mainwindow_1(QWidget *parent = 0);
    ~sub_mainwindow_1();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::sub_mainwindow_1 *m_ui;

private slots:
	void on_actionAction_2_triggered();
	void on_actionAction_1_triggered();
};

#endif // SUB_MAINWINDOW_1_H
