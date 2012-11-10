#include "DigitalClock.h"
#include <QTime>
#include <QTimer>

DigitalClock::DigitalClock(QWidget *parent)
	: QLCDNumber(parent)
{
	// define estilo e cor do texto do LCD:
	setSegmentStyle(Filled );
	setForegroundRole ( QPalette::Midlight);
	// quantidade de dígitos a exibir (hh:mm:ss):
	setNumDigits(8);

	// cria um objeto QTimer (que irá emitir o signal "timeout" 
	// no intervalo de tempo a ser especificado):
	QTimer *timer = new QTimer(this);

	// especifica o intervalo de tempo (1 segundo)
	// para emissão do sinal "timeout":
	timer->start(1000);
	
	// conecta o signal "timeout" do objeto timer 
	// (será emitido sempre que o intervalo de tempo for atingido)
	// ao slot "showTime" desta classe:
	connect(timer, SIGNAL(timeout()), 
			 this, SLOT(showTime()) );

	// define o título da janela:
	setWindowTitle("Digital Clock");
	
	// força a definição da largura e altura da janela:
	resize(300, 120);

	// força a exibição inicial da hora no LCD:
	showTime();
}

void DigitalClock::showTime()
{
	// pega a hora atual da máquina:
	QTime time = QTime::currentTime();

	// converte o objeto QTime para string, 
	// com o formato especificado no argumento:
	QString text = time.toString("hh:mm:ss");
	
	display(text); // exibe o texto contendo a hora atual no QLCDNumber
}

