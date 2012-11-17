/*
Esta classe trata a janela principal da aplicação.
A janela terá um ""DigitalClock" à esquerda e dois labels à direita:
- O primeiro label deverá imprimir o texto(a hora) que é passado por "DigitalClock" sempre que este emite o signal "timeChanged";
- O segundo label também irá imprimir esse mesmo texto, mas de modo diferenciado, com atributos de fonte e cor, usando HTML.
*/

#include "MainWidget.h"

MainWidget::MainWidget(QWidget * pParent )
	: QWidget( pParent )
{	
	DigitalClock * pClock = new DigitalClock;
	QLabel * pTopLabel = new QLabel;

	// a variável abaixo, "_m_pBottomLabel", é um membro da classe
	// pois será usada em outra função e não apenas na construtora:
	_m_pBottomLabel = new QLabel;

	// acrescenta bordas aos labels;
	pTopLabel->setFrameShape ( QFrame::Box );
	pTopLabel->setFrameShadow( QFrame::Raised ); // Raised
	_m_pBottomLabel->setFrameShape ( QFrame::Box );
	_m_pBottomLabel->setFrameShadow( QFrame::Sunken );// Sunken

	// layout para agrupar, verticalmente, os labels à direita da janela:
	QVBoxLayout * vlay = new QVBoxLayout;
	vlay->addWidget(pTopLabel);
	vlay->addWidget(_m_pBottomLabel);
	
	// layout para agrupar, horizontalmente, 
	// o widget "DigitalClock" à esquerda e o layout vertical à direita:
	QHBoxLayout * hlay = new QHBoxLayout;
	hlay->addWidget(pClock,2); // se possível, o "DigitalClock" deverá ocupar o dobro da largura 
	hlay->addLayout(vlay,1);   // com relação ao layout vertical que ficará à direita

	// Conectar signals a slots:

	// 1- o signal "timeChanged" emitido pelo "DigitalClock"
	//		pode ser conectado diretamente ao slot "setText" de "pTopLabel",
	//		pois o texto passado como argumento será impresso 
	//		do mesmo modo que é enviado pelo signal, sem alterações:
	connect( pClock,   SIGNAL (timeChanged( const QString &)) ,
			 pTopLabel,  SLOT ( setText (const QString &)) );

	// 2- contudo esse mesmo sinal não pode ser conectado diretamente ao slot "setText" de "_m_pBottomLabel",
	//		pois queremos imprimir o texto de modo diferenciado;
	//		então esta classe ("MainWidget") precisa ter um slot próprio ("setTime", no caso)
	//		que faça o tratamento do texto antes de passá-lo para "_m_pBottomLabel": 
	connect( pClock, SIGNAL (timeChanged( const QString &)) ,
			 this,     SLOT ( setTime (const QString &)) );

	// associa o layout a este objeto  "MainWidget":
	setLayout( hlay );

	// define o título desta janela:
	setWindowTitle("Digital Clock / Label Clock");

	// força a definição da largura e altura da janela:
	resize(400, 120);

	// força a exibição inicial da hora no LCD:
	// (consequentemente ocorrerá também a atualização dos labels
	//  por força do mecanismo signal/slot):
	pClock->showTime();
}

// slot setTime: será acionado pelo signal "timeChanged" de "DigitalClock",
// recebendo como argumento um texto contendo a hora atual; 
// irá tratar esse texto para imprimi-lo em "_m_pBottomLabel":
void MainWidget::setTime( const QString & qstTime )
{
	// pega os segundos da hora atual:
	int nSecs = qstTime.right(2).toInt();
	
	QString temp;

	// monta o texto para o "_m_pBottomLabel" usando tags HTML,
	// sendo que a cada segundo troca a fonte e a cor do texto:
	if ( nSecs & 1 )
		temp = "<font face='Verdana, Arial, Helvetica, sans-serif' size='5' color='#ff0000'>";
	else
		temp = "<font face='Times New Roman, Times, serif' size='6' color='#0000ff'>";
	
	// completa as tags:
	temp += "<b>";
	temp += qstTime;
	temp += "</b></font>";

	// passa o texto para "_m_pBottomLabel":
	_m_pBottomLabel->setText( temp);
}


