#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QMdiSubWindow>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

#include "form1.h"
#include "form2.h"
#include "webbrowser.h"
#include "aboutdlg.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	// inicializa com zero os ponteiros para as duas "subwindows"
	// que só devem ter uma instância em execução:
	, m_subwinForm1(0)
	, m_subwinForm2(0)
{
	ui->setupUi(this);

	QDesktopWidget * desk = qApp->desktop();

	int w = desk->width(); // largura disponível no desktop
	int h = desk->height(); // altura, idem

	int mw_w = int ( w *0.8) ; // largura: 80% do desktop
	int mw_h  = int ( h * 0.7); // altura: 70%

	// centralizar horizontalmente:
	int mw_x = int ( w * 0.1 );  // x: 10% do desktop
				// logo teremos 10% à esquerda, 80% do widget
				// sobrando 10% à direita: centralizou.

	// verticalmente: ao invés de centralizar,
	// vou me aproximar do topo:
	int mw_y = int ( h * 0.05 );

	// define posição "x,y"(canto esquerdo superior)
	// e dimensões(altura, largura) iniciais:
	setGeometry(mw_x, mw_y, mw_w, mw_h );
	// define tamanho mínimo: 60% do inicial:
	setMinimumSize( int(mw_w*0.6), int(mw_h*0.6) );

	// Irá acrescentar aqui um "label" e uma "comboBox" à "toolbar"
	// (não conseguimos fazer isso no QtDesigner):
	QLabel * labelCombo = new QLabel(" Visualização: ");
	QComboBox * comboViewMode = new QComboBox;

	// adiciona itens à comboBox:
	comboViewMode->addItem("Abas (triangulares)");
	comboViewMode->addItem("Abas (retangulares)");
	comboViewMode->addItem("Cascata");
	comboViewMode->addItem("Telhas");

	// agora, adiciona um "separator",
	// o label e a comboBox na toolBar:
	ui->mainToolBar->addSeparator();
	ui->mainToolBar->addWidget( labelCombo );
	ui->mainToolBar->addWidget(comboViewMode);

	// signal "activated" da comboBox:
	// ao contrário do signal "currentIndexChanged",
	// este signal é emitido sempre que um item da comboBox
	// é selecionado (mesmo que o índice não tenha sido alterado):
	connect( comboViewMode, SIGNAL(activated(int)),
				 this, SLOT(selectViewMode(int)) );
	// e o slot "selectViewMode" será chamado sempre que uma linha da comboBox
	// for pressionada, mesmo que já seja a linha atual.

	// força seleção inicial do modo de visualizacão
	// usando a primeira linha da comboBox:
	selectViewMode(0);
}

MainWindow::~MainWindow()
{
	delete ui;
}

// slot conectado ao signal "triggered" da action "actionForm1"
// - irá criar nova instância do widget "Form1" e sua respectiva "subWindow":
void MainWindow::on_actionForm1_triggered()
{
	// Para "Form1" admitimos apenas uma instância em execução.
	// Então, sua "subWindow" será criada apenas se não houver uma instância já em execução:

	if ( !m_subwinForm1 ) // ... se não está instanciada...
	{
		// Cria nova instância de "Form1" ("new Form1")
		// que sera o "internal widget" da nova instancia de "m_subWinForm1":
		m_subwinForm1 = createSubWindow_( new Form1 );

		// Conecta o signal "destroyed" desta subWindow(chamado pela destrutora da base QObject)
		// ao slot "subWinForm1Destroyed" da "mainWindow";
		// com isso saberemos que a instância atual de "Form1" será destruída logo em seguida:
		connect(m_subwinForm1, SIGNAL(destroyed()),
					this, SLOT(subWinForm1Destroyed()) );

		// Irá conectar um signal de "Form1" a um slot de "Form2":
		connectForm1ToForm2_();
	}

	// Exibir essa subWindow, conforme a necessidade:
	showSubWindow_(m_subwinForm1);

	// Coloca essa "subWindow" no primeiro plano da mdiArea:
	ui->mdiArea->setActiveSubWindow(m_subwinForm1);
}

// slot conectado ao signal "triggered" da action "actionForm2"
// - irá criar nova instância do widget "Form2" e sua respectiva "subWindow":
void MainWindow::on_actionForm2_triggered()
{
	// Para "Form2" admitimos apenas uma instância em execução.
	// Então, sua "subWindow" será criada apenas se não houver uma instância já em execução:

	if ( !m_subwinForm2 ) // ... se não está instanciada ...
	{
		// Cria nova instância de "Form2" ("new Form2")
		// que sera o "internal widget" da nova instancia de "m_subWinForm2":
		m_subwinForm2 = createSubWindow_( new Form2 );

		// Conecta o signal "destroyed" desta subWindow(chamado pela destrutora da base QObject)
		// ao slot "subWinForm2Destroyed" da "mainWindow";
		// com isso saberemos que a instância atual de "Form2" será destruída logo em seguida:
		connect(m_subwinForm2, SIGNAL(destroyed()),
					this, SLOT(subWinForm2Destroyed()) );

		// Irá conectar um signal de "Form1" a um slot de "Form2":
		connectForm1ToForm2_();
	}

	// Exibir essa "subWindow", conforme a necessidade:
	showSubWindow_(m_subwinForm2);

	// Coloca essa "subWindow" no primeiro plano da mdiArea:
	ui->mdiArea->setActiveSubWindow(m_subwinForm2);
}

// slot conectado ao signal "triggered" da action "actionBrowser"
// - irá criar nova instância do widget "WebBrowser" e sua respectiva "subWindow":
void MainWindow::on_actionBrowser_triggered()
{
	// Para "WebBrowser" admitimos múltiplas instâncias em execução.
	// Então, aqui sempre será criada uma nova instância de uma "subWindow"
	// (mesmo que já existam outras instâncias em execução).
	// Cada instância dessa subWindow receberá como seu "internal widget"
	// uma nova instancia do widget "WebBrowser" ("new WebBrowser"):
	QMdiSubWindow * browser = createSubWindow_( new WebBrowser);

	// Exibir essa "subWindow", conforme a necessidade:
	showSubWindow_(browser);

	// Coloca essa "subWindow" no primeiro plano da mdiArea:
	ui->mdiArea->setActiveSubWindow(browser);
}

// função auxiliar que cria nova instância de uma "subWindow",
// já definindo qual será o "internal widget" dessa "subWindow":
QMdiSubWindow * MainWindow::createSubWindow_( QWidget * internalWidget )
{
	//Uma nova instância de determinada "subWindow" é criada
	// e adicionada ao objeto "mdiArea".
	// E um determinado "widget" é passado aqui para que se torne
	// o "internal Widget" dessa "subWindow":
	QMdiSubWindow * subWin = ui->mdiArea->addSubWindow( internalWidget );

	// Atributo "DeleteOnClose": no evento "close" dessa "subWindow",
	// a instância do objeto "QMdiSubWindow" será liberada/destruída:
	subWin->setAttribute(Qt::WA_DeleteOnClose);

	return subWin; // retorna endereço da nova "subWindow"
}

// função auxiliar que exibe cada uma das subWindows:
void MainWindow::showSubWindow_( QMdiSubWindow * subWin )
{
	// checa se a "subWindow" está minimizada
	// ou se ainda não foi exibida:

	if ( ui->mdiArea->viewMode() == QMdiArea::SubWindowView && subWin->isMinimized())
		subWin->showNormal(); // restaura se estiver minimizada
	else if ( !subWin->isVisible() )
		subWin->show(); // exibe (se não está visível é porque foi criada agora);
}

// função auxiliar que irá conectar um signal de "Form1" a um slot de "Form2":
void MainWindow::connectForm1ToForm2_()
{
	// Checa se as duas "subWindows" desses dois "forms" já foram instanciadas:
	if ( m_subwinForm1 && m_subwinForm2 )
	{
		// Recupera os objetos "Form"
		// que são os "internal widget" de cada subWindow:
		Form1 * form1 = static_cast<Form1*>(m_subwinForm1->widget() );
		Form2 * form2 = static_cast<Form2*>(m_subwinForm2->widget() );

		// Conecta o signal "editTextChanged" do "form1"
		// ao slot "externText" do "form2"
		// (ver form1.h/form1.cpp e form2.h/form2.cpp).
		// Nesse signal, o "form1" envia o texto do seu "lineEdit"
		// e o "form2", no slot, adiciona esse texto em sua "comboBox":
		connect( form1, SIGNAL(editTextChanged(QString)),
					   form2, SLOT(externText(QString)) );
	}
}

// slot conectado ao signal "activated" da comboBox
// - permite a seleção do modo de visualização:
void MainWindow::selectViewMode(int index)
{
	if ( index > 1 ) // irá usar subWindows (e não abas)
	{
		// então, antes de modificar modo de exibição,
		// checa se há alguma "subWindow" minimizada:
		QList<QMdiSubWindow*> subWindows = ui->mdiArea->subWindowList();
		foreach ( QMdiSubWindow* subWin, subWindows )
			showSubWindow_(subWin); // se estiver minimizada, será restaurada
	}

	switch ( index )
	{
		case 0: // abas triangulares
			ui->mdiArea->setViewMode(QMdiArea::TabbedView);
			ui->mdiArea->setTabShape(QTabWidget::Triangular);
			break;

		case 1: // abas retangulares com cantos arredondados
			ui->mdiArea->setViewMode(QMdiArea::TabbedView);
			ui->mdiArea->setTabShape(QTabWidget::Rounded);
			break;

		case 2: // cascata
			ui->mdiArea->setViewMode(QMdiArea::SubWindowView);
			ui->mdiArea->cascadeSubWindows();
			break;

		case 3: // telhas
			ui->mdiArea->setViewMode(QMdiArea::SubWindowView);
			ui->mdiArea->tileSubWindows();
			break;
	}

	// Se tiver mudado o "viewMode" de "subWindows" para "abas",
	// a janela ativa irá apresentar a action "restore" no menu de contexto.
	// Pois, como já está ativa, o slot "subWindowActivated" não será chamado;
	// então, forçamos aqui que o "restore" seja desabilitado
	// (ATENÇÃO: ver, abaixo, comentário sobre a "Bug Tracker" de Qt)
	on_mdiArea_subWindowActivated( ui->mdiArea->activeSubWindow()); // desabilitar a action "restore"
}

// Abaixo:
// slot para o signal "subWindowActivated";
// quando uma subWindow é ativada, caso o "viewMode" seja "abas",
// podemos desabilitar a opção "restore" do menu de contexto.
// ==========================================================================
// ATENÇÃO: PROVAVELMENTE isto será desnecessário em próximas versões de Qt.
// Ver a entrada sobre esse tópico na "Bug Tracker" de Qt em:
// http://qt.nokia.com/developer/task-tracker/index_html?method=entry&id=211669
// Entrada: 211669 - Restoring a QMdiSubWindow when QMdiArea viewMode is QMdiArea::TabbedView
// Status atual:
// 2008-05-15 19:50 - Entry created: Task status changed to 'Open', Resolution set to 'Pending', Version found set to '4.4.0', Version for fix set to 'Not scheduled', Priority changed to 'No Priority'
// 2008-05-19 10:24 - Version for fix set to 'Some future release'
// 2008-05-19 10:24 - Priority changed to '3'
// ==========================================================================


