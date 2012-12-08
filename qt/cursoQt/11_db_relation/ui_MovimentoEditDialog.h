/********************************************************************************
** Form generated from reading UI file 'MovimentoEditDialog.ui'
**
** Created: Sat 5. May 10:05:41 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIMENTOEDITDIALOG_H
#define UI_MOVIMENTOEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MovimentoEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *clienteHLayout;
    QLabel *clienteLabel;
    QComboBox *clienteCombo;
    QSpacerItem *clienteHSpacer;
    QHBoxLayout *tipoHLayout;
    QLabel *tipoLabel;
    QComboBox *tipoCombo;
    QSpacerItem *tipoHSpacer;
    QHBoxLayout *lastMovHLayout;
    QLabel *lastMovLabel;
    QDateEdit *movDate;
    QSpacerItem *lastMovHSpacer;
    QHBoxLayout *descriptionHLayout;
    QLabel *descrLabel;
    QLineEdit *descrEdit;
    QSpacerItem *buttonsSeparatorVSpacer;
    QHBoxLayout *movimentoButtonsHLayout;
    QGroupBox *movimentoEditGroup;
    QHBoxLayout *horizontalLayout;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QGroupBox *movimentoNavGroup;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *movimentoNavFirstBtn;
    QPushButton *movimentoNavPrevBtn;
    QPushButton *movimentoNavNextBtn;
    QPushButton *movimentoNavLastBtn;
    QSpacerItem *movimentoButtonsHSpacer;

    void setupUi(QDialog *MovimentoEditDialog)
    {
        if (MovimentoEditDialog->objectName().isEmpty())
            MovimentoEditDialog->setObjectName(QString::fromUtf8("MovimentoEditDialog"));
        MovimentoEditDialog->resize(497, 279);
        verticalLayout = new QVBoxLayout(MovimentoEditDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clienteHLayout = new QHBoxLayout();
        clienteHLayout->setObjectName(QString::fromUtf8("clienteHLayout"));
        clienteLabel = new QLabel(MovimentoEditDialog);
        clienteLabel->setObjectName(QString::fromUtf8("clienteLabel"));

        clienteHLayout->addWidget(clienteLabel);

        clienteCombo = new QComboBox(MovimentoEditDialog);
        clienteCombo->setObjectName(QString::fromUtf8("clienteCombo"));

        clienteHLayout->addWidget(clienteCombo);

        clienteHSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        clienteHLayout->addItem(clienteHSpacer);


        verticalLayout->addLayout(clienteHLayout);

        tipoHLayout = new QHBoxLayout();
        tipoHLayout->setObjectName(QString::fromUtf8("tipoHLayout"));
        tipoLabel = new QLabel(MovimentoEditDialog);
        tipoLabel->setObjectName(QString::fromUtf8("tipoLabel"));

        tipoHLayout->addWidget(tipoLabel);

        tipoCombo = new QComboBox(MovimentoEditDialog);
        tipoCombo->setObjectName(QString::fromUtf8("tipoCombo"));

        tipoHLayout->addWidget(tipoCombo);

        tipoHSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tipoHLayout->addItem(tipoHSpacer);


        verticalLayout->addLayout(tipoHLayout);

        lastMovHLayout = new QHBoxLayout();
        lastMovHLayout->setObjectName(QString::fromUtf8("lastMovHLayout"));
        lastMovLabel = new QLabel(MovimentoEditDialog);
        lastMovLabel->setObjectName(QString::fromUtf8("lastMovLabel"));

        lastMovHLayout->addWidget(lastMovLabel);

        movDate = new QDateEdit(MovimentoEditDialog);
        movDate->setObjectName(QString::fromUtf8("movDate"));
        movDate->setCalendarPopup(true);

        lastMovHLayout->addWidget(movDate);

        lastMovHSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lastMovHLayout->addItem(lastMovHSpacer);


        verticalLayout->addLayout(lastMovHLayout);

        descriptionHLayout = new QHBoxLayout();
        descriptionHLayout->setObjectName(QString::fromUtf8("descriptionHLayout"));
        descriptionHLayout->setContentsMargins(-1, 0, -1, -1);
        descrLabel = new QLabel(MovimentoEditDialog);
        descrLabel->setObjectName(QString::fromUtf8("descrLabel"));

        descriptionHLayout->addWidget(descrLabel);

        descrEdit = new QLineEdit(MovimentoEditDialog);
        descrEdit->setObjectName(QString::fromUtf8("descrEdit"));

        descriptionHLayout->addWidget(descrEdit);


        verticalLayout->addLayout(descriptionHLayout);

        buttonsSeparatorVSpacer = new QSpacerItem(20, 115, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(buttonsSeparatorVSpacer);

        movimentoButtonsHLayout = new QHBoxLayout();
        movimentoButtonsHLayout->setObjectName(QString::fromUtf8("movimentoButtonsHLayout"));
        movimentoEditGroup = new QGroupBox(MovimentoEditDialog);
        movimentoEditGroup->setObjectName(QString::fromUtf8("movimentoEditGroup"));
        horizontalLayout = new QHBoxLayout(movimentoEditGroup);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 3, 5, 3);
        okBtn = new QPushButton(movimentoEditGroup);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagens/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(movimentoEditGroup);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagens/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        cancelBtn->setFlat(false);

        horizontalLayout->addWidget(cancelBtn);


        movimentoButtonsHLayout->addWidget(movimentoEditGroup);

        movimentoNavGroup = new QGroupBox(MovimentoEditDialog);
        movimentoNavGroup->setObjectName(QString::fromUtf8("movimentoNavGroup"));
        horizontalLayout_2 = new QHBoxLayout(movimentoNavGroup);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 3, 5, 3);
        movimentoNavFirstBtn = new QPushButton(movimentoNavGroup);
        movimentoNavFirstBtn->setObjectName(QString::fromUtf8("movimentoNavFirstBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagens/first.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavFirstBtn->setIcon(icon2);

        horizontalLayout_2->addWidget(movimentoNavFirstBtn);

        movimentoNavPrevBtn = new QPushButton(movimentoNavGroup);
        movimentoNavPrevBtn->setObjectName(QString::fromUtf8("movimentoNavPrevBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagens/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavPrevBtn->setIcon(icon3);

        horizontalLayout_2->addWidget(movimentoNavPrevBtn);

        movimentoNavNextBtn = new QPushButton(movimentoNavGroup);
        movimentoNavNextBtn->setObjectName(QString::fromUtf8("movimentoNavNextBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagens/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavNextBtn->setIcon(icon4);

        horizontalLayout_2->addWidget(movimentoNavNextBtn);

        movimentoNavLastBtn = new QPushButton(movimentoNavGroup);
        movimentoNavLastBtn->setObjectName(QString::fromUtf8("movimentoNavLastBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagens/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavLastBtn->setIcon(icon5);

        horizontalLayout_2->addWidget(movimentoNavLastBtn);


        movimentoButtonsHLayout->addWidget(movimentoNavGroup);

        movimentoButtonsHSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        movimentoButtonsHLayout->addItem(movimentoButtonsHSpacer);


        verticalLayout->addLayout(movimentoButtonsHLayout);


        retranslateUi(MovimentoEditDialog);

        QMetaObject::connectSlotsByName(MovimentoEditDialog);
    } // setupUi

    void retranslateUi(QDialog *MovimentoEditDialog)
    {
        MovimentoEditDialog->setWindowTitle(QApplication::translate("MovimentoEditDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        clienteLabel->setText(QApplication::translate("MovimentoEditDialog", "Cliente: ", 0, QApplication::UnicodeUTF8));
        tipoLabel->setText(QApplication::translate("MovimentoEditDialog", "Tipo do Movimento: ", 0, QApplication::UnicodeUTF8));
        lastMovLabel->setText(QApplication::translate("MovimentoEditDialog", "Data do Movimento: ", 0, QApplication::UnicodeUTF8));
        descrLabel->setText(QApplication::translate("MovimentoEditDialog", "Descri\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        movimentoEditGroup->setTitle(QApplication::translate("MovimentoEditDialog", "Concluir Edi\303\247\303\243o: ", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("MovimentoEditDialog", "Confirmar", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("MovimentoEditDialog", "Cancelar", 0, QApplication::UnicodeUTF8));
        movimentoNavGroup->setTitle(QApplication::translate("MovimentoEditDialog", "Navega\303\247\303\243o: ", 0, QApplication::UnicodeUTF8));
        movimentoNavFirstBtn->setText(QString());
        movimentoNavPrevBtn->setText(QString());
        movimentoNavNextBtn->setText(QString());
        movimentoNavLastBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MovimentoEditDialog: public Ui_MovimentoEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIMENTOEDITDIALOG_H
