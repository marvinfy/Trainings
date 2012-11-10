/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 3. Nov 12:23:45 2012
**      by: Qt User Interface Compiler version 4.7.4
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
    QAction *actionSair;
    QAction *actionToggleBrowser;
    QAction *actionSobre;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
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
    QMenu *menuArquivo;
    QMenu *menuExibir;
    QMenu *menuAjuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(426, 347);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagens/agenda.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow , QMenuBar, QMenu , QToolButton, QStatusBar {\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 255);\n"
"font: bold 9pt \"Verdana\";\n"
"}\n"
"\n"
"#centralWidget, QLabel, QLCDNumber {\n"
"	background-image: url(:/imagens/background_blue.jpg);\n"
"	color: rgb(255, 255, 255);\n"
"	font: bold 9pt \"Verdana\";\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"#dockWidgetContents, #dockWidgetContents QLabel {\n"
"	background-color: rgb(0, 85, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagens/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSair->setIcon(icon1);
        actionToggleBrowser = new QAction(MainWindow);
        actionToggleBrowser->setObjectName(QString::fromUtf8("actionToggleBrowser"));
        actionToggleBrowser->setCheckable(true);
        actionToggleBrowser->setChecked(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagens/web.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToggleBrowser->setIcon(icon2);
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagens/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobre->setIcon(icon3);
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        digitalClock = new QLCDNumber(centralWidget);
        digitalClock->setObjectName(QString::fromUtf8("digitalClock"));
        digitalClock->setNumDigits(8);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setMinimumSize(QSize(258, 98));
        webView->setUrl(QUrl("about:blank"));

        verticalLayout->addWidget(webView);


        verticalLayout_2->addWidget(webFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 426, 19));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuExibir = new QMenu(menuBar);
        menuExibir->setObjectName(QString::fromUtf8("menuExibir"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(16, 16));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setOpenExternalLinks(true);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuArquivo->menuAction());
        menuBar->addAction(menuExibir->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuArquivo->addAction(actionSair);
        menuExibir->addAction(actionToggleBrowser);
        menuAjuda->addAction(actionSobre);
        mainToolBar->addAction(actionSair);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionToggleBrowser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSobre);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(webEdit, SIGNAL(returnPressed()), webButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Janela Principal", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSair->setStatusTip(QApplication::translate("MainWindow", "Encerrar esta aplica\303\247\303\243o", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSair->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionToggleBrowser->setText(QApplication::translate("MainWindow", "Exibe/Oculta o Web Browser", 0, QApplication::UnicodeUTF8));
        actionToggleBrowser->setIconText(QApplication::translate("MainWindow", "Web", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionToggleBrowser->setToolTip(QApplication::translate("MainWindow", "Web Browser", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionToggleBrowser->setStatusTip(QApplication::translate("MainWindow", "Permite Exiber ou ocultar o Web Browser", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionToggleBrowser->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        actionSobre->setText(QApplication::translate("MainWindow", "Sobre...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSobre->setStatusTip(QApplication::translate("MainWindow", "Informa\303\247\303\265es sobre esta aplica\303\247\303\243o", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSobre->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        webLabel->setText(QApplication::translate("MainWindow", "Endere\303\247o web: ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        webEdit->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">Informe aqui</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">um endere\303\247o </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">Web</span></p>\n"
""
                        "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/imagens/web.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        webEdit->setStatusTip(QApplication::translate("MainWindow", "Informe um endere\303\247o web", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        webButton->setText(QString());
        menuArquivo->setTitle(QApplication::translate("MainWindow", "Arquivo", 0, QApplication::UnicodeUTF8));
        menuExibir->setTitle(QApplication::translate("MainWindow", "Exibir", 0, QApplication::UnicodeUTF8));
        menuAjuda->setTitle(QApplication::translate("MainWindow", "Ajuda", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Barra de Ferramentas", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Favoritos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">FAVORITOS!</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/imagens/favorites.png\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin"
                        "-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Visite:</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://www.agit.com.br\"><span style=\" font-size:12pt; font-weight:600; text-decoration: underline; color:#0000ff;\">Site da Agit</span></a></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-"
                        "weight:600; text-decoration: underline; color:#0000ff;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://www.qtcentre.org\"><span style=\" font-size:12pt; font-weight:600; text-decoration: underline; color:#0000ff;\">Qt Centre</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
