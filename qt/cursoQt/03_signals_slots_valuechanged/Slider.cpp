#include "Slider.h"
#include <QDebug>

Slider::Slider(QObject *parent) :
    QObject(parent)
 , m_value(0)
{
}

void Slider::setValue(int val)
{
	QString senderName( sender() ? sender()->metaObject()->className() : "main");

	if ( val!=m_value)
	{
		qDebug() << "Slider novo valor: " << val
						<< "enviado por: " << senderName;
		m_value = val;
		emit valueChanged(m_value);
	}
	else
	{
		qDebug() << "Slider meu valor é " << m_value << " e " << senderName
				<< " me enviou " << val << " - não fiz nada";
	}
}
