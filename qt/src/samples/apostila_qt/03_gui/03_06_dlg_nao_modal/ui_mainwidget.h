/********************************************************************************
** Form generated from reading ui file 'mainwidget.ui'
**
** Created: Sat 26. Sep 15:20:30 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QString::fromUtf8("MainWidgetClass"));
        MainWidgetClass->resize(336, 152);
        MainWidgetClass->setMinimumSize(QSize(336, 152));
        verticalLayout = new QVBoxLayout(MainWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(MainWidgetClass);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(MainWidgetClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(MainWidgetClass);

        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QApplication::translate("MainWidgetClass", "MainWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidgetClass", "Digite qualquer coisa aqui para exibir a MessageBox:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
