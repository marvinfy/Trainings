#ifndef PROCESSAR_PROCESSEVENTS_H
#define PROCESSAR_PROCESSEVENTS_H

#include <QObject>

class Processar_ProcessEvents : public QObject
{
    Q_OBJECT
public:
    explicit Processar_ProcessEvents(QObject *parent = 0);
		void startProcess(quint32 loopCount);
		void stopProcess() { m_canRun = false; }
signals:
		void progress(quint32 progressCount);
		void finished();

private:
		quint32 m_loopCount;
		bool m_canRun;
};

#endif // PROCESSAR_PROCESSEVENTS_H
