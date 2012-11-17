 #include <QtCore/QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "TestaObj.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	 {
		  TestaObj o1("o1"); // "parent" ZERO
		  TestaObj o2("o2"); // "parent" ZERO

		  // conecto o SIGNAL da base (QObject)
		  // ao SLOT da derivada (TestaObj):
		  QObject::connect( &o2, SIGNAL(destroyed(QObject*)) ,
								  &o1, SLOT (onDestroyed(QObject *)));
		  // na destrutora de QObject, ao final temos
				// emit destroyed( this );

		  // Será que esta aqui vai funcionar ???????? NÃO! (só a anterior...)
		  QObject::connect( &o1, SIGNAL(destroyed(QObject*)) ,
								  &o2, SLOT (onDestroyed(QObject *)));

		  qDebug() << "o2 (primeiro) e o1(depois) serao destruidos agora";

	 }  // destrutora de "o2" será chamada aqui e emitirá o SIGNAL "destroyed"
		  // em seguida será chamada a destrutora de "o1".

 
		/*//1
	 QTimer timer;
	 timer.connect (&timer, SIGNAL(timeout()),
						 &a , SLOT(quit())) ;
	 qDebug() << "esta aplicacao se auto-destruira em 5 segundos";
	 timer.start(5000); // 5.000 milisegundos, 5 segndos)
*/

  TestaObj ob3("ob3");
  QObject::connect ( &ob3, SIGNAL(exit()),
							&a, SLOT(quit()), Qt::QueuedConnection);


/*	// 2
	 qDebug() <<  "vou provocar agora o encerramento";
	 ob3.finish();
*/

  // 3
  QTimer timer;
  timer.connect (&timer, SIGNAL(timeout()),
										  &ob3 , SIGNAL(exit()) );
  qDebug() << "esta aplicacao se auto-destruira em 5 segundos";
  timer.start(5000); // 5.000 milisegundos 5 segndos)

 return a.exec();
}
