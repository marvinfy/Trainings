#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStringList>
#include <QTextStream>
#include <QModelIndex>
#include <QItemSelectionModel>

// forward declarations:
class QStandardItemModel;
class QStandardItem;
class QTreeView;
class QTableView;
class QListView;
class QComboBox;

class MainWidget : public QWidget
{
	Q_OBJECT

	public:
		MainWidget( const QByteArray & data, QWidget * parent = 0 );

	protected:
		void closeEvent ( QCloseEvent * event ) ;		

	private slots:
		void on_treehdr_sortIndicator_changed ( int, Qt::SortOrder );
		void on_tablehdr_sortIndicator_changed ( int, Qt::SortOrder );

		void on_selection_changed(const QModelIndex & current, const QModelIndex & previous);		
		void on_colOrder_changed(int col);
		void on_btSave_clicked();
		void on_itemChanged ( QStandardItem * item ) ;		
	
	private:
		void populateModel (QStandardItem * item, QStringList::const_iterator & iter,  
						QStringList::const_iterator & iterEnd, int currentLevel) ;
		
		void saveModel(QTextStream & stream, int level, QModelIndex parentIndex=QModelIndex() );		

		// model:		
		QStandardItemModel *model ;
		// objeto para sincronizar o item selecionado em uma "view"
		// com as demais "views":
		QItemSelectionModel *selectionModel ;
		
		// StringList que irá alimentar o "model":
		QStringList lsItems;

		// "views":	
		QTreeView *tree;
		QTableView *table;
		QListView *list;
		QComboBox *combo;
		
		bool itemChanged;
};

#endif // MAINWIDGET_H

