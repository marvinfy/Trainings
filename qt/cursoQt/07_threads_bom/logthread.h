#ifndef LOGTHREAD_H
#define LOGTHREAD_H

#include <QThread>

class LogThread : public QThread
{
    Q_OBJECT
public:
    explicit LogThread(QObject *parent = 0);

	/*
	  void run() // essa é a implementação DEFAULT da run
	  {
			exec();
	  }
	  */
signals:

public slots:
		void logMessage(const QString & str);
};

#endif // LOGTHREAD_H
