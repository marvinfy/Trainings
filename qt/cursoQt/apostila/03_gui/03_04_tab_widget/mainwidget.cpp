#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QStyleFactory>
#include <QMessageBox>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent), ui(new Ui::MainWidget)
	, nameOK(false)
	, mailOK(false)
{
	ui->setupUi(this);

	// o "tabWidget" deve começar sempre com a primeira aba selecionada
	// (pois, no QtDesigner, outra aba pode ter sido a última selecionada):
	ui->tabWidget->setCurrentIndex(0);

	// valores iniciais para a aba "parâmetros":
	ui->spNameMinLen->setValue( 3 ); // mínimo de 3 caracteres para nome
	ui->ckbMailArroba->setChecked(true); // e-mail deve conter arroba.

	// aba "estilos":
	// popula a comboBox da aba "Estilos" com os estilos disponíveis:
	ui->cbStyles->addItems(QStyleFactory::keys());
	// força o uso do estilo que esteja na primeira linha da comboBox:
	on_cbStyles_activated( ui->cbStyles->itemText(0) );
}

MainWidget::~MainWidget()
{
	delete ui;
}

// ==== ==== slots:

// ==== aba cadastro:

// nome em maíusculas:
void MainWidget::on_ckbUpperName_stateChanged()
{
	if (  ui->ckbUpperName->isChecked() )  // em maíusculas
		ui->edName->setText( ui->edName->text().toUpper()  );
}

// verifica/valida o nome:
void MainWidget::on_edName_textChanged()
{
	// valida o nome, habilitando/desabilitando o botão "Aceitar":
	if ( ui->edName->text().length() < ui->spNameMinLen->value()   ) // compara com o valor do spinBox de parâmetros
		nameOK = false; // erro: tamanho menor que minimo
	else
		nameOK = true; // tamanho ok;

	on_ckbUpperName_stateChanged(); // checa se o nome precisa ficar em maíusculas

	updateStatus();
}
// verifica/valida o e-mail:
void  MainWidget::on_edMail_textChanged()
{
	mailOK = true;
	// valida o e-mail, habilitando/desabilitando o botão "Aceitar":
	if ( ui->ckbMailArroba->isChecked() ) // verifica se a checkBox de parâmetros determina que o e-mail tem que conter '@'
	{
		int posArroba = ui->edMail->text().indexOf( '@' );
		// poderia continuar a busca para ver se existe mais que uma '@'...
		if ( posArroba < 1 || ui->edMail->text().length() < 3 ) // <- '1' -> deve haver ao menos um caracter antes da '@' e outro depois
			mailOK = false; // não contem '@', ou então ela é o primeiro caracter, ou então não há um caracter depois dela
	}
	updateStatus();
}
void MainWidget::on_okButton_clicked()
{
	QString result;
	result  = "Nome: " + ui->edName->text() + "\n";
	result += "Mail:  " + ui->edMail->text();
	QMessageBox::information( this, "Dados Aceitos",
							  result );
	close();
}

// ==== aba parametros:

// o parâmetro "tamanho mínimo do nome" foi alterado;
// altera o spinBox de "parâmetros" e força uma revalidação do nome em "cadastro";
// OBS: se o spinBox foi alterado esta função também será chamada
// pois o signal "valueChanged" do spinBox foi conectado ao slot "setText" deste lineEdit no QtDesigner
void MainWidget::on_edNameMinLen_textChanged()
{
	// altera o valor do spinBox
	ui->spNameMinLen->setValue( ui->edNameMinLen->text().toInt() );
	// força revalidacão do nome na aba "cadastro":
	on_edName_textChanged();
}
// o parâmetro "e-mail deve conter uma arroba" foi alterado:
// então força uma revalidacão do e-mail em "cadastro":
void MainWidget::on_ckbMailArroba_stateChanged ()
{
	// força revalidação do e-mail na aba "cadastro":
	on_edMail_textChanged();
}

// ==== aba estilos:

// solicitada mudança de estilo:
void MainWidget::on_cbStyles_activated(
								const QString & styleName)
{
	QStyle * style = QStyleFactory::create(styleName);
}

// ==== ==== funções auxiliares:

// - habilita/desabilita o botão "Aceitar"
// - escreve mensagem no label "Status"
void MainWidget::updateStatus()
{
	if ( nameOK && mailOK )
	{
		ui->okButton->setEnabled(true); // habilita botão "Aceitar"
		ui->statusLabel->setText("Dados aceitáveis.");
	}
	else
	{
		ui->okButton->setEnabled(false); // desabilita botão "Aceitar"

		QString status ;

		if ( !nameOK   )
			status = QString("Nome: mínimo de %1 caracteres").arg(  ui->spNameMinLen->value() );

		if ( !mailOK )
		{
			if ( !status.isEmpty() )
				status += '\n';

			status += "e-mail: deve conter arroba, com (no mínimo) um caractere antes e outro depois";
		}

		ui->statusLabel->setText( status );
	}
}



