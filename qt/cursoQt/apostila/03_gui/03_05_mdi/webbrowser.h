#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QtGui/QWidget>

namespace Ui {
    class WebBrowser;
}

class WebBrowser : public QWidget {
    Q_OBJECT
public:
    WebBrowser(QWidget *parent = 0);
    ~WebBrowser();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::WebBrowser *m_ui;
};

#endif // WEBBROWSER_H
