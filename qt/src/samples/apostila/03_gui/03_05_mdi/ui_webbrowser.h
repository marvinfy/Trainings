/********************************************************************************
** Form generated from reading ui file 'webbrowser.ui'
**
** Created: Fri 30. Oct 21:13:46 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
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
        Q_UNUSED(WebBrowser);
    } // retranslateUi

};

namespace Ui {
    class WebBrowser: public Ui_WebBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBBROWSER_H
