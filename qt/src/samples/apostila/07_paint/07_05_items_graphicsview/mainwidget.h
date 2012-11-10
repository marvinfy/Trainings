#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtGui/QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPaintEngine>

class GView; // derivada de QGraphicsView (abaixo)

namespace Ui
{
    class MainWidgetClass;
}

// Neste exemplo temos 2 "players" (2 imagens)
// e uma bola que se movimenta horizontalmente entre eles.

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidgetClass *ui;

	// habilita tratamento de eventos de teclado e mouse:
	void startGame();
	// desabilita o tratamento desses eventos:
	void stopGame();

	// movimentar a bola em função dos eventos de teclado ou mouse:
	void moveBallToInitialPosition();
	private slots:
		void moveBall(qreal xMove, QEvent * event); // move a bola
		void changeState() {
			// finaliza/inicia, desabilitando/habilitando movimento da bola
			m_started ? stopGame() : startGame();
		}

	public:
	bool m_started; // se verdadeiro, trata eventos de teclado e mouse para movimentar a bola
					// do contrário ignora esses eventos.
	// GraphicsView:
	GView * m_gView;
	// mediador entre a view e os itens a serem desenhados:
	QGraphicsScene * m_gScene; // agrupa e trata os itens

	qreal m_ballXMove; // deslocamento horizontal da bola a cada evento de teclado ou mouse

	typedef QGraphicsPixmapItem Player; // item: pixmap
	typedef QGraphicsEllipseItem Ball;  // item: ellipse

	Player * m_player1; // pixmap
	Player * m_player2; // pixmap
	Ball * m_ball; // ellipse

	// texto:
	struct Text : public QGraphicsItem // o texto é um item com retângulo e texto
	{
		Text(); // construtor
		void setMainAttributes(qreal mainWidth, qreal mainHeight, const QColor & mainBackColor, QColor & rectPenColor);
		void adjustRect();

                // redefine as duas virtuais-PURAS da base:
                QRectF boundingRect()const;
		void paint ( QPainter * paint, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );

                void setFirstString(const QString & firstString);

		QStringList m_strings; // lista de strings para compor o texto

		// largura/altura do retângulo que servirá de moldura e fundo para o texto
		qreal m_rectWidth;
		qreal m_rectHeight;
		int m_wMargin; // margem lateral (esquerda/direita)
		int m_topMargin; // margem do topo

		QFont m_font;  // fonte

		QColor m_mainBackColor;
		QColor m_rectPenColor;
		qreal m_mainWidth;
		qreal m_mainHeight;
	};

	Text * m_text;
};

// Criar uma derivada de QGraphicsView
// - neste exemplo, a derivada serve principalmente para tratar o evento "resize"(virtual).
//   e, além disso, os eventos de teclado e mouse
// Caso não houvesse interesse sequer nesses eventos
// poderíamos usar um objeto da própria classe base e a derivada não seria necessária.
class GView : public QGraphicsView
{
	Q_OBJECT

	public:
	// construtora
	GView(QWidget * parent, const bool & started);

	protected:
	// evento resize - virtual da base
	// (VER comentários sobre ele em "mainwidget.cpp" nessa função)
	void resizeEvent(QResizeEvent *event);

	// eventos de mouse e teclado - virtuais da base
	void keyReleaseEvent( QKeyEvent * event );
	void mouseReleaseEvent ( QMouseEvent * event );
	void mouseMoveEvent ( QMouseEvent * event );
	void print();

	public:
		signals:
		// signal para que a bola seja movida:
		void moveBall(qreal xMove, QEvent * event);
		// signal para que o movimento inicie ou finalize:
		void stateChanged();

	private:
		const bool & m_started;
};


#endif // MAINWIDGET_H
