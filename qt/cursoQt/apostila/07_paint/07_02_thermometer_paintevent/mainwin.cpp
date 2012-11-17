#include "MainWin.h"

#include <QPaintEvent>
#include <QPainter>

#include <QSlider>
#include <QSpinBox>
# include <QGridLayout>

MainWin::MainWin ( QWidget * pParent )
    : QWidget(pParent )
{
	// cria um slider, define o seu range e sua largura mínima:
	m_slider = new QSlider(Qt::Horizontal, this);
	m_slider->setMinimumWidth (200);
	m_slider->setRange(0, 100);

	// Cria uma spin-box para exibir o valor do slider,
	// podendo também alterar o slider:
	QSpinBox * spin = new QSpinBox(this);
	spin->setRange(0,100);

	// cria o termômetro e define seu tamanho mínimo:
	m_thermometer = new Thermometer(this);
	m_thermometer->setMinimumSize(60,250);

	// cria um gridLayout, relacionando-o ao widget principal('this'):
	QGridLayout * gridLayout = new QGridLayout(this);
	// o grid terá 4 colunas, sendo que a segunda e a terceira
	// ocuparão um espaço maior:
	gridLayout->setColumnStretch(0,1);
	gridLayout->setColumnStretch(1,3);
	gridLayout->setColumnStretch(2,3);
	gridLayout->setColumnStretch(3,1);
	// o termômetro ocupa a segunda e a terceira colunas (inicia na coluna 1, com colspan=2):
	gridLayout->addWidget(m_thermometer, 0, 1, 1, 2, Qt::AlignHCenter);
	// o slider ocupa as 3 primeiras colunas (inicia na coluna 0, com colspan=3):
	gridLayout->addWidget(m_slider, 1, 0, 1, 3);
	// a spin-box ocupa apenas a quarta e última coluna:
	gridLayout->addWidget(spin, 1, 3);

	// Conecta o signal "valueChanged" do slider
	// ao slot "setValue" da spin-box para que exiba o valor do slider,
	// quando este for alterado:
	connect(m_slider, SIGNAL(valueChanged(int)),
					 spin, SLOT(setValue(int)));

	// Conexão inversa: o signal da spin-box e o slot do slider:
	connect(spin, SIGNAL(valueChanged(int)),
					m_slider, SLOT(setValue(int)));

	// Conecta o signal "valueChanged" do slider
	// ao slot "update" do termômetro,
	// de modo a forçar uma nova pintura do termômetro:
	connect(m_slider, SIGNAL(valueChanged(int)),
                         m_thermometer, SLOT( update()));
                        // =>	update(); => força um  novo "paintEvent"

	m_slider->setValue(0);
}

// paintEvent: aqui podemos personalizar o desenho/pintura de um Widget
// usando um objeto QPainter relacionado a esse Widget:
void Thermometer::paintEvent(QPaintEvent * pEv)
{
	MainWin * mainWin = qobject_cast<MainWin*>( parent() );
	// "qobject_cast": semelhante ao standard "dynamic_cast", mas NÃO usa RTTI.
	// A exigência é que o tipo envolvido tenha declarado a macro Q_OBJECT.

	if ( !mainWin)
		return; // parent não é do tipo "MainWin*" !!!

	// Objeto QPainter que permitirá desenhar na área cliente do widget "Thermometer"
	QPainter paint(this);

	// desenha um fundo para área total do "thermometer":
	//paint.fillRect( this->rect(), QBrush( Qt::yellow ));
	// ou, neste exemplo:
	paint.fillRect( pEv->rect() ,QBrush( Qt::yellow ));

	// área restante para desenho das partes brancas e vermelha do "thermometer":
	const int border =4; // borda
	const int left = this->rect().left()+border;   //  coordenada "x", esquerda, adicionando borda
	const int width = this->width()-(border<<1); // largura, subtraindo borda-esquerda e borda-direita
	const int top = this->rect().top()+border; //  coordenada "y", topo, adicionando borda
	const int height = this->height()-(border<<1); // altura, subtraindo borda-superior e borda-inferior

	// 1) a parte inferior do label "thermometer"
	//      será preenchida em vermelho,
	//      ocupando uma área proporcional ao valor atual do slider

	// 2) a parte superior do "thermometer",
	//     será preenchida com branco
	//     e ocupará a área restante

	// Desativar a caneta para que não seja usada ao desenhar retângulos abaixo.
	paint.setPen(Qt::NoPen);
	// Caso fosse usada uma caneta, as áreas inferior e superior teriam, além de bordas laterais,
	// tambem uma borda acima da área vermelha e abaixo da área branca,
	// fazendo uma divisão entre as duas, o que não é desejado aqui.
	// Por isso, acima, desenhamos um fundo para a área total do "thermometer"
	// e estabelecemos bordas que serão obedecidas no desenho das 2 áreas internas.


	// 1) ==== área INFERIOR (vermelha, proporcional ao valor do slider):

	// 1.a) valor atual do slider:
	const int redValue = mainWin->slider()->value();
	// 1.b) altura para esta área  calculada proporcionalmente ao valor do slider:
	const int redHeight  = (redValue * height) / mainWin->slider()->maximum() ;
	// 1.c) coordenada "y"(topo) para a cor vermelha,
	const int redTop = top + (height-redHeight) ;  // preencherá toda a área inferior a partir de "redTop"

	// 1.d) desenha a parte inferior (vermelha):
	if ( redHeight > 0  )
	{
		paint.setBrush(QBrush(Qt::red)); // "pincel" vermelho para o fundo
		paint.drawRect( left, redTop, width, redHeight );
	}

	// 2) ==== área SUPERIOR (branca, ocupando a área restante):

	// 2.a) altura para esta área:
	const int whiteHeight= height-redHeight;
	// 2.b) coordenada "y"(topo) para cor branca:
	const int & whiteTop = top;

	// 2.c) desenha a parte superior (branca)
	if ( whiteHeight > 0  )
	{
		paint.setBrush(QBrush(Qt::white)); // "pincel" branco para o fundo
		paint.drawRect( left, whiteTop, width, whiteHeight );
	}
}
