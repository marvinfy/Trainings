/********************************************************************************
** Form generated from reading UI file 'sub_mainwindow_1.ui'
**
** Created: Sat 27. Nov 09:27:18 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB_MAINWINDOW_1_H
#define UI_SUB_MAINWINDOW_1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sub_mainwindow_1
{
public:
    QAction *actionAction_1;
    QAction *actionAction_2;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *sub_mainwindow_1)
    {
        if (sub_mainwindow_1->objectName().isEmpty())
            sub_mainwindow_1->setObjectName(QString::fromUtf8("sub_mainwindow_1"));
        sub_mainwindow_1->resize(800, 600);
        actionAction_1 = new QAction(sub_mainwindow_1);
        actionAction_1->setObjectName(QString::fromUtf8("actionAction_1"));
        actionAction_2 = new QAction(sub_mainwindow_1);
        actionAction_2->setObjectName(QString::fromUtf8("actionAction_2"));
        centralwidget = new QWidget(sub_mainwindow_1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(-1, 30, -1, -1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(276, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(276, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(276, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 372, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        sub_mainwindow_1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sub_mainwindow_1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        sub_mainwindow_1->setMenuBar(menubar);
        statusbar = new QStatusBar(sub_mainwindow_1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sub_mainwindow_1->setStatusBar(statusbar);
        toolBar = new QToolBar(sub_mainwindow_1);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        sub_mainwindow_1->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionAction_1);
        menuArquivo->addAction(actionAction_2);
        toolBar->addAction(actionAction_1);
        toolBar->addAction(actionAction_2);

        retranslateUi(sub_mainwindow_1);

        QMetaObject::connectSlotsByName(sub_mainwindow_1);
    } // setupUi

    void retranslateUi(QMainWindow *sub_mainwindow_1)
    {
        sub_mainwindow_1->setWindowTitle(QApplication::translate("sub_mainwindow_1", "Form 1", 0, QApplication::UnicodeUTF8));
        actionAction_1->setText(QApplication::translate("sub_mainwindow_1", "Action 1", 0, QApplication::UnicodeUTF8));
        actionAction_2->setText(QApplication::translate("sub_mainwindow_1", "Action 2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sub_mainwindow_1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Este \303\251 um lineEdit da </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SubWindow - 1</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">(QMainWindow)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sub_mainwindow_1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Esta \303\251 uma comboBox da</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">SubWindow - 1</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">(QMainWindow)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        menuArquivo->setTitle(QApplication::translate("sub_mainwindow_1", "Actions (SubWindow - 1)", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("sub_mainwindow_1", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sub_mainwindow_1: public Ui_sub_mainwindow_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB_MAINWINDOW_1_H
