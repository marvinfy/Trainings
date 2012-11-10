/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Nov 3 17:04:33 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSobre;
    QAction *actionExit;
    QAction *actionShow_Hide_broser;
    QAction *actionActionFavoritos;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *digitalClock;
    QFrame *webFrame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *webLabel;
    QLineEdit *webEdit;
    QPushButton *webButton;
    QWebView *webView;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuShow;
    QMenu *menuAjuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(653, 414);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagens/web.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 223, 223);"));
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagens/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobre->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setChecked(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagens/exit.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExit->setIcon(icon2);
        actionShow_Hide_broser = new QAction(MainWindow);
        actionShow_Hide_broser->setObjectName(QString::fromUtf8("actionShow_Hide_broser"));
        actionShow_Hide_broser->setCheckable(true);
        actionShow_Hide_broser->setChecked(true);
        actionShow_Hide_broser->setIcon(icon);
        actionActionFavoritos = new QAction(MainWindow);
        actionActionFavoritos->setObjectName(QString::fromUtf8("actionActionFavoritos"));
        actionActionFavoritos->setCheckable(true);
        actionActionFavoritos->setChecked(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagens/favorites.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActionFavoritos->setIcon(icon3);
        actionActionFavoritos->setIconVisibleInMenu(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        digitalClock = new QLCDNumber(centralWidget);
        digitalClock->setObjectName(QString::fromUtf8("digitalClock"));
        digitalClock->setDigitCount(8);
        digitalClock->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(digitalClock);


        verticalLayout_2->addLayout(horizontalLayout);

        webFrame = new QFrame(centralWidget);
        webFrame->setObjectName(QString::fromUtf8("webFrame"));
        webFrame->setFrameShape(QFrame::Panel);
        webFrame->setFrameShadow(QFrame::Sunken);
        webFrame->setLineWidth(1);
        webFrame->setMidLineWidth(0);
        verticalLayout = new QVBoxLayout(webFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        webLabel = new QLabel(webFrame);
        webLabel->setObjectName(QString::fromUtf8("webLabel"));

        horizontalLayout_2->addWidget(webLabel);

        webEdit = new QLineEdit(webFrame);
        webEdit->setObjectName(QString::fromUtf8("webEdit"));

        horizontalLayout_2->addWidget(webEdit);

        webButton = new QPushButton(webFrame);
        webButton->setObjectName(QString::fromUtf8("webButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagens/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        webButton->setIcon(icon4);

        horizontalLayout_2->addWidget(webButton);


        verticalLayout->addLayout(horizontalLayout_2);

        webView = new QWebView(webFrame);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setMinimumSize(QSize(504, 161));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        verticalLayout->addWidget(webView);


        verticalLayout_2->addWidget(webFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 25));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QString::fromUtf8("menuFIle"));
        menuShow = new QMenu(menuBar);
        menuShow->setObjectName(QString::fromUtf8("menuShow"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAutoFillBackground(false);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(dockWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setOpenExternalLinks(true);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 160, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);
        QWidget::setTabOrder(horizontalSlider, spinBox);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuShow->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuFIle->addAction(actionExit);
        menuShow->addAction(actionShow_Hide_broser);
        menuShow->addAction(actionActionFavoritos);
        menuAjuda->addAction(actionSobre);
        mainToolBar->addAction(actionExit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShow_Hide_broser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSobre);
        mainToolBar->addAction(actionActionFavoritos);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
        QObject::connect(webEdit, SIGNAL(returnPressed()), webButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt Dummy Browser", 0, QApplication::UnicodeUTF8));
        actionSobre->setText(QApplication::translate("MainWindow", "About...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSobre->setStatusTip(QApplication::translate("MainWindow", "About this application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSobre->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit the app", 0, QApplication::UnicodeUTF8));
        actionExit->setIconText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Exit the app", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("MainWindow", "Exits the application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionShow_Hide_broser->setText(QApplication::translate("MainWindow", "Show/Hide browser", 0, QApplication::UnicodeUTF8));
        actionShow_Hide_broser->setIconText(QApplication::translate("MainWindow", "Web", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShow_Hide_broser->setToolTip(QApplication::translate("MainWindow", "Show/Hide browser", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionShow_Hide_broser->setStatusTip(QApplication::translate("MainWindow", "Show or Hide the web browser", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionShow_Hide_broser->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        actionActionFavoritos->setText(QApplication::translate("MainWindow", "Show/Hide Favorites", 0, QApplication::UnicodeUTF8));
        actionActionFavoritos->setIconText(QApplication::translate("MainWindow", "Fav", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActionFavoritos->setToolTip(QApplication::translate("MainWindow", "Toggle Favorites", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionActionFavoritos->setStatusTip(QApplication::translate("MainWindow", "Shows or hides favorites", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        webLabel->setText(QApplication::translate("MainWindow", "URL:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        webEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#1f7dc5;\">Digite a URL</span></p><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#1f7dc5;\">aqui</span></p><p align=\"center\"><img src=\":/imagens/web.png\"/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        webEdit->setStatusTip(QApplication::translate("MainWindow", "URL", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        webButton->setText(QString());
        menuFIle->setTitle(QApplication::translate("MainWindow", "FIle", 0, QApplication::UnicodeUTF8));
        menuShow->setTitle(QApplication::translate("MainWindow", "Show", 0, QApplication::UnicodeUTF8));
        menuAjuda->setTitle(QApplication::translate("MainWindow", "Ajuda", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Toolbar", 0, QApplication::UnicodeUTF8));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Favoritos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><img src=\":/imagens/favorites.png\"/></p><p align=\"center\"><a href=\"http://qt.digia.com\"><span style=\" font-size:16pt; text-decoration: underline; color:#0000ff;\">Qt - Digia</span></a></p><p align=\"center\"><a href=\"http://www.qtcentre.org\"><span style=\" font-size:16pt; text-decoration: underline; color:#0000ff;\">QtCentre</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
