#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// slots:

// pushButtons:
void Widget::on_printerButton_clicked()
{
	ui->printWidget->printToSelectedPrinter();
}
void Widget::on_pdfButton_clicked()
{
	ui->printWidget->printToPdf();
}
void Widget::on_printWidgetButton_clicked()
{
	ui->printWidget->printToWidget();
}


