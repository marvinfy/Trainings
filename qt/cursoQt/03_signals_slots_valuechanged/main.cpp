#include <QtCore/QCoreApplication>

#include "Spin.h"
#include "Slider.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	 Spin spin;
	 Slider slider;
	 QObject::connect(&spin, SIGNAL(valueChanged(int)),
							&slider, SLOT(setValue(int)));

	 QObject::connect(&slider, SIGNAL(valueChanged(int)),
							&spin, SLOT(setValue(int)));

	 // só funcionará ser for agendada
	 // pois o quit interrompe o event-loop (se eu já estiver no event-loop)
	 QObject::connect(&spin, SIGNAL(finish()),
							&a, SLOT(quit()), Qt::QueuedConnection);

	 for ( int n = 1; n<=10; ++n)
	 {
		 spin.setValue(n*100+1);
		 slider.setValue(n*100+1);
	 }

    return a.exec();
}
