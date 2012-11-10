#include "TestaObj.h"
#include <QDebug>

TestaObj::TestaObj(QString objName, QObject *parent) :
    QObject(parent)
{
	setObjectName(objName);
}
TestaObj::~TestaObj()
{
	qDebug() << "Destrutora - objeto " << objectName() ;
}

// conectado ao SIGNAL "destroyed" da base QObject
// emitido na destrutora-base:
void TestaObj::onDestroyed(QObject * sender)
{
	qDebug() << "eu, " << this->objectName()
							<< ", recebi sinal 'destroyed' de: "
							<< sender->objectName();
}
