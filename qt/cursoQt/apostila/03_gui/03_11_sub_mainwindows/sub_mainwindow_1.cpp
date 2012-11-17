#include "sub_mainwindow_1.h"
#include "ui_sub_mainwindow_1.h"
#include <QMessageBox>

sub_mainwindow_1::sub_mainwindow_1(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::sub_mainwindow_1)
{
    m_ui->setupUi(this);
}

sub_mainwindow_1::~sub_mainwindow_1()
{
    delete m_ui;
}

void sub_mainwindow_1::changeEvent(QEvent *e)
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

void sub_mainwindow_1::on_actionAction_1_triggered()
{
	QMessageBox::information(this, "Sub main window 1",
							 "Esta é a SubMainWindow 1\nExecutando\nAction - 1");
}

void sub_mainwindow_1::on_actionAction_2_triggered()
{
	QMessageBox::information(this, "Sub main window 1",
							 "Esta é a SubMainWindow 1\nExecutando\nAction - 2");

}
