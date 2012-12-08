#include <QtGui/QApplication>
#include "Widget.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>
#include <QDate>
#include <QFile>
#include <QMetaEnum>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include <QInputDialog>

bool createFakeData(QSqlDatabase & db, QString & error);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// exibe na "application output" todos os drivers disponíveis (apenas para teste):
	qDebug() << QSqlDatabase::drivers();

	enum { DrvSqlite, DrvPostgre, DrvMysql, DrvOracle};

	QStringList driversNickname;  // insere cada string indicadora de driver na posição determinada pelo "enum" acima:
	driversNickname.insert(DrvSqlite, "Sqlite");
	driversNickname.insert(DrvPostgre, "Postgre");
	driversNickname.insert(DrvMysql, "Mysql");
	driversNickname.insert(DrvOracle, "Oracle");

	bool ok;
	QString selDriverNickname = QInputDialog::getItem(a.activeWindow(),
																	  "Selecionar Banco de Dados",
														  "Selecione um dos bancos de dados disponíveis:",
																	  driversNickname,0, false, &ok);

	// se OK, seta o driver selecionado acima:
	QSqlDatabase db;

	if (ok && !selDriverNickname.isEmpty())
	{
		if (selDriverNickname == driversNickname[DrvSqlite] )
			db = QSqlDatabase::addDatabase("QSQLITE");      // SQLITE
		else if ( selDriverNickname == driversNickname[DrvPostgre])
			db = QSqlDatabase::addDatabase("QPSQL");        // POSTGRE
		else if ( selDriverNickname == driversNickname[DrvMysql])
			db = QSqlDatabase::addDatabase("QMYSQL");     // MYSQL
		else if ( selDriverNickname== driversNickname[DrvOracle])
			db = QSqlDatabase::addDatabase("QOCI");         // ORACLE
		else
			selDriverNickname=""; // ??? entrou um que não estava na lista... ???
	}

	if (!ok || selDriverNickname.isEmpty())
	{
		QMessageBox::warning(0, "Erro", "Nenhum banco foi selecionado. Impossível prosseguir.");
		return 0;
	}

	bool isDbEmpty =  false; // se o banco estiver vazio, será preenchido com tabelas e dados para teste

	if ( db.driverName() == "QSQLITE")  // --- SQLITE
	{
			#ifdef Q_OS_WIN
					 const char * fileName = "c:/cursoQt/dados/12_db_teste.db";
			#else
					 const char * fileName =	"/home/nome_user/cursoQt/dados/17_db_teste.db";
			#endif

			// para saber se está vazio no Sqlite basta verificar se o arquivo existe antes de chamar "db.open()"
			isDbEmpty = !QFile::exists(fileName); // pois, no SqLite a função "open" não falhará se o banco não existir: "open" criará o arquivo "teste.db"
			db.setDatabaseName(fileName);
	}
	else if (db.driverName() == "QPSQL")  // --- POSTGRE
	{
		db.setDatabaseName("cursoqt");
		db.setHostName("localhost");
		db.setUserName("postgres");
		db.setPassword("curso1");
	}
	else if (db.driverName() == "QMYSQL") // --- MYSQL
	{
		db.setDatabaseName("cursoqt");
		db.setHostName("localhost");
		db.setUserName("root");
		db.setPassword("curso1");
	}
	else if (db.driverName() == "QOCI") // --- ORACLE
	{
		db.setDatabaseName("");
		db.setHostName("localhost");
		db.setUserName("system");
		db.setPassword("curso1");

	}

	if ( !db.open()) // no SQlite se o "teste.db" não existir será criado aqui.
	{
		QMessageBox::critical(0,  "ERRO", "Erro na abertura do banco:\n"
														+ db.lastError().text());
		return 0;
	}

	// descobrir se o banco está vazio nos drivers listados (exceto Sqlite, pois isso já foi feito acima):
	QString queryTable;

	if ( db.driverName() == "QPSQL") // ---- POSTGRE
		queryTable = "SELECT tablename FROM pg_tables where tablename = 'contatos'";
	else if ( db.driverName() == "QMYSQL") // ---- MYSQL
		queryTable = "SELECT table_name FROM INFORMATION_SCHEMA.TABLES  WHERE table_name = 'contatos'";
	else if ( db.driverName() == "QOCI") // ---- ORACLE
		queryTable = "select object_name from user_Objects  where object_name = 'contatos' OR object_name = 'CONTATOS'";

	if (!queryTable.isEmpty())
	{
		QSqlQuery query(db);
		// descobre se uma tabela chave já foi criada:
		if ( !query.exec(queryTable) )
		{
			QMessageBox::warning(0, "ERRO", "Falha na busca de informações sobre tabelas em " +db.driverName() +":\n"
																	+query.lastError().text());
			return 0;
		}
		isDbEmpty = !query.next(); // se a query está vazia (não consegue ir para a table selecionada) então não devem existir as tabelas necessárias
																									// já que 'clientes' depende de 'contatos' e 'movimento' depende de 'clientes'
	}

	if ( isDbEmpty) // se o arquivo(SQLITE) NÃO existia antes do open, ou se houve ERRO na QUERY acima(TODOS OS OUTROS) ...
	{
		db.transaction();

		QString error;
		if ( createFakeData(db, error) )  // cria tabelas e alimenta com dados para teste.
		{
			db.commit();
		}
		else
		{
			db.rollback();
			QMessageBox::critical(0, "ERRO", error);
			return 0;
		}
	}

	Widget w(db);
	w.show();

	return a.exec();
}

