#include <QtGui>

int main(int argc , char ** argv)
{
    QApplication app(argc, argv); // objeto que inicia a aplicacao

    // cria um botao ;
	// - o primeiro argumento e a 'caption' do botao;
	// - o segundo argumento, sendo zero, significa que o botao nao tem uma janela "parent";
			//  logo ele sera a propria janela principal:	

    QPushButton * button = new QPushButton("Quit", 0);

	// == Conectando eventos a uma acao:

	// o "sinal" (funcao emissora) de que houve um "click" do botao sera conectado 
	// a um "slot" (funcao receptora) do objeto da classe QApplication (neste caso, o "slot" e a funcao "quit"):
	QObject::connect(button, SIGNAL(clicked()), 
					 &app, SLOT(quit()));

	// e a funcao "quit" de QApplication encerrara o programa.

    // exibe o botao:
    button->show();

    // entra no "event loop"  (laco de mensagens)
    app.exec();

    return 0;
}