void MainWindow::on_mdiArea_subWindowActivated(QMdiSubWindow* subWin)
{
	// se está usando abas...
	if ( subWin && ui->mdiArea->viewMode() == QMdiArea::TabbedView )
	{
		// com abas, desabilitar a action "restore"

		// 1) Primeira alternativa (a mais simples):
		//    confiando no tradição, desabilitamos a primeira action da lista de actions
		//    (que *costuma ser* "Restore").
		//    *Hoje* isso funciona(sempre foi assim).

		if ( subWin->actions().size()> 0)
			subWin->actions().first()->setEnabled(false);

		// A primeira action *deve ser*(!) o restore...
		// Exceto se algo mudar no futuro,
		// OU SE modificarmos os "windowFlags" das subWindows
		// (dependendo da mudança feita, o menu de sistema pode ser alterado por decorrência)

		// 2) segunda alternativa: localizar a "action restore" pelo seu texto;
		//    Problema: a string "restore" deve ser obrigatoriamente traduzida
		//    caso se esteja usando dicionários (internacionalização).
		//    E a tradução de "restore" deve estar presente no(s) dicionário(s) para Qt, já que e uma string de Qt.
		//    e também no(s) dicionário(s) da aplicacão de forma idêntica:
		/*
			QList<QAction*> swActions = subWin->actions();
			foreach( QAction * swAction, swActions )
			{
				// usar "Rest" (ao invés de "Restore"): assim, esse método
				// pode funcionar para alguns idiomas sem tradução
				// - inglês, português, italiano, espanhol, francês, alemão...
				if ( swAction->text().indexOf( tr("Rest") ) >= 0 )
				{
					swAction->setEnabled(false);
					break;
				}
			}
		*/

		// 3) Terceira alternativa (mais elegante, MAIS SEGURA e... mais dispendiosa):
		//    percorrer a lista de actions como feito na segunda alternativa
		//    para descobrir qual aquela cujo *ícone* corresponde à action "restore":
		/*
			QList<QAction*> swActions = subWin->actions();
			foreach( QAction * swAction, swActions )
			{
				// podemos comparar o ícone da action com o ícone padrão "QStyle::SP_TitleBarNormalButton"
				// que é aquele usado na action "restore
				if ( swAction->icon().pixmap(32).toImage() ==
					 qApp->style()->standardIcon(QStyle::SP_TitleBarNormalButton).pixmap(32).toImage() )
				{
					swAction->setEnabled(false);
					break;
				}
				// *** o custo extra da alternativa acima está na conversão de QPixMap para QImage
			}
		*/

		// 4) Uma quarta alternativa: mais radical e que resolve o problema na raiz,
		//    ainda que se seja a mais onerosa de todas.
		//    Neste caso, alteramos o "systemMenu" de cada "subWindow" (com "setSystemMenu").
		//    Assim, teremos um "systemMenu" específico para os dois diferentes "viewModes"
		//	  Mas isso seria muito trabalhoso.

		// ====================================================================
		// OBS: Como a solução do problema em Qt JÁ ESTÁ AGENDADA
		//      (ainda que para 'Some future release')
		//      preferimos usar aqui a solução mais simples (primeira alternativa)
		//      (isto é, menos trabalhosa e também menos onerosa).
		// ====================================================================

	}
}


// slot para o signal "triggered" da action "actionAbout"
// - abre o diálogo modal "About"(Sobre):
void MainWindow::on_actionAbout_triggered()
{
	AboutDlg dlg(this);
	dlg.exec(); // o diálogo modal é aberto com "exec"
				// e, assim, enquanto não for fechado,
				// não poderemos dar foco em qualquer outra janela
				// da mesma aplicacão.
}

// slot conectado ao signal "triggered" da action "actionQuit"
// - irá chamar "close", gerando uma chamada a "closeEvent";
//   e, em "closeEvent", a MainWindow poderá ser fechada, caso o evento seja aceito.
//   Por default o evento é sempre aceito.
//   Mas, neste exemplo, redefinimos a virtual "closeEvent",
//   podendo aceitá-lo ou não (ver "closeEvent" mais abaixo).
void MainWindow::on_actionQuit_triggered()
{
	close();
}

//  closeEvent: quando a mainWindow recebe o evento "close"
//  podemos aceitá-lo ou não (por default ele é aceito):
void MainWindow::closeEvent(QCloseEvent * event)
{
	// Checa se há alguma "subWindow" aberta:
	if ( ui->mdiArea->subWindowList().size() > 0 )
	{
		QMessageBox::StandardButton result
				= QMessageBox::question(this, "Encerrar a aplicação",
					"Existem janelas abertas.\nEncerrar mesmo assim?",
					QMessageBox::Yes | QMessageBox::No );

		if ( result == QMessageBox::Yes )
			ui->mdiArea->closeAllSubWindows(); // Fecha todas as SubWindows. Em seguida, a MainWindow será fechada e a aplicação será encerrada.
		else
			event->ignore(); // Este evento deve ser IGNORADO: a MainWindow não será fechada.
	}
}
