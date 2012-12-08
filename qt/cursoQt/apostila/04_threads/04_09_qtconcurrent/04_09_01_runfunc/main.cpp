
#include <QDebug>
#include <QThread>
#include <QString>
#include <QtConcurrentRun>
#include <QApplication>
#include <iostream>

using namespace QtConcurrent;

QMutex mut_cout;
void hello(const QString & name);

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	int cpus = QThread::idealThreadCount();
	std::cout << "Quantidade de cores: " << cpus 
								<< '\n';
	std::cout << "threads que serão criados pelo Pool (default) " <<
			QThreadPool::globalInstance()->maxThreadCount() << "\n";

		// executará tantos threads quantas forem as "cpus"
	// exceto se forçarmos para mais:
	//QThreadPool::globalInstance()->setMaxThreadCount( cpus * 2 );

//	std::cout << "threads que serão criados pelo Pool " <<
		//	QThreadPool::globalInstance()->maxThreadCount() << "\n";

	QFuture<void> f1 = QtConcurrent::run( hello, QString("Alice")  );
	QFuture <void>f2 = run(hello, QString("Bob"));
	QFuture<void> f3 = run(hello, QString("John"));
	QFuture<void> f4 = run(hello, QString("Scott"));

	// posso continuar trabalhando aqui
	// ao "mesmo tempo" em que "f1", "f2", "f3" e "f4" trabalham
	for ( int n=0; n < 50; ++n)
	{
		mut_cout.lock();
		std::cout << "main : ----- \tprocessando... " << n 
						<< " thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
		mut_cout.unlock();
	}

	mut_cout.lock();
	std::cout << "main: encerrou seu loop " 
						<< " from " << (unsigned int)(QThread::currentThreadId()) 
						<< " - tecle <enter> para sair" << std::endl;
	mut_cout.unlock();

	std::cin.get();

	f1.waitForFinished();
	f2.waitForFinished();
	f3.waitForFinished();
	f4.waitForFinished();


	return 0;
}

void hello(const QString & name)
{
	for ( int n=0; n< 10 ; ++n)
	{
		mut_cout.lock();
		std::cout << "Hello: " << name.toStdString() << " \tprocessando... " << n
						<< " thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
		mut_cout.unlock();
	}

		mut_cout.lock();
		std::cout << "Hello: encerrei "<< name.toStdString() 
						<< " thread " << (unsigned int)(QThread::currentThreadId()) 
						<< std::endl;

		mut_cout.unlock();
}
