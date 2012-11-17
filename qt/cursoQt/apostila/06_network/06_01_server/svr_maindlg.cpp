#include "svr_maindlg.h"
#include <QtGui>
#include <iostream>

// ======== classe da janela principal (derivada de QWidget):

svr_mainDlg::svr_mainDlg(QWidget *parent, Qt::WFlags flags)
    : QWidget(parent, flags)
{
    setupUi(this);

	stopButton->setEnabled( false ); // desabilita o 'stop' pois ainda não inciiou...
	portEdit->setText("6666"); // valor default para o número de porta TCP

	// Conecta o signal do TcpServer que envia novas mensagens de log
	// ao slot apropriado deste objeto.
	// Esse signal poderá ser emitido originalmente por um objeto "TcpDataExchangeSocket"
	// e, se isso ocorrer, o objeto TcpServer também emitirá o mesmo signal,
	// pois o signal de "TcpDataExchangeSocket" foi conectado ao signal do TcpServer.
	// Além disso, o próprio objeto TcpServer poderá também enviar suas
	// próprias mensagens de 'log' (emitindo o signal diretamente).
	connect( &tcpServ, SIGNAL(logMessage(const QString  &)) ,
						this, SLOT(newLogMessage(const QString &)));
}
svr_mainDlg::~svr_mainDlg()
{

}

// slot para o signal 'click' do botão 'startButton';
// INICIAR aqui a espera de conexões:
void svr_mainDlg::on_startButton_clicked()
{
	// recupera a porta:
	quint16 nPort = portEdit->text ().toUShort();

	// Inicia a espera de conexões a partir de qualquer IP deste host (ou seja, qualquer de suas placas de rede)
	// o que e indicado por 'QHostAddress::Any'.
	// A espera de conexões será feita na porta especificada por 'nPort':
	if ( tcpServ.listen ( QHostAddress::Any,  nPort ) )
	{
		// OK. Espera por conexões iniciada com sucesso.
		// Então, desabilitar o botão 'startButton' e habilitar o botão 'stopButton':
		startButton->setEnabled( false );
		stopButton->setEnabled ( true );
	}
	else
		QMessageBox::information(this, "Tcp Server", 
										"Falha ao iniciar o server" );
						
}

// slot para o signal 'click' do botão 'stopButton';
// ENCERRAR aqui a espera de conexões:
void svr_mainDlg::on_stopButton_clicked()
{
	  // como vai encerrar, habilita o botão 'startButton' e desabilita o botão  'stopButton':
		startButton->setEnabled( true );
		stopButton->setEnabled ( false );

		// para de receber novas conexões:
		tcpServ.close();

		// Interrompe comunicação com os clientes que já estejam conectados
		// sabendo-se que cada cliente é atendido por um objeto "QTcpSocket" específico
		// que, neste exemplo, é implementado com a derivada "TcpDataExchangeSocket":
		foreach ( QObject * obj , tcpServ.children())
		{
				TcpDataExchangeSocket * sock = qobject_cast<TcpDataExchangeSocket *>(obj);
				if ( sock )
					sock->close(); // interrompe comunicação com este cliente.
		}
}

// recebeu uma nova mensagem de log:
void svr_mainDlg::newLogMessage(const QString & msg)
{
	// adiciona a mensagem no QWidgetList:
	messagesList->addItem( new QListWidgetItem(msg));
	// seleciona a linha adicionada:
	messagesList->setCurrentRow( messagesList->count()-1);
}
