#include "writefile.h"
#include <QThread>
#include <QtConcurrentRun>
#include <QDebug>
#include <QCoreApplication>

WriteFile::WriteFile(QObject *parent) :
    QObject(parent)
{
}

void WriteFile::generateData(int rowCount)
{
	m_rowCount = rowCount;
	m_data.resize(rowCount);
	qDebug()  << rowCount << m_data.size();

	for (int n=0; n<rowCount; ++n)
	{
		// povoar o vetor
		QPair<QString , double > pair;
		pair.first = QString("%1").arg(n+1);
		pair.second = qrand() * 1.33 +1;
		m_data[n] = pair;
	}
}

bool WriteFile::writeTxt()
{
	int cpus = QThread::idealThreadCount();
	if ( cpus == 0)
		cpus = 1;

	int begin = 0;
	int count = m_rowCount / cpus;

	QVector <QFuture<bool> > futures;
	futures.resize(cpus);
	m_txtFiles.resize(cpus);

	for ( int c=1; c<=cpus; ++c)
	{
		int end = c==cpus? m_rowCount-1 : begin+count-1 ;

		m_txtFiles[c-1] = new QFile("cobranca.txt");
		if ( !m_txtFiles[c-1]->open(QIODevice::WriteOnly | QIODevice::Truncate))
		{
			qDebug() << "falha ao abrir arquivo\n";
			return false;
		}
		futures[c-1]=QtConcurrent::run(
											this, &WriteFile::writeLoop, c-1, begin, end);

		begin = end + 1;
	}

	for ( int c=0; c<cpus; ++c)
		futures[c].waitForFinished();

	for ( int c=0; c<cpus; ++c)
		m_txtFiles[c]->close();

	qDeleteAll(m_txtFiles);

	qDebug() << "threads encerraram\n";
	return true;
}

bool WriteFile::writeLoop(int index, int begin, int end)
{
	enum { nameLen=40, valueLen = 12, terminatorLen = 2,
						recordLen = nameLen+valueLen+terminatorLen};

	const char * terminator = "\r\n";
	int offset = begin * recordLen;
	m_txtFiles[index]->seek(offset);

	qDebug() << "thread: " << QThread::currentThreadId() <<
					"begin: " << begin << "end: " << end
				<< "offset: " << offset;

	for ( ; begin <= end; ++begin)
	{
		m_txtFiles[index]->write(QString("%1").arg(
																m_data[begin].first,  // string
																-nameLen, // tamanho, alinhado à esquerda
																'*' // preenchedor à direita
								 ).toAscii()
							 );

		m_txtFiles[index]->write(QString("%1").arg(
											m_data[begin].second, // double
											valueLen, // tamanho alinhado à direita
											 'f',  // formato: fixed
												//(o default é 'g' que pode ser notação exponencial)
											  2, // precisão.
												'0' // preenchedor à esquerda
											).toAscii()

							 );

		m_txtFiles[index]->write(terminator);
	}

	// emit threadFinished();
	return true;
}
