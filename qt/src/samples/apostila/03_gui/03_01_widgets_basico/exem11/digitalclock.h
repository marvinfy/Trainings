#ifndef _DIGITAL_CLOCK_H_INC_
#define _DIGITAL_CLOCK_H_INC_

#include <QtGui>

#include <QLCDNumber>

// class DigitalClock: derivada de QLCDNumber (um display "LCD"),
// acrescentando um slot e um signal:
class DigitalClock : public QLCDNumber
{
	// esta classe tem slots e signals próprios;
	// então é preciso adicionar a macro "Q_OBJECT"
	// para que seja invocado o "moc" (meta-object compiler)
	Q_OBJECT

	public:
		// construtora
		DigitalClock(QWidget *parent = 0);

	public slots:
		// o slot "showTime" será conectado ao signal "timeout" de um objeto QTimer
		// e desse modo será acionado sempre que um intervalo de tempo for atingido.
		void showTime();

	public:

	signals:
		// ao receber o signal "timeout" do objeto QTimer,
		// o slot "showTime" irá disparar o signal "timeChanged"
		 // que poderá ser recebido por qualquer outro objeto desta aplicação:
		void timeChanged(const QString & qstTime);
};


#endif //  ( _DIGITAL_CLOCK_H_INC_ )
