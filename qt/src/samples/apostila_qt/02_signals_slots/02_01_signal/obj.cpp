
#include <QCoreApplication>
#include <QTimer>
#include <iostream>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	QTimer timer;

	QObject::connect( &timer, SIGNAL(timeout()) ,
                         &app  , SLOT(quit()) );
	
  std::cout << "timer start - aplicacao encerrara em 5 segundos..." << std::endl;
  timer.start(5000);

  app.exec(); // event-loop

	std::cout << "main: fim" << std::endl;

	return 0;
}

