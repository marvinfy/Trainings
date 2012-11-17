#include "dlg_database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QVariant>

dlg_database::dlg_database()
{
}

bool dlg_database::open()
{
	const char * dbFileName = "teste.dat";
	bool fileExists = QFile::exists(dbFileName);

	QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbFileName);

	/*	db.setHostName("...");
	db.setUserName("...");
	db.setPassword("...");
	*/

	if (!db.open())
	{
		QMessageBox::warning( qApp->activeWindow(), "Erro",
									"Erro na abertura do banco");
		return false;
	}

	if ( !fileExists )
		createTables();

	return true;
}
void dlg_database::createTables()
{
	  QSqlQuery query; // pega a conexão default

	  query.exec("CREATE TABLE uf ("
				 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "name VARCHAR(3) NOT NULL)");

	  query.exec("INSERT INTO uf (name) VALUES ('SP')");
	  query.exec("INSERT INTO uf (name) VALUES ('MG')");
	  query.exec("INSERT INTO uf (name) VALUES ('RJ')");
	  query.exec("INSERT INTO uf (name) VALUES ('BA')");

	query.exec("CREATE TABLE pessoas ("
				 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "name VARCHAR(41) NOT NULL, "
				 "sexo VARCHAR(10) NOT NULL, "
				 "estcivil VARCHAR(11) NOT NULL, "
				 "recebe_mail BOOL NOT NULL, "
				 "uf_id INTEGER NOT NULL, "
				 "FOREIGN KEY (uf_id) REFERENCES uf)") ;
 }
