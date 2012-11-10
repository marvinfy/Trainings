#include <QtGui/QApplication>
#include <QDir>
#include <QMessageBox>

#include "widget.h"
#include "model.h"

// cria um arquivo de teste caso não exista o arquivo com dados:
bool CriaArquivoTeste( QFile & file ) ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	// Path para localizar o arquivo que será a fonte de dados do "model":
	QString appPath = QDir::currentPath ();

	// Caso "debug" ou "release" estejam no path,
	// remover para manter o diretório do projeto:
	appPath.remove( "/debug" );
	appPath.remove( "/release");

	// nome completo do arquivo:
	QString fileName = appPath + "/teste.dat";

	// Se esse arquivo não existir, criar um arquivo com alguns dados para teste:
	if ( !QFile::exists( fileName ) )
	{
		QFile file( fileName );

		if ( !CriaArquivoTeste( file ) )
			QMessageBox::warning(0, "Erro",  "Não foi possível criar o arquivo de teste.");

		if ( file.isOpen() )
			file.close();
	}

	// Passa o "fileName" para a construtora de "Widget"
	// pois ele será usado para abrir arquivo que será a fonte de dados para o "model"
	Widget w ( fileName );
	w.show();
	return a.exec();
}

// função auxiliar para criar um registro no arquivo de teste:
bool GravaRegistro( QFile & file, const char * nome, const char * cidade );

// cria um arquivo de teste caso não exista um arquivo:
bool CriaArquivoTeste( QFile & file )
{
	if ( !file.open(QIODevice::WriteOnly) )
		return false;

	if ( !GravaRegistro(file, "Antonio da Silva", "Andradina"))
		return false;
	if ( !GravaRegistro(file, "Pedro Campos", "Campinas"))
		return false;
	if ( !GravaRegistro(file, "Joaquim Antunes", "Bauru"))
		return false;
	if ( !GravaRegistro(file, "Leandro Melo", "Catanduva"))
		return false;
	if ( !GravaRegistro(file, "Rolando Lero", "Araraquara"))
		return false;
	if ( !GravaRegistro(file, "Maria Mara", "Rio de Janeiro"))
		return false;
	if ( !GravaRegistro(file, "Ana Carolina", "Salvador"))
		return false;
	if ( !GravaRegistro(file, "Mariazinha zinha", "Bauru"))
		return false;
	if ( !GravaRegistro(file, "Ledo Engano", "Catanduva"))
		return false;
	if ( !GravaRegistro(file, "Pedro Costa", "Rio de Janeiro"))
		return false;
	if ( !GravaRegistro(file, "Belmiro miro", "Salvador"))
		return false;

	return true;
}

// função auxiliar para criar um registro no arquivo de teste:
bool GravaRegistro( QFile & file, const char * nome, const char * cidade )
{
	// Completa nome e cidade com brancos à direita, se necessario
	QString strNome ( QString("%1").arg(nome,  -Model::NomeLen) ) ;   // "-" alinhar à esquerda, com brancos à direita
	QString strCidade ( QString("%1").arg(cidade, -Model::CidadeLen) );  // idem

	if ( file.write(strNome.toAscii(), Model::NomeLen) != Model::NomeLen )
		return false; // erro (não conseguiu gravar a quantidade de bytes solicitada)

	if ( file.write(strCidade.toAscii(), Model::CidadeLen) != Model::CidadeLen )
		return false; // erro  (idem)

	if ( file.write("\n", sizeof(char('\n')) ) != sizeof(char('\n')) )
		return false; // erro (idem)

	return true;
}

