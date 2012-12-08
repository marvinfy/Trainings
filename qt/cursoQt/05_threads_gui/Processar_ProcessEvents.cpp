#include "Processar_ProcessEvents.h"
#include <QApplication>

Processar_ProcessEvents::Processar_ProcessEvents(QObject *parent) :
    QObject(parent)
{
}

void Processar_ProcessEvents::startProcess(quint32 loopCount)
{
	m_loopCount = loopCount;
	m_canRun = true;
	quint32 progressCount;
	quint32 previousProgress=0;

	for (quint32 n=1; n<=m_loopCount && m_canRun; ++n)
	{
		// sem a linha abaixo, a interface pode "congelar" ("aplicação não está respondendo")
		// contudo torna o processamento muuuuiiiiiitooo lento.
		QApplication::processEvents();

		progressCount = quint32( (double(n)/m_loopCount) * 100);
		if ( progressCount > previousProgress)
		{
			previousProgress  = progressCount;
			emit progress(progressCount);
		}
	}
	emit finished();
}
