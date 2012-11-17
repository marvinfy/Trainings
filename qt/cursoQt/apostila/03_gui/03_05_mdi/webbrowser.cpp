#include "webbrowser.h"
#include "ui_webbrowser.h"

WebBrowser::WebBrowser(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WebBrowser)
{
    m_ui->setupUi(this);
}

WebBrowser::~WebBrowser()
{
    delete m_ui;
}

void WebBrowser::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
