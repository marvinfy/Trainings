





#ifndef TESTAOBJ_H
#define TESTAOBJ_H

#include <QObject>

class TestaObj : public QObject
{
    Q_OBJECT
		
public:
	 explicit TestaObj(QString objName,
							 QObject *parent = 0);

	~TestaObj();

void finish()		
{
	emit exit();
}

signals:
		void exit ( );
		
public slots:
		void onDestroyed(QObject * sender);
		
};

#endif // TESTAOBJ_H
