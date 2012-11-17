#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Form1)
{
    m_ui->setupUi(this);
}

Form1::~Form1()
{
    delete m_ui;
}

// slot para o signal "textChanged" do "lineEdit" deste "form";
// - capturar aqui qualquer mudança de texto do lineEdit:
void Form1::on_lineEdit_textChanged(const QString&text)
{
	// emite um signal, que disponibiliza o texto do "lineEdit"
	// para o mundo externo à classe:
	emit editTextChanged( text );
	// neste exemplo, este signal será conectado a um slot de "Form2";
	// e, nesse slot, o "Form2" irá adicionar esse texto a sua "comboBox"
	// (ver "form2.h/form2.cpp")
}

void Form1::changeEvent(QEvent *e)
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
