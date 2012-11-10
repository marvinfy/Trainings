#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

namespace Ui
{
    class Widget;
}

class QMenu;
class QAction;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

	// contextMenu:
	QMenu * m_contextMenu;
	// actions para o contextMenu:
	QAction * m_action1;
	QAction * m_action2;

private slots:
	// slots para as duas actions executadas
	// a partir do contextMenu:
	void onAction1();
	void onAction2();

protected:
	// redefine a virtual contextMenuEvent
	// é aqui que o menu será executado
	// quando o botão direito do mouse for acionado
	// (ou outra ação padrão prevista pela plataforma)
	void contextMenuEvent(QContextMenuEvent *event);
};

#endif // WIDGET_H
