#include <QtGui/QApplication>
#include "Widget.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QDebug>


void createFakeData(QSqlDatabase & db);

int main(int argc, char *argv[])
{

	 QApplication a(argc, argv);

	 qDebug() << "drivers instalados: " << QSqlDatabase::drivers();
	 qDebug() <<  "sizeof(QSqlDatabase): " << sizeof(QSqlDatabase);

#ifdef Q_OS_WIN

	 const char * path = "c:/cursoQt/dados/";
 #else
	 const char * path = "/home/user_name/cursoQt/dados/";
#endif

	 QDir dir(path);
	 if (!dir.exists())
	 {
			 if ( !dir.mkdir(path) ) // ou dir.mkpath(path)
			{
				 QMessageBox::critical(0, "Erro Fatal", "Não foi possível criar diretorio dados");
				 return 0;
			}
	 }
	 QString fileName(QString(path)+"16_teste.db");

	 QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	// db.setHostName("host");
	// db.setUserName("user");
	// db.setPassword("pwd");

	 db.setDatabaseName(fileName);

	 // tres alternativas para usar o objeto QSqlDatabase ( conexão )

	 // 1) memorizar o objeto "db" (como membro de classe ou global)
		//	 QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		//   QSqlQuery query( db ); query.exec(...);

	 // 2) se tenho uma única conexão posso não memorizar
	 //        pois essa sera considerada a conexão default e será usada
	 //       em todas as ações referentes a banco de dados.
	 //   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	 //   db.set...(...);
	 // QSqlQuery query ; query.exec(...);  // USA A CONEXÃO DEFAULT

	 // 3) se tenho mais que uma conexão, posso atribuir um nome:

	 // QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE", "DB1");
	 // QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "DB2");
	 // QSqlDatabase db3 = QSqlDatabase::addDatabase("QOCI", "DB3_ORACLE");
	 // E agora, se eu não memorizar o objeto "db", posso recuperar
	 // esse objeto a partir dos nome de conexão :
	//	 QSqlDatabase db1 = QSqlDatabase::database("DB1");
	 //	 QSqlDatabase db2 = QSqlDatabase::database("DB2");
	 //	 QSqlDatabase db3 = QSqlDatabase::database("DB3_ORACLE");
	 //  QSqlQuery query (db1 ); // ou (db2) ou (db3)
	 // query.exec(...);

	 bool jaExiste = QFile::exists(fileName);
	 if ( !db.open( ))
	 {
		 // QMessageBox...
		 QMessageBox::critical(0, "Erro", "Falha ao abrir banco:\n" +
									  db.lastError().text() );
		 return 0;
	 }

	 if ( !jaExiste )
		 createFakeData( db );

	 Widget w (db);
	 w.show();

	 return a.exec();
}

void createFakeData(QSqlDatabase & db)
{
	 //QSqlQuery query; // conexão default
	// QSqlQuery query(QSqlDatabase::database("nome_conexao"));
	QSqlQuery query(db);

	// não precisa pois já sei que o banco foi criado
	// agora e não tem tabelas:
 // query.exec("DROP TABLE scooter");

 /*
	// executando a query SEM PEGAR O RETORNO:

 query.exec("CREATE TABLE scooter ("
					"id INTEGER PRIMARY KEY AUTOINCREMENT, "
					"name VARCHAR(40) NOT NULL, "
					"maxspeed INTEGER NOT NULL, "
					"maxrange INTEGER NOT NULL, "
					"weight INTEGER NOT NULL, "
					"description VARCHAR(80) NOT NULL)");
*/
 // o correto seria:
  if ( !query.exec( "CREATE TABLE scooter ("
										 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
										 "name VARCHAR(40) NOT NULL, "
										 "maxspeed INTEGER NOT NULL, "
										 "maxrange INTEGER NOT NULL, "
										 "weight INTEGER NOT NULL, "
										 "description VARCHAR(80) NOT NULL)")

		)
  {
	  QMessageBox::critical(0, "Erro", "Falha ao executar:\n" +
									query.lastError().text() );
	  return ;  // a função deveria ser bool e retornar false

  }
  // o mesmo para as queries abaixo:

	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Mod-Rad 1500', 40, 35, 298, "
					"'Speedometer, odometer, battery meter, turn signal "
					"indicator, locking steering column')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Rad2Go Great White E36', 22, 12, 93, "
					"'10\" airless tires')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('X-Treme X360', 21, 14, 59, "
					"'Cargo rack, foldable')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Vego SX 600', 20, , 76, "
					"'Two interchangeable batteries, foldable')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Sunbird E Bike', 18, 30, 118, '')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Leopard Shark', 16, 12, 63, "
					"'Battery indicator, removable seat, foldable')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Vego iQ 450', 15, 0, 60, "
					"'OUT OF STOCK')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('X-Treme X-11', 15, 11, 38, "
					"'High powered brakes, foldable')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('ZZ Cruiser', 14, 10, 46, "
					"'Two batteries, removable seat')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('X-Treme X-010', 10, 10, 14, "
					"'Solid tires')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Q Electric Chariot', 10, 15, 60, "
					"'Foldable')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('X-Treme X250', 15, 12, 0, "
					"'Solid aluminum deck')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Go MotorBoard 2000X', 15, 0, 20, "
					"'Foldable and carryable')");
	 query.exec("INSERT INTO scooter (name, maxspeed, "
					"maxrange, weight, description) "
					"VALUES ('Goped ESR750 Sport Electric Scooter', "
					"20, 6, 45, " "'Foldable and carryable')");
}
