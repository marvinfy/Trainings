#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPainter>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

// Neste exemplo temos 2 "players" (2 imagens)
// e uma bola que se movimenta horizontalmente entre eles.

// Este exemplo não permitirá o redimensionamento da janela
// pois os itens de desenho não se movimentarão.
// Por isso define "maximumSize" com a mesma dimensão de "minimumSize"

// Nos próximos exemplos, veremos como reposicionar/redimensionar os itens
// permitindo o redimensionamento da janela.

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidgetClass)
	, m_started (false )
	, m_drawAction ( DrawOff )
{
    ui->setupUi(this);
	// desabilita preenchimento automático do fundo da janela:
	setAutoFillBackground( false );

	// define dimensões da janela:
	const int w = 500;
	const int h = int(w*0.75);
	const int margin = int(w*0.05);
	m_idealWidth = w;
	m_idealHeight = h;
	resize(w,h);
	setMinimumSize(w,h);
	setMaximumSize(w,h); // trava redimensionamento da janela

	// cor de fundo:
	m_background = QBrush ( QColor(48,48,0) );
	const QPoint center = QPoint( w>>1, h>>1 );

	// define a imagem e o posicionamento do primeiro "player":
	m_player1.load(":/images/next.png");
	m_player1.m_winPoint = QPoint(margin ,
                            center.y() - (m_player1.height()>>1) );

	// define a imagem e o posicionamento do segundo "player":
	m_player2.load(":/images/back.png");
	m_player2.m_winPoint = QPoint(w-margin-m_player2.width() ,
                        center.y() - (m_player2.height()>>1) );

	// bola:
	m_ball.m_brush = m_background.color().lighter(500); // cor de fundo:
	const int diameter = int ( w*0.025 )+4;
	m_ball.m_xMove = diameter-1; // deslocamento horizontal
	m_ball.setSize( QSize(diameter,diameter) ); // dimensões
	moveBallToInitialPosition(); // posicionamento inicial;

	// habilitar o evento move do mouse, mesmo quando nenhum botão está pressionado
	setMouseTracking(true);
	// responder todos os eventos de teclado ou click:
	setFocusPolicy(Qt::StrongFocus);
	// dirigir todos os eventos de teclado para este widget:
	grabKeyboard();

	// preenche o texto a ser desenhado no tabuleiro
	// deixando a primeira linha em branco
	// (ela sera acrescentada posteriormente em função do estado do "jogo"):
	m_text.m_strings << "" // primeira linha com conteúdo variável
					 << "" // linha em branco
					 << "<Enter> ou o botão esquerdo do mouse param/iniciam o jogo."
					 << "Setas movimentam a bola uma posição à esquerda ou à direita."
					 << "Movimento do mouse move bola até posição horizontal do mouse."
					 << "Botão direito do mouse permite imprimir a tela em um arquivo PDF.";

	// cria o objeto QPrinter:
	m_print = new QPrinter( QPrinter::ScreenResolution);
	// ***** OBS: em Windows, poderá ocorrer um problema com a construtora de QPrinter:
	// caso a impressora-default, definida no SO, não esteja disponível:
	// EM MODO DEBUG a aplicação é interrompida por um "assert"(e não uma exception)
	// Já em MODO RELEASE a aplicacão rodará normalmente.

	// coloca o "jogo" em posição inativa:
	stopGame();

	// exibe o widget principal(o que implicará no primeiro "paintEvent"):
	m_drawAction = DrawBoard; // ao exibir, deverá pintar todo o "tabuleiro"
	show();
}

MainWidget::~MainWidget()
{
    delete ui;
	delete m_print;
}

