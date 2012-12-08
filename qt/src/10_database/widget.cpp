#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QSqlDatabase db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_db(db)
{
    ui->setupUi(this);
    m_model = new QSqlTableModel(this, m_db);
    m_model->setTable("scooter");

    int nameCol = m_model->fieldIndex("name");
    int idCol = m_model->fieldIndex("id");

    m_model->setSort(m_model->fieldIndex("name"), Qt::AscendingOrder);
    m_model->select();

    ui->tableView->setModel(m_model);

    ui->tableView->horizontalHeader()->hideSection(idCol);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sortEdit_returnPressed()
{

}

void Widget::on_filterEdit_returnPressed()
{

}
