
#ifndef MainWin_H
#define MainWin_H

#include <QWidget>
class QSlider;

class Thermometer : public QWidget
{
	Q_OBJECT

	public:
		Thermometer(QWidget * pParent = NULL )
			: QWidget(pParent)
		{
		}

	protected:
		virtual void paintEvent(QPaintEvent * pEv);
};

class MainWin : public QWidget
{
	Q_OBJECT

	QSlider * m_slider;
	Thermometer * m_thermometer;

	public:
		MainWin(QWidget * pParent = NULL );

		const QSlider * slider() const { return m_slider; }

};

#endif // ( MY_CLASS_H )


