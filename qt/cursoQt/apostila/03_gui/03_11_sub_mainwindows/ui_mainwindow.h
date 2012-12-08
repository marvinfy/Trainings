/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon 26. Oct 20:42:43 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSubMainWindow_1;
    QAction *actionSubMainWindow_2;
    QAction *actionAbas_triangulares;
    QAction *actionAbas_retangulares;
    QAction *actionCascata;
    QAction *actionTelhas;
    QAction *actionSair;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuSubWindows;
    QMenu *menuExibir;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        actionSubMainWindow_1 = new QAction(MainWindow);
        actionSubMainWindow_1->setObjectName(QString::fromUtf8("actionSubMainWindow_1"));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        actionSubMainWindow_1->setFont(font);
        actionSubMainWindow_2 = new QAction(MainWindow);
        actionSubMainWindow_2->setObjectName(QString::fromUtf8("actionSubMainWindow_2"));
        actionSubMainWindow_2->setFont(font);
        actionAbas_triangulares = new QAction(MainWindow);
        actionAbas_triangulares->setObjectName(QString::fromUtf8("actionAbas_triangulares"));
        actionAbas_retangulares = new QAction(MainWindow);
        actionAbas_retangulares->setObjectName(QString::fromUtf8("actionAbas_retangulares"));
        actionCascata = new QAction(MainWindow);
        actionCascata->setObjectName(QString::fromUtf8("actionCascata"));
        actionTelhas = new QAction(MainWindow);
        actionTelhas->setObjectName(QString::fromUtf8("actionTelhas"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionSair->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 19));
        menuSubWindows = new QMenu(menuBar);
        menuSubWindows->setObjectName(QString::fromUtf8("menuSubWindows"));
        menuExibir = new QMenu(menuBar);
        menuExibir->setObjectName(QString::fromUtf8("menuExibir"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSubWindows->menuAction());
        menuBar->addAction(menuExibir->menuAction());
        menuSubWindows->addAction(actionSubMainWindow_1);
        menuSubWindows->addAction(actionSubMainWindow_2);
        menuSubWindows->addSeparator();
        menuSubWindows->addAction(actionSair);
        menuExibir->addAction(actionAbas_triangulares);
        menuExibir->addAction(actionAbas_retangulares);
        menuExibir->addAction(actionCascata);
        menuExibir->addAction(actionTelhas);
        mainToolBar->addAction(actionSair);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSubMainWindow_1);
        mainToolBar->addAction(actionSubMainWindow_2);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbas_triangulares);
        mainToolBar->addAction(actionAbas_retangulares);
        mainToolBar->addAction(actionCascata);
        mainToolBar->addAction(actionTelhas);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSubMainWindow_1->setText(QApplication::translate("MainWindow", "SubMainWindow - 1", 0, QApplication::UnicodeUTF8));
        actionSubMainWindow_1->setIconText(QApplication::translate("MainWindow", "Sub 1", 0, QApplication::UnicodeUTF8));
        actionSubMainWindow_2->setText(QApplication::translate("MainWindow", "SubMainWindow - 2", 0, QApplication::UnicodeUTF8));
        actionSubMainWindow_2->setIconText(QApplication::translate("MainWindow", "Sub 2", 0, QApplication::UnicodeUTF8));
        actionAbas_triangulares->setText(QApplication::translate("MainWindow", "Abas triangulares", 0, QApplication::UnicodeUTF8));
        actionAbas_retangulares->setText(QApplication::translate("MainWindow", "Abas retangulares", 0, QApplication::UnicodeUTF8));
        actionCascata->setText(QApplication::translate("MainWindow", "Cascata", 0, QApplication::UnicodeUTF8));
        actionTelhas->setText(QApplication::translate("MainWindow", "Telhas", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
        menuSubWindows->setTitle(QApplication::translate("MainWindow", "SubWindows", 0, QApplication::UnicodeUTF8));
        menuExibir->setTitle(QApplication::translate("MainWindow", "Janelas", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Barra de Ferramentas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
