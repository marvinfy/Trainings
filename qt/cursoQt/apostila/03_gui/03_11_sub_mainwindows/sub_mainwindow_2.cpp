#include "sub_mainwindow_2.h"
#include "ui_sub_mainwindow_2.h"
#include <QMessageBox>

sub_mainwindow_2::sub_mainwindow_2(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::sub_mainwindow_2)
{
    m_ui->setupUi(this);
}

sub_mainwindow_2::~sub_mainwindow_2()
{
    delete m_ui;
}

void sub_mainwindow_2::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void sub_mainwindow_2::on_actionAction_1_triggered()
{
	QMessageBox::information(this, "Sub main window 2",
							 "Esta é a SubMainWindow 2\nExecutando\nAction - 1");
}

void sub_mainwindow_2::on_actionAction_2_triggered()
{
	QMessageBox::information(this, "Sub main window 2",
							 "Esta é a SubMainWindow 2\nExecutando\nAction - 2");

}
