#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

	// cria um "model" usando o "QDirModel"
	model = new QDirModel (this);

	// Neste exemplo, serão criadas quatro "views":
	// uma "tree", uma "table", uma "list" e uma "ComboBox",
	// relacionadas ao mesmo "model", usando o "RootIndex" default.

	// 1- ==== a primeira "view" é uma "tree":
	ui->treeView->setModel(model);

	// 2- ==== a segunda "view" é uma "table"
	ui->tableView->setModel(model);

	// 3- ==== a terceira view é uma "list":
	ui->listView->setModel(model);

	// 4- ==== a quarta "view" é uma "comboBox"
	ui->comboBox->setModel(model);

	
	connect( ui->treeView, SIGNAL(pressed(const QModelIndex &)),
				this ,  SLOT(anyViewPressed  (const QModelIndex &)) );

	connect( ui->tableView, SIGNAL(pressed(const QModelIndex &)),
				this ,  SLOT(anyViewPressed  (const QModelIndex &)) );

	connect( ui->listView, SIGNAL(pressed(const QModelIndex &)),
				this ,  SLOT(anyViewPressed (const QModelIndex &)) );

	connect (ui->comboBox->view() , SIGNAL(pressed(const QModelIndex &)),
				this ,  SLOT(anyViewPressed  (const QModelIndex &)) );

	ui->listView->setSelectionBehavior ( QAbstractItemView::SelectRows );

	ui->treeView->setCurrentIndex(model->index(0, 0));
	anyViewPressed ( model->index(0,0) );

	// exibe, forçando recálculo de layout
	show();

	// e agora calcula largura inicial
	// de cada "view" do splitter inferior:
	QList< int > cols;
	int w = ui->tablelistSplitter->width();
	cols << int(w* 0.80) << int(w*0.20);
	ui->tablelistSplitter->setSizes(cols);

	// atenção: as duas funções abaixo podem ser lentas
	// se existirem muitas linhas:
	ui->treeView->resizeColumnToContents(0);
	ui->tableView->resizeColumnsToContents(); // tenta que todas as colunas
																										// tenham espaço para seu conteúdo

	ui->tableView->horizontalHeader()->setStretchLastSection(true);
													// última coluna ocupará espaço disponível

	setWindowTitle("01_dir - 4 'views' usando o mesmo 'model' (diretórios)");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::anyViewPressed ( const QModelIndex & index )
{

	// atualiza o texto do "lineEdit":
//	ui->lineEdit->setText( model->data(index, Qt::DisplayRole).toString() );
	ui->lineEdit->setText(index.data().toString());
	
	// sincroniza todas as "views":
	if ( sender() != ui->treeView)
		ui->treeView->setCurrentIndex(index);

	// Para as demais "views": checar se o índice é pertinente.
	// Por exemplo, se for um nome de diretório ou de arquivo,
	// o item só existe na "treeView";
	// então para as demais "views" é preciso buscar
	// os itens de primeiro nível (ou seja, os drives):

	QModelIndex firstlevelIndex(index);
	// quando o "parent" do "index" for um "QModelIndex" vazio (inválido)
	// é porque esse "index" corresponde ao primeiro nível:
//	while ( firstlevelIndex.parent() != QModelIndex() ) // há quem use...
	// mas prefiro:
	while ( firstlevelIndex.parent().isValid())
		firstlevelIndex = firstlevelIndex.parent();

	ui->tableView->setCurrentIndex(firstlevelIndex);
	ui->listView->setCurrentIndex(firstlevelIndex);
	ui->comboBox->setCurrentIndex(firstlevelIndex.row());
}


void Widget::on_comboBox_highlighted(int row)
{
	// faria isto:
	 // ui->comboBox->setCurrentIndex(row);
	// mas quero mudar todas as views
	// então basta:
	anyViewPressed(model->index(row,0));
}
