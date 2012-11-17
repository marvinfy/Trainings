#include <QtGui>

int main(int argc , char ** argv)
{
    QApplication app(argc, argv); // objeto que inicia a aplicacao

	// cria um botao ;
	// - o primeiro argumento e a 'caption' do botao;
	// - o segundo argumento, sendo zero, significa que o botao nao tem uma janela "parent";
			//  logo ele sera a propria janela principal:	
   QPushButton * button = new QPushButton("Hello", 0);

    // exibe o botao:
    button->show();

    // entra no "event loop"  (laco de mensagens)
    app.exec();

    return 0;
}
