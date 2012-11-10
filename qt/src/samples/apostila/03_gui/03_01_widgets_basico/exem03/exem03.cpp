#include <QtGui>

int main(int argc , char ** argv)
{
	QApplication app(argc, argv); // objeto que inicia a aplicacao

	// cria um "Widget" (abreviatura de "Windows Gadget)
	// que e a base de todas as janelas;
	// essa sera a janela principal:

	QWidget * wgMain = new QWidget(0);

	// Acrescenta dois "Widgets" (no caso dois botoes)
	// na janela principal;
	// - observar que o segundo argumento ("wgMain")
	// significa que "wgMain" e a janela "parent" dos botoes:
	QPushButton * btAboutQt	= new QPushButton("About Qt",
							wgMain);
	QPushButton * btQuit	= new QPushButton("Quit", 
							wgMain);
	
	// define posicao dos botoes(em relacao a janela "parent")
	// e dimensoes dos botoes:
	btAboutQt->setGeometry(0, 10, 100, 40);
	btQuit->setGeometry   (0, 60, 100, 40);

	// == Conectando eventos a uma acao:

	// o primeiro botao estara conectado ao "slot" "aboutQt" 
	// do objeto de QApplication:
	QObject::connect( btAboutQt, SIGNAL( clicked() ) , 
					  &app	   , SLOT  ( aboutQt() )  );

	// o segundo, ao "slot" "quit":
	QObject::connect( btQuit , SIGNAL( clicked() ) , 
					  &app	 , SLOT  ( quit() )  );

	// exibe a janela:
	wgMain->show();

	// entra no "event loop"  (laco de mensagens)
	app.exec();

	return 0;
}
