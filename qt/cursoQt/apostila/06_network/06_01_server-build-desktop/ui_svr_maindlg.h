/********************************************************************************
** Form generated from reading UI file 'svr_maindlg.ui'
**
** Created: Fri 29. Apr 16:51:23 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SVR_MAINDLG_H
#define UI_SVR_MAINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_svr_mainDlgClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *stopButton;
    QSpacerItem *horizontalSpacer_4;
    QListWidget *messagesList;

    void setupUi(QWidget *svr_mainDlgClass)
    {
        if (svr_mainDlgClass->objectName().isEmpty())
            svr_mainDlgClass->setObjectName(QString::fromUtf8("svr_mainDlgClass"));
        svr_mainDlgClass->resize(357, 342);
        verticalLayout = new QVBoxLayout(svr_mainDlgClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(svr_mainDlgClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        portEdit = new QLineEdit(svr_mainDlgClass);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setMaximumSize(QSize(91, 16777215));

        horizontalLayout->addWidget(portEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        startButton = new QPushButton(svr_mainDlgClass);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(startButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        stopButton = new QPushButton(svr_mainDlgClass);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        sizePolicy.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(stopButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        messagesList = new QListWidget(svr_mainDlgClass);
        messagesList->setObjectName(QString::fromUtf8("messagesList"));

        verticalLayout->addWidget(messagesList);


        retranslateUi(svr_mainDlgClass);

        QMetaObject::connectSlotsByName(svr_mainDlgClass);
    } // setupUi

    void retranslateUi(QWidget *svr_mainDlgClass)
    {
        svr_mainDlgClass->setWindowTitle(QApplication::translate("svr_mainDlgClass", "svr_mainDlg", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("svr_mainDlgClass", "Porta:", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("svr_mainDlgClass", "Iniciar", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("svr_mainDlgClass", "Parar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class svr_mainDlgClass: public Ui_svr_mainDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SVR_MAINDLG_H
