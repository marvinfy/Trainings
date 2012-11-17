#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QModelIndex>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent), ui(new Ui::MainWidget)
{
	ui->setupUi(this);

	// acrescentar itens em cada view após os itens já incluídos no QtDesigner:

	// ícone para o novo item de cada view:
	QIcon iconRadio; // usa um ícone do arquivo de recursos:
	iconRadio.addPixmap(QPixmap(":/images/ok_button.png"),
						QIcon::Normal, QIcon::Off);


	// ==== listWidget:

	// cria um novo item para a listWidget:
	QListWidgetItem * listItem = new QListWidgetItem(
							iconRadio , // ícone  (já inserido no arquivo de recursos)
							"Item 3" // texto
													);

	ui->listWidget->addItem(listItem);


	// ==== treeWidget:

	int treeTotalRows =ui->treeWidget->topLevelItemCount();


	 QTreeWidgetItem * treeItem = new QTreeWidgetItem;
	ui->treeWidget->insertTopLevelItem(treeTotalRows, treeItem );

	treeItem->setText(0, "Item 3");   // coluna 0
	treeItem->setIcon(0, iconRadio );
		  QTreeWidgetItem * treeSubItem = new QTreeWidgetItem( treeItem );
	treeSubItem->setText(0, "Item 31");

	// expandir os nós do treeWidget:
	ui->treeWidget->expandAll();


	// ==== tableWidget:

	int tableTotalRows = ui->tableWidget->rowCount();
	ui->tableWidget->setRowCount( tableTotalRows + 1 );

	QTableWidgetItem * tableHeader1 =
													new QTableWidgetItem;
	tableHeader1->setIcon(	iconRadio );

	QTableWidgetItem * tableItem1 = new QTableWidgetItem("31");
	QTableWidgetItem * tableItem2 = new QTableWidgetItem("32");
	tableItem1->setIcon(
															QIcon(":/images/radiobutton-off.png") );
	tableItem2->setIcon(
														 QIcon(":/images/radiobutton-on.png") );

	ui->tableWidget->setVerticalHeaderItem(tableTotalRows,tableHeader1 );

        ui->tableWidget->setItem(tableTotalRows, 0,  tableItem1 );
        ui->tableWidget->setItem(tableTotalRows, 1, tableItem2);

	ui->tableWidget->verticalHeader()->setClickable (true);

	// signal do header da table:
        connect(  ui->tableWidget->verticalHeader(), SIGNAL (sectionPressed( int ) ) ,
                                    this,  SLOT(tableheaderSectionPressed ( int ) ) );

}

MainWidget::~MainWidget()
{
	delete ui;
}
void MainWidget::on_treeWidget_pressed (const QModelIndex & index )
{
	QModelIndex firstlevelIndex(index);

	// quando o "parent" do "index" for um
	// "QModelIndex" vazio (inválido)
	// é porque esse "index" corresponde ao primeiro nível:
//	while ( firstlevelIndex.parent() != QModelIndex() )
        // MELHOR:
	while ( firstlevelIndex.parent().isValid() )
		firstlevelIndex = firstlevelIndex.parent();

	// alterar a linha do "listWidget",
	ui->listWidget->setCurrentRow(firstlevelIndex.row());
}
void MainWidget::on_listWidget_currentRowChanged( int currentRow )
{
	QAbstractItemModel * model = ui->treeWidget->model();

        QModelIndex modelIndex( model->index(currentRow, 0,
                                                    ui->treeWidget->rootIndex() ) );

	ui->treeWidget->setCurrentIndex( modelIndex );

}

void MainWidget::on_tableWidget_itemPressed( QTableWidgetItem * item  )
{
	ui->listWidget->setCurrentRow( ui->tableWidget->row(item) );
}

void MainWidget::tableheaderSectionPressed ( int logicalIndex )
{
	ui->listWidget->setCurrentRow( logicalIndex );
}

