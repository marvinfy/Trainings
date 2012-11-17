#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
//@@ incluí aqui:
#include <QDirModel>

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

	//@@ acrescentei aqui:
	private:
		QDirModel *model;

	public slots:
			void anyViewPressed ( const QModelIndex & index );


private slots:
	 void on_comboBox_highlighted(int index);
};

#endif // WIDGET_H
