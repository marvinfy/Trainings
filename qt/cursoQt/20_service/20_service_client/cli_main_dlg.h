#ifndef CLI_MAIN_DLG_H
#define CLI_MAIN_DLG_H

#include <QtGui/QDialog>
#include <QTcpSocket>

#include "ui_cli_main_dlg.h"

class cli_main_dlg : public QDialog
                        , private Ui::cli_main_dlgClass
{
    Q_OBJECT

public:
    cli_main_dlg(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~cli_main_dlg();
	
private slots:
	void on_btBegin_clicked() ;
	void on_btStop_clicked() ;
	void on_btCmd_clicked() ;
	
	 void clientRead();
	 void connectionClosed();
	 void someError();
	
private:
	QTcpSocket tcpSocket;

};

#endif // CLI_MAIN_DLG_H
