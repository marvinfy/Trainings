#include "MovimentoEditDialog.h"
#include "ui_MovimentoEditDialog.h"

#include <QSqlRelationalDelegate>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QMessageBox>
#include <QDebug>

MovimentoEditDialog::MovimentoEditDialog(QSqlRelationalTableModel* model,
													  ColumnIndexes & colInd,
													  int curRow,
													  bool canSubmit, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::MovimentoEditDialog)
	, m_movModel(model)
	, m_insert(curRow<0) // se linha < 0, então é inserção, do contrário é edição
	, m_canSubmit(canSubmit)
	, m_colInd(colInd)
{
	ui->setupUi(this);


	if ( m_insert )
		ui->movimentoNavGroup->hide(); // se vai inserir, não haverá havegação.

	// seta as comboBox para que sejam alimentadas pelo relacionamento correspondente
	// exibindo a coluna "nome" ao inves de "id":

	// nomes de clientes na respectiva combo:
	QSqlTableModel *cliRelationModel =
									m_movModel->relationModel(m_colInd.movClienteId);
	ui->clienteCombo->setModel(cliRelationModel);
	ui->clienteCombo->setModelColumn(cliRelationModel->fieldIndex("name"));
	// como o relation model só duas colunas (chave e valor), poderia:
	//ui->clienteCombo->setModelColumn(1); // índice da coluna valor
	
	ui->clienteCombo->model()->sort(cliRelationModel->fieldIndex("name"), Qt::AscendingOrder);

	// tipos de movimento na respectiva combo:
	QSqlTableModel *tipoRelationModel = m_movModel->relationModel(m_colInd.movTipoId);
	ui->tipoCombo->setModel(tipoRelationModel);
	ui->tipoCombo->setModelColumn(tipoRelationModel->fieldIndex("name"));
	ui->tipoCombo->model()->sort(tipoRelationModel->fieldIndex("name"), Qt::AscendingOrder);

	// * ^^ Nos 2 "relationModel" acima, temos sempre duas colunas: "chave" e "valor associado".

	// cria um mapeador que relacionará widgets "sem-model" com
	// as colunas respectivas do model:
	m_movMapper = new QDataWidgetMapper(this);

	// "submitPolicy": "auto" ou "manual"; se "auto" irá completar alterações se a linha selecionada for alterada
	m_movMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit); // "manual" -> teremos que chamar "submit" no momento apropriado.
	// define o "model" a ser usado pelo "mapper":
	m_movMapper->setModel(m_movModel);
	// define o delegate que permite exibir colunas relacionadas em comboBox's
	m_movMapper->setItemDelegate(new QSqlRelationalDelegate(this));

	// mapeia cada widget necessário para a coluna respectiva no model:
	m_movMapper->addMapping(ui->clienteCombo, m_colInd.movClienteId);
	m_movMapper->addMapping(ui->tipoCombo, m_colInd.movTipoId);
	m_movMapper->addMapping(ui->movDate, m_colInd.movDate);
	m_movMapper->addMapping(ui->descrEdit, m_colInd.movDescription);

	// conecta os botões de navegação diretamente aos slots do "mapper"
	// (neste caso, não é necessário criar novos slots para isso, exceto se quisermos fazer algo diferenciado)
	if ( !m_insert )
	{
		connect(ui->movimentoNavFirstBtn, SIGNAL(clicked()),
																			m_movMapper, SLOT(toFirst()));
		connect(ui->movimentoNavPrevBtn, SIGNAL(clicked()),
																			m_movMapper, SLOT(toPrevious()));
		connect(ui->movimentoNavNextBtn, SIGNAL(clicked()),
																			m_movMapper, SLOT(toNext()));
		connect(ui->movimentoNavLastBtn, SIGNAL(clicked()),
																			m_movMapper, SLOT(toLast()));
	}

	// se for inserir, deve criar nova linha no model
	if ( m_insert ) // INSERIR
	{
		// insere uma nova linha no model (caso o insert seja cancelado, deverá ser removida):
		curRow = m_movModel->rowCount(); // altera curRow para o total de linhas
		// rowCount -> total de linhas -> uma nova linha no final:
		m_movModel->insertRow(curRow);

		// em inclusão, seta widgets de data (para forçar o default):
		ui->movDate->setDate( QDate::currentDate() );

		setWindowTitle("INCLUIR novo movimento - "); // título do diálogo
	}
	else  // ALTERAR
		setWindowTitle("ALTERAR um movimento - ");  // título do diálogo

	QSqlDatabase db = m_movModel->database();
	setWindowTitle( windowTitle() + db.driverName());

	m_movMapper->setCurrentIndex(curRow); // seta a "row" do mapper

	// desabilta a opção do menu de sistema "fechar" ("X");
	// desse modo só poderá fechar o diálogo com os botões "OK" e "CANCELAR"
	// e não precisaremos redefinir a virtual "closeEvent" para finalzação
	Qt::WindowFlags flags = windowFlags();
	flags |=  Qt::CustomizeWindowHint;  // acrescenta: flags customizados
	flags &= ~Qt::WindowCloseButtonHint;  // desabilita: closeButton
	setWindowFlags(flags);

}

MovimentoEditDialog::~MovimentoEditDialog()
{
	delete ui;
}

