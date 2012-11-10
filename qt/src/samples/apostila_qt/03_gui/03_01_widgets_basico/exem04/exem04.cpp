#include <QtGui>

int main(int argc , char ** argv)
{
	QApplication app(argc, argv); // objeto que inicia a aplicacao

	// cria um "Widget" (abreviatura de "Windows Gadget) que e a base de todas as janelas;
	// essa será a janela principal:

	QWidget * wgMain = new QWidget(0);

	// Cria dois "Widgets" (no caso dois botões);
	// - observar que os botões são criados aqui sem uma janela "parent":
	QPushButton * btAboutQt	= new QPushButton("About Qt", 0);
	QPushButton * btQuit	= new QPushButton("Quit", 0);

	// == Conectando eventos a uma acao:

	// o primeiro botão estara conectado ao "slot" "aboutQt" 
	// do objeto de QApplication:
	QObject::connect( btAboutQt, SIGNAL( clicked() ) , 
					  &app	   , SLOT  ( aboutQt() )  );

	// o segundo, ao "slot" "quit":
	QObject::connect( btQuit , SIGNAL( clicked() ) , 
					  &app	 , SLOT  ( quit() )  );


	// cria um objeto de "layout" para organizar os botões dentro da janela:
	QVBoxLayout * layMain = new QVBoxLayout;
	// adiciona os botões ao layout:
	layMain->addWidget( btAboutQt );
	layMain->addWidget( btQuit );

	// associa o layout à janela principal:
	wgMain->setLayout ( layMain );

	// exibe a janela:
	wgMain->show();

	// entra no "event loop"  (laco de mensagens)
	app.exec();

	return 0;
}
