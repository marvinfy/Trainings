#include "MainWidget.h"
#include "ui_MainWidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
	 ui->setupUi(this);

	 //----------

	 // ======== LIST

	 // mais simples:
	 //ui->listWidget->addItem("Linha 3");

	 // mais detalhado:
	 QListWidgetItem * listItem = new QListWidgetItem(
				 QIcon(":/imagens/ficheiro.png"), "Linha 3");
	 listItem->setToolTip("Eu sou a Linha 3");
	 // listItem->setBackGround, setForeGround, setFont ... etc...

	 ui->listWidget->addItem(listItem);
	 // ou:
// ui->listWidget->insertItem(ui->listWidget->count(), listItem); // última linha
	 // ou:
// ui->listWidget->insertItem(0, listItem);  // primeira linha

	 // ======== TABLE
	 int tableRowCount = ui->tableWidget->rowCount();
	 ui->tableWidget->insertRow(tableRowCount); // terceira linha

	 // linha, coluna, item:
	 ui->tableWidget->setItem( tableRowCount, 0,
										new QTableWidgetItem("Linha 3-A"));

	 /*
	 QTableWidgetItem * tItem = new QTableWidgetItem("Linha 3-B");
	 tItem->setBackground(...);
	 tItem->setIcon(QIcon(...))
	 tItem->setForeground(...);
	 tItem->setToolTip(...);
	 tItem->setStatusTip(...);
	 ui->tableWidget->setItem(tableRowCount, 1, tItem );
	 */

	 ui->tableWidget->setItem(tableRowCount, 1,
									  new QTableWidgetItem("Linha 3-B"));

	 // ======== TREE

	 // passa para 2 colunas:
	 ui->treeWidget->setColumnCount(2);
	 // título da segunda coluna:
	 ui->treeWidget->headerItem()->setText(1, "Propriedades");

	 QTreeWidgetItem * item = new QTreeWidgetItem(
										 QStringList() << "Linha 3-A" << "Linha 3-B");

	 ui->treeWidget->invisibleRootItem()->addChild(item);

	 QTreeWidgetItem * subItem = new QTreeWidgetItem(
										 QStringList() << "Linha 3-A-1" );

	 item->addChild(subItem);
	 subItem->addChild(new QTreeWidgetItem( QStringList("Linha 3-A-1-1")));

	 ui->treeWidget->expandAll(); // não usar em árvores muito grandes...

	 // ---------

	 connect(ui->listWidget, SIGNAL(pressed(QModelIndex)),
				this, SLOT(anyViewActivated(QModelIndex)));

	 connect(ui->tableWidget, SIGNAL(pressed(QModelIndex)),
				this, SLOT(anyViewActivated(QModelIndex)));

	 connect(ui->treeWidget, SIGNAL(pressed(QModelIndex)),
				this, SLOT(anyViewActivated(QModelIndex)));

}

MainWidget::~MainWidget()
{
	delete ui;
}

void MainWidget::anyViewActivated(const QModelIndex &index)
{
	ui->lineEdit->setText(index.data().toString());
	// a função acima é uma mera "função de conveniencia".  Na verdade é:
	//	ui->lineEdit->setText(index.model()->data(index).toString());

	QModelIndex firstLevelIndex (index);

	if ( sender() != ui->treeWidget)
	{
		ui->treeWidget->setCurrentIndex(
					ui->treeWidget->model()->index(index.row(),0)); // linha, coluna
	}
	else
	{
		while (firstLevelIndex.parent().isValid())
			firstLevelIndex = firstLevelIndex.parent();
	}

	if ( sender() != ui->tableWidget)
		ui->tableWidget->selectRow(firstLevelIndex.row());

	if ( sender() != ui->listWidget)
		ui->listWidget->setCurrentRow(firstLevelIndex.row());
}
