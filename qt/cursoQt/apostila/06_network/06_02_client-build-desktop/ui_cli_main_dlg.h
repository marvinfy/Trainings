/********************************************************************************
** Form generated from reading UI file 'cli_main_dlg.ui'
**
** Created: Fri 29. Apr 16:51:39 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLI_MAIN_DLG_H
#define UI_CLI_MAIN_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_cli_main_dlgClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *hostEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QLineEdit *requestArgEdit;
    QPushButton *sendRequestButton;
    QSpacerItem *verticalSpacer_2;
    QComboBox *requestCombo;

    void setupUi(QDialog *cli_main_dlgClass)
    {
        if (cli_main_dlgClass->objectName().isEmpty())
            cli_main_dlgClass->setObjectName(QString::fromUtf8("cli_main_dlgClass"));
        cli_main_dlgClass->resize(338, 317);
        cli_main_dlgClass->setMaximumSize(QSize(16777215, 317));
        gridLayout = new QGridLayout(cli_main_dlgClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(cli_main_dlgClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        hostEdit = new QLineEdit(cli_main_dlgClass);
        hostEdit->setObjectName(QString::fromUtf8("hostEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hostEdit->sizePolicy().hasHeightForWidth());
        hostEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(hostEdit, 0, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(cli_main_dlgClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        portEdit = new QLineEdit(cli_main_dlgClass);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setMaximumSize(QSize(91, 16777215));

        gridLayout->addWidget(portEdit, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        startButton = new QPushButton(cli_main_dlgClass);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(startButton, 3, 2, 1, 1);

        stopButton = new QPushButton(cli_main_dlgClass);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(stopButton, 4, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 2, 1, 1);

        label_3 = new QLabel(cli_main_dlgClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 6, 0, 1, 2);

        requestArgEdit = new QLineEdit(cli_main_dlgClass);
        requestArgEdit->setObjectName(QString::fromUtf8("requestArgEdit"));
        requestArgEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(requestArgEdit->sizePolicy().hasHeightForWidth());
        requestArgEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(requestArgEdit, 7, 2, 1, 2);

        sendRequestButton = new QPushButton(cli_main_dlgClass);
        sendRequestButton->setObjectName(QString::fromUtf8("sendRequestButton"));
        sendRequestButton->setEnabled(false);

        gridLayout->addWidget(sendRequestButton, 8, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 2, 1, 1);

        requestCombo = new QComboBox(cli_main_dlgClass);
        requestCombo->setObjectName(QString::fromUtf8("requestCombo"));
        requestCombo->setEnabled(false);

        gridLayout->addWidget(requestCombo, 6, 2, 1, 1);


        retranslateUi(cli_main_dlgClass);

        QMetaObject::connectSlotsByName(cli_main_dlgClass);
    } // setupUi

    void retranslateUi(QDialog *cli_main_dlgClass)
    {
        cli_main_dlgClass->setWindowTitle(QApplication::translate("cli_main_dlgClass", "cli_main_dlg", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cli_main_dlgClass", "Host:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cli_main_dlgClass", "Porta:", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("cli_main_dlgClass", "Conectar", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("cli_main_dlgClass", "Desconectar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("cli_main_dlgClass", "Comando:", 0, QApplication::UnicodeUTF8));
        sendRequestButton->setText(QApplication::translate("cli_main_dlgClass", "Executar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cli_main_dlgClass: public Ui_cli_main_dlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLI_MAIN_DLG_H
