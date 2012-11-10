/********************************************************************************
** Form generated from reading UI file 'maindlg.ui'
**
** Created: Sat 9. Apr 15:26:20 2011
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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainDlgClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnTask;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textResult;

    void setupUi(QDialog *MainDlgClass)
    {
        if (MainDlgClass->objectName().isEmpty())
            MainDlgClass->setObjectName(QString::fromUtf8("MainDlgClass"));
        MainDlgClass->resize(397, 330);
        verticalLayout = new QVBoxLayout(MainDlgClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnTask = new QPushButton(MainDlgClass);
        btnTask->setObjectName(QString::fromUtf8("btnTask"));

        horizontalLayout->addWidget(btnTask);

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
        MainDlgClass->setWindowTitle(QApplication::translate("MainDlgClass", "Task - com exec (event loop do thread => bloqueia interface)", 0, QApplication::UnicodeUTF8));
        btnTask->setText(QApplication::translate("MainDlgClass", "Executar Tarefa", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDlgClass: public Ui_MainDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDLG_H
