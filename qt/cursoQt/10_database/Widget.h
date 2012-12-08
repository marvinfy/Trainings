#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
    class Widget;
}
#include <QModelIndex>
class Widget : public QWidget
{
    Q_OBJECT

public:
	 explicit Widget(QSqlDatabase & db, QWidget *parent = 0);
    ~Widget();

	private slots:
		void on_sortEdit_returnPressed();
		void on_filterEdit_returnPressed();

		void dataChanged(const QModelIndex & index);

	private:
    Ui::Widget *ui;
	QSqlDatabase m_db;
	QSqlTableModel * m_model;

	// índices das colunas
	int m_nameCol;
	int m_idCol;
	int m_maxSpeedCol;
	int m_maxRangeCol;

};

#endif // WIDGET_H
