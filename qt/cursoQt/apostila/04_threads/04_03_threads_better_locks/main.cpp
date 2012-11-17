#include <QtCore/QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QReadWriteLock>
#include <iostream>
class  SomeThread : public QThread
{
	protected:
		void run();
	private:
			static QMutex m_mutex;
			static QReadWriteLock m_rwLock;

			static int m_var;
			// para uso com mutex (via QMutexLocker):
			void readMutexFunc();
			void writeMutexFunc();
			// para uso com ReadWriteLock:
			void readFunc();
			void writeFunc();
} ;

QReadWriteLock SomeThread::m_rwLock;
QMutex SomeThread::m_mutex;
int SomeThread::m_var = 0;
QMutex cout_mut;

int main(int argc, char *argv[])
{
	enum { ThreadsCount = 3 };
	SomeThread threads[ ThreadsCount ];
	for ( int t=0; t<ThreadsCount; ++t )
		threads[t].start();

	// ... main continua aqui...
	std::cin.get();
	for ( int t=0; t<ThreadsCount; ++t )
		threads[t].wait();
}
void SomeThread::run()
{
	// bloqueia/desbloqueia "cout_mut" manualmente:
	cout_mut.lock();
	std::cout << "\n========= thread " << currentThreadId()
						<< " iniciando PRIMEIRO processamento\n" ;
	cout_mut.unlock();

	for (int n=0; n<15; ++n)
	{
		readMutexFunc();
		writeMutexFunc();
	}

	// bloqueia/desbloqueia "cout_mut" manualmente:
	cout_mut.lock();
	std::cout << "\n========= thread " << currentThreadId()
						<< " iniciando SEGUNDO processamento\n";
	cout_mut.unlock();

	for (int n=0; n<15; ++n)
	{
		readFunc();
		writeFunc();
	}
}

void SomeThread::readMutexFunc()
{
	int var;
	{
		QMutexLocker lock (&m_mutex);  // lock AQUI
		var = m_var;

	} // unlock de "m_mutex" AQUI
	// (destrutora para "lock")

	QMutexLocker cout_lock ( &cout_mut );
	std::cout<<  "ReadMutexFunc : var=" << var << " - Thread: " <<currentThreadId()
			<< std::endl;

} // unlock para "cout_mut" aqui

void SomeThread::writeMutexFunc()
{
	int var ;
	{
		QMutexLocker lock ( &m_mutex); // lock AQUI
		++m_var;
		var = m_var;

	} // unlock de "m_mutex" AQUI (destrutora para "lock")

	QMutexLocker cout_lock ( &cout_mut );
	std::cout<<  "WriteMutexFunc : var=" << var << " - Thread: " <<currentThreadId()
			<< std::endl;

} // unlock para "cout_mut" aqui

void SomeThread::readFunc()
{
	int var;
	{
		QReadLocker lock (&m_rwLock );
		var = m_var;

	} // unlock para "m_rwLock" aqui (destrutora de QReadLocker)

	QMutexLocker cout_lock(&cout_mut);
	std::cout<<  "ReadFunc : var=" << var << " - Thread: " <<currentThreadId()
			<< std::endl;

} // unlock para "cout_mut" aqui.

void SomeThread::writeFunc()
{
	int var;
	{
		QWriteLocker lock (&m_rwLock );
		++m_var;
		var = m_var;

	} // unlock para ("m_rwLock") aqui (destrutora de QWriteLocker);

	QMutexLocker cout_lock (&cout_mut);
	std::cout<<  "WriteFunc : var=" << var << " - Thread: " <<currentThreadId()
			<< std::endl;

} // unlock para "cout_mut" aqui
