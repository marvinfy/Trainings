
#include "printwidget.h"

#include <QPainter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QFont>
#include <QFontMetrics>
#include <QDebug>

PrintWidget::PrintWidget(QWidget * parent)
		: QWidget(parent)
		, m_outputType(Invalid)
{

	setAutoFillBackground(false);

	QStringList names;
	names << "Eabha Biddell" << "Prentice Hutchison"
		  << "Rameesha Davidge" << "Digby Roson" << "Nettah Newarch"
		  << "Lewisha Middleton" << "Ahmed Hanmer"
		  << "Jordyn-Leigh Lamant" << "Lindsay Bigham"
		  << "Kaylay Weir" << "Sofia Weir" << "Coel Spurlock"
		  << "Youcef Culpan" << "Lucy-Jasmine Blanchard"
		  << "Ally Hodgkin" << "Ara Collinge" << "Luka Dempster"
		  << "Samanta Winster" << "Keri Palin" << "Ruiridh Bisset"
		  << "Norman Epworth" << "Kezia Raw"
		  << "Kaylan-Thomas Swynford Sr." << "Kashaf Benning"
		  << "Norma Yair" << "Edan Bassett" << "Akshat Mcglasson"
		  << "Philippa Upton" << "Tylor Rockliff" << "Aqdas Buckman"
		  << "Briana Dowell" << "Querida North" << "Chelsay Botts"
		  << "Kishanth Calloway" << "Jan Covington"
		  << "Teighan Monson" << "Claudia Mendel" << "Kerra Doe"
		  << "Kara Depp" << "Harlie Soole" << "Viggo Streeter"
		  << "Ava Cofel" << "Catherine Balderston"
		  << "Brendan Gosnay" << "Zhaoyun Haygarth" << "Deri Pepler"
		  << "Vicki Hopwood" << "Amitra Bindless" << "Cerhys Hayton"
		  << "Gwendoline Westall"
		  << "Eabha Biddell" << "Prentice Hutchison"
		  << "Rameesha Davidge" << "Digby Roson" << "Nettah Newarch"
		  << "Lewisha Middleton" << "Ahmed Hanmer"
		  << "Jordyn-Leigh Lamant" << "Lindsay Bigham"
		  << "Kaylay Weir" << "Sofia Weir" << "Coel Spurlock"
		  << "Youcef Culpan" << "Lucy-Jasmine Blanchard"
		  << "Ally Hodgkin" << "Ara Collinge" << "Luka Dempster"
		  << "Samanta Winster" << "Keri Palin" << "Ruiridh Bisset"
		  << "Norman Epworth" << "Kezia Raw"
		  << "Kaylan-Thomas Swynford" << "Kashaf Benning"
		  << "Norma Yair" << "Edan Bassett" << "Akshat Mcglasson"
		  << "Philippa Upton" << "Tylor Rockliff" << "Aqdas Buckman"
		  << "Briana Dowell" << "Querida North" << "Chelsay Botts"
		  << "Kishanth Calloway" << "Jan Covington"
		  << "Teighan Monson" << "Claudia Mendel" << "Kerra Doe"
		  << "Kara Depp" << "Harlie Soole" << "Viggo Streeter"
		  << "Ava Cofel" << "Catherine Balderston"
		  << "Brendan Gosnay" << "Zhaoyun Haygarth" << "Deri Pepler"
		  << "Vicki Hopwood" << "Amitra Bindless" << "Cerhys Hayton"
		  << "Gwendoline Westall";

	int n=1;
	// cria um conjunto de dados com duas colunas (nome e número):
	foreach( const QString & name, names )
	{
		m_dataMap.insert( QString("%1-%2").arg(n, 3, 10, QChar('0')).arg(name),
						 QString("%1").arg( n, 12, 10, QChar('0') ) ) ;
		++n;
	}
				// obs:  alternativas quando "QString::arg" recebe um número:
				// arg(num); // apenas o número
				// ou, usando largura e caracter de preenchimento:
				// arg(num, width, base, fill );
				// no exemplo acima: num=n,  width=12, base=10, fill='0'


		// inicializa o objeto QPrinter:
	m_printer = new QPrinter( QPrinter::HighResolution );
	// ***** OBS: em Windows, poderá ocorrer um problema com a construtora de QPrinter:
	// caso a impressora-default, definida no SO, não esteja disponível:
	// EM MODO DEBUG a aplicação é interrompida por um "assert"(e não uma exception)
	// Já em MODO RELEASE a aplicacão rodará normalmente.

	show();

}
PrintWidget::~PrintWidget()
{
	delete m_printer;
}

