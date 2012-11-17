#include <QtGui>
#include <iostream>

void populate_model ( QStandardItem * item, QVector<QSize> & vec_ColsRows,
					  int level, QString & prevRows);

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget * main_wg = new QWidget;

	// cria um objeto "splitter" para compartilhar widgets:    
	QSplitter *splitter = new QSplitter(main_wg);

	// cria um "model" usando o "StandardModel"
	QStandardItemModel *model = new QStandardItemModel;

	const int totCols = 3;
	int col;
	// define os títulos das colunas:
	for (col = 0; col < totCols; ++col) 
	{
		model->setHorizontalHeaderItem(col, 
			new QStandardItem( QString("COL-%1").arg(col+1) ) );
	}
	
	// alimenta linhas, colunas e sub-níveis:	
	QStandardItem *parentItem = model->invisibleRootItem();
	
	const int iniLevel = 0;
	const int totLevels= 3;
	QString prevRows("");
	QVector<QSize> vec_ColsRows; // colunas, linhas de cada nível 
	vec_ColsRows.reserve( totLevels );	
				// quantidade-colunas, quantidade-linhas
	vec_ColsRows << QSize(3,10) << QSize(3,3) << QSize(3,2) ;
	populate_model ( parentItem, vec_ColsRows,
						 iniLevel, prevRows);
	
	// Neste exemplo,
	// O "model" foi alimentado com linhas, colunas e sub-níveis:
	// E serão criadas 4 "views" (uma "tree", uma "table", uma "list" e uma "comboBox")
	// relacionadas ao mesmo "model";
	// Cada "view" exibe os dados de uma determinada maneira;

	// 1- ==== a primeira "view" é uma "tree":
	QTreeView *tree = new QTreeView(splitter);
	tree->setModel(model);
	// habilita classificação na tree:
	tree->setSortingEnabled(true);
	// classifica
	tree->sortByColumn(0);	
	// expande toda a árvore:
	tree->expandAll();
	// força largura de todas as colunas
	// para exibição completa do texto dos seus itens
	for (col = 0; col < totCols; ++col)
		tree->resizeColumnToContents(col);

	// configura o header para permitir mudança na ordem de classificacão:
	QHeaderView * hdrTree = tree->header();
	hdrTree->setClickable (true);
	hdrTree->setSortIndicator(0,Qt::AscendingOrder);
	hdrTree->setSortIndicatorShown(true);
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
	hdrTable->setClickable (true);
	hdrTable->setSortIndicator(0,Qt::AscendingOrder);
	hdrTable->setSortIndicatorShown(true);
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
	glayMain->addWidget( combo, 0, 1); // linha 0, coluna 0;
	glayMain->setRowMinimumHeight(1, glayMain->verticalSpacing() * 4); // linha 1: linha de separação
	glayMain->addWidget( splitter, 2, 0, 1, 3 ); // linha 2, coluna 0, rowSpan 1, colSpan 3

	main_wg->setWindowTitle("06_standard - 4 'views' usando o mesmo 'model' (StandardModel) - recursivo");
	main_wg->resize(800,500);	

	main_wg->show();
	return app.exec();
}

void populate_model (QStandardItem * item,
					 QVector<QSize> & vec_ColsRows,
					  int level, QString & prevRows)
{
	if ( level >= vec_ColsRows.size())
		return; // não há mais níveis de hierarquia na árvore
		
	const int totCols = vec_ColsRows[level].width();
	const int totRows = vec_ColsRows[level].height();
	const int row = item->rowCount();

	// alimenta um nível:
	QList<QStandardItem*> itCols;
	for (int col = 0; col < totCols; ++ col )
		itCols << new QStandardItem ( "item " + prevRows +
                                 QString("%1%2").arg(row).arg(col));
	// adiciona item neste nível:
	item->appendRow(itCols );

	// adiciona sub-nível neste nível:
	QString newPrevRows( prevRows + QString().setNum(row) );
	populate_model(item->child(row,0), vec_ColsRows, level+1, newPrevRows);

	// próximo item neste nível:
	if ( item->rowCount() < totRows )
		populate_model(item, vec_ColsRows, level, prevRows);
}

