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

	// Cria mais dois "Widgets" com textos explicativos sobre os botões;
	// no caso, dois objetos da classe "QLabel":
	// (o '\n' no meio dos textos permitirá a quebra dos mesmos em 2 linhas):
	QLabel * lbAboutQt = new QLabel("O botão ao lado exibirá um diálogo\ncom informações sobre Qt.", 0);
	QLabel * lbQuit    = new QLabel("O botão ao lado\nencerrará esta aplicação.", 0);
	
	// == Conectando eventos a uma acao:

	// o primeiro botão estara conectado ao "slot" "aboutQt" 
	// do objeto de QApplication:
	QObject::connect( btAboutQt, SIGNAL( clicked() ) , 
					  &app	   , SLOT  ( aboutQt() )  );

	// o segundo, ao "slot" "quit":
	QObject::connect( btQuit , SIGNAL( clicked() ) , 
					  &app	 , SLOT  ( quit() )  );


	// cria um objeto de "layout" para organizar os dois botões VERTICALMENTE:
	QVBoxLayout * vlayButtons = new QVBoxLayout;
	// cria outro objeto de "layout" para organizar os dois labels VERTICALMENTE:
	QVBoxLayout * vlayLabels = new QVBoxLayout;

	// adicionar objetos aos 2 layouts:

	// botões:
	vlayButtons->addWidget( btAboutQt); 
	vlayButtons->addWidget( btQuit   ); 
	// labels:
	vlayLabels->addWidget ( lbAboutQt );
	vlayLabels->addWidget ( lbQuit  );  
	
	// finalmente, cria um objeto de "layout" que irá organizar os dois "layouts" anteriores HORIZONTALMENTE:
	QHBoxLayout * hlayMain = new QHBoxLayout;
	hlayMain->addLayout( vlayButtons  );
	hlayMain->addLayout( vlayLabels );


	// associa o layout horizontal à janela principal:
	wgMain->setLayout ( hlayMain );

	// exibe a janela:
	wgMain->show();

	// entra no "event loop"  (laco de mensagens)
	app.exec();

	return 0;
}
