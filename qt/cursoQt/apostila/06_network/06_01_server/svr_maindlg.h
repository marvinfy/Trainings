#ifndef SVR_MAINDLG_H
#define SVR_MAINDLG_H

#include <QtGui/QWidget>
#include <QProcess>

#include "ui_svr_maindlg.h"

#include "TcpConnectionServer.h" // <- classe derivada de QTcpServer: aguardar e aceitar conexões; proceder desconexões.

class svr_mainDlg : public QWidget
								  , private Ui::svr_mainDlgClass

{
    Q_OBJECT

public:
    svr_mainDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~svr_mainDlg();
	
private slots:

 // == acrescentados via "go to Slot":
	void on_startButton_clicked() ;
	void on_stopButton_clicked() ;

	//== acrescentados manualmente:
	void newLogMessage(const QString & msg);
	// esse slot servirá para receber mensagens de  'log' que serão enviadas
	// pelo TcpServer que emitirá um signal sempre que tiver algo a dizer.

private:

	// objeto da classe TcpConnectionServer (derivada de QTcpServer)
	// sua única função é aguardar conexões (ou encerrá-las):
	TcpConnectionServer tcpServ;

};

#endif // SVR_MAINDLG_H