// "startGame": posiciona "m_started" como "true"
// habilitando o tratamento dos eventos de teclado e mouse para movimento da bola,
// muda título da janela e move bola para posição inicial.
void MainWidget::startGame() // OBS: esta função é acionada pela tecla <enter>
{
	m_started = true; // estado atual
	// string indicadora do estado:
	QString strState = "--- INICIADO - tecle <enter> para parar";
	setWindowTitle(strState); // título da janela
	m_text.m_strings.front() = strState; // muda primeira linha da stringlist do texto

	// bola na posição inicial:
	moveBallToInitialPosition();
	// repinta todo o "tabuleiro", com novo texto
	m_drawAction = DrawBoard;
	repaint();
}

// "stopGame": posiciona "m_started" como "false"
// desabilitando o tratamento dos eventos de teclado e mouse para movimento da bola,
// e muda título da janela
void MainWidget::stopGame() // OBS: esta função é acionada pela tecla <enter>
{
	m_started = false; // estado atual
	// string indicadora do estado:
	QString strState = "+++ PARADO - tecle <enter> para iniciar";
	setWindowTitle(strState); // título da janela
	m_text.m_strings.front() = strState; // muda primeira linha da stringlist do texto

	// repinta todo o "tabuleiro", com novo texto
	m_drawAction = DrawBoard;
	repaint();
}

// evento "release" do teclado:
void MainWidget::keyReleaseEvent( QKeyEvent * event )
{
	// analisa a última tecla pressionada/liberada:
	switch( event->key() )
	{
		case Qt::Key_Enter:
		case Qt::Key_Return:
			// desabilita/habilita tratamento dos eventos de teclado e mouse para movimento
			m_started ? stopGame() : startGame();
			return;

		case Qt::Key_Left:
		case Qt::Key_Backtab:
		case Qt::Key_Up:
			moveBall( -1, event); // move bola para a esquerda
			return;

		case Qt::Key_Tab:
		case Qt::Key_Right:
		case Qt::Key_Down:
			moveBall( 1, event);  // move bola para a direita
			return;

		default:
			event->ignore(); // ignora outras teclas
	}
}

// evento "Release" do mouse:
void MainWidget::mouseReleaseEvent ( QMouseEvent * event )
{
	// analisa qual o botão do mouse que foi pressionado:
	switch( event->button() )
	{
		case Qt::LeftButton :
			// desabilita/habilita tratamento dos eventos de teclado e mouse para movimento
			m_started ? stopGame() : startGame();
			return;

		// imprimir em pdf:
		case Qt::RightButton:
		{
			// solicita um nome para o arquivo pdf a gravar:
			QString fileName  = QFileDialog::getSaveFileName(this,
                                "Informe o nome do arquivo para gravar o pdf",
                                ".", "Pdf files (*.pdf)");

			if (!fileName.isEmpty())
			{
				if ( fileName.right(4).toLower() != ".pdf" )
					fileName+=".pdf";

				// define formato e arquivo pdf
				m_print->setOutputFormat(QPrinter::PdfFormat);
				m_print->setOutputFileName(fileName);

				// PRINTER: desenhar na impressora (pdf)
				m_drawAction = DrawToPrinter;
				repaint(); // chama paintEvent direta e imediatamente

				// garantir que a janela seja repintada também
				m_drawAction = DrawBoard;
				repaint();

				// PRINTER: abrir JÁ o pdf:
				QDesktopServices::openUrl(QUrl("file:///" + fileName) );
			}

			return;
		}

		default:
			event->ignore(); // ignora outros botões
	}
}

// evento "move" do mouse:
void MainWidget::mouseMoveEvent ( QMouseEvent * event )
{
	moveBall( event->x(), event );
}

// move bola para posição inicial:
void MainWidget::moveBallToInitialPosition()
{
	const int ballX = m_player1.m_winPoint.x()+m_player1.width()-3;
	const int ballY = m_player1.m_winPoint.y() + (m_player1.height()>>1)-(m_ball.height()>>1);
	m_ball.moveTo( ballX, ballY);
}

