#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>

// Este "Delegate" personalizado será implementado como uma comboBox

class Delegate : public QItemDelegate
{
	Q_OBJECT

public:
	Delegate( QObject * parent );

	// === Redefine virtuais da base

	// Define opções e exibe o delegate:
	void paint(QPainter *painter, const QStyleOptionViewItem &option,
			   const QModelIndex &index) const;

	// Cria o "widget" (neste caso uma "comboBox")
	// que será o "editor" do Delegate:
	QWidget *createEditor(QWidget *parent,
						  const QStyleOptionViewItem &option,
						  const QModelIndex &index) const;

	// Alimenta a combobox com uma lista de cidades:
	void setEditorData(QWidget *editor, const QModelIndex &index) const;

	// Repassa para o Model a cidade que foi selecionada na comboBox:
	void setModelData(QWidget *editor, QAbstractItemModel *model,
					  const QModelIndex &index) const;

	// === Slots:

private slots:
	// slot necessário para encerrar a edição:
	void commitAndCloseEditor();

	// === outros membros:
private:
	// Lista de cidades para alimentar a comboBox:
	QStringList m_listaCidades ;
};

#endif // DELEGATE_H
