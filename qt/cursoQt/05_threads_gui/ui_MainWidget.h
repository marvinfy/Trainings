/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created: Sat 17. Nov 11:26:20 2012
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QLineEdit *loopCountEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *processEventsButton;
    QPushButton *threadButton;
    QSpacerItem *horizontalSpacer_11;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_2;
    QLineEdit *cpusEdit;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QLineEdit *elapsedEdit;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(400, 314);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        loopCountEdit = new QLineEdit(MainWidget);
        loopCountEdit->setObjectName(QString::fromUtf8("loopCountEdit"));

        horizontalLayout->addWidget(loopCountEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        processEventsButton = new QPushButton(MainWidget);
        processEventsButton->setObjectName(QString::fromUtf8("processEventsButton"));

        horizontalLayout_2->addWidget(processEventsButton);

        threadButton = new QPushButton(MainWidget);
        threadButton->setObjectName(QString::fromUtf8("threadButton"));

        horizontalLayout_2->addWidget(threadButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_2);

        progressBar = new QProgressBar(MainWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        cpusEdit = new QLineEdit(MainWidget);
        cpusEdit->setObjectName(QString::fromUtf8("cpusEdit"));
        cpusEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(cpusEdit);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_3 = new QLabel(MainWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(false);

        horizontalLayout_4->addWidget(label_3);

        elapsedEdit = new QLineEdit(MainWidget);
        elapsedEdit->setObjectName(QString::fromUtf8("elapsedEdit"));
        elapsedEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(elapsedEdit);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 107, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        closeButton = new QPushButton(MainWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_5->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(MainWidget);
        QObject::connect(closeButton, SIGNAL(clicked()), MainWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "Valor M\303\241ximo para o loop: ", 0, QApplication::UnicodeUTF8));
        processEventsButton->setText(QApplication::translate("MainWidget", "Processar\n"
"com \"ProcessEvents\"", 0, QApplication::UnicodeUTF8));
        threadButton->setText(QApplication::translate("MainWidget", "Processar\n"
"com Thread", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "Quantidade de cpus (ou \"cores\")", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWidget", "Tempo Decorrido:", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("MainWidget", "Sair", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