// ==== CONFIRMA alterações feitas
void MovimentoEditDialog::on_okBtn_clicked()
{
	/* FAZER AQUI as análises necessarias, analisando o conteúdo dos widgets
  e verificando se eles são válidos de acordo com as regras estabelecidas para o caso.
  Se algum estiver inválido, retornar e não prosseguir.
  *** O mesmo que fizemos no exercício "Dialogo" ***
 */
	int cliComboRow= ui->clienteCombo->currentIndex();
	if ( cliComboRow<0)
	{
		QMessageBox::warning(this, "Erro", "Selecione um cliente");
		ui->clienteCombo->setFocus();
		return;
	}
	// outras validações...

	QSqlDatabase db = m_movModel->database();
	db.transaction();

	// linha atual do mapper:
	int mapperRow = m_movMapper->currentIndex();

	if ( !m_insert)
	{
		// == recupera o 'id' do movimento no model de movimento (já que permite navegação):
		m_currentMovimentoId = m_movModel->index( mapperRow, m_colInd.movId).data().toInt();
	}

	// = recupera o 'id' do cliente, já que permite mudar o cliente(tanto em edição quanto em inserção)
	m_currentClienteId = ui->clienteCombo->model()->index(cliComboRow, 0).data().toInt();
	// onde 0(zero) é o índice da coluna "chave" no "relationModel" da "combo"), no caso o "id" do cliente.

	// o mapper deve fazer com que o model submeta os dados, atualizando a fonte de dados
	// (pois está posicionado para "ManualSubmit"):

	QString errMsg;
	if ( m_canSubmit || m_insert ) // "submit" não falha nas inserções.
	{
		if ( !m_movMapper->submit())
			errMsg = "Falha ao enviar dados ao banco:\n" + m_movModel->lastError().text();
	}
	else // executa a query UPDATE diretamente no banco
	{
		QSqlQuery query(db);
		int tipo_id = ui->tipoCombo->model()->index(ui->tipoCombo->currentIndex(), 0).data().toInt();
		QString mov_date = ui->movDate->date().toString("dd/MM/yyyy");
		QString descr = ui->descrEdit->text();
		if ( query.exec(QString("UPDATE movimento SET cliente_id = %1, tipo_id = %2, mov_date = '%3', description = '%4' WHERE mov_id = %5")
							  .arg(m_currentClienteId).arg(tipo_id).arg(mov_date).arg(descr).arg(m_currentMovimentoId)))
		{
			m_movModel->query().finish();
			m_movModel->select(); // select, pois a alteração foi feita sem conhecimento do model(diretamente no banco)
		}
		else
			errMsg = "Falha ao enviar dados diretamente ao banco:\n" + query.lastError().text();
	}

	if ( !errMsg.isEmpty() )
	{
		QMessageBox::warning(this, "ERRO", errMsg);
		db.rollback(); // desfaz a transação
		on_cancelBtn_clicked(); // cancela
		return;
	}

	if ( m_insert ) // se inserido, o "id" do movimento só poderá ser recuperado agora (após o "submit")
	{
		// pegar o "lastInsertId", caso o driver suporte essa 'feature':

		QString queryIdText;

		if (db.driverName()=="QPSQL" ) // POSTGRE suporta a 'feature' "lastInsertID", mas depende de configuração não-default...
			queryIdText = "select currval('movimento_mov_id_seq')"; // então é mais seguro usar uma query de acesso nativo
		else if (db.driverName()=="QOCI") // ORACLE, idem...
			queryIdText = "select movimento_mov_id_seq.currval from dual";
		// else if {} ... // outras exceções...

		if ( queryIdText.isEmpty())  // tenta recuperar id pelo "lastInsertId":
		{
			if ( db.driver()->hasFeature(QSqlDriver::LastInsertId))
				m_currentMovimentoId = m_movModel->query().lastInsertId().toInt();
			else
				qDebug() << "Driver " << db.driverName() << " nao suporta 'lastInsertId' - pesquisar na documentação do banco";
		}
		else  // usa query específica do banco
		{
			QSqlQuery queryId(db);
			if ( queryId.exec(queryIdText) && queryId.next()) // executa e tenta posicionar na primeira(e única) linha da query
				m_currentMovimentoId = queryId.value(0).toInt(); // pega o valor da primeira(e única) coluna da query
			else
				QMessageBox::warning(this, "ERRO",  "Falha ao recuperar id do registro inserido:\n" + queryId.lastError().text());
		}
	}
	// finaliza transação:
	db.commit();

	accept(); // "accept", ao invés de "close": -> além de fechar o diálogo (chamando "close()"),
	// "accept" faz com que o retorno da função "exec",
	// no codigo de quem criou o diálogo, retorne "QDialog::Accepted" e assim fique sabendo
	// que a edição foi CONFIRMADA e não cancelada.
}

// ==== CANCELA alterações feitas
void MovimentoEditDialog::on_cancelBtn_clicked()
{
	if ( m_insert ) // se estava inserindo
	{
		int row = m_movMapper->currentIndex();
		m_movModel->removeRow(row); // remove a linha onde a inserção  ocorreria
	}

	// descarta alterações:
	m_movMapper->revert();

	reject(); // "reject", ao invés de "close": -> além de fechar o diálogo (chamando "close()"),
	// "reject" faz com que o retorno da função "exec",
	// no codigo de quem criou o diálogo, retorne "QDialog::Rejected" e assim fique sabendo
	// que a edição foi CANCELADA e não confirmada.
}
