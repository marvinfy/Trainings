/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created: Wed 23. Jun 23:33:33 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "radiobuttongroup.h"

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nomeEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    RadioButtonGroup *sexoGroup;
    QVBoxLayout *verticalLayout;
    QRadioButton *femininoRB;
    QRadioButton *masculinoRB;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *emailCheck;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *ufCombo;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    RadioButtonGroup *estcivGroup;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *solteiroRB;
    QRadioButton *casadoRB;
    QRadioButton *divorciadoRB;
    QRadioButton *viuvoRB;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *editBtn;
    QPushButton *editFinishedBtn;
    QPushButton *navBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QString::fromUtf8("MainDialog"));
        MainDialog->resize(354, 340);
        verticalLayout_5 = new QVBoxLayout(MainDialog);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame = new QFrame(MainDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(212, 208, 200, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setBold(true);
        font.setWeight(75);
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nomeEdit = new QLineEdit(frame);
        nomeEdit->setObjectName(QString::fromUtf8("nomeEdit"));

        horizontalLayout->addWidget(nomeEdit);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        sexoGroup = new RadioButtonGroup(frame);
        sexoGroup->setObjectName(QString::fromUtf8("sexoGroup"));
        sexoGroup->setFlat(false);
        sexoGroup->setCheckable(false);
        verticalLayout = new QVBoxLayout(sexoGroup);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        femininoRB = new QRadioButton(sexoGroup);
        femininoRB->setObjectName(QString::fromUtf8("femininoRB"));

        verticalLayout->addWidget(femininoRB);

        masculinoRB = new QRadioButton(sexoGroup);
        masculinoRB->setObjectName(QString::fromUtf8("masculinoRB"));

        verticalLayout->addWidget(masculinoRB);


        horizontalLayout_5->addWidget(sexoGroup);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_5);

        emailCheck = new QCheckBox(frame);
        emailCheck->setObjectName(QString::fromUtf8("emailCheck"));

        verticalLayout_3->addWidget(emailCheck);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        ufCombo = new QComboBox(frame);
        ufCombo->setObjectName(QString::fromUtf8("ufCombo"));

        horizontalLayout_2->addWidget(ufCombo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        estcivGroup = new RadioButtonGroup(frame);
        estcivGroup->setObjectName(QString::fromUtf8("estcivGroup"));
        estcivGroup->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(estcivGroup);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        solteiroRB = new QRadioButton(estcivGroup);
        solteiroRB->setObjectName(QString::fromUtf8("solteiroRB"));

        verticalLayout_2->addWidget(solteiroRB);

        casadoRB = new QRadioButton(estcivGroup);
        casadoRB->setObjectName(QString::fromUtf8("casadoRB"));

        verticalLayout_2->addWidget(casadoRB);

        divorciadoRB = new QRadioButton(estcivGroup);
        divorciadoRB->setObjectName(QString::fromUtf8("divorciadoRB"));

        verticalLayout_2->addWidget(divorciadoRB);

        viuvoRB = new QRadioButton(estcivGroup);
        viuvoRB->setObjectName(QString::fromUtf8("viuvoRB"));

        verticalLayout_2->addWidget(viuvoRB);


        verticalLayout_4->addWidget(estcivGroup);

        verticalSpacer_2 = new QSpacerItem(70, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 3);

        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        editBtn = new QPushButton(MainDialog);
        editBtn->setObjectName(QString::fromUtf8("editBtn"));

        horizontalLayout_4->addWidget(editBtn);

        editFinishedBtn = new QPushButton(MainDialog);
        editFinishedBtn->setObjectName(QString::fromUtf8("editFinishedBtn"));

        horizontalLayout_4->addWidget(editFinishedBtn);

        navBtn = new QPushButton(MainDialog);
        navBtn->setObjectName(QString::fromUtf8("navBtn"));

        horizontalLayout_4->addWidget(navBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_4);


        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "MainDialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainDialog", "Nome: ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nomeEdit->setToolTip(QApplication::translate("MainDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Verdana'; font-size:10pt; font-weight:600; color:#ff0000;\">Digite o nome da pessoa</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        nomeEdit->setWhatsThis(QApplication::translate("MainDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Verdana'; font-size:10pt; font-weight:600; color:#00aa00;\">Esta caixinha serve para voc\303\252 digitar o nome da pessoa.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        sexoGroup->setTitle(QApplication::translate("MainDialog", " Sexo: ", 0, QApplication::UnicodeUTF8));
        femininoRB->setText(QApplication::translate("MainDialog", "Feminino", 0, QApplication::UnicodeUTF8));
        masculinoRB->setText(QApplication::translate("MainDialog", "Masculino", 0, QApplication::UnicodeUTF8));
        emailCheck->setText(QApplication::translate("MainDialog", "Recebe e-mail", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Verdana'; font-size:12pt; font-weight:600; color:#0055ff;\">UF:  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/mapa_brasil.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        ufCombo->clear();
        ufCombo->insertItems(0, QStringList()
         << QApplication::translate("MainDialog", "SP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainDialog", "RJ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainDialog", "MG", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        ufCombo->setToolTip(QApplication::translate("MainDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Verdana'; font-size:12pt; font-weight:600;\">Selecione uma UF<br /></span><img src=\":/images/mapa_brasil.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        estcivGroup->setTitle(QApplication::translate("MainDialog", " Estado Civil: ", 0, QApplication::UnicodeUTF8));
        solteiroRB->setText(QApplication::translate("MainDialog", "Solteiro", 0, QApplication::UnicodeUTF8));
        casadoRB->setText(QApplication::translate("MainDialog", "Casado", 0, QApplication::UnicodeUTF8));
        divorciadoRB->setText(QApplication::translate("MainDialog", "Divorciado", 0, QApplication::UnicodeUTF8));
        viuvoRB->setText(QApplication::translate("MainDialog", "Vi\303\272vo", 0, QApplication::UnicodeUTF8));
        editBtn->setText(QApplication::translate("MainDialog", "Editar", 0, QApplication::UnicodeUTF8));
        editFinishedBtn->setText(QApplication::translate("MainDialog", "Concluir", 0, QApplication::UnicodeUTF8));
        navBtn->setText(QApplication::translate("MainDialog", "Navegar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
