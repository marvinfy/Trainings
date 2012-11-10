/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 2. Apr 15:03:19 2011
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
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAppQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_1;
    QWidget *dockWidgetContents_1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QCalendarWidget *calendarWidget;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout;
    QWebView *webView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(734, 559);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        actionAppQuit = new QAction(MainWindow);
        actionAppQuit->setObjectName(QString::fromUtf8("actionAppQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAppQuit->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 734, 24));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(16, 16));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_1 = new QDockWidget(MainWindow);
        dockWidget_1->setObjectName(QString::fromUtf8("dockWidget_1"));
        dockWidgetContents_1 = new QWidget();
        dockWidgetContents_1->setObjectName(QString::fromUtf8("dockWidgetContents_1"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(dockWidgetContents_1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        dockWidget_1->setWidget(dockWidgetContents_1);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_1);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox = new QComboBox(dockWidgetContents_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        calendarWidget = new QCalendarWidget(dockWidgetContents_3);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(calendarWidget);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_3);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QString::fromUtf8("dockWidget_4"));
        sizePolicy.setHeightForWidth(dockWidget_4->sizePolicy().hasHeightForWidth());
        dockWidget_4->setSizePolicy(sizePolicy);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        webView = new QWebView(dockWidgetContents_4);
        webView->setObjectName(QString::fromUtf8("webView"));
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setUrl(QUrl("http://www.qtcentre.org/content/?s=e95be77f90b9c03edeea8ded06382b9e"));

        verticalLayout->addWidget(webView);

        dockWidget_4->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_4);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionAppQuit);
        mainToolBar->addAction(actionAppQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAppQuit->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
        actionAppQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Arquivo", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "Exibir", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Barra de Ferramentas", 0, QApplication::UnicodeUTF8));
        dockWidget_1->setWindowTitle(QApplication::translate("MainWindow", "Dock-1", 0, QApplication::UnicodeUTF8));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Dock-2", 0, QApplication::UnicodeUTF8));
        dockWidget_3->setWindowTitle(QApplication::translate("MainWindow", "Dock-3", 0, QApplication::UnicodeUTF8));
        dockWidget_4->setWindowTitle(QApplication::translate("MainWindow", "Dock-4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
