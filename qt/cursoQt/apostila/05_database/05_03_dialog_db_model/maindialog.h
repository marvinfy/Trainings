#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "dlg_database.h"

namespace Ui {
    class MainDialog;
}

class QMenu ;
class QString;
class QGroupBox;
class QSqlRelationalTableModel;
class QDataWidgetMapper;

class MainDialog : public QDialog {
    Q_OBJECT
public:
    MainDialog(QWidget *parent = 0);
    ~MainDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainDialog *ui;

	QMenu * m_editBtnMenu;
	QMenu * m_editFinBtnMenu;
	QMenu * m_navBtnMenu ;
	dlg_database m_db;

	// model:
	QSqlRelationalTableModel * m_tableModel;
	QDataWidgetMapper * m_mapper;

	// indica se uma edição está em curso e qual é ela:
	enum EditActions { EA_None, EA_Insert, EA_Update };
	EditActions m_editAction;

	// habilita/desabilita botões e widgets conforme modo de edição
	void changeEditAction(EditActions editAction);

	// "limpa" 'widgets' quando não há dados a exibir:
	void clearWidgets();

	// "Actions" para navegação:
	QAction * m_firstAct ;  // "primeiro registro"
	QAction * m_prevAct ; // "registro anterior"
	QAction * m_nextAct ; // "próximo registro"
	QAction * m_lastAct ;  // "último registro"

	// "Actions" para entrada em edição (apenas as que são usadas em várias funções):
	QAction * m_editUpdAct; // "alterar registro"
	QAction * m_editDelAct;  // "deletar registro"

private slots:
	void onInsert();
	void onUpdate();
	void onDelete();

	void onOK();
	void onCancel();

	// muda estado das 'actions' (habilita / desabilita):
	void updateActionsState(int row);

protected:
	// redefine a virtual contextMenuEvent
	// é aqui que o menu será executado
	// quando o botão direito do mouse for acionado
	// (ou outra ação padrão prevista pela plataforma)
	void contextMenuEvent(QContextMenuEvent *event);

};

#endif // MAINDIALOG_H
