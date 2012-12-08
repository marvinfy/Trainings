/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Sat 3. Dec 10:46:10 2011
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabCadastro;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *ckbUpperName;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *edName;
    QLineEdit *edMail;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabParam;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *edNameMinLen;
    QSpinBox *spNameMinLen;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *ckbMailArroba;
    QSpacerItem *verticalSpacer_4;
    QWidget *tabStyles;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QComboBox *cbStyles;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *statusLabel;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(319, 308);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tabCadastro = new QWidget();
        tabCadastro->setObjectName(QString::fromUtf8("tabCadastro"));
        verticalLayout_4 = new QVBoxLayout(tabCadastro);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, -1, 3, 3);
        ckbUpperName = new QCheckBox(tabCadastro);
        ckbUpperName->setObjectName(QString::fromUtf8("ckbUpperName"));

        verticalLayout_4->addWidget(ckbUpperName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tabCadastro);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(tabCadastro);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        edName = new QLineEdit(tabCadastro);
        edName->setObjectName(QString::fromUtf8("edName"));
        edName->setMinimumSize(QSize(211, 0));

        verticalLayout_3->addWidget(edName);

        edMail = new QLineEdit(tabCadastro);
        edMail->setObjectName(QString::fromUtf8("edMail"));
        edMail->setMinimumSize(QSize(211, 0));

        verticalLayout_3->addWidget(edMail);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 122, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(tabCadastro);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);

        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabCadastro, QString());
        tabParam = new QWidget();
        tabParam->setObjectName(QString::fromUtf8("tabParam"));
        verticalLayout_5 = new QVBoxLayout(tabParam);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(tabParam);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        line = new QFrame(tabParam);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(tabParam);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_4);

        edNameMinLen = new QLineEdit(tabParam);
        edNameMinLen->setObjectName(QString::fromUtf8("edNameMinLen"));

        horizontalLayout_3->addWidget(edNameMinLen);

        spNameMinLen = new QSpinBox(tabParam);
        spNameMinLen->setObjectName(QString::fromUtf8("spNameMinLen"));

        horizontalLayout_3->addWidget(spNameMinLen);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer_3);

        ckbMailArroba = new QCheckBox(tabParam);
        ckbMailArroba->setObjectName(QString::fromUtf8("ckbMailArroba"));

        verticalLayout_5->addWidget(ckbMailArroba);

        verticalSpacer_4 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        tabWidget->addTab(tabParam, QString());
        tabStyles = new QWidget();
        tabStyles->setObjectName(QString::fromUtf8("tabStyles"));
        gridLayout = new QGridLayout(tabStyles);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(tabStyles);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        cbStyles = new QComboBox(tabStyles);
        cbStyles->setObjectName(QString::fromUtf8("cbStyles"));

        gridLayout->addWidget(cbStyles, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 175, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 0, 1, 1);

        tabWidget->addTab(tabStyles, QString());

        verticalLayout->addWidget(tabWidget);

        statusLabel = new QLabel(MainWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setFrameShape(QFrame::Panel);
        statusLabel->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(statusLabel);


        retranslateUi(MainWidget);
        QObject::connect(spNameMinLen, SIGNAL(valueChanged(QString)), edNameMinLen, SLOT(setText(QString)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Janela Principal", 0, QApplication::UnicodeUTF8));
        ckbUpperName->setText(QApplication::translate("MainWidget", "nome em mai\303\272sculas", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "Nome:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "email", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("MainWidget", "Aceitar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCadastro), QApplication::translate("MainWidget", "Cadastro", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabCadastro), QApplication::translate("MainWidget", "Preencher dados cadastrais", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Par\303\242metros para preenchimento dos dados do Cadastro</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">M\303\255nimo de caracteres</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">para o campo nome:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ckbMailArroba->setText(QApplication::translate("MainWidget", "Obrigat\303\263rio uso do arroba no e-mail", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabParam), QApplication::translate("MainWidget", "Par\303\242metros", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabParam), QApplication::translate("MainWidget", "Regras para cadastro", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWidget", "Estilos", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabStyles), QApplication::translate("MainWidget", "Estilos", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabStyles), QApplication::translate("MainWidget", "Estilo de janela da aplica\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
