#ifndef CLASSE_1_H
#define CLASSE_1_H

#include <QObject>

class Spin : public QObject
{
    Q_OBJECT
public:
	 explicit Spin(QObject *parent = 0);

	signals:
			void valueChanged(int val);
			void finish();

	public slots:
			void setValue(int val);

private:
		int m_value;
		bool m_isValid;
};

#endif // CLASSE_1_H
