/********************************************************************************
** Form generated from reading UI file 'maindlg.ui'
**
** Created: Sat 9. Apr 15:28:12 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDLG_H
#define UI_MAINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainDlgClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnTask;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textResult;

    void setupUi(QDialog *MainDlgClass)
    {
        if (MainDlgClass->objectName().isEmpty())
            MainDlgClass->setObjectName(QString::fromUtf8("MainDlgClass"));
        MainDlgClass->resize(421, 330);
        MainDlgClass->setMinimumSize(QSize(421, 0));
        verticalLayout = new QVBoxLayout(MainDlgClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(MainDlgClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnTask = new QPushButton(MainDlgClass);
        btnTask->setObjectName(QString::fromUtf8("btnTask"));

        horizontalLayout->addWidget(btnTask);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_2 = new QLabel(MainDlgClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(MainDlgClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        textResult = new QTextEdit(MainDlgClass);
        textResult->setObjectName(QString::fromUtf8("textResult"));
        textResult->setMinimumSize(QSize(345, 234));

        verticalLayout->addWidget(textResult);


        retranslateUi(MainDlgClass);

        QMetaObject::connectSlotsByName(MainDlgClass);
    } // setupUi

    void retranslateUi(QDialog *MainDlgClass)
    {
        MainDlgClass->setWindowTitle(QApplication::translate("MainDlgClass", "Task - com sem\303\241foro", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainDlgClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Clique repetida e rapidamente no bot\303\243o abaixo</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">e verifique se a interface congelou</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnTask->setText(QApplication::translate("MainDlgClass", "Executar Tarefa", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainDlgClass", "Tarefas Pendentes: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDlgClass: public Ui_MainDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDLG_H
