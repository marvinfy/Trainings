
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>
#include <QTextCharFormat>
#include <QMessageBox>

#include "MainDlg.h"
MainDlg::MainDlg(QWidget * pParent)
	: QDialog(pParent)
{
	setWindowTitle( "Busca Palavras");
	label = new QLabel( "&Palavras a realçar:" );
	
	_m_LineEdit = new QLineEdit;
	label->setBuddy(_m_LineEdit);

	_m_TextEdit = new QTextEdit;
	_m_HighLighter = new _SyntaxHighlighter( _m_TextEdit->document() );
	_m_HighLighter->_m_pDlg = this;
	
	_m_ckbCaseSens=new QCheckBox( "&Diferenciar maiúsculas de minúsculas" );
	
	btnFind= new QPushButton("&Buscar");
	btnFind->setDefault(true);
	btnFind->setEnabled(false);
	
	QPushButton * btnClose  = new QPushButton("&Sair");

	connect(_m_LineEdit, SIGNAL(textChanged(const QString &)),
					  this, SLOT(_enableFindBtn(const QString &)));

	connect(btnFind, SIGNAL(clicked()),
					  this, SLOT(_findBtnClicked()));

	connect(_m_ckbCaseSens, SIGNAL(clicked()),
					  this, SLOT(_findBtnClicked()));

	connect(btnClose, SIGNAL(clicked()),
					  this, SLOT(close()));

	QHBoxLayout * hlayBuscar= new QHBoxLayout;
	hlayBuscar->addWidget(label   ,1);
	hlayBuscar->addWidget(_m_LineEdit,6);
	hlayBuscar->addWidget(btnFind, 1);

	QHBoxLayout * hlayBottom= new QHBoxLayout;
	hlayBottom->addStretch();
	hlayBottom->addWidget(btnClose);
	hlayBottom->addStretch();
	
	QVBoxLayout * vlayMain = new QVBoxLayout;
	vlayMain->addWidget(_m_ckbCaseSens);
	vlayMain->addLayout( hlayBuscar);
	vlayMain->addWidget(_m_TextEdit);
	vlayMain->addLayout( hlayBottom);

	setLayout(vlayMain);

	// força a definição da largura e altura da janela:
	resize(500, 300);

	_m_LineEdit->setText("SyntaxHighlighter reservadas int double char short long");	
	_m_TextEdit->setText("As palavras relacionadas acima, serão realçadas aqui('SyntaxHighlighter').\nPor exemplo, palavras reservadas de uma linguagem, como int, double, char, short ou long.\n\nSe 'case sensitive', INT, SHORT ou DOUBLE, por exemplo, não seriam realçadas.\n\n\nPARA NOVOS TESTES, MUDE AS PALAVRAS ACIMA E/OU MUDE ESTE TEXTO.");
}

void MainDlg::_enableFindBtn(const QString & text)
{
	bool bEmpty = text.isEmpty();

	btnFind->setEnabled( !bEmpty );
	
	if ( bEmpty ) // retira o realce da última palavra que foi apagada no LineEdit
		_m_HighLighter->rehighlight();
}

void MainDlg::_findBtnClicked()
{
	_m_HighLighter->rehighlight();
}

// virtual da base redefinida:
void _SyntaxHighlighter::highlightBlock(const QString & textToLighter)
{
	// elimina brancos no início e no fim:
	QString wordsToLighter (_m_pDlg->_m_LineEdit->text().trimmed());

	_m_cs = _m_pDlg->_m_ckbCaseSens->isChecked()	
									? Qt::CaseSensitive
									: Qt::CaseInsensitive;
/*
	_m_WordsList.clear();

	// pega cada palavra do texto do LineEdit
	// e alimenta a StringList de palavras a realçar:
	
	int nEndPosition;
	int nIniPosition = wordsToLighter.length()> 0 ? 0 : -1; 
	while ( nIniPosition >= 0 )
	{		
		nEndPosition = wordsToLighter.indexOf(" ", nIniPosition);
		if ( nEndPosition > 0 )
		{
			_m_WordsList.push_back( wordsToLighter.mid(nIniPosition, nEndPosition-nIniPosition) );

			//@@ acrescentei:
			while ( wordsToLighter[nEndPosition+1]== ' ')
				++nEndPosition;
			//@@ <end>

			nIniPosition = nEndPosition + 1;
		}
		else
		{
			_m_WordsList.push_back( wordsToLighter.mid(nIniPosition ) );
			nIniPosition = nEndPosition;
		}
	}

*/
	// TODO O CÓDIGO COMENTADO ACIMA PODERIA SER SUBSTITUÍDO POR:
	_m_WordsList = wordsToLighter.split(' ', QString::SkipEmptyParts, _m_cs);

	QTextCharFormat wordFormat;

	wordFormat.setForeground(Qt::red);
	wordFormat.setFontWeight(QFont::Bold);

	/*
	QStringList::iterator it;
	for ( it = _m_WordsList.begin(); it!=_m_WordsList.end(); ++it)
	{
		QString str = *it;
		//...... // o mesmo trabalho feito no "foreach" abaixo.
	}
*/
	// simplifico o laço acima com "foreach":
	foreach( const QString & str,  _m_WordsList )
	{
		int nPosition = 0;
		while ( nPosition>=0 )
		{
			nPosition = textToLighter.indexOf( str, nPosition, _m_cs );
			if ( nPosition >= 0 )
			{
				setFormat( nPosition, str.length(), wordFormat );
				nPosition+=str.length();
			}
		}
	}
}

