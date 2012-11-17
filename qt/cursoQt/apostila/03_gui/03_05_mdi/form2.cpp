#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Form2)
{
    m_ui->setupUi(this);
}

Form2::~Form2()
{
    delete m_ui;
}

// slot "externText" que recebe um texto oriundo de qualquer widget;
// neste slot, esse texto será adicionado à comboBox deste Form.
// Neste exemplo, este slot será conectado a um signal de "Form1",
// o qual enviará um novo texto sempre que o seu "lineEdit" seja alterado
// (ver "form1.h/form1.cpp")
void Form2::externText( const QString & text)
{
	// adiciona na comboBox o texto recebido no parâmetro "text":
	m_ui->comboBox->addItem( text );
	// e seleciona a última linha acrescentada acima:
	m_ui->comboBox->setCurrentIndex( m_ui->comboBox->count() - 1 );
}


void Form2::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
