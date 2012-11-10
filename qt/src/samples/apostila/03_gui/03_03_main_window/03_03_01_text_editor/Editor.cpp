#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>

#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QTextStream>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QComboBox>

#include <QMetaObject>

#include "Editor.h"

Editor::Editor(QWidget * pParent)
	: QMainWindow( pParent )
	, _m_bCloseWindow(false)
{

	QString curDir = QDir::currentPath();
	curDir.replace( "/debug", "/", Qt::CaseInsensitive);
	curDir.replace( "/release", "/", Qt::CaseInsensitive);
	if ( curDir.right(1)[0] != '/')
		curDir += "/";

	// ícone desta janela:
	setWindowIcon( QIcon( curDir+"editor.png") );
	setWindowTitle(tr("%1[*] - %2").arg(tr("sem título")).arg(tr("Text Editor")));

	// ==== cria o editor de texto:
	textEdit = new QTextEdit;

	// ==== cria o menu "File":
	fileMenu = menuBar()->addMenu(tr("&Arquivo"));

	// == menu: File New:
	QAction *actNew = fileMenu->addAction("&Novo");
	connect(actNew, SIGNAL(triggered()), 
			  this, SLOT  (_newFile()));

	actNew->setIcon ( QIcon ( curDir+"filenew.png" ) );

	// == menu: File Open:
	QAction * actOpen = fileMenu->addAction("&Abrir") ;
	connect(actOpen, SIGNAL(triggered()), 
			   this, SLOT  (_openFile()));

	actOpen->setIcon ( QIcon ( curDir+"fileopen.png" ) );

	// == menu: File Save:
	QAction * actSave = fileMenu->addAction("&Salvar");
	connect(actSave, SIGNAL(triggered()), 
			   this,   SLOT(_saveFile()));

	actSave->setIcon ( QIcon ( curDir+"filesave.png" ) );

	// == menu: File Save As:
	QAction * actSaveAs = fileMenu->addAction("Salvar &como...");
	connect(actSaveAs, SIGNAL(triggered()), 
			   this,   SLOT(_saveFileAs()));

	// separator:
	fileMenu->addSeparator();

	// == menu: File Print:
	QAction * actPrint = fileMenu->addAction("&Imprimir...");
	connect(actPrint, SIGNAL(triggered()), 
				this, SLOT  (_print()));

	actPrint->setIcon ( QIcon ( curDir+"fileprint.png" ) );

	// separator:
	fileMenu->addSeparator();

	// == menu: About Box:
	QAction * actAboutBox = fileMenu->addAction("So&bre...");
	connect(actAboutBox, SIGNAL(triggered()), 
				   this, SLOT  (_aboutbox()));
	actAboutBox->setIcon ( QIcon ( curDir+"about.png" ) );

	// == menu: About Qt:
	QAction * actAboutQt = fileMenu->addAction("Sobre &Qt...");
	connect(actAboutQt, SIGNAL(triggered()), 
				qApp,   SLOT(aboutQt()));

	actAboutQt->setIcon ( QIcon ( curDir+"qt.png" ) );

	// separator:
	fileMenu->addSeparator();

	// == menu: Quit:
	QAction * actQuit = fileMenu->addAction("Sai&r");
	connect(actQuit, SIGNAL(triggered()), 
			   this,   SLOT(_quit()));

	actQuit->setIcon ( QIcon ( curDir+"quit.png" ) );

	// ==== cria o menu "Edit":
	fileMenu = menuBar()->addMenu(tr("&Edit"));

	// == menu: Edit Undo:
	QAction *actUndo = fileMenu->addAction("&Desfazer");
	connect(actUndo, SIGNAL(triggered()), 
		   textEdit, SLOT  (undo()));

	actUndo->setIcon ( QIcon ( curDir+"editundo.png" ) );

	// == menu: Edit Redo:
	QAction *actRedo = fileMenu->addAction("&Restaurar");
	connect(actRedo, SIGNAL(triggered()), 
		   textEdit, SLOT  (redo()));

	actRedo->setIcon ( QIcon ( curDir+"editredo.png" ) );

	// ==== adiciona uma "toolbar":
	QToolBar * toolBar = new QToolBar;
	toolBar->setOrientation(Qt::Horizontal);
	addToolBar( toolBar );
	setIconSize( QSize(16,15) );

	toolBar->addAction(actNew);
	toolBar->addAction(actOpen);	
	toolBar->addAction(actSave);
	toolBar->addSeparator();
	toolBar->addAction(actPrint);
	toolBar->addSeparator();
	toolBar->addAction(actUndo);
	toolBar->addAction(actRedo);
	toolBar->addSeparator();
	toolBar->addAction(actAboutBox);
	toolBar->addAction(actAboutQt);
	toolBar->addSeparator();
	toolBar->addAction(actQuit);

	toolBar->addSeparator();

	QLabel * lbFont = new QLabel ( "Fonte", this );
	QComboBox * cbFont = new QComboBox(this);
	cbFont->addItem("Arial");
	cbFont->addItem("Times");
	cbFont->setObjectName("cbFont");

	toolBar->addWidget(lbFont);
	toolBar->addWidget(cbFont);

	actRedo->setEnabled(false);
	actUndo->setEnabled(false);

	connect(textEdit, SIGNAL(textChanged()), 
				this, SLOT  (_textChanged()));

	connect(textEdit, SIGNAL(undoAvailable(bool)), 
			actUndo, SLOT  (setEnabled(bool)));

	connect(textEdit, SIGNAL(redoAvailable(bool)), 
			actRedo, SLOT  (setEnabled(bool)));

	QStatusBar * pStatusBar = statusBar();
	connect( pStatusBar, SIGNAL( messageChanged(const QString &) ) ,
				   this, SLOT  ( _statusBarMsgChanged( const QString &) ) );
	
	// fará a conexão, por exemplo, do signal da combo 
	// ao slot on_cbFont_currentIndexChanged;
	// e o mesmo poderia ser usado para outros objetos.
	QMetaObject::connectSlotsByName(this);

	/*
		// a conexão abaixo não é mais necessária
		// devido a "connectSlotsByName"
		// --- será usado o slot  "on_cbFont_currentIndexChanged"

	connect( cbFont, SIGNAL( currentIndexChanged( int) ),
				this, SLOT( FontChanged (int) ) );
*/

	cbFont->setCurrentIndex ( -1 );
	cbFont->setCurrentIndex ( 0 );

	setCentralWidget( textEdit );

	_newFile(); // começa com um arquivo novo.
}

