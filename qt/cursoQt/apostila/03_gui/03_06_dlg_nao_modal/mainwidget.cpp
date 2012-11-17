#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPalette>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidgetClass)
{
    ui->setupUi(this);

	// ==== mudar cores de um Widget qualquer:
	QPalette pal;

	// configura uma MessageBox não-modal para testar cores
	// (e aproveita para testar algumas funcionalidades de QMessageBox):

	// acrescenta o flag "StaysOnTop" aos flags da MessageBox,
	// para que fique sempre no topo das demais janelas (sempre visivel)
	msgBox.setWindowFlags (
                        msgBox.windowFlags()
                        | Qt::Tool
                        | Qt::WindowStaysOnTopHint);

	// não será modal:
	msgBox.setModal(false);
	// tera apenas o botão "Close":
	msgBox.setStandardButtons( QMessageBox::Close );// botão close

	msgBox.setIcon ( QMessageBox::Information ); // ícone
	msgBox.setWindowTitle( "lineEdit"  ); // título

	// texto adicional (informativo):
	msgBox.setInformativeText(
			"... continue digitando normalmente...");

	// acrescenta opção para abrir uma caixa de detalhamento do texto da "MsgBox"
	msgBox.setDetailedText(
			"Esta MessageBox exibe o texto do 'lineEdit'");

	// muda cores da msgbox:

	// cor de fundo:
	pal.setColor( QPalette::Window,     QColor(Qt::yellow) );
	// cor do texto:
	pal.setColor( QPalette::WindowText, QColor(Qt::red) );
	// cor de fundo dos botões:
	pal.setColor( QPalette::Button,     QColor(0,0,223) );
	// cor do texto dos botões:
	pal.setColor( QPalette::ButtonText, QColor(0, 255, 255) );

	// deve preencher o fundo automaticamente
	// usando a cor correspondende da "Palette".
	// (do contrario, precisaríamos redefinir a virtual "PaintEvent"):
	msgBox.setAutoFillBackground(true);

	// modifica a "Palette" da MessageBox:
	msgBox.setPalette(pal);

	// posiciona o Widget principal nas coordenadas especificadas:
	move( 200, 300);
	msgBox.setMinimumWidth(400);

}
// === slot para o signal "textChanged" do"lineEdit":
void MainWidget::on_lineEdit_textChanged()
{
	// passa o texto do lineEdit para MessageBox:
	msgBox.setText( ui->lineEdit->text()  );
	// coloca a MessageBox no topo do desktop:
	msgBox.move( 0,0 );
	// exibe:
	msgBox.show(); // não-modal (ao contrário de "exec()" -> modal)
	activateWindow();
	QCoreApplication::processEvents();

	// força o foco no edit, para não interromper a digitação:
	ui->lineEdit->setFocus();
}

MainWidget::~MainWidget()
{
    delete ui;
}
