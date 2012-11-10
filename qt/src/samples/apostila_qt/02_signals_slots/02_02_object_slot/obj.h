#include <QObject>
#include <iostream>

class TestObj : public QObject
{ 
	Q_OBJECT

	private slots :
		void on_destroyed(QObject * pSender)
		{
			std::cout << this->objectName().toStdString()
					  << ": recebi aviso de "
					  << pSender->objectName().toStdString() 
					  << " (que sera destruido)" 
					  <<  std::endl;
		}

	public:
		TestObj( QObject * p = 0 ) : QObject( p ){}
		~TestObj()
		{
			std::cout << "TestObj::~TestObj: " << objectName().toStdString() << std::endl;
		}
};

