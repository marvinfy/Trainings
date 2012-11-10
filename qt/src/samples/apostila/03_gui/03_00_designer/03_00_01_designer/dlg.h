#ifndef _DLG_H_INC_
#define _DLG_H_INC_

#include "ui_designer.h"

class Dlg : public QDialog , private Ui::Dialog
{									
	Q_OBJECT

	public:
		Dlg( QWidget *parent = 0 ) // construtor
		: QDialog (parent )
		{
			setupUi(this); // usa configurações de Ui::Dialog
		}

	// agora posso acrescentar métodos específicos;
	// e posso acrescentar também novos signals e slots
	// .....................

};

#endif // ( _DLG_H_INC_ )

