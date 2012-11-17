#ifndef SUB_MAINWINDOW_2_H
#define SUB_MAINWINDOW_2_H

#include <QtGui/QMainWindow>

namespace Ui {
    class sub_mainwindow_2;
}

class sub_mainwindow_2 : public QMainWindow {
    Q_OBJECT
public:
    sub_mainwindow_2(QWidget *parent = 0);
    ~sub_mainwindow_2();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::sub_mainwindow_2 *m_ui;

private slots:
	void on_actionAction_2_triggered();
	void on_actionAction_1_triggered();
};

#endif // SUB_MAINWINDOW_2_H
