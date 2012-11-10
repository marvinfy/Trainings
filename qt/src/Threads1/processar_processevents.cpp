#include "processar_processevents.h"
#include <QApplication>

Processar_ProcessEvents::Processar_ProcessEvents(QObject *parent) :
    QObject(parent)
{
}

void Processar_ProcessEvents::startProcess(quint32 loopCount)
{
    m_canRun = true;
    m_loopCount = loopCount;

    quint32 progressCount;
    quint32 previousProgress = 0;

    for (quint32 i = 1; i <= m_loopCount && m_canRun; i++)
    {
        // Sem a linha abaixo, a interface pode "congelar", mas fica extremamente lento,
        // pois tem que checar a fila de eventos..
        // O tempo de processamento sobe absurdamente
        QApplication::processEvents();

        progressCount = quint32((double(i)/m_loopCount) * 100);
        if (progressCount > previousProgress)
        {
            previousProgress = progressCount;
            emit progress(progressCount);
        }
    }

    emit finished();
}

