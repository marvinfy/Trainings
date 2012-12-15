/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created: Mon 17. Sep 12:09:37 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
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

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *hostEdit;
    QLabel *label;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startStopBtn;
    QSpacerItem *horizontalSpacer_4;
    QWidget *requestInfoCtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *requestCombo;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *argEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer_8;
    QListWidget *listWidget;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(375, 296);
        verticalLayout_2 = new QVBoxLayout(MainWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        hostEdit = new QLineEdit(MainWidget);
        hostEdit->setObjectName(QString::fromUtf8("hostEdit"));

        horizontalLayout->addWidget(hostEdit);

        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portEdit = new QLineEdit(MainWidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        horizontalLayout->addWidget(portEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        startStopBtn = new QPushButton(MainWidget);
        startStopBtn->setObjectName(QString::fromUtf8("startStopBtn"));

        horizontalLayout_2->addWidget(startStopBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        requestInfoCtn = new QWidget(MainWidget);
        requestInfoCtn->setObjectName(QString::fromUtf8("requestInfoCtn"));
        verticalLayout = new QVBoxLayout(requestInfoCtn);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(requestInfoCtn);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        requestCombo = new QComboBox(requestInfoCtn);
        requestCombo->setObjectName(QString::fromUtf8("requestCombo"));

        horizontalLayout_3->addWidget(requestCombo);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(requestInfoCtn);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        argEdit = new QLineEdit(requestInfoCtn);
        argEdit->setObjectName(QString::fromUtf8("argEdit"));

        horizontalLayout_4->addWidget(argEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        sendButton = new QPushButton(requestInfoCtn);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout_5->addWidget(sendButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(requestInfoCtn);

        listWidget = new QListWidget(MainWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "Host:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "Porta: ", 0, QApplication::UnicodeUTF8));
        startStopBtn->setText(QApplication::translate("MainWidget", "Conectar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWidget", "Requisi\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        requestCombo->clear();
        requestCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWidget", "1 - enviar mensagem", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWidget", "2 - executar programa", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWidget", "Argumento", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("MainWidget", "Enviar Comando", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
