#include "logthread.h"
#include <QDateTime>
#include <iostream>

LogThread::LogThread(QObject *parent) :
    QThread(parent)
{
}

void LogThread::logMessage(const QString &str)
{
	QString now (QDateTime::currentDateTime().
																	toString("dd/MM/yyyy hh:mm:ss"));

	std::cout << now.toStdString() << " : " << str.toStdString() << "\n";
}
