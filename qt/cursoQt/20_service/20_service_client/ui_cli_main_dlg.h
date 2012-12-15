/********************************************************************************
** Form generated from reading UI file 'cli_main_dlg.ui'
**
** Created: Tue 9. Aug 17:23:47 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLI_MAIN_DLG_H
#define UI_CLI_MAIN_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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
    QLineEdit *edHost;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *edPort;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *btBegin;
    QPushButton *btStop;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btCmd;
    QSpacerItem *verticalSpacer_2;

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

        edHost = new QLineEdit(cli_main_dlgClass);
        edHost->setObjectName(QString::fromUtf8("edHost"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edHost->sizePolicy().hasHeightForWidth());
        edHost->setSizePolicy(sizePolicy);

        gridLayout->addWidget(edHost, 0, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(cli_main_dlgClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        edPort = new QLineEdit(cli_main_dlgClass);
        edPort->setObjectName(QString::fromUtf8("edPort"));
        edPort->setMaximumSize(QSize(91, 16777215));

        gridLayout->addWidget(edPort, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        btBegin = new QPushButton(cli_main_dlgClass);
        btBegin->setObjectName(QString::fromUtf8("btBegin"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btBegin->sizePolicy().hasHeightForWidth());
        btBegin->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btBegin, 3, 2, 1, 1);

        btStop = new QPushButton(cli_main_dlgClass);
        btStop->setObjectName(QString::fromUtf8("btStop"));
        btStop->setEnabled(false);
        sizePolicy1.setHeightForWidth(btStop->sizePolicy().hasHeightForWidth());
        btStop->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btStop, 4, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 2, 1, 1);

        btCmd = new QPushButton(cli_main_dlgClass);
        btCmd->setObjectName(QString::fromUtf8("btCmd"));
        btCmd->setEnabled(false);

        gridLayout->addWidget(btCmd, 6, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 2, 1, 1);


        retranslateUi(cli_main_dlgClass);

        QMetaObject::connectSlotsByName(cli_main_dlgClass);
    } // setupUi

    void retranslateUi(QDialog *cli_main_dlgClass)
    {
        cli_main_dlgClass->setWindowTitle(QApplication::translate("cli_main_dlgClass", "cli_main_dlg", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cli_main_dlgClass", "Host:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cli_main_dlgClass", "Porta:", 0, QApplication::UnicodeUTF8));
        btBegin->setText(QApplication::translate("cli_main_dlgClass", "Conectar", 0, QApplication::UnicodeUTF8));
        btStop->setText(QApplication::translate("cli_main_dlgClass", "Desconectar", 0, QApplication::UnicodeUTF8));
        btCmd->setText(QApplication::translate("cli_main_dlgClass", "Executar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cli_main_dlgClass: public Ui_cli_main_dlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLI_MAIN_DLG_H
