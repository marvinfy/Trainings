/********************************************************************************
** Form generated from reading UI file 'webbrowser.ui'
**
** Created: Sat 26. Mar 16:55:06 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBBROWSER_H
#define UI_WEBBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_WebBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QWebView *webView;

    void setupUi(QWidget *WebBrowser)
    {
        if (WebBrowser->objectName().isEmpty())
            WebBrowser->setObjectName(QString::fromUtf8("WebBrowser"));
        WebBrowser->resize(400, 300);
        verticalLayout = new QVBoxLayout(WebBrowser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        webView = new QWebView(WebBrowser);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("http://www.qtcentre.org/"));

        verticalLayout->addWidget(webView);


        retranslateUi(WebBrowser);

        QMetaObject::connectSlotsByName(WebBrowser);
    } // setupUi

    void retranslateUi(QWidget *WebBrowser)
    {
        WebBrowser->setWindowTitle(QApplication::translate("WebBrowser", "Web Browser", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WebBrowser: public Ui_WebBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBBROWSER_H
