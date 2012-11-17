#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtGui/QWidget>
#include <QTableWidgetItem>
class QModelIndex;

namespace Ui
{
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

private slots:

	// tree:
		void on_treeWidget_pressed ( const QModelIndex & index );

		// list:
		void on_listWidget_currentRowChanged ( int currentRow ) ;

		// table:
		// item pressionado:
		void on_tableWidget_itemPressed (QTableWidgetItem * item  ) ;

		// seção do header pressionada:
		void tableheaderSectionPressed ( int logicalIndex ) ;
};

#endif // MAINWIDGET_H
