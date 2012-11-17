#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget)
{
    ui->setupUi(this);

	int w = width();
	QList<int> cols;
	cols << int ( w *0.5 ) // 50%
			<< int ( w *0.3) // 30%
			<< int (w * 0.2) ;  // 20%
	ui->splitter->setSizes( cols );

}

MainWidget::~MainWidget()
{
    delete ui;
}
