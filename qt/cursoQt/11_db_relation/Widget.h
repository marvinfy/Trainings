#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ColumnIndexes.h"

namespace Ui {
    class Widget;
}

#include <QModelIndex>
#include <QAbstractItemModel>
#include <QSqlRelationalTableModel>

class QSqlDatabase;
class QSqlRecord;

class Widget : public QWidget
{
    Q_OBJECT

public:
	 explicit Widget(QSqlDatabase & db, QWidget *parent = 0);
    ~Widget();

	private:
    Ui::Widget *ui;

	 QSqlDatabase & m_db;
	 QSqlRelationalTableModel *m_clientesModel;
	 QSqlRelationalTableModel *m_movimentoModel;

	 // números(índices) das colunas das tabelas:
	 ColumnIndexes m_colInd;
	bool m_canSubmit; //saber se o método "submit" pode ser usado
												// para determinado driver sql

	 // Função auxiliar para completar uma alteração ou uma inserção.
	 //	Finaliza edição ou inserção, selecionando a linha alterada ou inserida na table de movimento:
	 void movEditInsertFinish_(int dlgResult, int clienteId, int movimentoId, int prevCliRow, int prevMovRow);

	 // função auxiliar para buscar a linha do model onde está um valor único para determinada coluna,
	 // devolvendo a linha onde o valor foi encontrado:
	 int findExactly_(QAbstractItemModel * model, int colIndex,
																		const QVariant & valueToFind)
	 {
		 QModelIndexList indList = model->match(
					 model->index(0,colIndex), // procura a partir da linha zero, na coluna especificada
					 Qt::DisplayRole, // leitura do valor na coluna
					 valueToFind,  // valor que quero encontrar
					 1, // quantas ocorrências (aqui apenas uma, pois o valor deve ser único...)
					 Qt::MatchExactly // poderia ser "aproximado". Quero exato.
					 );

		 if ( indList.size() >0) // se encontrou alguma ocorrencia...
			 return indList.first().row(); // "first", pois buscamos apenas uma (o "1" na função match e com o flag "Qt::MatchExactly")
		 else
			 return -1; // não encontrou: retorna linha inválida
	 }
	 bool hasRelations_( QSqlRelationalTableModel * model)
	 {
		 int t=model->columnCount();
		 for ( int i =0 ; i <t; ++i)
		 {
			 if ( model->relation(i).isValid())
				 return true;
		 }
		 return false;
	 }

private slots:

	 // == acrescentados via "goto Slot":

	 void on_clienteDeleteBtn_clicked();

	 void on_movimentoTable_doubleClicked(QModelIndex index);
	 void on_movimentoEditBtn_clicked();
	 void on_movimentoInsertBtn_clicked();
	 void on_movimentoDeleteBtn_clicked();

	void on_movimentoNavLastBtn_clicked();
	 void on_movimentoNavNextBtn_clicked();
	 void on_movimentoNavPrevBtn_clicked();
	 void on_movimentoNavFirstBtn_clicked();

	 // == acrescentados no codigo:
	 void atualizaMovimentoTable(const QModelIndex&clientesIndex); // atualizar a tabela de movimentos de acordo com o cliente selecionado(exibir apenas movimentos desse cliente)
	 void clienteDataChanged(const QModelIndex & clientesIndex); // uma célula de table de clientes foi alterada.
};

#endif // WIDGET_H
