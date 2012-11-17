
#include <QtGui>

int main(int argc , char * argv[])
{
	QApplication app(argc, argv); // objeto para iniciar a aplicação
	
	// cria um objeto "slider" e um "label"
	QSlider * pSlider = new QSlider(Qt::Horizontal); 
	QLabel * pLabel = new QLabel;

	// cria um layout:
	QHBoxLayout * layMain = new QHBoxLayout;

	// adciona os widgets ao layout:
	layMain->addWidget( pSlider );
	layMain->addWidget( pLabel );

	// acrescenta bordas ao label;
	pLabel->setFrameShape ( QFrame::Box );
	pLabel->setFrameShadow( QFrame::Raised );

	// conecta o sinal "valueChanged" do "slider"
	// ao "slot" "SetNum" do "label":
	QObject::connect(pSlider, SIGNAL( valueChanged(int) ),
					 pLabel , SLOT  ( setNum(int) ) );

	// define o range e o valor inicial do slider:
	pSlider->setRange(0, 100); // range
	pSlider->setValue( 20 ); // valor inicial

		// acima, a função "setValue" já irá modificar o valor do "slider";
		// nesse momento, o "slider" emitirá o sinal "valueChanged" que já irá modificar o conteúdo do label;
		// e sempre que o "slider" for movimentado, o sinal será emitido e o label será modificado.

	// janela principal:
	QWidget * wgMainWindow = new QWidget;

	// adiciona o layou à janela principal:
	wgMainWindow->setLayout ( layMain );

	// exibe a janela
	wgMainWindow->show();

	// entra no eventloop (laço de mensagens):
	app.exec();

	return 0;
}

