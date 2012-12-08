#include <QtGui>
class StringListModelEx : public QStringListModel
{
	public:
		StringListModelEx (QStringList & strings, QObject * parent)
			: QStringListModel(parent)
			, m_strings(strings) // Perigo do 2.método (membro-referencia):
							// se a variável  QStringList que foi passada aqui
							// SAIR DE ESCOPO, terei uma referência INVÁLIDA
			{   }

		const QStringList & stringList() const { return m_strings; }

		// método 1
//		void	setStringList ( const QStringList & strings )
	//																			{ m_strings = strings; }

	 private:
		// método 2;
		void	setStringList ( const QStringList & );

	protected:
		int rowCount(const QModelIndex &/*parent*/) const
		{return m_strings.size(); }

		Qt::ItemFlags flags(const QModelIndex &index) const
		{
			return QStringListModel::flags(index) | Qt::ItemIsEditable;
		}
		QVariant data(const QModelIndex &index, int role) const
		{
			if ( role == Qt::DisplayRole)
				return m_strings[index.row()];
			else
				return QStringListModel::data(index, role);
		}
		bool setData(const QModelIndex &index, const QVariant &value, int role)
		{
			if ( role == Qt::EditRole)
			{
				m_strings[index.row()] = value.toString();
				emit dataChanged(index, index);
				return true;
			}
			else
				return QStringListModel::setData(index, value, role);
		}

	private:
		QStringList & m_strings; // referência ao inves de objeto
					// ver comentário "PERIGO"  na construtora.
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget main_wg;

	// cria um objeto "splitter" para compartilhar widgets:    
	QSplitter *splitter = new QSplitter(&main_wg);

	// cria um "model" usando o "QStringListModel"

	QStringList slist;
	
	slist << "Maria"<< "João"<< "Zulmira" << "Pedro"<< "Antonio"
				<< "Berenice" << "Artur" << "Carlos";

// 1. método:
//	StringListModelEx *model = new StringListModelEx(&main_wg);
//	model->setStringList(slist);

	// 2.método:
	StringListModelEx *model = new StringListModelEx(slist , &main_wg);
//	model->setStringList(slist);  // no 2. método essa função é PRIVATE

	model->sort(0); // classifica pela coluna zero

	// Neste exemplo,
	// O "model" será configurado para pegar dados 
	// de uma stringlist.
	// E serão criadas 4 "views" (uma "tree", uma "table", uma "list" e uma "comboBox")
	// relacionadas ao mesmo "model";
	// Cada "view" exibe os dados de uma determinada maneira;

	// 1- ==== a primeira "view" é uma "tree":
	QTreeView *tree = new QTreeView(splitter);
	tree->setModel(model);
	tree->setHeaderHidden(true);

	// retira a linha indicadora de nível da árvore:
	//tree->setRootIsDecorated(false);

	// 2- ==== a segunda "view" é uma "table"
	QTableView *table = new QTableView(splitter);
	table->setModel(model);
	table->setAlternatingRowColors(true);
	table->horizontalHeader()->setVisible(false);
	table->horizontalHeader()->setStretchLastSection(true);

	// 3- ==== a terceira view é uma "list": 
	QListView *list = new QListView(splitter);
	list->setModel(model);

	// deixo todas as views editarem, menos a listView:
	list->setEditTriggers(QAbstractItemView::NoEditTriggers);
	
	// 4- ==== a quarta "view" é uma "comboBox"
	QComboBox *combo = new QComboBox;
	combo->setModel(model);

	// layout para agrupar a "combo" e a "splitter":
	QGridLayout * glayMain = new QGridLayout;
	main_wg.setLayout( glayMain);

	glayMain->addWidget(combo, 0, 1 ); // linha 0, coluna 1;
	glayMain->setRowMinimumHeight(1, glayMain->verticalSpacing() * 4); // linha 1: linha de separação
	glayMain->addWidget( splitter, 2, 0, 1, 3 ); // linha 2, coluna 0, rowSpan 1, colSpan 3

	main_wg.setWindowTitle("02_strings - 4 'views' usando o mesmo 'model' (StringList)");
	main_wg.resize(800,500);

	main_wg.show();
	int ret = app.exec();

	// se dados foram alterados, altera a stringlist
	 // (MAS ISTO SÓ FAZIA SENTIDO QUANDO EU USAVA A CLASSE BASE)
/*	int rows = model->rowCount();
	for ( int r=0; r<rows; ++r)
	{
		QModelIndex index ( model->index(r,0) );
//		QString itemData (model->data(index, Qt::DisplayRole).toString() );
		QString itemData (index.data().toString() );
		if ( slist[r] != itemData)
			slist[r] = itemData;
	}
	 */


	/*  // usando o 1. método:
	 const QStringList & newSList = model->stringList();
	 foreach ( const QString & str, newSList)
              qDebug() << str;
	*/
	// usando o 2. método:
	foreach ( const QString & str, slist)
				 qDebug() << str;

	return ret;
}

