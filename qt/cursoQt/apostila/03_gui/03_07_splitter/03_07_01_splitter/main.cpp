#include <QtGui/QApplication>
#include <QSplitter>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget wgMain;
	wgMain.setWindowTitle ( "Splitter-1");

	QSplitter * splitter = new QSplitter (&wgMain );
	QLabel * label1 = new QLabel ( "Label - 1", splitter );
	QLabel * label2 = new QLabel ( "Label - 2", splitter );
	QLabel * label3 = new QLabel ( "Label - 3", 0 );
	splitter->addWidget( label3 );

	label1->setFrameShape(	QFrame::WinPanel );
	label2->setFrameShape(	QFrame::WinPanel );
	label3->setFrameShape(	QFrame::WinPanel );
	label1->setFrameShadow(	QFrame::Sunken );
	label2->setFrameShadow(	QFrame::Sunken );
	label3->setFrameShadow(	QFrame::Sunken );

	int width = 750, height = 550;
	splitter->setMinimumSize( width/3, height/3); // um terço.
	// colunas:
	QList<int> cols;
	cols << int ( width *0.5 ) // 50%
			<< int ( width *0.3) // 30%
			<< int (width * 0.2) ;  // 20%
	splitter->setSizes( cols );
	splitter->setChildrenCollapsible( false ); // impede que uma "banda"
                                    // seja ocultada (fique com tamanho zero)

	QVBoxLayout * layMain = new QVBoxLayout ( &wgMain );
	layMain->addWidget(splitter);
	wgMain.resize( width, height );
	wgMain.move(0,0);
	wgMain.show();

    return a.exec();
}

