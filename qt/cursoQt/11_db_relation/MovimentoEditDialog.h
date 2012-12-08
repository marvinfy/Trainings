#ifndef MOVIMENTOEDITDIALOG_H
#define MOVIMENTOEDITDIALOG_H

#include <QDialog>
#include <QModelIndex>

#include "ColumnIndexes.h"

#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>

namespace Ui {
    class MovimentoEditDialog;
}

class MovimentoEditDialog : public QDialog
{
    Q_OBJECT

public:
	 explicit MovimentoEditDialog(QSqlRelationalTableModel* model,
													ColumnIndexes & colInd,
													int curRow,
													bool canSubmit, QWidget *parent = 0);
    ~MovimentoEditDialog();

	 int currentClienteId() const { return m_currentClienteId; }
	 void setCurrentClienteId(int currentClienteId) { m_currentClienteId = currentClienteId; }
	 int currentMovimentoId() const { return m_currentMovimentoId; }
	 void setCurrentMovimentoId(int currentMovimentoId){ m_currentMovimentoId = currentMovimentoId; }

private:
    Ui::MovimentoEditDialog *ui;

	 QSqlRelationalTableModel * m_movModel;
	QDataWidgetMapper * m_movMapper; // mapeia widgets "sem model" para colunas de um model
	bool m_insert ;  // true-> insert (se curRow<0) ; false ->update (se curRow>=0)
	bool m_canSubmit;
	int m_currentClienteId;
	int m_currentMovimentoId;

	// números(índices) das colunas das tabelas:
	ColumnIndexes & m_colInd;
private slots:

	 // acrescentados via "goto Slot":
	 void on_cancelBtn_clicked();
	 void on_okBtn_clicked();

};

#endif // MOVIMENTOEDITDIALOG_H
