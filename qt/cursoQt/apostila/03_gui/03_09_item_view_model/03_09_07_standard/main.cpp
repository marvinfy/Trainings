#include <QtGui>
#include <QApplication>
#include <QDir>

#include "MainWidget.h"

void createTreeFile ( const QString & fileName );

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QString appPath = QDir::currentPath ();
	appPath.remove( "/debug" );
	appPath.remove( "/release");

	QString treeFileName = appPath + "/tree.dat";
	
	if ( !QFile::exists( treeFileName ) )
		createTreeFile(treeFileName);	

	// lê o arquivo de dados para montar a tree:	
	QFile file(treeFileName);
	file.open(QIODevice::ReadOnly);	
	// passa para a construtora de MainWidget
	// o buffer com o resultado da leitura do arquivo:
	MainWidget * mainWin = new MainWidget( file.readAll());
	file.close();

	mainWin->show();
	return app.exec();
	
	delete mainWin;
}

void createTreeFile ( const QString & fileName )
{
	QFile file( fileName );
	file.open(QIODevice::WriteOnly);
	QTextStream textTree(&file);

	// A stringlist de "MainWidget" conterá a estrutura da "tree".
	// Neste exemplo, ao invés de XML (que usaremos no próximo)	
	// indicamos o nível com um número inicial, indicador de nível, seguido de ";"
	// e separamos colunas (se existirem) com um '\t'
	
	textTree << "frutas\tvitaminas"	<< '\n'
				<< "\tcítricas"			<< '\n'
					<< "\t\tlaranja"		<< '\n'
					<< "\t\tlimão"	<< '\n'
				<< "\toutras"			<< '\n'
					<< "\t\tpêssego"		<< '\n'
					<< "\t\tameixa"		<< '\n'
					<< "\t\tmelancia"		<< '\n'
			<< "cereais\tfibras"		<< '\n'
				<< "\ttrigo"			<< '\n'
				<< "\tcevada"			<< '\n'
				<< "\taveia"			<< '\n'
			<< "carnes\tproteínas"	<< '\n'
				<< "\tcarne branca"		<< '\n'
					<< "\t\tfrango"		<< '\n'
					<< "\t\tpeixe"		<< '\n'
				<< "\tcarne vermelha"	<< '\n'
					<< "\t\tbovina"		<< '\n'
						<< "\t\t\tcarne de primeira"  << '\n'
						<< "\t\t\tcarne de segunda"   << '\n'
						<< "\t\t\tvitela"	<< '\n'
					<< "\t\tcabrito"		<< '\n'
					<< "\t\tjavali"		<< '\n' ;
	file.close();
}

