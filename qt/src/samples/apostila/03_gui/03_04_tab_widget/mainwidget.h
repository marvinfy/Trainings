#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtGui/QWidget>

namespace Ui
{
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

	bool nameOK;
	bool mailOK;

private slots:

	// ==== aba cadastro:
	void on_ckbUpperName_stateChanged();
	void on_edName_textChanged();
	void on_edMail_textChanged();
	void on_okButton_clicked();

	// ==== aba parametros:
	void on_edNameMinLen_textChanged( );
	void on_ckbMailArroba_stateChanged ( ) ;

	// ==== aba estilos:
	void on_cbStyles_activated(const QString & styleName) ;

	// ==== ==== funções auxiliares:
	void updateStatus();
};

#endif // MAINWIDGET_H
