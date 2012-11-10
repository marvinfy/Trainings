#include "maindialog.h"
#include "ui_maindialog.h"
#include <QApplication>
#include <QCloseEvent>
#include <QMenu>
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDataWidgetMapper>
#include <QSqlRelationalDelegate>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
	// sempre abaixo da linha acima:
	m_editBtnMenu = new QMenu(this);
	m_editFinBtnMenu= new QMenu(this);
	m_navBtnMenu = new QMenu(this);

	QAction * editInsAct = new QAction("Inserir", this);
	m_editUpdAct = new QAction("Alterar", this);
	m_editDelAct = new QAction("Deletar", this);

	m_editBtnMenu->addAction(editInsAct);
	m_editBtnMenu->addAction(m_editUpdAct);
	m_editBtnMenu->addAction(m_editDelAct);

	QAction * editFinConfAct = new QAction ("Confirmar", this);
	QAction * editFinCancAct = new QAction ("Cancelar", this);
	m_editFinBtnMenu->addAction(editFinConfAct);
	m_editFinBtnMenu->addAction(editFinCancAct);

	m_firstAct = new QAction("Primeiro", this);
	m_prevAct = new QAction("Anterior", this);
	m_nextAct = new QAction("Próximo", this);
	m_lastAct = new QAction("Último", this);
	m_navBtnMenu->addAction(m_firstAct);
	m_navBtnMenu->addAction(m_prevAct);
	m_navBtnMenu->addAction(m_nextAct);
	m_navBtnMenu->addAction(m_lastAct);

	ui->editBtn->setMenu(m_editBtnMenu);
	ui->editFinishedBtn->setMenu(m_editFinBtnMenu);
	ui->navBtn->setMenu(m_navBtnMenu);

	// limpa itens que tenham sido inseridos no designer
	ui->ufCombo->clear();

	// tenta abrir a conexão ao banco de dados:
	if ( !m_db.open() )
	{
		QMessageBox::warning( this, "Erro", "Erro na abertura do banco");
		QApplication::postEvent(this,  new QCloseEvent()); // agenda evento para fechar a janela e encerrar a aplicação
		return;
	}

	ui->sexoGroup->groupRadioButtons();
	ui->estcivGroup->groupRadioButtons();

	m_tableModel = new QSqlRelationalTableModel(this);
	m_tableModel->setTable("pessoas");

	int pessoasNomeIndex = m_tableModel->fieldIndex("name");
	int pessoasSexoIndex = m_tableModel->fieldIndex("sexo");
	int pessoasEstcivIndex = m_tableModel->fieldIndex("estcivil");
	int pessoasMailIndex = m_tableModel->fieldIndex("recebe_mail");
	int pessoasUFIDIndex = m_tableModel->fieldIndex("uf_id");

	// relaciona o campo "uf_id" da tabela "pessoas"
	// ao campo "id" da tabela "uf", retornando o campo "name" da tabela "uf":
	m_tableModel->setRelation(pessoasUFIDIndex,
													 QSqlRelation("uf", "id", "name"));

	m_tableModel->select();  // executa uma query "select"

	// Prepara a comboBox para entender o relacionamento entre "pessoas" e "uf"
	// para isso recupera o "model de relacionamento" criado acima com "setRelation".
	// Esse é um model relacionado ao campo "pessoasUFIDIndex":
	QSqlTableModel *relationModel =
			m_tableModel->relationModel(pessoasUFIDIndex);
	ui->ufCombo->setModel(relationModel); // seta esse 'model' para a 'comboBox'
	// Define qual a coluna do 'model' que deve ser exibida pela 'combo'.
	// Nesse caso, é a coluna 'name'(de 'uf'):
	ui->ufCombo->setModelColumn(relationModel->fieldIndex("name"));

	// Mapear para o 'model', os demais 'widgets', que, ao contrário, da 'comboBox'
	// não têm suporte próprio para trabalhar com 'models':

	// Instancia o 'QDataWidgetMapper':
	m_mapper = new QDataWidgetMapper(this);
	// Define como os dados serão alterados no banco de dados ('Auto' ou 'Manual'):
	m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
	// Define o 'model' a ser usado por esse 'mapper':
	m_mapper->setModel(m_tableModel);
	// Define o 'delegate' (que faz a intermediação entre o 'model' e o seu modo de visualização/edição)
	// Neste caso, temos o 'QSqlRelationalDelegate', que permite ativar o tratamento relacional em uma 'comboBox':
	m_mapper->setItemDelegate(new QSqlRelationalDelegate(this));

	// Mapeia os widgets:

	// 'edit' para 'nome' <-> campo 'name' da tabela 'pessoas':
	m_mapper->addMapping( ui->nomeEdit, pessoasNomeIndex);
	m_mapper->addMapping(ui->ufCombo, pessoasUFIDIndex);
	m_mapper->addMapping(ui->emailCheck,  pessoasMailIndex);

	// No caso dos "radio buttons", como foram agrupados em um QButtonGroup,
	// através da classe personalizada "RadioButtonGroup", onde temos a propriedade "checkedButtonText",
	// essa propriedade deve ser usada aqui para que o mapeamento saiba como ler/alterar o valor do widget:
	m_mapper->addMapping(ui->sexoGroup,  pessoasSexoIndex, "checkedButtonText");
	m_mapper->addMapping(ui->estcivGroup,  pessoasEstcivIndex, "checkedButtonText");

	// conecta as 'actions' de navegação
	// aos 'slots' de navegação do 'mapper':

	connect(m_firstAct, SIGNAL(triggered()) ,
				 m_mapper, SLOT(toFirst()) );

	connect(m_prevAct, SIGNAL(triggered()) ,
			m_mapper, SLOT(toPrevious()) );

	connect(m_nextAct, SIGNAL(triggered()) ,
			m_mapper, SLOT(toNext()) );

	connect(m_lastAct, SIGNAL(triggered()) ,
			m_mapper, SLOT(toLast()) );

	// Para tomar conhecimento de mudanças de linha (registro) no 'mapper'
	// a fim de habilitar/desabilitar as 'actions' de navegação e edição que não se apliquem:
	connect(m_mapper, SIGNAL(currentIndexChanged(int)),
				this, SLOT(updateActionsState(int)));

	// Insert / Update / Delete:
	connect( editInsAct, SIGNAL(triggered()) ,
					this, SLOT(onInsert()));
	connect(m_editUpdAct, SIGNAL(triggered()) ,
				 this, SLOT(onUpdate()) );
	connect(m_editDelAct, SIGNAL(triggered()) ,
				 this, SLOT(onDelete()) );

	// Confirmar / Cancelar:
	connect(editFinConfAct, SIGNAL(triggered()) ,
				 this, SLOT(onOK()) );
	connect(editFinCancAct, SIGNAL(triggered()) ,
				 this, SLOT(onCancel()) );

	// habilita/desabilita botões e widgets conforme modo de edição
	changeEditAction( EA_None );	// EA_None: não está em modo de edição

	// Posicionar no primeiro registro de "pessoas", caso exista algum
	m_mapper->toFirst();
	if ( m_tableModel->rowCount()==0)  // caso a tabela esteja vazia, "toFirst" não fará nada.
		updateActionsState( m_mapper->currentIndex() ); // então, este 'slot' não será chamado.
}

