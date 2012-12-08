#include <QSettings>
#include "ftp.h"

// ====== construtor:

qt_test_ftp1::qt_test_ftp1() 
	: QObject(0) 
{
	// conecta os "signals" de QFtp que interessam neste exemplo;
	// eles nos informarão do andamento (e do sucesso) das operações:

	connect( &m_Ftp, SIGNAL( commandStarted (int)), 
			   this, SLOT  (on_ftp_commandStarted (int))); 

	connect( &m_Ftp, SIGNAL( commandFinished(int, bool)), 
			   this, SLOT  (on_ftp_commandFinished(int, bool))); 

	connect( &m_Ftp, SIGNAL(listInfo(const QUrlInfo &)), 
			   this , SLOT  (on_ftp_listInfo(const QUrlInfo &))); 
}

// ======= INICIA CONNECT / LOGIN:

void qt_test_ftp1::beginSession()
{
	QString qsHost;
	QString qsUserName;
	QString qsUserPass;

	// ***> altere o arquivo "ftp.conf" para testar.

	// pega configurações em "ftp.conf":
	QSettings settings("ftp.conf", QSettings::IniFormat);

	settings.beginGroup("ftp_info");
	qsHost = settings.value( "host" , "").toString();
	m_qsInitialDir = settings.value( "initial_dir", "" ).toString();
	qsUserName = settings.value( "user", "" ).toString();
	qsUserPass = settings.value( "password", "" ).toString();
	settings.endGroup();

	// Falta: avaliar sucesso das ações acima...
//	if ( qsHost.isEmpty() )
		// erro
	// o mesmo para as demais;

	m_bError = false;

	// se "connectToHost" falhar, "login" não será executada
	m_Ftp.connectToHost(qsHost); 
	m_Ftp.login( qsUserName, qsUserPass );
}

// =======  Recebe o SIGNAL "commandStarted":

void qt_test_ftp1::on_ftp_commandStarted (int /* id */)
{
	QFtp::Command Cmd = m_Ftp.currentCommand();
	switch ( Cmd )
	{
		case QFtp::ConnectToHost:
			std::cout << "*** AGUARDE: conectando ao servidor..." << std::endl;
			return;

		case QFtp::Login:
			std::cout << "*** Conectado... Autenticando o usuario..." << std::endl;
			return;

		case QFtp::Cd :
			std::cout << ("*** entrando no diretorio..." + m_qsInitialDir).toStdString() << std::endl;
			return;
	
		case QFtp::Mkdir :
			std::cout << ("*** criando diretorio..." + m_qsInitialDir).toStdString() << std::endl;
			return;

		case QFtp::List :
			std::cout << "*** recuperando lista de arquivos..." << std::endl;
			return;

		default:
			return;
	}
}

// =======  Recebe o SIGNAL "commandFinished":

void qt_test_ftp1::on_ftp_commandFinished(int /* id */, 
										  bool bError)
{ 
	m_bError = bError;
	
	switch ( m_Ftp.currentCommand() )
	{
		case QFtp::ConnectToHost: 
			endConnect( bError ); return;
			
		case QFtp::Login : 
			endLogin( bError );	return;
			
		case QFtp::Cd : 
			endCD( bError ); return;

		case QFtp::List: 
			endList(bError); return;

		case QFtp::Mkdir :
			endMkdir( bError ); return;

		case QFtp::Close :
			std::cout << "*** endSession" << std::endl;
			emit endSession(); // emite o "signal" "endSession"
			return;

		default: return;
	}
}

// ======== Recebe o SIGNAL listInfo

void qt_test_ftp1::on_ftp_listInfo(const QUrlInfo & urinfo )
{	
	// adiciona arquivo à lista:
	m_lsFiles.push_back ( urinfo.name().toStdString() );
}

// ======== FINALIZA Connect

void qt_test_ftp1::endConnect(bool bError)
{
	if ( bError )
	{
		std::cout << "--- conexao falhou" << std::endl;
		m_Ftp.abort(); m_Ftp.close();
	}
	else
		std::cout << "+++ conexao completou" << std::endl;
}

// ======== FINALIZA Login

void qt_test_ftp1::endLogin(bool bError)
{
	if ( bError )
	{
		std::cout << "--- login falhou" << std::endl;
		m_Ftp.abort(); m_Ftp.close();
	}
	else
	{
		std::cout << "+++ login completou" << std::endl;
	
		// === próxima ação:
		m_bCDFirstTry = true;
		m_Ftp.cd( m_qsInitialDir ); // tenta entrar no diretório
	}
}

// ======== FINALIZA CD 	

void qt_test_ftp1::endCD(bool bError)
{
	if ( bError )
	{
		std::cout << "--- CD falhou" << std::endl;

		if ( ! m_bCDFirstTry ) // se já tentou criar o diretório mas não conseguiu entrar
		{
			m_Ftp.abort(); m_Ftp.close();
			return; // nada feito
		}

		// tenta criar o diretório
		m_bCDFirstTry = false;
		m_Ftp.mkdir( m_qsInitialDir	);
		// e se for bem sucedido, tenta novamente entrar nesse diretório:
		m_Ftp.cd ( m_qsInitialDir );
	}
	else
	{
		std::cout << "+++ CD completou" << std::endl;

		// === próxima ação: 
		m_lsFiles.clear();
		m_Ftp.list();  // recuperar lista de arquivos
	}
}

// ======== FINALIZA List

void qt_test_ftp1::endList(bool bError)
{
	if ( bError )
	{
		std::cout << "--- List falhou" << std::endl;
		m_Ftp.abort();
	}
	else
	{
		std::cout << "+++ List completou" << std::endl;
		
		// imprime lista de arquivos:
		if ( m_lsFiles.size() )
		{
			std::list< std::string >::iterator It;
			std::cout << "\t=== Lista de Arquivos" << std::endl;
			for ( It=m_lsFiles.begin(); It!=m_lsFiles.end(); ++It )
				std::cout << "\t\t" << It->c_str() << std::endl;
		}
		else
			std::cout << "\t===Lista de Arquivos vazia" << std::endl;
	}	

	m_Ftp.close(); // fim
}

// ======== FINALIZA Mkdir 
// neste exemplo, talvez nunca seja executada...

void qt_test_ftp1::endMkdir(bool bError)
{
	if ( bError )
	{
		std::cout << "--- Mkdir falhou" << std::endl;
		m_Ftp.abort(); m_Ftp.close();
	}
	else
		std::cout << "+++ Mkdir completou" << std::endl;
}

