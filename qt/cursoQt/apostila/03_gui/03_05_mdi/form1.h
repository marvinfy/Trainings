#ifndef FORM1_H
#define FORM1_H

#include <QtGui/QWidget>

namespace Ui {
    class Form1;
}

class Form1 : public QWidget {
    Q_OBJECT
public:
    Form1(QWidget *parent = 0);
    ~Form1();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Form1 *m_ui;

 private slots:
	// slot para o signal "textChanged" do "lineEdit" deste "form";
	// - capturar aqui qualquer mudança de texto do lineEdit:
	void on_lineEdit_textChanged(const QString&text);

public:
	signals:
	// signal que disponibiliza o texto do "lineEdit"
	// para o mundo externo à classe:
	void editTextChanged( const QString & text);
	// neste exemplo, este signal será conectado a um slot de "Form2";
	// e, nesse slot, o "Form2" irá adicionar esse texto a sua "comboBox"
	// (ver "form2.h/form2.cpp")

};

#endif // FORM1_H