// "moveBall": irá mover a bola;
// ela é chamada a partir dos eventos de teclado e mouse;
// se "m_started" for "false", retornará sem fazer nada
// e com isso esses eventos serão ignorados:
void MainWidget::moveBall(int xMove, QEvent * event)
{
	if ( !m_started )
	{
		event->ignore(); // se não iniciado, ignora o evento de teclado ou mouse
		return;
	}

	// "limpar" a posição atual da janela antes de desenhá-la na nova posição
	m_drawAction = EraseBall;
	repaint(m_ball);

	// limites para movimento da bola:
	const int leftLimit = m_player1.m_winPoint.x()+m_player1.width()-3;
	const int rightLimit = m_player2.m_winPoint.x()-m_ball.width()+3;

	int ballLeft;
	// define movimento, sabendo-se que MouseMove envia um valor absoluto
	// e os demais eventos enviam um valor relativo:
	if ( event->type() == QEvent::MouseMove )
		ballLeft = xMove - m_ball.width()/2;
	else
		ballLeft = m_ball.left() + (xMove * m_ball.m_xMove);

	ballLeft = qMax ( ballLeft,  leftLimit);
	ballLeft = qMin ( ballLeft,  rightLimit);

	// move:
	m_ball.moveLeft( ballLeft );
	// provoca o redesenho da bola em sua nova posição:
	m_drawAction = DrawBall;
	repaint(m_ball);
}

// paintEvent: chamada sempre que a janela precisa ser repintada
// ou sempre que uma nova pintura foi forçada
// com uma chamada a "update" ou "repaint":
void MainWidget::paintEvent(QPaintEvent * pEv)
{
	QPainter paint;

	if ( m_drawAction == DrawToPrinter )
		paint.begin(m_print);
	else
		paint.begin(this);

	// suavização de bordas e pixmaps:
	paint.setRenderHints(QPainter::Antialiasing
                                | QPainter::TextAntialiasing
                                    | QPainter::SmoothPixmapTransform );

	// analisa ação de pintura a ser executada agora:
	switch ( m_drawAction )
	{
		case DrawToPrinter:
		case DrawBoard:
		case DrawOff:
			// DrawOff: indica um repaint automático (se a janela perdeu/recuperou foco, ou se outra janela passou por cima, etc).
						// o qual é solicitado pelo sistema, sem controle da aplicacão
			drawBoard(paint);
			break;

		// apaga a bola antes que ela mude de posição e seja desenhada na nova:
		case EraseBall:
			eraseBall(paint, pEv->rect()); // desenhará apenas o retângulo necessário
			break;

		// desenha a bola em sua nova posição:
		case DrawBall:
			drawBall(paint, pEv->rect());  // desenhará apenas o retângulo necessário
			break;
	}

	// nenhuma ação é esperada agora:
	m_drawAction = DrawOff;
	// (exceto se eventos externos tornarem necessária uma nova pintura)

	paint.end();
}

// desenha o fundo
void MainWidget::drawBoard(QPainter & paint)
{
	// pinta o fundo da janela usando toda a área da janela:
	paint.fillRect( this->rect(), Qt::black );

	// retângulo que delimita área de desenho:
	paint.setPen(QPen(Qt::darkGray,2)); // caneta
	paint.setBrush( m_background );
	paint.drawRect( 2,2, m_idealWidth-4, m_idealHeight-4);

	// como o fundo foi pintado, é preciso também
	// pintar os itens sobre o fundo:

	// desenha texto:
	drawText(paint);
	// desenha players:
	drawPlayers(paint);
	// desenha a bola:
	drawBall(paint, m_ball);

}

// desenha texto
void MainWidget::drawText(QPainter & paint)
{
	m_text.adjustRect(m_idealWidth, m_idealHeight);
	m_text.draw(paint, m_background);
}

// desenha os players:
void MainWidget::drawPlayers(QPainter & paint)
{
	// player-1:
	QRect targetRect = m_player1.rect();
	targetRect.moveTo( m_player1.m_winPoint);
	paint.drawImage ( targetRect, m_player1, m_player1.rect() );

	// player-2:
	targetRect = m_player2.rect();
	targetRect.moveTo( m_player2.m_winPoint);
        // moveTo ( int x , int y );
        // moveTo ( QPoint & point );

	paint.drawImage ( targetRect, m_player2, m_player2.rect() );
}

