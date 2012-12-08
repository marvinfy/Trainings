#ifndef FORM2_H
#define FORM2_H

#include <QtGui/QWidget>

namespace Ui {
    class Form2;
}

class Form2 : public QWidget {
    Q_OBJECT
public:
    Form2(QWidget *parent = 0);
    ~Form2();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Form2 *m_ui;

private slots :
	// slot que recebe um texto oriundo de qualquer widget;
	// neste slot, esse texto será adicionado à comboBox deste Form:
	void externText( const QString & text);
	// neste exemplo, este slot será conectado a um signal de "Form1",
	// o qual enviará um novo texto sempre que o seu "lineEdit" seja alterado
	// (ver "form1.h/form1.cpp")
};

#endif // FORM2_H
