#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget * main_wg = new QWidget;

	// cria um objeto "splitter" para compartilhar widgets:    
	QSplitter *splitter = new QSplitter(main_wg);

	const int totRows=10;
	const int totCols = 3;
	// cria um "model" usando o "StandardModel"
	QStandardItemModel *model =
			new QStandardItemModel(totRows, totCols);
	int row, col;

	// define os títulos das colunas:
	for (col = 0; col < totCols; ++col) 
	{
		model->setHorizontalHeaderItem(col, 
			new QStandardItem( QString("COL-%1").arg(col+1) ) );
	}
	
	// alimenta linhas e colunas:
	for (row = 0; row < totRows; ++row) 
	{ 
		for (col = 0; col < totCols; ++col) 
		{
			QStandardItem *item = 
					new QStandardItem(
                                        QString("row %0, col %1").arg(row).arg(col));
			model->setItem(row, col, item);
			for (int sub=0; sub<2; ++sub)
				item->appendRow(new QStandardItem(
										 QString("%0-%1").arg(row).arg(sub)));
		}
	}	
	
	// Neste exemplo,
	// O "model" foi alimentado com linhas e colunas.
	// E serão criadas 4 "views" (uma "tree", uma "table", uma "list" e uma "comboBox")
	// relacionadas ao mesmo "model";
	// Cada "view" exibe os dados de uma determinada maneira;

	// 1- ==== a primeira "view" é uma "tree":
	QTreeView *tree = new QTreeView(splitter);
	tree->setModel(model);
	// habilita classificação na tree:
	tree->setSortingEnabled(true);
	// classifica
	//tree->sortByColumn(0);
	tree->hideColumn(1);

	// configura o header para permitir mudança na ordem de classificacão:
	QHeaderView * hdrTree = tree->header();
	hdrTree->setSortIndicator(0,Qt::AscendingOrder);
	hdrTree->setMovable(true); // permite mover colunas do header

	// 2- ==== a segunda "view" é uma "table"
	QTableView *table = new QTableView(splitter);
	table->setModel(model);
	table->setAlternatingRowColors(true);
	// habilita classificação na table:
	table->setSortingEnabled(true);
	// classifica
	table->sortByColumn(0);	

	// configura o header para permitir mudança na ordem de classificacão:
	QHeaderView * hdrTable = table->horizontalHeader();
	hdrTable->setSortIndicator(0,Qt::AscendingOrder);
	hdrTable->setMovable(true); // permite mover colunas do header
			
	// 3- ==== a terceira view é uma "list": 
	QListView *list = new QListView(splitter);
	list->setModel(model);

	// 4- ==== a quarta "view" é uma "comboBox"
	QComboBox *combo = new QComboBox;
	combo->setModel(model);

	// configura a "splitter" definindo a largura de cada "view"
	int width = 800;	
	QList< int > cols;
	cols << int(width* 0.45) << int(width*0.45) << int(width*0.1);
	splitter->setSizes(cols);	
	
	// layout para agrupar a "combo" e a "splitter":
	QGridLayout * glayMain = new QGridLayout;
	main_wg->setLayout( glayMain);
	glayMain->addWidget( combo, 0, 1); // linha 0, coluna 1;
	glayMain->setRowMinimumHeight(1, glayMain->verticalSpacing() * 4); // linha 1: linha de separação
	glayMain->addWidget( splitter, 2, 0, 1, 3 ); // linha 2, coluna 0, rowSpan 1, colSpan 3

	main_wg->setWindowTitle("04_standard - 4 'views' usando o mesmo 'model' (StandardModel)");
	main_wg->resize(width,500);	

	main_wg->show();
	return app.exec();
}


