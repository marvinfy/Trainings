#include <QObject>
#include <iostream>

class TestObj : public QObject
{ 
	Q_OBJECT

private slots :
		void on_Nothing(TestObj * pSender)
		{
			std::cout << this->objectName().toStdString()
					  << ": recebi aviso de "
					  << pSender->objectName().toStdString() 
					  << " (doNothing)" 
					  <<  std::endl;
		}
	
	protected: 
		signals:
		void doNothing(TestObj *);

	public:
		TestObj( QObject * p = 0 ) : QObject( p ){}
		void Func()
		{
			emit doNothing(this);
		}

};