void Editor::_openFile()
{
	// checa se há algum documento modificado que precisa ser salvo:
	if ( ! _CanCloseNow() )
	{
		_statusMessage();
		return;
	}

	QString fileName = 
		QFileDialog::getOpenFileName(this,
					"Open", ".",
					"Text files (*.txt)");

	if (!fileName.isEmpty())
	{
		QFile file( fileName );
		if ( file.open(QIODevice::ReadWrite) )
		{
			QByteArray data = file.readAll();
			QString str = QString::fromLocal8Bit(data);
		    textEdit->setPlainText(str);
			_setCurrentFile( fileName );
		}
	}
	_statusMessage();
}
void Editor::_newFile()
{
	// checa se há algum documento modificado que precisa ser salvo:
	if ( _CanCloseNow() )
	{
		textEdit->setPlainText("");
		_setCurrentFile( "" );
	}
	_statusMessage();
}

void Editor::_saveFile()
{
	if ( _m_CurrentFileName.isEmpty() )
		_saveFileAs(); // precisa de um nome..,
	else
	{
		_save( _m_CurrentFileName );
		_statusMessage();
	}
}
void Editor::_saveFileAs()
{
	QString fileName = QFileDialog::getSaveFileName(this,
						"Save", ".", "Text files (*.txt)");
	
	if (!fileName.isEmpty() )
		_save(fileName);

	_statusMessage();
}
bool Editor::_save(const QString & PathAndFileName)
{
	QFile file( PathAndFileName );
	if ( file.open(QIODevice::WriteOnly) )
	{
		QString str = textEdit->toPlainText();
		QTextStream tout(&file);
		tout << str;
		_setCurrentFile( PathAndFileName );
		return true;
	}
	return false;
}
void Editor::_quit()
{
	// checa se há algum documento modificado que precisa ser salvo:
	if ( _CanCloseNow() )
		qApp->quit();
}


