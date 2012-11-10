#include <QObject>
#include <iostream>

class TestObj : public QObject
{ 
	Q_OBJECT

	public:
		TestObj( QObject * p = 0 ) : QObject( p ){}
		void func()
		{
			emit doNothing(this);
		}
		void exit()
		{
			emit quit();
		}

	public slots :
		void on_Nothing(TestObj * pSender)
		{
			std::cout << this->objectName().toStdString()
					  << ": recebi aviso de "
					  << pSender->objectName().toStdString() 
					  << " (doNothing)" 
					  <<  std::endl;
		}
	
		signals:
			void doNothing(TestObj *);
			void quit();		
};

