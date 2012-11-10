/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 26. Mar 16:55:06 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
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
    QAction *actionQuit;
    QAction *actionForm1;
    QAction *actionForm2;
    QAction *actionBrowser;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_Arquivo;
    QMenu *menuJanelas;
    QMenu *menuAj_uda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(667, 529);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        actionQuit->setFont(font);
        actionQuit->setIconVisibleInMenu(true);
        actionForm1 = new QAction(MainWindow);
        actionForm1->setObjectName(QString::fromUtf8("actionForm1"));
        actionForm1->setFont(font);
        actionForm2 = new QAction(MainWindow);
        actionForm2->setObjectName(QString::fromUtf8("actionForm2"));
        actionForm2->setFont(font);
        actionBrowser = new QAction(MainWindow);
        actionBrowser->setObjectName(QString::fromUtf8("actionBrowser"));
        actionBrowser->setFont(font);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionAbout->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 1);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setTabShape(QTabWidget::Triangular);

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 19));
        menu_Arquivo = new QMenu(menuBar);
        menu_Arquivo->setObjectName(QString::fromUtf8("menu_Arquivo"));
        menuJanelas = new QMenu(menuBar);
        menuJanelas->setObjectName(QString::fromUtf8("menuJanelas"));
        menuAj_uda = new QMenu(menuBar);
        menuAj_uda->setObjectName(QString::fromUtf8("menuAj_uda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(true);
        mainToolBar->setIconSize(QSize(16, 16));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Arquivo->menuAction());
        menuBar->addAction(menuJanelas->menuAction());
        menuBar->addAction(menuAj_uda->menuAction());
        menu_Arquivo->addAction(actionQuit);
        menuJanelas->addAction(actionForm1);
        menuJanelas->addAction(actionForm2);
        menuJanelas->addSeparator();
        menuJanelas->addAction(actionBrowser);
        menuAj_uda->addAction(actionAbout);
        mainToolBar->addAction(actionQuit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionForm1);
        mainToolBar->addAction(actionForm2);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBrowser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; text-decoration: underline; color:#ff0000;\">Sair</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionQuit->setStatusTip(QApplication::translate("MainWindow", "Sair da Aplica\303\247\303\243o.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionForm1->setText(QApplication::translate("MainWindow", "Formul\303\241rio 1", 0, QApplication::UnicodeUTF8));
        actionForm1->setIconText(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionForm1->setToolTip(QApplication::translate("MainWindow", "Form-1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionForm1->setStatusTip(QApplication::translate("MainWindow", "Abre o Formul\303\241rio 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionForm1->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", 0, QApplication::UnicodeUTF8));
        actionForm2->setText(QApplication::translate("MainWindow", "Formul\303\241rio 2", 0, QApplication::UnicodeUTF8));
        actionForm2->setIconText(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionForm2->setToolTip(QApplication::translate("MainWindow", "Form-2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionForm2->setStatusTip(QApplication::translate("MainWindow", "Abre o Formul\303\241rio 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionForm2->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", 0, QApplication::UnicodeUTF8));
        actionBrowser->setText(QApplication::translate("MainWindow", "Web Browser", 0, QApplication::UnicodeUTF8));
        actionBrowser->setIconText(QApplication::translate("MainWindow", "Web", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBrowser->setToolTip(QApplication::translate("MainWindow", "Browser", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionBrowser->setStatusTip(QApplication::translate("MainWindow", "Abre o Navegador Web", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionBrowser->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "Sobre...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("MainWindow", "Informa\303\247\303\265es sobre esta aplicac\303\243o", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menu_Arquivo->setTitle(QApplication::translate("MainWindow", "&Arquivo", 0, QApplication::UnicodeUTF8));
        menuJanelas->setTitle(QApplication::translate("MainWindow", "&Janelas", 0, QApplication::UnicodeUTF8));
        menuAj_uda->setTitle(QApplication::translate("MainWindow", "Aj&uda", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "ToolBar Principal", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