void MainDialog::onInsert()
{
	// insere uma nova linha no 'model':
	int row = m_tableModel->rowCount(); // uma nova linha
	m_tableModel->insertRow(row);
	m_mapper->setCurrentIndex(row);

   // limpa controles de edição:
	clearWidgets();

	// habilita/desabilita botões e widgets conforme modo de edição
	changeEditAction( EA_Insert );
}

void MainDialog::onUpdate()
{
	// habilita/desabilita botões e widgets conforme modo de edição
	changeEditAction( EA_Update );
}

void MainDialog::onDelete()
{
	if ( QMessageBox::question(this, "Confirmar", "Excluir este registro?",
							   QMessageBox::Yes|QMessageBox::No)
			!= QMessageBox::Yes )
	{
		return;
	}

	// remove linha no 'model':
	int row = m_mapper->currentIndex();
	bool result = m_tableModel->removeRow(row);

	if ( result )
	{
		// completa a operação:
		m_mapper->submit();
		// reposiona linha atual do 'mapper' (será o registro que estava após o deletado, exceto se for o último):
		m_mapper->setCurrentIndex(qMin(row, m_tableModel->rowCount() - 1));
	}
	else
		QMessageBox::warning(this, "Erro", "Erro ao deletar registro\n" + m_tableModel->lastError().text() );

	updateActionsState( m_mapper->currentIndex());
}

void MainDialog::onOK()
{
	if ( ui->nomeEdit->text().length() < 5)
	{
		QMessageBox::warning(this, "Erro", "Nome: mínimo 5 caracteres");
		ui->nomeEdit->setFocus();
		return;
	}

	if ( ui->sexoGroup->checkedButtonText().isEmpty())
	{
		QMessageBox::warning(this, "Erro", "Sexo deve ser preenchido");
		ui->femininoRB->setFocus();
		return;
	}

	if ( ui->estcivGroup->checkedButtonText().isEmpty() )
	{
		QMessageBox::warning(this, "Erro", "Estado civil deve ser preenchido");
		ui->solteiroRB->setFocus();
		return;
	}
	if ( ui->ufCombo->currentIndex() < 0)
	{
		QMessageBox::warning(this, "Erro", "UF deve ser preenchida");
		ui->ufCombo->setFocus();
		return;
	}

	int row = m_mapper->currentIndex();

	bool result = m_mapper->submit();  // efetua insert ou update

	QString errMsg ;
	if ( ! result )
	{
		if ( m_editAction == EA_Insert )
		{
			errMsg = "Erro ao Inserir dados\n" + m_tableModel->lastError().text();
			m_tableModel->removeRow(row);
		}
		else
			errMsg = "Erro ao Atualizar dados\n" + m_tableModel->lastError().text();
	}

	if ( !errMsg.isEmpty())
	{
		QMessageBox::warning(this, "Erro", errMsg);
		m_mapper->toFirst(); // tenta ir para o primeiro, se existir
	}

	// retorna o índice para o "mapper":
	m_mapper->setCurrentIndex(row);
	// habilita/desabilita botões e widgets conforme modo de edição
	changeEditAction( EA_None );	// EA_None: não está mais em modo de edição
	// atualiza estado das 'actions'
	updateActionsState( m_mapper->currentIndex());
}

