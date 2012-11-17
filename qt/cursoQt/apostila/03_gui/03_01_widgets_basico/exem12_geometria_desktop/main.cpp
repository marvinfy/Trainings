#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QMessageBox>

int main(int argc , char * argv[] )
{
	QApplication app ( argc, argv );

	QWidget wg_main(0);

	if ( QMessageBox::question ( 0, 
		"Posição e tamanho do Main Widget", 
		"Usar coordenadas fixas?",
							QMessageBox::Yes | QMessageBox::No )
		== QMessageBox::Yes )
	{
		// posiciona o widget principal em coordenadas e tamanho fixos:
		wg_main.setMinimumSize( 200, 100 ); // podendo usar "resize", "maximumSize" , etc.
		wg_main.move( 500, 400 );
	}
	else
	{
		wg_main.setMinimumSize( 200, 100 );
		// centralizar o widget principal 
		// (podendo também modificar seu tamanho para um percentual do desktop)
	
		QDesktopWidget desk ;
		QRect desk_rect = desk.availableGeometry ( 	desk.primaryScreen () );
	
		if ( QMessageBox::question ( 0, 
			"*** Vou centralizar o widget ***", 
		"Devo também forçar o tamanho para um percentual do Desktop?",
							QMessageBox::Yes | QMessageBox::No )
			== QMessageBox::Yes )
		{
			// forçar a largura e altura para um percentual do desktop:
			int cx = int( desk_rect.width() * 0.8); // 80% da largura do desktop
			int cy = int( desk_rect.height() * 0.7); // 70% da altura do desktop
			wg_main.resize(cx, cy);
		}
		else
			wg_main.resize(200,100);

		wg_main.adjustSize();
		int x = desk_rect.center().x() - (wg_main.width()/2);
		int y = desk_rect.center().y() - (wg_main.height()/2);
		wg_main.move(x, y);
	}

	wg_main.show();
	
	app.exec();

	return 0;
}

