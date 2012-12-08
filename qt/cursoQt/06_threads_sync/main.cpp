#include <QtGui/QApplication>
#include "Widget.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	 /*
	 QString s("ABC");
	 for ( int n=0; n<s.length() ; ++n)
		 qDebug( ) <<s.toInt();  // imprime 0 0 0

	 for ( int n=0; n<s.length() ; ++n)
		 qDebug( ) << int(s.at(n).toAscii()); // imprime 65 66 67
*/

	 Widget w;
    w.show();

    return a.exec();
}