// função auxiliar para simplificar a execução de algumas queries:
bool query_exec_(QSqlQuery & query, const QString & queryText, int & contador, QString & error );

bool createFakeData(QSqlDatabase & db, QString & error)
{
	QTime time;
	time.start();


	if ( db.driverName()=="QSQLITE")   // -------- SQLITE
	{
		QSqlQuery query(db);

		// tabela de cidades:
		if (!query.exec("CREATE TABLE cidades ("
							 "cid_id INTEGER PRIMARY KEY AUTOINCREMENT, "
							 "name VARCHAR(40) NOT NULL)") )
		{
			error = "Criando tabela cidades:\n" + query.lastError().text();
			return false;
		}

		// tabela de contatos:
		if ( !query.exec("CREATE TABLE contatos ("
							  "con_id INTEGER PRIMARY KEY AUTOINCREMENT, "
							  "name VARCHAR(40) NOT NULL)") )
		{
			error = "Criando tabela contatos:\n" + query.lastError().text();
			return false;
		}

		// tabela de clientes:
		if ( ! query.exec("CREATE TABLE clientes ("
								"cli_id INTEGER PRIMARY KEY AUTOINCREMENT, "
								"name VARCHAR(40) NOT NULL, "
								"cidade_id INTEGER NOT NULL, "
								"contato_id INTEGER NOT NULL, "
								"FOREIGN KEY (cidade_id) REFERENCES cidades(cli_id), "
								"FOREIGN KEY (contato_id) REFERENCES contatos(con_id))") )
		{
			error = "Criando tabela clientes:\n" + query.lastError().text();
			return false;
		}

		// tabela de tipo de movimento:
		if (!query.exec("CREATE TABLE mov_tipo ("
											  "mt_id INTEGER PRIMARY KEY AUTOINCREMENT, "
											  "name VARCHAR(40) NOT NULL)"))
		{
			error = "Criando tabela tipos de movimento:\n" + query.lastError().text();
			return false;
		}

		// tabela de movimento
		if ( !query.exec("CREATE TABLE movimento ("
					  "mov_id INTEGER PRIMARY KEY AUTOINCREMENT, "
					  "cliente_id INTEGER NOT NULL, "
					  "tipo_id INTEGER NOT NULL, "
					  "mov_date DATE NOT NULL, "
					  "description VARCHAR(40) NOT NULL, "
					  "FOREIGN KEY (cliente_id) REFERENCES clientes(cli_id), "
					  "FOREIGN KEY (tipo_id) REFERENCES mov_tipo(mt_id))" ) )
		{
			error = "Criando tabela movimento:\n" + query.lastError().text();
			return false;
		}

	}
	// ========================================
	else if ( db.driverName() == "QPSQL" ) // --------- POSTGRE
	{
		QSqlQuery query(db);

		// create sequences
		if ( !query.exec( "create sequence clientes_cli_id_seq increment 1 minvalue 1 "
								"maxvalue 9223372036854775807  start 1 cache 1" ) )
		{
			error = "Criando sequencia clientes:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create sequence movimento_mov_id_seq increment 1 minvalue 1 "
								 "maxvalue 9223372036854775807 start 1 cache 1"))
		{
			error = "Criando sequencia movimento:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("create sequence contatos_con_id_seq increment 1 minvalue 1 "
											"maxvalue 9223372036854775807 start 1 cache 1"))
		{
			error = "Criando sequencia contatos:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create sequence cidades_cid_id_seq increment 1 minvalue 1 "
											"maxvalue 9223372036854775807 start 1 cache 1" ))
		{
			error = "Criando sequencia cidades:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create sequence mov_tipo_mt_id_seq increment 1 minvalue 1 "
											"maxvalue 9223372036854775807 start 1 cache 1" ) )
		{
			error = "Criando sequencia mov_tipo:\n" + query.lastError().text();
			return false;
		}

		// create tables

		if ( !query.exec("create table \"clientes\" ("
					"\"cli_id\" integer not null default nextval('clientes_cli_id_seq') unique, "
					"\"name\" varchar(40) not null, "
					"\"cidade_id\" integer not null, "
					"\"contato_id\" integer not null, "
					"constraint \"pk_clientes\" primary key (\"cli_id\",\"cidade_id\",\"contato_id\") "
					") with oids" ) )
		{
			error = "Criando tabela clientes:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("create table \"movimento\" ("
					"\"mov_id\" integer not null default nextval('movimento_mov_id_seq') unique, "
					"\"cliente_id\" integer not null, "
					"\"tipo_id\" integer not null, "
					"\"mov_date\" date not null, "
					"\"description\" varchar(40) not null, "
					"constraint \"pk_movimento\" primary key (\"mov_id\",\"cliente_id\",\"tipo_id\") "
					") with oids" ) )
		{
			error = "Criando tabela movimento:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create table \"contatos\" 	("
					"\"con_id\" integer not null default nextval('contatos_con_id_seq') unique, "
					"\"name\" varchar(40) not null unique, "
					"constraint \"pk_contatos\" primary key (\"con_id\") "
					") with oids" ) )
		{
			error = "Criando tabela contatos:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("create table \"cidades\" ("
					"\"cid_id\" integer not null default nextval('cidades_cid_id_seq') unique, "
					"\"name\" varchar(40) not null, "
					"constraint \"pk_cidades\" primary key (\"cid_id\") "
					") with oids" ) )
		{
			error = "Criando tabela cidades:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create table \"mov_tipo\" ("
					"\"mt_id\" integer not null default nextval('mov_tipo_mt_id_seq') unique, "
					"\"name\" varchar(40) not null unique, "
					"constraint \"pk_mov_tipo\" primary key (\"mt_id\") "
					") with oids" ))
		{
			error = "Criando tabela tipos de movimento:\n" + query.lastError().text();
			return false;
		}

		// índices e relacionamentos:
		if (!query.exec( "create index \"ix_relation_cli_mov\" on \"movimento\" (\"cliente_id\")" ))
		{
			error = "Criando indice movimento/clientes:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec( "alter table \"movimento\" add constraint \"relation_cli_mov\" foreign key (\"cliente_id\") references \"clientes\" (\"cli_id\") on update restrict on delete restrict" ) )
		{
			error = "Criando relacionamento movimento/clientes:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create index \"ix_relation_con_cli\" on \"clientes\" (\"contato_id\")" ))
		{
			error = "Criando indice clientes/contatos:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec ("alter table \"clientes\" add constraint \"relation_con_cli\" foreign key (\"contato_id\") references \"contatos\" (\"con_id\") on update restrict on delete restrict" ) )
		{
			error = "Criando relacionamento clientes/contatos:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create index \"ix_relation_cid_cli\" on \"clientes\" (\"cidade_id\")" ))
		{
			error = "Criando indice clientes/cidades:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec( "alter table \"clientes\" add constraint \"relation_cid_cli\" foreign key (\"cidade_id\") references \"cidades\" (\"cid_id\") on update restrict on delete restrict" ))
		{
			error = "Criando relacionamento clientes/cidades:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec( "create index \"ix_relation_movtipo_mov\" on \"movimento\" (\"tipo_id\")" ) )
		{
			error = "Criando indice movimento/tipo de movimento:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec( "alter table \"movimento\" add constraint \"relation_movtipo_mov\" foreign key (\"tipo_id\") references \"mov_tipo\" (\"mt_id\") on update restrict on delete restrict" ) )
		{
			error = "Criando relacionamento movimento/tipo de movimento:\n" + query.lastError().text();
			return false;
		}
	}
	// ========================================
	else if ( db.driverName() == "QMYSQL") // --------- MYSQL
	{
		QSqlQuery query(db);

		if ( !query.exec("CREATE TABLE contatos ( "
										"con_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE, "
										"name VARCHAR(40) NOT NULL, "
										"UNIQUE (con_id), UNIQUE (name), PRIMARY KEY (con_id) ) ENGINE = InnoDB" ))
		{
			error = "Criando tabela contatos:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("CREATE TABLE cidades ( "
									"cid_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE, "
									"name VARCHAR(40) NOT NULL, "
									"UNIQUE (cid_id),  PRIMARY KEY (cid_id) ) ENGINE = InnoDB" ) )
		{
			error = "Criando tabela cidades:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("CREATE TABLE mov_tipo ( "
								"mt_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE, "
								"name VARCHAR(40) NOT NULL, "
								"UNIQUE (mt_id), UNIQUE (name), PRIMARY KEY (mt_id) ) ENGINE = InnoDB" ) )
		{
			error = "Criando tabela tipo de movimento:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("CREATE TABLE clientes ( "
								"cli_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE, "
								"name VARCHAR(40) NOT NULL, "
								"cidade_id BIGINT UNSIGNED NOT NULL, "
								"contato_id BIGINT UNSIGNED NOT NULL, "
								"UNIQUE (cli_id), PRIMARY KEY (cli_id), "
								"CONSTRAINT Relation_cid_cli Foreign Key (cidade_id) references cidades (cid_id) on delete  restrict on update  restrict, "
								 "CONSTRAINT Relation_con_cli Foreign Key (contato_id) references contatos (con_id) on delete  restrict on update  restrict "
							  ") ENGINE = InnoDB" ) )
		{
			error = "Criando tabela clientes:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("CREATE TABLE movimento ( "
							"mov_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE, "
							"cliente_id BIGINT UNSIGNED NOT NULL, "
							"tipo_id BIGINT UNSIGNED NOT NULL, "
							"mov_date DATE NOT NULL, "
							"description VARCHAR(40) NOT NULL, "
							"UNIQUE (mov_id), PRIMARY KEY (mov_id), "
							"CONSTRAINT Relation_cli_mov Foreign Key (cliente_id) references clientes (cli_id) on delete  restrict on update  restrict, "
							"CONSTRAINT Relation_movtipo_mov Foreign Key (tipo_id) references mov_tipo (mt_id) on delete  restrict on update  restrict "
							  ") ENGINE = InnoDB" ) )
		{
			error = "Criando tabela movimento:\n" + query.lastError().text();
			return false;
		}
	}
	// ========================================
	else if ( db.driverName() == "QOCI") // --------- ORACLE
	{
		QSqlQuery query(db);

		if ( !query.exec("Create table contatos ( con_id Number(24) NOT NULL , name Varchar2(40) NOT NULL  UNIQUE , "
											"Constraint pk_contatos primary key (con_id))"))
		{
			error = "Criando tabela contatos:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("Create table cidades ( cid_id Number(24) NOT NULL , name Varchar2(40) NOT NULL , "
											"Constraint pk_cidades primary key (cid_id))"))
		{
			error = "Criando tabela cidades:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("Create table mov_tipo (mt_id Number(24) NOT NULL , name Varchar2(40) NOT NULL  UNIQUE , "
											"Constraint pk_mov_tipo primary key (mt_id))") )
		{
			error = "Criando tabela tipo de movimento:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("Create table clientes ( cli_id Number(24) NOT NULL , name Varchar2(40) NOT NULL , "
											"cidade_id Number(24) NOT NULL , 	contato_id Number(24) NOT NULL , "
											"Constraint pk_clientes primary key (cli_id))" ) )
		{
			error = "Criando tabela clientes:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("Create table movimento ( mov_id Number(24) NOT NULL  , cliente_id Number(24) NOT NULL , "
											"tipo_id Number(24) NOT NULL , mov_date Date NOT NULL , 	description Varchar2(40) NOT NULL , "
											"Constraint pk_movimento primary key (mov_id))" ) )
		{
			error = "Criando tabela movimento:\n" + query.lastError().text();
			return false;
		}


		if ( !query.exec("Create Index IX_Relation_con_cli ON clientes (contato_id)" ))
		{
			error = "Criando indice clientes/contatos:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("Create Index IX_Relation_cid_cli ON clientes (cidade_id)" ))
		{
			error = "Criando indice clientes/cidades:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("Create Index IX_Relation_cli_mov ON movimento (cliente_id)" ))
		{
			error = "Criando indice movimento/clientes:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("Create Index IX_Relation_movtipo_mov ON movimento (tipo_id)" ) )
		{
			error = "Criando indice movimento/tipo:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("Alter table clientes add Constraint Relation_con_cli foreign key (contato_id) references contatos (con_id)" ))
		{
			error = "Criando relacionamento clientes/contatos:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("Alter table clientes add Constraint Relation_cid_cli foreign key (cidade_id) references cidades (cid_id)" ) )
		{
			error = "Criando relacionamento clientes/cidades:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("Alter table movimento add Constraint Relation_cli_mov foreign key (cliente_id) references clientes (cli_id)" ))
		{
			error = "Criando relacionamento movimento/clientes:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("Alter table movimento add Constraint Relation_movtipo_mov foreign key (tipo_id) references mov_tipo (mt_id)" ) )
		{
			error = "Criando relacionamento movimento/tipos:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("CREATE SEQUENCE clientes_cli_id_seq  	increment by 1 start with 1 nocycle nocache" ) )
		{
			error = "Criando sequencia clientes:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE SEQUENCE movimento_mov_id_seq increment by 1 start with 1 nocycle nocache") )
		{
			error = "Criando sequencia movimento:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE SEQUENCE contatos_con_id_seq increment by 1 start with 1 nocycle nocache" ) )
		{
			error = "Criando sequencia contatos:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE SEQUENCE cidades_cid_id_seq  increment by 1 start with 1 nocycle nocache") )
		{
			error = "Criando sequencia cidades:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE SEQUENCE mov_tipo_mt_id_seq increment by 1 start with 1 nocycle nocache"))
		{
			error = "Criando sequencia tipos de movimento:\n" + query.lastError().text();
			return false;
		}

		if ( !query.exec("CREATE OR REPLACE TRIGGER inc_clientes_trig BEFORE INSERT ON clientes "
				"FOR EACH ROW BEGIN SELECT clientes_cli_id_seq.NEXTVAL into :new.cli_id FROM dual; END;") )
		{
			error = "Criando trigger clientes:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE OR REPLACE TRIGGER inc_movimento_trig BEFORE INSERT ON movimento "
				"FOR EACH ROW BEGIN SELECT movimento_mov_id_seq.NEXTVAL into :new.mov_id FROM dual; END;") )
		{
			error = "Criando trigger movimento:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE OR REPLACE TRIGGER inc_contatos_trig BEFORE INSERT ON contatos "
				"FOR EACH ROW BEGIN 	SELECT contatos_con_id_seq.NEXTVAL into :new.con_id FROM dual; END;") )
		{
			error = "Criando trigger contatos:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE OR REPLACE TRIGGER inc_cidades_trig BEFORE INSERT ON cidades "
				"FOR EACH ROW BEGIN SELECT cidades_cid_id_seq.NEXTVAL into :new.cid_id FROM dual; END;") )
		{
			error = "Criando trigger cidades:\n" + query.lastError().text();
			return false;
		}
		if ( !query.exec("CREATE OR REPLACE TRIGGER inc_movtipo_trig BEFORE INSERT ON mov_tipo "
				"FOR EACH ROW BEGIN SELECT mov_tipo_mt_id_seq.NEXTVAL into :new.mt_id FROM dual; END;" ) )
		{
			error = "Criando trigger tipos de movimento:\n" + query.lastError().text();
			return false;
		}
	}
	// ========================================
	else //  === algo errado em 'main': um driver não esperado
	{
		error = "Driver não suportado por esta aplicação";
		return false;
	}

	// ======= Código COMUM para TODOS os drivers
	//                  (as queries abaixo não dependem do driver):

	QSqlQuery query(db);

	// === alimenta a tabela cidades com dados:
	int cidades = 0;
	// "exec" return true(1) ou false(0):
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('São Paulo')", cidades, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('Porto Alegre')" , cidades, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('Campinas')" , cidades, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('Rio de Janeiro')" , cidades, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('Curitiba')" , cidades, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('Salvador')" , cidades, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO cidades (name) VALUES ('Belo Horizonte')" , cidades, error ) )
		return false;

	qDebug() << "Cidades inseridas " << cidades;

	// === alimenta a tabela contatos com dados:
	int contatos = 0;
	// "exec" return true(1) ou false(0):
	if ( ! query_exec_( query, "INSERT INTO contatos (name) VALUES ('Julio Juliano')" , contatos, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO contatos (name) VALUES ('Alberto Berto')" , contatos, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO contatos (name) VALUES ('Maria Mariana')" , contatos, error ) )
		return false;

	qDebug() << "Contatos inseridos " << contatos;

	// === alimenta a tabela tipo de movimento com dados:
	int mov_tipos = 0;
	// "exec" return true(1) ou false(0):
	if ( ! query_exec_( query, "INSERT INTO mov_tipo (name) VALUES ('Consultoria')" , mov_tipos, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO mov_tipo (name) VALUES ('Treinamento')" , mov_tipos, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO mov_tipo (name) VALUES ('Desenvolvimento')" , mov_tipos, error ) )
		return false;
	if ( ! query_exec_( query, "INSERT INTO mov_tipo (name) VALUES ('Apoio a Desenvolvimento')" , mov_tipos, error ) )
		return false;

	qDebug() << "Tipos de movimento inseridos " << mov_tipos;


	// ==== *** alimenta a tabela de clientes com "PREPARE"  no estilo ORACLE:

	// Preenche uma lista de nomes de clientes,
	// para depois mostrar o exemplo de "Query Preparada":
	QStringList names;
	names	<< "Parafusos, Porcas e Pregos LTDA"
			<< "Organizações Tabajara"
			<< "Pai & Filhos Corporation"
			<< "Serviços Aleatórios Inc"
			<< "Porta de Cadeia Advocacia"
			<< "Fazemos Qualquer Negócio SA"
			<< "Financeira Metralha Brothers"
			<< "Lucro Incerto SA";

	// simplesmente inicia preparando a query, sem executá-la ainda
	// o texto da query, para "VALUES", usa PARAMETROS NOMEADOS, no estilo ORACLE
	if ( !query.prepare("INSERT INTO clientes (name, cidade_id, contato_id) "
					  "VALUES (:name, :cidade_id, :contato_id)" ) )
	{
		error = "Falha ao preparar a query 'inserir em clientes':\n" + query.lastError().text();
		return false;
	}

	int clientes =0;
	std::srand(std::time(NULL));
	// agora irá executar a query, apenas passando os parametros necessários
	// para preencher o campo correspondente ao parametro:
	foreach (const QString & name, names) // percorre a lista de nomes preenchida acima
	{
		// relaciona cada parâmetro aos valores desejados:
		query.bindValue(":name", name);
		query.bindValue(":cidade_id", 1 + (std::rand() % cidades)); // define uma cidade aleatoriamente
		query.bindValue(":contato_id", 1 + (std::rand() % contatos)); // define um contato aleatoriamente

		if ( ! query.exec( ) ) // executa a query sem texto (já foi preparado)
		{
			error = "Falha ao inserir clientes:\n" + query.lastError().text();
			return false;
		}
		++clientes;
	}

	qDebug() << "Clientes inseridos " << clientes ;


	// ==== *** alimenta a tabela de movimentos usando PREPARE no estilo ODBC:

	// Esse é um estilo pobre (comparado com ORACLE) pois
	// os parametros são marcados com "?" sequencialmente
	// e sua alimentação terá que seguir a ordem sequencial correta
	// para preencher corretamente cada campo:

	// simplesmente inicia preparando a query, sem executá-la ainda
	// o texto da query, para "VALUES", usa PARAMETROS SEQUENCIAIS
	// marcados com "?", no estilo ODBC:

	if ( !query.prepare("INSERT INTO movimento (cliente_id, tipo_id, mov_date, description) "
					  "VALUES (?,?,?,?)" ) )
	{
		error = "Falha ao preparar a query 'inserir em movimento':\n" + query.lastError().text();
		return false;
	}

	const int cliente_sem_movimento = clientes/2; // um cliente não terá movimento

	int movimentos;
	int movimentos_not=0;
	const int totalMovimentos = 600;

	for ( movimentos = 0; movimentos <totalMovimentos; ++movimentos )
	{
		// ADICIONA cada parâmetro PELA ORDEM das "?" aos valores desejados.
		// Para isso, AO INVÉS de "bindValue" usa "addBindValue":

		int cliente_id = 1+(movimentos % clientes); // define um cliente aleatoriamente

		if ( cliente_id == cliente_sem_movimento) // deixa pelo menos um cliente sem movimento...
			++movimentos_not;
		else
		{
			query.addBindValue(cliente_id); // id do cliente
			query.addBindValue(1 + (std::rand() % mov_tipos)); // define um tipo de movimento aleatoriamente
			// define aleatoriamente a data do ultimo movimento (data de hoje menos uma quantidade qualquer de dias):
			query.addBindValue( QDate::currentDate().addDays( -(std::rand() % 365)));
			// coluna "description":
			query.addBindValue( QString("Movimento #%1").arg(movimentos));

			if ( !query.exec() )
			{
				error = "Falha ao inserir movimento:\n" + query.lastError().text();
				return false;
			}
		}
	}

	qDebug() << "Movimentos inseridos " << movimentos - movimentos_not ;

	qDebug() << "Tempo decorrido: " << time.elapsed();
	return true;
}
/*
 TEMPOS de criação dos bancos (em RELEASE building)

SQLITE 3:
// sem transaction
Tempo decorrido: 4157 ms:
// com transaction:
Tempo decorrido:  16 ms

POSTGRE 9.0:
// sem transaction:
Tempo decorrido:  547 ms
// com transaction:
Tempo decorrido:  344 ms

MYSQL 5.0:
// sem transaction:
Tempo decorrido:  859 ms
// com transaction:
Tempo decorrido:  718 ms

ORACLE 10.g EXPRESS (usado sem BEGIN/END e execBatch : menos performance):

// sem transaction:
Tempo decorrido:  844 ms
// com transaction:
Tempo decorrido:  468 ms
*/

 bool query_exec_(QSqlQuery & query, const QString & queryText, int & contador, QString & error )
{
	if ( query.exec(queryText) )
	{
		  ++contador;
		  return true;
	}
	else
	{
		  error = query.lastError().text();
		  return false;
	}
}

