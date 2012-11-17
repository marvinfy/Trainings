
#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QLayout>
#include <QMessageBox>

#include "MainDlg.h"

MainDlg::MainDlg(QWidget * pParent)
	: QDialog(pParent)
	, _m_bAccept( false )
{
	setWindowTitle( "Cadastro");

	_m_edNome = new QLineEdit;;
	QLabel *lbNome = new QLabel("Nome:");
	lbNome->setBuddy( _m_edNome );

	QHBoxLayout *hlay_1 = new QHBoxLayout ;
	hlay_1->addWidget( lbNome, 1);
	hlay_1->addWidget( _m_edNome, 6);
	hlay_1->addStretch( );

	QGroupBox * gbSexo = new QGroupBox (" Sexo: ");
	QVBoxLayout * vlaySexo = new QVBoxLayout;
	_m_rbFeminino  = new QRadioButton("Feminino");
	_m_rbMasculino = new QRadioButton("Masculino");
	vlaySexo->addWidget( _m_rbFeminino );
	vlaySexo->addWidget( _m_rbMasculino );
	gbSexo->setLayout( vlaySexo );

	_m_ckbEmail = new QCheckBox ("recebe e-mail");
	QLabel *lbUF = new QLabel("UF:");
	_m_cbUF = new QComboBox;
	QHBoxLayout * hlayUF = new QHBoxLayout;
	hlayUF->addWidget( lbUF);
	hlayUF->addWidget( _m_cbUF);
	hlayUF->addStretch();

	QVBoxLayout * vlayLeft = new QVBoxLayout;
	vlayLeft->addWidget( gbSexo );
	vlayLeft->addWidget( _m_ckbEmail );
	vlayLeft->addLayout ( hlayUF );

	QGroupBox *gbEstCiv = new QGroupBox (" Estado Civil: ");
	// também podemos usar QButtonGroup para agrupar os radiobuttons...
	QVBoxLayout * vlayEstCiv = new QVBoxLayout;
	_m_rbSolteiro	= new QRadioButton("Solteiro"	, gbEstCiv);
	_m_rbCasado		= new QRadioButton("Casado"		, gbEstCiv);
	_m_rbDivorciado = new QRadioButton("Divorciado"	, gbEstCiv);
	_m_rbViuvo		= new QRadioButton("Viuvo"		, gbEstCiv);
	vlayEstCiv->addWidget( _m_rbSolteiro);
	vlayEstCiv->addWidget( _m_rbCasado );
	vlayEstCiv->addWidget( _m_rbDivorciado);
	vlayEstCiv->addWidget( _m_rbViuvo);
	gbEstCiv->setLayout( vlayEstCiv );


	QHBoxLayout *hlay_2 = new QHBoxLayout ;
	hlay_2->addLayout( vlayLeft  , 2 );
	hlay_2->addWidget( gbEstCiv,2 );
	hlay_2->addStretch( 1 );

	_m_buttonBox = new QDialogButtonBox(
			QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	QVBoxLayout *vlayMain = new QVBoxLayout ;
	vlayMain->addLayout( hlay_1);
	vlayMain->addLayout( hlay_2);
	vlayMain->addWidget( _m_buttonBox );

	connect(_m_edNome, SIGNAL(textChanged(const QString &)),
			     this, SLOT  (_nomeChanged(const QString &)));

	connect(_m_buttonBox, SIGNAL(accepted()),
					  this, SLOT(_accept()));

	connect(_m_buttonBox, SIGNAL(rejected()),
					  this, SLOT(_reject()));

	// alimenta a ComboBox UF:
	_m_cbUF->addItem("SP");
	_m_cbUF->addItem("RJ");
	_m_cbUF->addItem("AM");
	_m_cbUF->addItem("MG");
	_m_cbUF->addItem("RS");

	// nenhuma string estará selecionada inicialmente (índice = -1):
	_m_cbUF->setCurrentIndex(-1);
	
	// força análise inicial do edit nome:
	_nomeChanged("");

	setLayout(vlayMain);

}

// texto do LineEdit "nome" foi modificado:
void MainDlg::_nomeChanged(const QString & text)
{
	bool bEmpty = text.isEmpty();
	
	QPushButton * btnOK = 
		_m_buttonBox->button( QDialogButtonBox::Ok );

	btnOK->setEnabled( !bEmpty );
}

// botão OK
void MainDlg::_accept()
{
	// lê o texto do nome:
	QString qstNome = _m_edNome->text();

	// checa radiobuttons do grupo "sexo"

	// (*** como não usamos objetos QButtonGroup, iremos analisar cada radioButton separadamente *** )

	QString qstSexo;
	if ( _m_rbFeminino->isChecked() )
		qstSexo = "Feminino";
	else if ( _m_rbMasculino->isChecked() )
		qstSexo = "Masculino";
	else
	{
		QMessageBox::warning( this, "Erro", "Sexo: precisa ser informado.");	
		return;
	}

	
	QString qstEstCiv;
	if ( _m_rbSolteiro->isChecked() )
		qstEstCiv = "Solteiro";
	else if ( _m_rbCasado->isChecked() )
		qstEstCiv = "Casado";
	else if ( _m_rbDivorciado->isChecked() )
		qstEstCiv = "Divorciado";
	else if ( _m_rbViuvo->isChecked() )
		qstEstCiv = "Viuvo";
	else
	{
		QMessageBox::warning( this, "Erro", "Estado Civil: precisa ser informado.");	
		return;
	}

	QString qstUF = _m_cbUF->currentText();
	if ( qstUF.isEmpty() )
	{
		QMessageBox::warning( this, "Erro", "UF: precisa ser informada.");	
		_m_cbUF->setFocus();
		return;
	}

	QString qstEmail;
	if ( _m_ckbEmail->isChecked() )
		qstEmail = "Sim";
	else 
		qstEmail = "Nao";
	
	QString msg = "Cadastro foi confirmado:\n";
	msg += "\nNome\t=\t" + qstNome;
	msg += "\nSexo\t=\t" + qstSexo;
	msg += "\nEst.Civ\t=\t" + qstEstCiv;
	msg += "\nEmail\t=\t" + qstEmail;
	msg += "\nUF\t=\t" + qstUF;

	QMessageBox::information( this, "Confirmando", msg);	
	_m_bAccept = true;
	close();
}

// botão Cancel
void MainDlg::_reject()
{
	close();
}

// evento close:
void MainDlg::closeEvent( QCloseEvent * event )
{

	if ( !_m_bAccept)
	{
		if ( QMessageBox::question(this, "Close",  // título da message box
					"Deseja realmente sair?",    // texto da message box
					QMessageBox::Yes | QMessageBox::No) // botões
			!= QMessageBox::Yes )
		{
			event->setAccepted(false); // não fecha janela
			return;
		}
	}	
	event->setAccepted(true); // fecha janela
}