void Editor::closeEvent ( QCloseEvent * event )
{
	event->setAccepted( _CanCloseNow() );
}

// checa se há algum documento modificado que precisa ser salvo:
bool Editor::_CanCloseNow()
{
	if ( !textEdit->document()->isModified() )
		return true; // ok; documento não foi alterado ou já foi salvo.

	// o documento foi alterado;
	// perguntar ao usuário se ele quer salvar o documento:

	QMessageBox::StandardButton result;
	result = QMessageBox::warning(this, "Atenção",  // título da message box
					"O documento foi alterado.\nDeseja salvá-lo agora?",  // texto da message box
					QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel); // botões

	switch( result )
	{
		case QMessageBox::Yes :
			
			_saveFile();

			// mas o usuário pode ter cancelado o diálogo "save file":
			if ( textEdit->document()->isModified() ) // se o texto continua modificado
				break; // então o diálogo "save file" foi cancelado

			QMessageBox::information(this, 
						"Ok!",  "Documento foi salvo.");
			return true; // ok: o documento foi salvo


		case QMessageBox::No :
			QMessageBox::information(this, 									  
						"Ok:",  "Fechando o documento sem salvar.");
			return true; // o usuário não quer salvar o documento

		default: // botão "cancel"
			break;
	} 

	// botão "cancel" da message box foi pressionado
	// ou o diálogo "save file" foi cancelado
	QMessageBox::information(this, 
					"Ok!",  "Este documento não será fechado");

	return false; // o usuário desistiu de abandonar o documento
}

void Editor::_aboutbox()
{
	QMessageBox::about(this, "Text Editor", 
						"Text Editor\n\nversão 0.00.00.00...");
}

void Editor::_print()
{

	QPrinter printer;
	QPrintDialog printDlg(&printer, this);
	if (printDlg.exec() == QDialog::Accepted)
		textEdit->document()->print(&printer);	

}

void Editor::_textChanged()
{
	_statusMessage();
}

void Editor::_statusMessage()
{
	if (textEdit->document()->isModified() )
	{
		statusBar()->showMessage("***** MODIFICADO *****");
		setWindowModified(true);
	}
	else
	{
		statusBar()->showMessage("Pronto");
		setWindowModified(false);
	}
}

void Editor::_statusBarMsgChanged( const QString & msg )
{
	if ( msg.isEmpty() )
		_statusMessage();
}


void Editor::_setCurrentFile(const QString & PathAndFileName)
{
	_m_CurrentFileName = PathAndFileName;

	QString fileName;
	if (_m_CurrentFileName.isEmpty())
		fileName = tr("sem título.txt");
	else	
		fileName = QFileInfo(_m_CurrentFileName).fileName(); // nome do arquivo sem o "path"

	setWindowTitle(tr("%1[*] - %2").arg(fileName).arg(tr("Text Editor")));
	
	textEdit->document()->setModified(false);
	setWindowModified(false);
}

void Editor::on_cbFont_currentIndexChanged( int index)
{
	switch ( index )
	{
		case 0:
			textEdit->setFont ( QFont ( "Arial", 12) );
			break;
		case 1:
			textEdit->setFont ( QFont ( "Times", 12) );
			break;
	}
}

