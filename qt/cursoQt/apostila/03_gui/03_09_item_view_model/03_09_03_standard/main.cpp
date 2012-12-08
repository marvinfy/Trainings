#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget * main_wg = new QWidget;

	// cria um objeto "splitter" para compartilhar widgets:    
	QSplitter *splitter = new QSplitter(main_wg);
	const int totRows = 10;

	// ==== 1) cada item é um subnível do item anterior:

   QStandardItemModel * model1= new QStandardItemModel(main_wg);
	QStandardItem *parentItem = model1->invisibleRootItem();
	for (int i = 0; i < totRows; ++i)
	{
		QStandardItem *item =
			new QStandardItem(QString("item %0").arg(i));
		parentItem->appendRow(item);
		parentItem = item;
	}
	QTreeView *tree1 = new QTreeView(splitter);
	tree1->setModel(model1);
	tree1->expandAll();

	// ==== 2) temos 3 itens no nível principal
		// e cada um deles tem dois sub-itens(como sub-nível):

	QStandardItemModel * model2= new QStandardItemModel;
	// define os títulos das colunas:
	for (int col = 0; col < 3; ++col)
	{
		model2->setHorizontalHeaderItem(col,
				new QStandardItem( QString("COL-%1").arg(col+1) ) );
	}
	parentItem = model2->invisibleRootItem();
	int rows = 3, subNiveis = 2;
	for (int i = 0; i < rows; ++i)
	{
		QStandardItem *item_n1 =
							new QStandardItem(QString("item %0").arg(i));
		parentItem->appendRow(item_n1);

		for ( int i2=0; i2 < subNiveis; ++i2 )
		{
			QStandardItem *item_n2 =
									new QStandardItem(QString("item %0%1").arg(i).arg(i2));
			item_n1->appendRow(item_n2);
		}
	}


	QTreeView *tree2 = new QTreeView(splitter);
	tree2->setModel(model2);
	tree2->expandAll();
	
	// tree2->expand( model2->index(1,0)); // expande só a segunda linha
	
	// layout :
	QVBoxLayout * layMain = new QVBoxLayout;
	layMain->addWidget(splitter);
	main_wg->setLayout( layMain);

	main_wg->setWindowTitle("03_standard - 2 tree views com diferentes models");
	main_wg->resize(600,500);

	main_wg->show();
	return app.exec();
}
