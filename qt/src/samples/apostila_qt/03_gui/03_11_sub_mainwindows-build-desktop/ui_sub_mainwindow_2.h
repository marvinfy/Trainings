/********************************************************************************
** Form generated from reading UI file 'sub_mainwindow_2.ui'
**
** Created: Sat 27. Nov 09:27:18 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB_MAINWINDOW_2_H
#define UI_SUB_MAINWINDOW_2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sub_mainwindow_2
{
public:
    QAction *actionAction_1;
    QAction *actionAction_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuActions;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *sub_mainwindow_2)
    {
        if (sub_mainwindow_2->objectName().isEmpty())
            sub_mainwindow_2->setObjectName(QString::fromUtf8("sub_mainwindow_2"));
        sub_mainwindow_2->resize(800, 600);
        actionAction_1 = new QAction(sub_mainwindow_2);
        actionAction_1->setObjectName(QString::fromUtf8("actionAction_1"));
        actionAction_2 = new QAction(sub_mainwindow_2);
        actionAction_2->setObjectName(QString::fromUtf8("actionAction_2"));
        centralwidget = new QWidget(sub_mainwindow_2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 20, -1, -1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        sub_mainwindow_2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sub_mainwindow_2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuActions = new QMenu(menubar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        sub_mainwindow_2->setMenuBar(menubar);
        statusbar = new QStatusBar(sub_mainwindow_2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sub_mainwindow_2->setStatusBar(statusbar);
        toolBar = new QToolBar(sub_mainwindow_2);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        sub_mainwindow_2->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuActions->menuAction());
        menuActions->addAction(actionAction_1);
        menuActions->addAction(actionAction_2);
        toolBar->addAction(actionAction_1);
        toolBar->addAction(actionAction_2);

        retranslateUi(sub_mainwindow_2);

        QMetaObject::connectSlotsByName(sub_mainwindow_2);
    } // setupUi

    void retranslateUi(QMainWindow *sub_mainwindow_2)
    {
        sub_mainwindow_2->setWindowTitle(QApplication::translate("sub_mainwindow_2", "SubMainWindow - 2", 0, QApplication::UnicodeUTF8));
        actionAction_1->setText(QApplication::translate("sub_mainwindow_2", "Action 1", 0, QApplication::UnicodeUTF8));
        actionAction_2->setText(QApplication::translate("sub_mainwindow_2", "Action 2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sub_mainwindow_2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Este \303\251 um textEdit da </span><span style=\" font-size:8pt; font-weight:600;\">SubWindow - 2</span><span style=\" font-size:8pt;\"> (QMainWindow)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("sub_mainwindow_2", "Actions (SubWindow - 2)", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("sub_mainwindow_2", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sub_mainwindow_2: public Ui_sub_mainwindow_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB_MAINWINDOW_2_H
