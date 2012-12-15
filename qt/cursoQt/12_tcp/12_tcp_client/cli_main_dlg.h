#ifndef CLI_MAIN_DLG_H
#define CLI_MAIN_DLG_H

#include <QtGui/QDialog>
#include <QTcpSocket>

#include <TcpDataProtocol.h> // <- protocolo de aplicação para troca de dados

#include "ui_cli_main_dlg.h"

class cli_main_dlg : public QDialog
								, private Ui::cli_main_dlgClass
{
    Q_OBJECT

public:
    cli_main_dlg(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~cli_main_dlg();
	
private slots:

	 // == slots adicionados via "go to Slot" (respostas ao click nos botões):

	 void on_startButton_clicked() ;
	void on_stopButton_clicked() ;
	void on_sendRequestButton_clicked() ;

	// == slots adicionados manualmente no código:
	
	// O signal 'connected' é emitido por QTcpSocket quando a conexão é estabelecida
	// isso permitiria aguardar a conexão assincronamente...
	 void sendRequest(); // <- e este slot será conectado a esse signal.

	 // O signal  'readyRead' é emitido quando há dados disponíveis para leitura...
	 void clientRead(); // <- e este slot será conectado a esse signal.

	 void connectionClosed(); // slot para o signal 'disconnected' (conexão encerrou)
	 void errorOccurred(); // slot para o signal 'error'
	
private:
	 // objeto 'QTcpSocket': estabelecerá a conexão TCP ao server e cuidará do intercâmbio de dados:
	QTcpSocket m_tcpSocket;
	TcpDataProtocol::requestSizeType m_nextBlockSize;
};

#endif // CLI_MAIN_DLG_H