// apaga a bola antes que ela mude de posição e seja desenhada na nova posição:
void MainWidget::eraseBall(QPainter & paint, const QRect & rect)
{
	paint.setPen(Qt::NoPen ); // sem caneta
	paint.setBrush(m_background); // cor de fundo da janela
	paint.drawRect(rect);
}

// desenha a bola em sua nova posição:
void MainWidget::drawBall(QPainter & paint, const QRect & rect)
{
	paint.setPen(Qt::NoPen ); // sem caneta
	// desenha o retangulo que envolve a bola
	// com a cMainWidget::or de background da janela
	// já que "autoFillBackground" está desativado:
	paint.setBrush(m_background);
	paint.drawRect(rect);

	// agora desenha a ellipse com a sua cor de fundo:
	paint.setBrush(m_ball.m_brush);
	paint.drawEllipse(rect);
}

// ===========================================================================
// ========================= Text
// ===========================================================================

// Text construtor:
MainWidget::Text::Text()
{
	m_font.setFamily("Verdana");
	m_font.setPointSize(8);
	m_font.setBold(true);
	m_wMargin = 4;
	m_topMargin = 10;
}

// define retângulo que servirá de moldura e fundo para o texto:
void MainWidget::Text::adjustRect(int idealWidth, int idealHeight)
{
	// FontMetrics permite apurar altura e largura de linhas
	// em função da fonte em uso:
	QFontMetrics fm(m_font);


	// QFontMetrics:
        // width('a'); width("texto"); -> largura do caracter ou do texto
        // averageCharWidth() -> largura média
	// height() -> altura da linha
	// leading() -> espaço entre linhas
	// lineSpacing() -> height() + leading()

	int interLine = qMax(1, fm.leading()); // espaço entre linhas
	int h = (4*interLine) // espaços para margem superior e inferior do texto dentro do retângulo (2 acima e 2 abaixo)
			+( (fm.lineSpacing()+interLine) * m_strings.size() );// altura de uma linha * quantidade de linhas

	// encontrar a linha de maior largura:
	int w = 0;
	foreach ( const QString & line, m_strings )
		w = qMax ( w, fm.width(line) ); // pega a maior largura até aqui

	// adiciona a largura da margem lateral à esquerda e à direita
	w+=(m_wMargin<<1);
	// define coordenada x:
	int x = (idealWidth>>1)-(w>>1);
	// coordenada y:
	int y = m_topMargin + int(idealHeight*0.025);
	m_rect.setRect(x,y,w,h);
}

// desenha:
void MainWidget::Text::draw(QPainter & paint, const QBrush & background)
{
	// desenha moldura do texto:
	paint.setBrush( background.color().lighter(1000) );
	paint.drawRect(m_rect);
	// fonte:
	paint.setFont( m_font );
	// coordenada x para o texto dentro do retangulo
	int	xLine = m_rect.x()+m_wMargin;
	// largura do texto; desconta as margens esquerda e direita:
	int wLine = m_rect.width()-(m_wMargin<<1);
	// coordenada y para o texto dentro do retângulo e altura de uma linha
	// em função da métrica do texto(dependente de sua fonte)
	QFontMetrics fm(m_font);
	int interLine = qMax(1, fm.leading()); // espaço entre linhas
	int	yLine = m_rect.y()+ (interLine<<1);
	int hLine = fm.height();

	// cor do texto:
	paint.setPen( QPen ( background.color() ) );
	foreach( const QString & line, m_strings)
	{
		// desenha texto:
		paint.drawText ( xLine , yLine,  wLine, hLine,
							Qt::AlignHCenter, line );
		// coordenada y da próxima linha:
		yLine+= fm.lineSpacing()+interLine;
	}
}

