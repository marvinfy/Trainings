#include "widget.h"
#include "ui_widget.h"

#include <QAction>
#include <QMenu>
#include <QContextMenuEvent>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

	// Cria um menu que depois será usado como um "contextMenu".
	// O "contextMenu" será exibido a partir do clique do
	// botão direito do mouse ou outra ação padrão determinada pela plataforma.
	// Nesse momento, sera chamada a virtual "contextMenuEvent", redefinida abaixo,
	// a qual irá exibir o "contextMenu".
	m_contextMenu = new QMenu(this); // cria objeto menu

	// Cria as "actions" que serão executadas
	// a partir do "contextMenu:
	m_action1 = new QAction("1) - Action-1", this);
	m_action2 = new QAction("2) - Action-2", this);

	// Conecta o "signal triggered" de todas as "actions"
	// aos respectivos "slots" fornecidos por esta classe(classe "Widget")
	connect(m_action1, SIGNAL(triggered()),
					this, SLOT( onAction1() ) );
	connect(m_action2, SIGNAL(triggered()),
					this, SLOT( onAction2() ) );


	// Adiciona os objetos "QAction" ao menu:
	m_contextMenu->addAction(m_action1);
	m_contextMenu->addAction(m_action2);

	// OPCIONALMENTE, também quero que o contextMenu
	// seja exibido quando este botão for pressionado:
	ui->pushButton->setMenu( m_contextMenu );

	// Devido ao uso da função "setMenu",
	// o "pushButton" irá exibir uma pequena seta
	// indicando que ao ser pressionado ele abrirá alguma coisa.
}

Widget::~Widget()
{
	delete ui;
}

// Função virtual "contextMenu":
// chamada quando "contextMenu" deve ser exibido;
// e o seu argumento "event" permite capturar facilmente
// a posição onde o menu de contexto deve ser exibido:
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
	// executa o menu na posição fornecida pelo parametro "event",
	// ponteiro para um objeto "QContextMenuEvent":
	m_contextMenu->exec(event->globalPos());
	
	// globalPos() -> posição ideal para exibição do menu
}

// "slots" para as duas "actions" executadas
// a partir do "contextMenu":
void Widget::onAction1()
{
	QMessageBox::information(this, "ACTION-1", "1) - testando a ACTION-1");
}
void Widget::onAction2()
{
	QMessageBox::information(this, "ACTION-2", "2) testando a ACTION-2");
}