void PrintWidget::printToSelectedPrinter()
{
	m_printer->setOutputFormat(QPrinter::NativeFormat);

	QPrintDialog printDlg(m_printer, this);
	if (printDlg.exec() == QDialog::Accepted)
	{
		// PRINTER: desenhar na impressora
		m_outputType = Printer;
		repaint();
	}
}
void PrintWidget::printToPdf()
{
// solicita um nome para o arquivo pdf a gravar:
	QString fileName = QFileDialog::getSaveFileName(this,
				"Informe o nome do arquivo para gravar o pdf",
				".", "Pdf files (*.pdf)");

	if (!fileName.isEmpty())
	{
		if ( fileName.right(4).toLower() != ".pdf" )
			fileName+=".pdf";

		// define formato e arquivo pdf
		m_printer->setOutputFormat(QPrinter::PdfFormat);
		m_printer->setOutputFileName(fileName);

		// PRINTER: desenhar na impressora (pdf)
		m_outputType = Printer;
		repaint(); // chama paintEvent direta e imediatamente

		// PRINTER: abrir JÁ o pdf:
		QDesktopServices::openUrl( QUrl("file:///" + fileName) );
	}
}
void PrintWidget::printToWidget()
{
	m_outputType = Widget;
	repaint();
}
// para imprimir relatorio no textEdit, na printer ou PDF:
void PrintWidget::paintEvent(QPaintEvent * event)
{
	if ( m_outputType == Invalid )
		return;

	QPainter paint;

	int leftMargin = 10;
	int topMargin = 10;

	QRectF rect; // retângulo para área-destino do desenho

	// checa se saída é a impressora ou o próprio Widget:
	int iniW, iniH;
	if ( m_outputType == Printer )
	{
		paint.begin(m_printer);
		rect=paint.viewport();  // destino é a viewPort de "Printer"
		iniW = int(rect.width());
		iniH = int(rect.height());

	}
	else
	{
		paint.begin(this);
		rect.setRect(0,0, this->width(), this->height()); // destino é a janela
		iniW = width();
		iniH = height() ;
	}


	// suavização de bordas e pixmaps:
	paint.setRenderHints( QPainter::Antialiasing
								| QPainter::TextAntialiasing
								| QPainter::SmoothPixmapTransform );


	QFont font;
	font.setFamily("Verdana");
	font.setBold(true);
	const int maxNameChars = 30 ; // máximo de caracteres para a coluna nome;
	const int maxNumChars  = 12;  // idem para a coluna número

	int wchar = maxNameChars+maxNumChars+leftMargin;
	font.setPixelSize(qMax(3, iniW/wchar) );
	qDebug() << wchar << iniW/wchar;

	// seta fonte:
	paint.setFont( font );


	// ==== tratar métrica do texto em função da fonte:

	// FontMetrics permite apurar altura e largura de linhas
	// em função da fonte em uso:
	QFontMetrics fm(font);

		// largura média em pixels para cada coluna, exceto a ultima
	int nameWidth = int( (fm.averageCharWidth()*maxNameChars)*1.25);

	// coordenadas das colunas:
	int nameX = leftMargin; // nome
	// número: após nome, com uma separacão correspondente a 3 caracteres
	int numX = nameX + nameWidth + (fm.averageCharWidth()*2) ;

	int yLine; // coordenada y (linha atual)
	if ( m_outputType == Printer )
		yLine = 99999; // linha atual (valor absurdo para forçar cabeçalho no início);
	else
		yLine=0;


	int page = 0;
	QMap<QString, QString>::iterator it;
	for ( it = m_dataMap.begin(); it!= m_dataMap.end(); ++it )
	{
		// cabeçalho (aqui poderia ter fonte diferente)
		if ( yLine + fm.lineSpacing() > iniH &&  m_outputType == Printer)
		{
			// salta de página se necessario:
			if ( page > 0 )
				m_printer->newPage();

			yLine=topMargin;
			++page;
			// imprime número da página:
			QString strNumPage = QString("Folha %1").arg(page);
			paint.drawText ( leftMargin , yLine,
											fm.width(strNumPage), fm.height(),
											Qt::AlignLeft,
											strNumPage );

			// coordenada y da próxima linha:
			// soma altura da linha e espaço entrelinhas:
			yLine += fm.lineSpacing();
			// como é o cabeçalho, acrescenta duas linhas em branco:
			yLine+= fm.lineSpacing()*2;

		}

		paint.drawText ( nameX , yLine,  fm.width(it.key()), fm.height(),
							Qt::AlignLeft, it.key() );
		paint.drawText ( numX , yLine,  fm.width(it.value()), fm.height(),
							Qt::AlignLeft, it.value() );

		// coordenada y da próxima linha:
		// soma altura da linha e espaço entrelinhas:
		yLine += fm.lineSpacing();

	}

	if ( m_outputType == Printer &&
						m_printer->outputFormat()!=QPrinter::PdfFormat)
	{
		m_printer->newPage();
	}

	paint.end();
	m_outputType = Invalid	;
}

