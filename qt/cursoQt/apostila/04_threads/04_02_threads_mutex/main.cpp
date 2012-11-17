#include <QtCore/QCoreApplication>
#include <QThread>
#include <QMutex>
#include <iostream>

/*
	Este projeto corrige o anterior usando
	um mutex
*/

QMutex coutMutex;  // mutex = "MUTual EXclusion"

class Thread : public QThread
{
	protected:
		void run(); // virtual da base;
			// para a aplicação é aqui que o thread começa
	public:
		static bool doProcess;
};
bool Thread::doProcess = true;

void Thread::run()
{
	int n;
	for ( n=0; n<30 && doProcess ; ++n)
	{
		coutMutex.lock();
		std::cout << "thread #" << currentThreadId()
				<< " - processando: " << n << std::endl;
		coutMutex.unlock();
	}
}
int main(int argc, char *argv[])
{
	enum { TotThreads = 4 };
	Thread threads[4];
	int n;

	for ( n=0; n<TotThreads; ++n)
		threads[n].start();

	// main: este thread continua trabalhando normalmente:

	coutMutex.lock();
	std::cout << "threads iniciaram - tecle <enter> p/ encerrar" << std::endl;
	coutMutex.unlock();
	std::cin.get();

	// aplicação vai encerrar (pois o "main-thread" vai encerrar):
	// então, deve esperar que os demais threads encerrem
	// para que possam realizar quaisquer tarefas de finalização:
	Thread::doProcess = false; // <- sinaliza para que encerrem
	for ( n=0; n<TotThreads; ++n)
		threads[n].wait(); // <- aguarda encerramento de cada um

	return 0;
}
