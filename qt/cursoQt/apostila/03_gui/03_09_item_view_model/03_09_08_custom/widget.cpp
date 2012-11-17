#include <QMessageBox>
#include "widget.h"
#include "ui_widget.h"

#include "Model.h"
#include "delegate.h"

Widget::Widget(const QString & fileName,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

	// Cria o "Model" personalizado, passando o nome do arquivo que será a fonte de dados
	// e este Widget como "parent" (this).
	// Finalmente o define como sendo o "model" da "tableView":
	ui->tableView->setModel( new Model(fileName, this) );
	// O mesmo para o "delegate":
	ui->tableView->setItemDelegate( new Delegate(this) );

	// outras propriedades da "tableView":
	ui->tableView->setAlternatingRowColors(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
