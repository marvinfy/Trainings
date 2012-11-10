#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPainter>
#include <QPaintEngine>
#include <QPrintEngine>
#include <QPrinter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

// Neste exemplo temos 2 "players" (2 imagens)
// e uma bola que se movimenta horizontalmente entre eles.

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidgetClass)
	, m_started (false )
	, m_toPrinter(false)
{
    ui->setupUi(this);
	// desabilita preenchimento automático do fundo da janela:
	setAutoFillBackground( false );

	// define dimensões da janela:
	m_idealWidth = 500;
	m_idealHeight =  int(m_idealWidth* 0.75);
	m_scaledWidth = m_idealWidth;
	m_scaledX = 0;
	const int margin = int(m_idealWidth*0.05);

	resize(m_idealWidth,m_idealHeight);
	setMinimumSize(m_idealWidth,m_idealHeight);

	// cor de fundo:
	m_background = QBrush ( QColor(48,48,0) );
	const QPoint center = QPoint( m_idealWidth>>1, m_idealHeight>>1 );

	// define a imagem e o posicionamento do primeiro "player":
	m_player1.load(":/images/next.png");
	m_player1.m_winPoint = QPoint(margin ,
							center.y() - (m_player1.height()>>1) );

	// define a imagem e o posicionamento do segundo "player":
	m_player2.load(":/images/back.png");
	m_player2.m_winPoint = QPoint(m_idealWidth-margin-m_player2.width() ,
							 center.y() - (m_player2.height()>>1) );

	// bola:
	m_ball.m_brush = m_background.color().lighter(500); // cor de fundo:
	const int diameter = int ( m_idealWidth*0.025 )+4;
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
					 << "<Enter> ou o botão esquerdo do mouse param/iniciam o \"jogo\"."
					 << "Setas movimentam a bola uma posição à esquerda ou à direita."
					 << "Movimento do mouse move bola até posição horizontal do mouse."
					 << "Botão direito do mouse permite imprimir a tela em um arquivo PDF.";

	// cria o objeto QPrinter em ALTA resolução:
	m_print = new QPrinter(QPrinter::HighResolution);
	// ***** OBS: em Windows, poderá ocorrer um problema com a construtora de QPrinter:
	// caso a impressora-default, definida no SO, não esteja disponível:
	// EM MODO DEBUG a aplicação é interrompida por um "assert"(e não uma exception)
	// Já em MODO RELEASE a aplicacão rodará normalmente.

	// coloca o "jogo" em posição inativa:
	stopGame();

	// exibe o widget principal(o que implicará no primeiro "paintEvent"):
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
void MainWidget::startGame()
{
	m_started = true; // estado atual
	// string indicadora do estado:
	QString strState = "--- INICIADO - tecle <enter> para parar";
	setWindowTitle(strState); // título da janela
	m_text.m_strings.front() = strState; // muda primeira linha da stringlist do texto

	// bola na posição inicial:
	moveBallToInitialPosition();
	// repinta todo o "tabuleiro" com novo texto:
	update();
}

// "stopGame": posiciona "m_started" como "false"
// desabilitando o tratamento dos eventos de teclado e mouse para movimento da bola,
// e muda título da janela
void MainWidget::stopGame()
{
	m_started = false; // estado atual
	// string indicadora do estado:
	QString strState = "+++ PARADO - tecle <enter> para iniciar";
	setWindowTitle(strState); // título da janela
	m_text.m_strings.front() = strState; // muda primeira linha da stringlist do texto

	// repinta todo o "tabuleiro" com novo texto:
	update();
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
			event->ignore(); // ignora outros botões
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

		case Qt::RightButton:
		{
			// solicita um nome para o arquivo pdf a gravar:
			QString fileName = QFileDialog::getSaveFileName(this,
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
				m_toPrinter = true;
				repaint(); // chama paintEvent direta e imediatamente

				// garantir que a janela seja repintada também
				m_toPrinter=false;
				repaint();

				// PRINTER: abrir JÁ o pdf:
				QDesktopServices::openUrl( QUrl("file:///" + fileName) );
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
// ela é chamada a partir de eventos de teclado e mouse;
// se "m_started" for "false", retornará sem fazer nada
// e com isso esses eventos serão ignorados:
void MainWidget::moveBall(qreal xMove, QEvent * event)
{
	if ( !m_started )
	{
		event->ignore(); // se não iniciado, ignora o evento de teclado ou mouse
		return;
	}

	// limites para movimento da bola:
	const qreal leftLimit = m_player1.m_winPoint.x()+m_player1.width()-3;
	const qreal rightLimit = m_player2.m_winPoint.x()-m_ball.width()+3;

	qreal ballLeft;
	// define movimento, sabendo-se que MouseMove envia um valor absoluto
	// e os demais eventos enviam um valor relativo:
	if ( event->type() == QEvent::MouseMove )
		ballLeft=  (xMove-m_scaledX)/(m_scaledWidth/m_idealWidth) - m_ball.width()/2;
	else
		ballLeft = m_ball.left() + (xMove * m_ball.m_xMove);

	ballLeft = qMax ( ballLeft,  leftLimit);
	ballLeft = qMin ( ballLeft,  rightLimit);

	// move:
	m_ball.moveLeft( int(ballLeft) );
	// provoca o redesenho da bola em sua nova posição:
	update();
}

// paintEvent: chamada sempre que a janela precisa ser repintada
// ou sempre que uma nova pintura foi forçada
// com uma chamada a "update" ou "repaint":
void MainWidget::paintEvent(QPaintEvent * pEv)
{
	QPainter paint;
	QRectF rect; // retângulo para área-destino do desenho
	if ( m_toPrinter )
	{
		paint.begin(m_print);
		rect=paint.viewport();  // destino é a viewPort de "Printer"

		// define área de impressão para "fillRect"(preenchimento do fundo)
		QSizeF backSize = QSizeF( width(), height() );
		// escalar dimensões iniciando com as dimensões da janela:
		backSize.scale( rect.width(), rect.height(), Qt::KeepAspectRatio);
		// e atingindo as dimensões de "printer", proporcionalmente:
		paint.setViewport ( 0,0, int(backSize.width()), int(backSize.height()) );
		// neste caso (pintar o fundo) a "window"(coordenadas lógicas)
		// deve corresponder à nova "viewport"(coordenadas físicas já escaladas)
		paint.setWindow(paint.viewport());
		// atualiza o retângulo de "printer", para continuidade da pintura:
		rect = paint.viewport();
	}
	else
	{
		paint.begin(this);
		rect.setRect(0,0, this->width(), this->height()); // destino é a janela
	}

	// suavização de bordas e pixmaps:
	paint.setRenderHints( QPainter::Antialiasing
								| QPainter::TextAntialiasing
								| QPainter::SmoothPixmapTransform );

	// pinta o fundo da janela usando TODA a área da janela:
	paint.fillRect(rect, Qt::black ); // pinta área total

	const qreal width = rect.width();
	const qreal height = rect.height();


	// Agora, para prosseguir na pintura/desenho,
	// mapeamos as dimensões iniciais do device (widget ou printer) para as dimensões atuais
	// de modo que não haja distorção no desenho dos itens,
	// caso tenha havido um redimensionamento da janela
	// que tenha mudado as proporções iniciais entre altura e largura:
	QSizeF scaledSize = QSizeF(m_idealWidth, m_idealHeight);

	// Em seguida, escalamos a dimensão inicial para a atual,
	// mantendo as proporções largura/altura(Qt::KeepAspectRatio)
        scaledSize.scale( width, height, Qt::KeepAspectRatio );
                                // Qt::IgnoreAspectRatio
                                // Qt::KeepAspectRatioByExpanding

	// x e y: centralizar na largura e na altura:
	qreal x = (width-scaledSize.width())/2; // metade de: (largura atual menos largura escalada)
	qreal y = (height-scaledSize.height())/2; // idem para altura;

	// Define as coordenadas físicas para a dimensão atual já escalada proporcionalmente:
	paint.setViewport(int(x),int(y),
					  int(scaledSize.width()),
					  int(scaledSize.height()) );

	// Por último, mantem as coordenadas lógicas de acordo com dimensão inicial(considerada ideal);
	// desse modo, ao definir posições e tamanhos dos itens podemos usar
	// geometria fixa, baseada nas dimensões originais/ideais,
	// e QPainter irá mapeá-la para as coordenadas físicas:
	paint.setWindow(0,0, m_idealWidth, m_idealHeight);

	// *** OBS: o mesmo efeito seria conseguido, fazendo-se:
		// paint.translate(x,y);
		// paint.scale(scaledSize.width()/m_idealWidth, scaledSize.height()/m_idealHeight);
	// *** ao invés de paint.setViewPort(...) seguido de paint.setWindow(...).

	m_scaledWidth = scaledSize.width();
	m_scaledX = x;

	paint.setPen(QPen(Qt::darkGray,2)); // caneta
	paint.setBrush( m_background );
	// retângulo que delimita área de desenho:
	paint.drawRect( 2,2, m_idealWidth-4, m_idealHeight-4);

	// desenha texto:
	drawText(paint);
	// desenha players:
	drawPlayers(paint);
	// desenha a bola:
	drawBall(paint);

	paint.end();
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
	targetRect.moveTo(m_player2.m_winPoint);
	paint.drawImage ( targetRect, m_player2, m_player2.rect() );
}

// desenha a bola em sua nova posição:
void MainWidget::drawBall(QPainter & paint)
{
	paint.setPen(Qt::NoPen ); // sem caneta
	// desenha o retangulo que envolve a bola
	// com a cor de background da janela
	// já que "autoFillBackground" está desativado:
	paint.setBrush(m_background);
	paint.drawRect(m_ball);

	// agora desenha a ellipse com a sua cor de fundo:
	paint.setBrush(m_ball.m_brush);
	paint.drawEllipse(m_ball);
}

// ===========================================================================
// ========================= Text
// ===========================================================================

// Text construtor:
MainWidget::Text::Text()
{
	m_font.setFamily("Verdana");
	m_font.setPixelSize(12); // <- *** ao invés de setPointSize(8)
						// pois a impressora está sendo usada em ALTA resolução
						// e o tamanho da fonte deve ser escalável do mesmo modo
						// que os demais itens de desenho.
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
	int interLines = qMax(1, fm.leading()); // espaço entre linhas
	int h = (4*interLines) // espaços para margem superior e inferior do texto dentro do retângulo (2 acima e 2 abaixo)
			+( (fm.lineSpacing()+interLines) * m_strings.size() );// altura de uma linha * quantidade de linhas

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
	int interLines = qMax(1, fm.leading()); // espaço entre linhas
	int	yLine = m_rect.y()+ (interLines<<1);
	int hLine = fm.height();

	// cor do texto:
	paint.setPen( QPen ( background.color() ) );
	foreach( const QString & line, m_strings)
	{
		// desenha texto:
		paint.drawText ( xLine , yLine,  wLine, hLine,
							Qt::AlignHCenter, line );
		// coordenada y da próxima linha:
		yLine+= fm.lineSpacing()+interLines;
	}
}

