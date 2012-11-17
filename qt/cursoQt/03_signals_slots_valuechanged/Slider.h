#ifndef CLASSE_2_H
#define CLASSE_2_H

#include <QObject>

class Slider : public QObject
{
    Q_OBJECT
public:
	 explicit Slider(QObject *parent = 0);

	signals:
			void valueChanged(int val);

	public slots:
			void setValue(int val);

private:
		int m_value;
};

#endif // CLASSE_2_H
