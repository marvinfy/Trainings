/********************************************************************************
** Form generated from reading UI file 'aboutdlg.ui'
**
** Created: Sat Nov 3 17:04:33 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDLG_H
#define UI_ABOUTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *aboutIcon;
    QSpacerItem *spacerIcon;
    QLabel *aboutText;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AboutDlg)
    {
        if (AboutDlg->objectName().isEmpty())
            AboutDlg->setObjectName(QString::fromUtf8("AboutDlg"));
        AboutDlg->resize(515, 217);
        verticalLayout_2 = new QVBoxLayout(AboutDlg);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        aboutIcon = new QLabel(AboutDlg);
        aboutIcon->setObjectName(QString::fromUtf8("aboutIcon"));
        aboutIcon->setFrameShape(QFrame::Panel);
        aboutIcon->setFrameShadow(QFrame::Sunken);
        aboutIcon->setPixmap(QPixmap(QString::fromUtf8(":/imagens/help.png")));

        verticalLayout->addWidget(aboutIcon);

        spacerIcon = new QSpacerItem(13, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(spacerIcon);


        horizontalLayout_2->addLayout(verticalLayout);

        aboutText = new QLabel(AboutDlg);
        aboutText->setObjectName(QString::fromUtf8("aboutText"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutText->sizePolicy().hasHeightForWidth());
        aboutText->setSizePolicy(sizePolicy);
        aboutText->setFrameShape(QFrame::WinPanel);
        aboutText->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(aboutText);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(233, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitButton = new QPushButton(AboutDlg);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(AboutDlg);
        QObject::connect(exitButton, SIGNAL(clicked()), AboutDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDlg);
    } // setupUi

    void retranslateUi(QDialog *AboutDlg)
    {
        AboutDlg->setWindowTitle(QApplication::translate("AboutDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        aboutIcon->setText(QString());
        aboutText->setText(QApplication::translate("AboutDlg", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">00_overview </span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Vers\303\243o alpha 0.0.1</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Qt - licen\303\247a LGPL</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("AboutDlg", "Sair", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDlg: public Ui_AboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDLG_H
