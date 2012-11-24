#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
	 connect(this, SIGNAL(startController()),
				&m_controller, SLOT(startProcess()), Qt::QueuedConnection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_stopButton_clicked()
{
	emit startController();
}

void Widget::onTaskDone(const QString &data)
{
	ui->listWidget->addItem(data);
	ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
}
