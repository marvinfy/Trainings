#include "Widget.h"
#include "ui_Widget.h"
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlField>
#include <QSqlResult>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>

// delegate personalizado para exibir data como "dd/mm/aaaa":
#include "DateDelegate.h"
#include "MovimentoEditDialog.h" // diálogo de edição/inserção na tabela "movimento"

Widget::Widget(QSqlDatabase & db, QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
	, m_db(db)
{
	ui->setupUi(this);

	// =========== Model para CLIENTES:

	m_clientesModel = new QSqlRelationalTableModel(this, m_db);
	m_clientesModel->setTable("clientes");

	// números das colunas de clientes:
	m_colInd.cliId= m_clientesModel->fieldIndex("cli_id");
	m_colInd.cliNome = m_clientesModel->fieldIndex("name");
	m_colInd.cliCidade = m_clientesModel->fieldIndex("cidade_id");
	m_colInd.cliContato = m_clientesModel->fieldIndex("contato_id");

	// cabeçalhos para clientes:
	m_clientesModel->setHeaderData(m_colInd.cliNome, Qt::Horizontal, "Nome");
	m_clientesModel->setHeaderData(m_colInd.cliCidade, Qt::Horizontal, "Cidade");
	m_clientesModel->setHeaderData(m_colInd.cliContato, Qt::Horizontal, "Contato");

	// definine classificação (a qual ocorrera no "select()")
	m_clientesModel->setSort(m_colInd.cliNome, Qt::AscendingOrder); // nome, ordem crescente

	// == *** relacionamentos de colunas com outras tabelas:

	// coluna "cidade" (relaciona o número da coluna com o campo "id" 
	// da tabela "cidades", retornando o nome da cidade
	m_clientesModel->setRelation(m_colInd.cliCidade,
												QSqlRelation("cidades", "cid_id", "name"));
	// coluna "contato" (relaciona o número da coluna com o campo "id" da tabela "contatos", retornando o nome do contato
	m_clientesModel->setRelation(m_colInd.cliContato,
											QSqlRelation("contatos", "con_id", "name"));


	// * ^^ Nos 2 "relationModel" acima, temos sempre duas colunas:
	//         "chave"(coluna 0) e "valor associado" (coluna 1).
	m_clientesModel->relationModel(m_colInd.cliCidade)->sort(1, Qt::AscendingOrder);
	m_clientesModel->relationModel(m_colInd.cliContato)->sort(1, Qt::AscendingOrder);


	// seleciona, usando tudo o que foi definido acima:
	m_clientesModel->select();

	// == table para clientes:
	ui->clientesTable->setModel( m_clientesModel);
	ui->clientesTable->hideColumn(m_colInd.cliId);

	ui->clientesTable->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->clientesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

	// *** seta o "delegate" para a "cliente table", de modo a exibir
	// as colunas relacionadas com outras tabelas em uma COMBOBOX (com as linhas dessas tabelas):
	ui->clientesTable->setItemDelegate(new QSqlRelationalDelegate(this));

	// se houver muitas linhas selecionadas a função abaixo pode demorar muito
	ui->clientesTable->resizeColumnsToContents();

	// =========== Model para MOVIMENTO:

	m_movimentoModel=new QSqlRelationalTableModel(this, m_db);
	m_movimentoModel->setTable("movimento");

	// números das coluans de "movimento":
	m_colInd.movId= m_movimentoModel->fieldIndex("mov_id");
	m_colInd.movClienteId = m_movimentoModel->fieldIndex("cliente_id");
	m_colInd.movTipoId = m_movimentoModel->fieldIndex("tipo_id");
	m_colInd.movDate = m_movimentoModel->fieldIndex("mov_date");
	m_colInd.movDescription = m_movimentoModel->fieldIndex("description");

	// cabeçalhos para movimento:
	m_movimentoModel->setHeaderData(m_colInd.movClienteId,
																Qt::Horizontal, "Cliente");
	m_movimentoModel->setHeaderData(m_colInd.movTipoId,
																Qt::Horizontal, "Tipo");
	m_movimentoModel->setHeaderData( m_colInd.movDate,
																Qt::Horizontal, "Data");
	m_movimentoModel->setHeaderData( m_colInd.movDescription,
																Qt::Horizontal, "Descrição");

	// *** relacionamentos para 2 colunas de movimentos ("clientes" e "tipo de movimento"):
	m_movimentoModel->setRelation(m_colInd.movClienteId,
											QSqlRelation("clientes", "cli_id", "name"));
	m_movimentoModel->setRelation(m_colInd.movTipoId,
											QSqlRelation("mov_tipo", "mt_id", "name"));

	// ordem de classificação para movimento:
	m_movimentoModel->setSort(m_colInd.movDate, Qt::DescendingOrder); // data, ordem decrescente

	// == table para movimento:
	ui->movimentoTable->setModel(m_movimentoModel);
	ui->movimentoTable->hideColumn(m_colInd.movId);

	ui->movimentoTable->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->movimentoTable->setSelectionBehavior(QAbstractItemView::SelectRows);

	// *** Define um DELEGATE para exibir a data no formato "dd/mm/aaaa"
	DateDelegate * dateColDelegate =
			new DateDelegate(m_colInd.movDate, this); //<- a coluna de data
	ui->movimentoTable->setItemDelegate( dateColDelegate);

	// *** A table de MOVIMENTO NÃO permitirá Edição:
	ui->movimentoTable->setEditTriggers(
														QAbstractItemView::NoEditTriggers);

	// deixa a última coluna ocupar todo o espaço vago:
	ui->movimentoTable->horizontalHeader()->setStretchLastSection(true);

	// conectar o SIGNAL "currentRowChanged" do "selectionModel de "clientesTable"
	// ao slot "atualizaMomentoTable" deste objeto Widget
	// (de modo que sejam exibidos apenas os movimentos do cliente selecionado):
	connect(ui->clientesTable->selectionModel(),
				 SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
				this, SLOT(atualizaMovimentoTable(const QModelIndex&)));

	// signal "dataChanged" para o "clientesModel" (dados alterados)
	connect(m_clientesModel, SIGNAL(
				  dataChanged(const QModelIndex&,const QModelIndex&)),
			this, SLOT(clienteDataChanged(const QModelIndex&)));

	// define o índice da table de Clientes para a linha zero, coluna zero do seu model:
	ui->clientesTable->setCurrentIndex( m_clientesModel->index(0, 0));

	// O método "submit" pode falhar se o driver for QPSQL e houver colunas relacionadas (QSqlRelation).
	// Caso seja verificado outro driver com o mesmo problema, acrescentar abaixo:
	m_canSubmit = m_db.driverName()!="QPSQL"
														|| !hasRelations_(m_clientesModel);
	// fazer a avaliação acima após os models terem sido configurados, de modo que aqui possamos identificar se tem "relations"

	setWindowTitle( "Tabelas relacionadas - " + db.driverName());
}

Widget::~Widget()
{
	delete ui;
}

void Widget::clienteDataChanged(
		const QModelIndex & clientesIndex)
{
	if (!clientesIndex.isValid())
		return;

	// memoriza a linha e coluna do item a ser alterado:
	int col = clientesIndex.column();
	int row = clientesIndex.row();
	if ( col == m_colInd.cliId) // nada a fazer se a coluna for o id.
		return;

	// memoriza se a coluna alterada foi a coluna "name"
	bool nameChanged = col == m_colInd.cliNome;
	QString name =
m_clientesModel->index(row, m_colInd.cliNome).data().toString();
	if ( nameChanged ) // se nome foi alterado, valida o nome
	{
		if ( name.length()< 3 || name.length()>40)
		{
			QMessageBox::warning(this, "Erro", "Nome do cliente: mínimo 3 e máximo 40 caracteres");
			m_clientesModel->revertAll(); // desfaz alterações.
			return;
		}
	}

	// pega o id do cliente antes de efetivar alteração dos dados:
	int clienteId =
			m_clientesModel->index(row, m_colInd.cliId).data().toInt();

	QString errMsg; // mensagem de erro caso ocorra algum

	// alterar no banco já, pois ao re-selecionar a linha alterada na "clientesTable",
	// o slot "atualizaMovimentoTable" será chamado (para atualizar a "movimentoTable")
	// e deverá visualizar o nome do cliente já alterado.

	if ( m_canSubmit ) // alteração normal
	{
		if ( !m_clientesModel->submitAll())
			errMsg = QString("Falha ao alterar o cliente selecionado:\n%1").arg(m_clientesModel->lastError().text());
	}
	else // falharia se usasse submit
	{
		QString queryText;

		if (col == m_colInd.cliNome)
			queryText =
					QString("UPDATE clientes SET name = '%1'").arg(name);

		// IDs de cidade e contato: pega os dados do ModelIndex, com "EditRole" (e não "DisplayRole", que é o nome)
		else if (col == m_colInd.cliCidade )
			queryText = QString("UPDATE clientes SET cidade_id = %1")
									.arg(clientesIndex.data(Qt::EditRole).toInt());

		else if (col == m_colInd.cliContato )
			queryText = QString("UPDATE clientes SET contato_id = %1")
									.arg(clientesIndex.data(Qt::EditRole).toInt());

		if ( !queryText.isEmpty())
		{
			queryText += QString(" WHERE cli_id = %1").arg(clienteId); // completa o texto da query com o filtro
			QSqlQuery query(m_db);
			if ( query.exec(queryText)) // executa diretamente no banco
			{
				m_clientesModel->query().finish();
				m_clientesModel->select(); // se foi feito diretamente no banco (sem o "model::submit"), precisa atualizar o model:
			}
			else
				errMsg = QString("Falha ao alterar o cliente selecionado:\n%1").arg(query.lastError().text());
		}
	}

	if ( !errMsg.isEmpty()) // se a mensagem de erro foi preenchida...
	{
		QMessageBox::warning(this, "Erro", errMsg);
		m_clientesModel->revertAll(); // desfaz alterações.
		return;
	}

	if ( nameChanged ) // se nome do cliente foi alterado...
	{
		// Abaixo, busca pelo id do cliente cujo nome foi alterado.
		// Necessário, já que está classificado por nome e a alteracão do nome pode mudar a linha em que o alterado ficará.
		// Do contrário (se o "sort" não afetasse o nome), bastaria fazer:
		// 		ui->clientesTable->selectRow(row);

		// agora busca a linha em que ficou o cliente com o "id" recuperado acima, na coluna "id":
		row = findExactly_(m_clientesModel, m_colInd.cliId, clienteId);
		m_movimentoModel->relationModel(m_colInd.movClienteId)->setSort(1, Qt::AscendingOrder);
		m_movimentoModel->relationModel(m_colInd.movClienteId)->select();
	}

	// seleciona linha do cliente, atualizando movimentos no slot "atualizaMovimentoTable":
	ui->clientesTable->selectRow(row);
	// redimensiona colunas, caso nomes tenham mudado de tamanho e força seleção da linha atualizada
	ui->clientesTable->resizeColumnsToContents();
}

// === SLOT para atualizar a tabela de movimentos de acordo com o cliente selecionado:
//				(apenas movimentos desse cliente)
void Widget::atualizaMovimentoTable(const QModelIndex& clientesIndex)
{
	if (clientesIndex.isValid())
	{
		int row = clientesIndex.row();
		QSqlRecord cliRecord = m_clientesModel->record(row);
		int id = cliRecord.value(m_colInd.cliId).toInt();
		// filtra:
		m_movimentoModel->setFilter(QString(
												 "cliente_id = %1").arg(id));

		// modifica o label, para indicar o cliente selecionado
		QString movLabel (QString("Movimentos para o cliente: [%1]")
								.arg(cliRecord.value(m_colInd.cliNome).toString()));
		ui->movimentoLabel->setText( movLabel );
	}
	else // indice inválido (nenhuma linha de "clientes" selecionada)
	{
		// filtra para não exibir movimentos:
		m_movimentoModel->setFilter("cliente_id = -1"); // id impossivel: nenum movimento será exibido
		// modifica o label:
		ui->movimentoLabel->setText("Movimento: cliente não selecionado");
	}

	// seleciona o model de movimento (com o filtro definido acima)
	m_movimentoModel->select();

	// habilita/desabilita os cabeçalhos da table de movimentos
	// dependendo de se esse model tem linhas ou está vazio:
	ui->movimentoTable->horizontalHeader()->setVisible(
				m_movimentoModel->rowCount() > 0);

	// vai para a primeira linha dos movimentos selecionados:
	ui->movimentoTable->selectRow(0);
	// faz com que todas as colunas exibam todo o seu texto, se isso for possivel:
	ui->movimentoTable->resizeColumnsToContents();
}

// === EXCLUIR CLIENTE:
void Widget::on_clienteDeleteBtn_clicked()
{
	QModelIndex index = ui->clientesTable->currentIndex();
	if (!index.isValid())
	{
		QMessageBox::warning(this, "Atenção", "Nenhum cliente selecionado.\nSelecione para excluir.");
		return;
	}

	// pega o cliente atualmente selecionado:
	int row = index.row();
	QSqlRecord record = m_clientesModel->record(row);
	// recupera o 'id' desse cliente:
	int id = record.value(m_colInd.cliId).toInt();

	// Descobre se há movimentos para este cliente:
	QSqlQuery query(QString("SELECT COUNT(*) FROM movimento "
									"WHERE cliente_id = %1").arg(id), m_db);
	int movimentos = 0;

	// atinge o primeiro (e único) registro da query "count":
	if (query.next())
		movimentos = query.value(0).toInt();

	QString msg;
	if ( movimentos > 0)
		msg = QString("Excluir o cliente [%1] e todos os seus [%2] movimentos?")
				.arg(record.value(m_colInd.cliNome).toString()).arg(movimentos);
	else
		msg = QString("Excluir o cliente [%1]?").arg(record.value(m_colInd.cliNome).toString());

	if ( QMessageBox::warning(this, "Atenção", msg, QMessageBox::Yes | QMessageBox::No)
		  != QMessageBox::Yes)
	{
		return;
	}

	// inicia uma 'transaction':
	// (deveria usar 'hasFeature'...)
//	if ( m_db.driver()->hasFeature(QSqlDriver::Transactions))
	// mas,como nunca uso um banco que não tenha transactions...
	m_db.transaction();

	// tenta excluir todos os movimentos do cliente selecionado:
	if ( ! query.exec(QString(
								"DELETE FROM movimento WHERE cliente_id = %1").arg(id))  )
	{
		// se falhou, rollback na transaction;
		m_db.rollback();
		QMessageBox::warning(this, "Erro", "Falha ao excluir movimentos do cliente selecionado:\n" + query.lastError().text());
		return;
	}

	QString errMsg;
	if ( m_canSubmit) // pode usar "submit"
	{
		// agora, tenta excluir o próprio cliente selecionado:
		if ( m_clientesModel->removeRow(index.row()) )
		{			// sucesso: o model deve atualizar a base de dados (submit):
			if ( !m_clientesModel->submitAll() )
				errMsg = "Falha ao enviar exclusão do cliente selecionado para o banco de dados:\n"
														+ m_clientesModel->lastError().text();
		}
		else
			errMsg = "Falha ao excluir o cliente selecionado:\n"
																			+ m_clientesModel->lastError().text();
	}
	else // falharia com "submit"
	{
		// tenta excluir o cliente selecionado:
		if ( query.exec(QString(
							"DELETE FROM clientes WHERE cli_id = %1").arg(id))  )
		{
			m_clientesModel->query().finish();
			m_clientesModel->select();
		}
		else
			errMsg = "Falha ao enviar exclusão do cliente selecionado para o banco de dados diretamente:\n"
																		+ query.lastError().text();
	}
	if (! errMsg.isEmpty())
	{
		// se falhou, rollback na transaction;
		m_db.rollback();
		QMessageBox::warning(this, "Erro", errMsg);
		return;
	}

	// finalmente, concluir a transaction positivamente:
	m_db.commit();

	// descobre qual linha selecionar na table de clientes, após excluir a linha atual:
	if ( row >= m_clientesModel->rowCount()) // tenta selecionar quem ficou na linha do excluído
		row = m_clientesModel->rowCount()-1;

	if ( row >= 0)
		ui->clientesTable->selectRow(row);

	ui->clientesTable->setFocus();
}

// ==== EDIÇÃO na Table "Movimento"

void Widget::on_movimentoEditBtn_clicked() // EDITAR (alterar)
{
	QModelIndex cliIndex = ui->clientesTable->currentIndex();
	QModelIndex movIndex = ui->movimentoTable->currentIndex();

	if ( movIndex.isValid() && cliIndex.isValid())
	{
		MovimentoEditDialog editDlg(m_movimentoModel,
											 m_colInd,
											 movIndex.row(), // linha válida: editar e não inserir
											m_canSubmit, this);

		editDlg.setCurrentClienteId(
	m_clientesModel->index(cliIndex.row(), m_colInd.cliId).data().toInt());
		editDlg.setCurrentMovimentoId(
m_movimentoModel->index(movIndex.row(), m_colInd.movId).data().toInt());

		int dlgResult = editDlg.exec(); //QDialog::Accepted
		//ou QDialog::Rejected (confirmado ou cancelado)

		// finaliza edição, selecionando a linha editada na table de movimento
		// (já que o diálogo de edição permite navegação e a linha pode ter mudado)
		movEditInsertFinish_(dlgResult, editDlg.currentClienteId(),
															editDlg.currentMovimentoId(),
															cliIndex.row(), movIndex.row() );
	}
	else
		QMessageBox::warning(this, "Atenção", "Nenhum cliente ou movimento selecionado.\nSelecione um para Editar.");
}
// double-click na Table de "Movimento":
void Widget::on_movimentoTable_doubleClicked(QModelIndex /* index */)
{
	// Repassa para o slot do botão "edit" (acima):
	on_movimentoEditBtn_clicked();
}

void Widget::on_movimentoInsertBtn_clicked() // INSERIR
{
	QModelIndex cliIndex = ui->clientesTable->currentIndex();
	QModelIndex movIndex = ui->movimentoTable->currentIndex();

	MovimentoEditDialog editDlg(m_movimentoModel, m_colInd, -1,
							m_canSubmit, this); // ''-1" -> "linha<0" -> vai inserir

	editDlg.setCurrentClienteId(m_clientesModel->index(cliIndex.row(), m_colInd.cliId).data().toInt());
	editDlg.setCurrentMovimentoId(m_movimentoModel->index(movIndex.row(), m_colInd.movId).data().toInt());

	int dlgResult = editDlg.exec(); //QDialog::Accepted  ou QDialog::Rejected (confirmado ou cancelado)

	// finaliza inserção, selecionando a linha inserida na table de movimento e a linha do cliente selecionado na table de clientes:
	movEditInsertFinish_(dlgResult, editDlg.currentClienteId(),
													editDlg.currentMovimentoId(),
															cliIndex.row(), movIndex.row() );
	}

// == Função auxiliar para completar uma alteração ou uma inserção.
//			Finaliza edição ou inserção, selecionando a linha alterada ou inserida na table de movimento:
void Widget::movEditInsertFinish_(int dlgResult,
												int clienteId, int movimentoId,
												int prevCliRow, int prevMovRow)
{
	if ( dlgResult == QDialog::Accepted )  // diálogo foi CONFIRMADO
	{
		// busca no model de clientes o índice da linha onde a coluna "id" corresponda ao "clienteId" retornado pelo diálogo de edição
		int row = findExactly_(m_clientesModel, m_colInd.cliId, clienteId );
		if ( row >= 0)
		{
			ui->clientesTable->selectRow(row); // seleciona a linha desse cliente na table de clientes

			// busca no model de movimento o índice da linha onde a coluna "id" corresponda ao "movimentoId" retornado pelo diálogo de edição
			row = findExactly_(m_movimentoModel, m_colInd.movId, movimentoId );
			if ( row >0)
				ui->movimentoTable->selectRow(row); // seleciona a linha desse movimento na table de movimentos
		}
		ui->clientesTable->resizeColumnsToContents();
		ui->movimentoTable->resizeColumnsToContents();
	}
	else // diálogo  foi CANCELADO: força seleção das linhas anteriores das tables
	{
		ui->clientesTable->selectRow( prevCliRow);
		ui->movimentoTable->selectRow(prevMovRow);
	}
}

void Widget::on_movimentoDeleteBtn_clicked() // DELETAR
{
	QModelIndex movIndex = ui->movimentoTable->currentIndex();
	if (!movIndex.isValid())
	{
		QMessageBox::warning(this, "Atenção", "Nenhum movimento selecionado.\nSelecione para excluir.");
		return;
	}

	QString msg("Excluir o movimento selecionado?");
	if ( QMessageBox::warning(this, "Atenção", msg, QMessageBox::Yes | QMessageBox::No)
		  != QMessageBox::Yes)
	{
		return;
	}

	// inicia uma 'transaction' (poderia checar antes se o banco suporta transactions):
	// bool hasTransaction = m_db.driver()->hasFeature(QSqlDriver::Transactions); if ( hasTransaction ) //....
	m_db.transaction();

	// linha atual na table de movimentos:
	int row = movIndex.row();
	QString errMsg; // mensagem de erro caso ocorra algum

	if ( m_canSubmit ) // remoção normal;
	{
		if ( m_movimentoModel->removeRow(row) )
		{
			// sucesso: o model deve atualizar a base de dados (submit):
			if (!m_movimentoModel->submitAll() )
				errMsg = QString("Falha ao enviar a exclusão para o banco de dados:\n%1").arg(m_movimentoModel->lastError().text());
		}
		else
			errMsg = QString("Falha ao excluir o movimento selecionado:\n%1").arg(m_movimentoModel->lastError().text());
	}
	else // remoção direta no banco
	{
		int movId = m_movimentoModel->index(row, m_colInd.movId).data().toInt();
		QSqlQuery query(m_db);
		if ( query.exec(QString(
			"DELETE FROM movimento WHERE mov_id = %1").arg(movId)))
		{
			m_movimentoModel->query().finish();
			m_movimentoModel->select(); // atualiza o model
		}
		else
			errMsg = QString("Falha ao excluir o movimento selecionado diretamente no banco de dados\n:%1").arg(query.lastError().text());
	}

	if ( !errMsg.isEmpty()) // se a mensagem de erro foi preenchida...
	{
		QMessageBox::warning(this, "Erro", errMsg);
		m_db.rollback(); // erro: rollback na transaction;
		return;
	}

	// finalmente, concluir a transaction positivamente:
	m_db.commit();

	// descobre qual linha selecionar na table de movimento, após excluir a linha atual:
	if ( row >= m_movimentoModel->rowCount()) // tenta selecionar quem ficou na linha do excluído
		row = m_movimentoModel->rowCount()-1;

	if ( row >= 0)
		ui->movimentoTable->selectRow(row);

	ui->movimentoTable->setFocus();
}

// ==== NAVEGAÇÃO na Table "Movimento"

void Widget::on_movimentoNavFirstBtn_clicked()  // PRIMEIRO
{
	if ( m_movimentoModel->rowCount() > 0 )
	{
		ui->movimentoTable->setFocus();
		ui->movimentoTable->selectRow( 0 );
	}
}

void Widget::on_movimentoNavPrevBtn_clicked() // ANTERIOR
{
	int row = ui->movimentoTable->currentIndex().row() - 1;
	if ( row >= 0 )
	{
		ui->movimentoTable->setFocus();
		ui->movimentoTable->selectRow(row);
	}
}

void Widget::on_movimentoNavNextBtn_clicked() // PRÓXIMO
{
	int row = ui->movimentoTable->currentIndex().row() + 1;
	if ( row < m_movimentoModel->rowCount()  )
	{
		ui->movimentoTable->setFocus();
		ui->movimentoTable->selectRow(row);
	}
}

void Widget::on_movimentoNavLastBtn_clicked() // ÚLTIMO
{
	int lastRow = m_movimentoModel->rowCount() - 1;
	if ( lastRow >= 0 )
	{
		ui->movimentoTable->setFocus();
		ui->movimentoTable->selectRow(lastRow);
	}
}

