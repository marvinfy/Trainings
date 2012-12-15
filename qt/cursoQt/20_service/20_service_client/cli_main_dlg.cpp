#include "cli_main_dlg.h"
#include <QHostAddress>
#include <QMessageBox>

cli_main_dlg::cli_main_dlg(QWidget *parent, Qt::WFlags flags)
    : QDialog(parent, flags)
{
    setupUi(this);

	connect(&tcpSocket, SIGNAL(disconnected()),
				this, SLOT(connectionClosed()));

	connect(&tcpSocket, SIGNAL(readyRead()),
            this, SLOT(clientRead()));
	
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
				this, SLOT(someError()));

	edHost->setText( "localhost");
	edPort->setText("5555");

}
cli_main_dlg::~cli_main_dlg()
{
}
void cli_main_dlg::on_btBegin_clicked() 
{
	QString host = edHost->text();
	int nport = edPort->text().toInt();
	if ( host == "localhost" )
		tcpSocket.connectToHost
				(QHostAddress::LocalHost, nport );
	else
		tcpSocket.connectToHost(host, nport );
	
	btBegin->setEnabled(false);
  // tenta conectar
	if ( tcpSocket.waitForConnected( 3000 ) ) // 3 segundos
	{
		btStop->setEnabled(true);
		btCmd->setEnabled(true);
	}
	else
	{
		QMessageBox::critical( this , "tcpServer", "Falha na conexão");
		btBegin->setEnabled(true);	
	}
		
}
void cli_main_dlg::on_btStop_clicked() 
{
		btBegin->setEnabled(true);	
		btStop->setEnabled(false);
		btCmd->setEnabled(false);
		
		if ( tcpSocket.isOpen() )
			tcpSocket.close() ; // fecha conexão
}

void cli_main_dlg::on_btCmd_clicked() 
{
	QDataStream out (&tcpSocket);
	out << QString("GET DATE TIME");

}
void cli_main_dlg::clientRead()
{	
	QDataStream in(&tcpSocket);
	QString servReply;
	in >> servReply;

	QMessageBox::information( this, "client",
		QString ( "Resposta do server:\n" ) + servReply  );
}
void cli_main_dlg::connectionClosed()
{
	// o server pode desconectar este cliente...
	// e o botão "stop" tambem vai provocar esta ação...
	QMessageBox::warning( this, "client", "conexão encerrada");
	// habilitar/desabilitar botões:
	on_btStop_clicked() ;
}
void cli_main_dlg::someError()
{
	// recupera erro...

	 // ... tcpSocket.error();
	// ... tcpSocket.errorString();
}

	
