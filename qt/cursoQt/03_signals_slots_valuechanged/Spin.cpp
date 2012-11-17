#include "Spin.h"
#include <QDebug>

Spin::Spin(QObject *parent) :
    QObject(parent)
 , m_value(0)
 , m_isValid(true)

{
}

void Spin::setValue(int val)
{
	QString senderName( sender() ? sender()->metaObject()->className() : "main");

	if ( val!=m_value && m_isValid)
	{

		if ( val >1000)
		{
			qDebug() <<  "SPIN FINISH !!! - enviado por " << senderName;
			m_isValid = false;
			emit finish();
		}
		else
		{
			qDebug() << "Spin novo valor: " << val
																					<< "enviado por: " << senderName;
			m_value = val;
			emit valueChanged(m_value);
		}
	}
	else
	{
		if ( m_isValid)
			qDebug() << "Spin meu valor é " << m_value << " e " << senderName
					<< " me enviou " << val << " - não fiz nada";
		else
			qDebug() << "Spin:  estou em um estado invalido e " << senderName
					<< " me enviou " << val << " - não fiz nada";
	}
}
