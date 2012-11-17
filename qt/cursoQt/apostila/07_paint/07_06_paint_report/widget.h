#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
	void on_printerButton_clicked();
	void on_pdfButton_clicked();
	void on_printWidgetButton_clicked();
};

#endif // WIDGET_H
