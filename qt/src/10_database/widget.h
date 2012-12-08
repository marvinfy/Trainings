#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QSqlDatabase db, QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_sortEdit_returnPressed();

    void on_filterEdit_returnPressed();

private:
    Ui::Widget *ui;
    QSqlDatabase m_db;
    QSqlTableModel* m_model;

};

#endif // WIDGET_H