void MainDialog::onCancel()
{	
	int row = m_mapper->currentIndex();
	if ( m_editAction == EA_Insert )
		m_tableModel->removeRow(row);

	// desfaz alterações nos 'widgets':
	m_mapper->revert(); // volta ao estado anterior
	m_mapper->setCurrentIndex(qMin(row, m_tableModel->rowCount() - 1));

	// habilita/desabilita botões e widgets conforme modo de edição
	changeEditAction( EA_None );	// EA_None: não está mais em modo de edição
	// atualiza estado das 'actions'
	updateActionsState( m_mapper->currentIndex());
}

// Modifica estado das 'actions' conforme o registro atual:
void MainDialog::updateActionsState(int row)
{
	int totRows = m_tableModel->rowCount() ;

	// habilita o botão "Navegar", CASO existam registros na tabela "pessoas":
	if ( totRows <= 1 )
	{
		ui->navBtn->setEnabled( false ); // se não há nenhum registro, ou se há apenas um, não há navegação
		if ( totRows==0 )
			clearWidgets(); // tabela vazia
	}
	else
	{
		ui->navBtn->setEnabled( true ); // habilita o botão "navegar"

		// desabilita as "actions" de navegação que não façam sentido:
		bool isFirst = row == 0;// primeira linha do model
		bool isLast = row ==  totRows-1; // última linha;
		m_firstAct->setEnabled(!isFirst); // se já está no primeiro registro, desabilita a "firstAction"
		m_prevAct->setEnabled(!isFirst); // e se estiver no primeiro, desabilita também a "prevAction"(não há um registro anterior)
		m_nextAct->setEnabled(!isLast); // idem para "proximo registro" se já estiver no último
		m_lastAct->setEnabled(!isLast);  // e "último registro"
	}

	// desabilita as "actions" de entrada em edição que não façam sentido:
	m_editUpdAct->setEnabled( totRows>0 );  // desabilita se não há registros, ou se estamos posicionados em um registro inválido
	m_editDelAct->setEnabled( totRows>0 );  // idem
}

void MainDialog::changeEditAction(EditActions editAction)
{
	m_editAction = editAction ;

	switch (m_editAction)
	{
		case EA_Insert:   // está entrando em modo de edição
		case EA_Update: // idem

			// oculta o botão "Editar" (está entrando em edição)
			ui->editBtn->hide();
			// e exibe o botão "Concluir" (ok/cancel):
			ui->editFinishedBtn->show();
			// desabilita o botão "Navegar":
			ui->navBtn->setEnabled(false);

			// habilita a frame de controles de edição:
			ui->frame->setEnabled(true);
			ui->frame->setFrameShadow(QFrame::Raised); // a frame "levanta"

			// foco no primeiro 'widget':
			ui->nomeEdit->setFocus();

			break;

		case EA_None:  // Não está em edição (ou está SAINDO de um modo de edição)

			// exibe o botão "Editar"
			ui->editBtn->show();
			// oculta o botão "Concluir"
			ui->editFinishedBtn->hide();

			// desabilita a frame de controles de edição:
			ui->frame->setEnabled(false);
			ui->frame->setFrameShadow(QFrame::Sunken); // a frame "afunda"
			break;
		}
}

// "limpa" 'widgets' quando não há dados a exibir:
void MainDialog::clearWidgets()
{
	ui->nomeEdit->setText(""); // nome: string vazia:

	ui->sexoGroup->uncheckAll();  // grupo sexo: todos desmarcados
	ui->estcivGroup->uncheckAll(); // grupo estado civil: idem

	ui->emailCheck->setChecked(false); // checkBox: desmarcada
	ui->ufCombo->setCurrentIndex(-1); // comboBox: índice inválido (menor que zero)
															// nenhuma linha marcada.
}

// Função virtual "contextMenu":
// chamada quando "contextMenu" deve ser exibido;
// e o seu argumento "event" permite capturar facilmente
// a posição onde o menu de contexto deve ser exibido:
void MainDialog::contextMenuEvent(QContextMenuEvent *event)
{
	// executa o menu na posição fornecida pelo parametro "event",
	// ponteiro para um objeto "QContextMenuEvent":

	if ( m_editAction == EA_None ) // não está em edição
	{
		if ( m_tableModel->rowCount() <= 1 ) // se não tem registros ou se tem apenas um
			m_editBtnMenu->exec(event->globalPos()) ; // o menu de contexto será o menu de "Entrada em edição"
		else
			m_navBtnMenu->exec(event->globalPos()); // o menu de contexto será o menu de navegação
	}
	else // esta em edição
		m_editFinBtnMenu->exec(event->globalPos()); // o menu de contexto será o menu "Concluir edição"
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
