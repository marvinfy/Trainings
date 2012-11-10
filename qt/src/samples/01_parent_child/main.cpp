#include <QtGui/QApplication>

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	 QLabel labelMain1("Label Main 1", 0); // não tem parent
	 labelMain1.setLayout( new QVBoxLayout);
	 
	 QPushButton * buttonMain = new QPushButton("Button Main", 0); // sem parent
	 QVBoxLayout * bmainVLay = new QVBoxLayout;
	 // o spacer abaixo só funcionaria se o button estivesse dentro de um widget container
	 // e o layout seria do container e o botão seria adicionado ao layout e em seguida o spacer
	// bmainVLay->addItem (new QSpacerItem(10,10, QSizePolicy::Fixed, QSizePolicy::Expanding));
	 buttonMain->setLayout ( bmainVLay);

	 QLabel labelMain2("", 0); // sem parent;
	 QPushButton * quitButton = new QPushButton("------ Quit -------", &labelMain2);
	 //  ou:
	// quitButton->setParent(&labelMain2);

	 // labelMain2 é o "parent de quitButton;
	 QPushButton * aboutButton = new QPushButton("Sobre Qt", &labelMain2); 
			// labelMain2 também é o "parent de aboutButton;

	 // usando geometria fixa:
	/* quitButton->setGeometry(10,10, 100, 50);
	 aboutButton->setGeometry(10,70, 100, 50);;
	 labelMain2.setMinimumSize( 110, 190 );
*/

	 QGridLayout * gridLay = new QGridLayout(&labelMain2);
	 gridLay->addItem(new QSpacerItem(10,10, QSizePolicy::Expanding, QSizePolicy::Fixed),
													0, 0); // linha zero, coluna zero
	 // o spacer expandirá na horizontal

	 gridLay->addWidget(aboutButton, 0, 1, 1,1, Qt::AlignHCenter );
																	// linha 0, coluna 1, rowSpan 1, colSpan 1, Alinhamento

	  gridLay->addItem(new QSpacerItem(10,10, QSizePolicy::Expanding, QSizePolicy::Fixed),
							 0, 2); // linha 0, coluna 2
	 
	 gridLay->addItem(new QSpacerItem(10,10, QSizePolicy::Expanding, QSizePolicy::Fixed),
							1, 0); // linha 1 coluna 0
	 gridLay->addWidget(quitButton, 1, 1, 1,1, Qt::AlignHCenter );
																		// linha 1, coluna 1
	 gridLay->addItem(new QSpacerItem(10,10, QSizePolicy::Expanding, QSizePolicy::Fixed),
							1, 2); // linha 1, coluna 2
	 
	 gridLay->addItem(new QSpacerItem(10,10, QSizePolicy::Fixed, QSizePolicy::Expanding),
							2, 0,
							1, 3);   // linha 2, coluna 0, rowSpan 1, colSpan 3, alinhamento
							// o spacer expandirá na vertical

	 QObject::connect( buttonMain, SIGNAL( clicked() ), 
							 buttonMain, SLOT( close() ) );
	 
	 QObject::connect( quitButton, SIGNAL( clicked() ),
											 &a, SLOT( quit() ) );

	 QObject::connect( aboutButton, SIGNAL( clicked() ),
											 &a, SLOT( aboutQt() ) );
	 
	 
	 labelMain1.show();
	 labelMain2.show();
	 buttonMain->show();
	 
    int ret = a.exec();
	 
	// não precisaria disso se tivesse alocado "buttonMain" na pilha.
	 delete buttonMain;
	 
	 return ret; // aqui são chamadas as destrutoras para labelMain1 e labelMain2
	 // NÃO PRECISO  deletar quitButton e aboutButton,
		//pois isso será feito pela destrutora de seu parent labelMain2
}
