/*


  Este exemplo dá conta de uma situação
  em que um thread precise esperar 
  qualquer ponto de processamento de outro thread
  que não seja a finalização desse thread.

  Para isso pode ser usado um semáforo
  com seu contador iniciado com zero.

  Neste exemplo, "main" irá esperar
  que cada "TestThread" já tenha iniciado.

*/


#include <QtCore>

#include <iostream>

static QSemaphore sem_mainWait( 0 ); // contador inicial: zero
							// aliás, zero já é o default

static QMutex mut_cout;

bool g_bTestThreadsProcess;

class TestThread : public QThread
{
	int _m_nThreadNumber;

	public:
		void  setNumber( int nThreadNumber ) { _m_nThreadNumber = nThreadNumber; }

	protected: 
		void run(); // redefine virtual da base
} ; 

void TestThread::run()
{
	// executa qualquer tarefa de inicialização
	// da qual o 'main-thread' dependa.
	
	// agora já pode liberar o main-thread 
	// que está aguardando até que este thread tenha iniciado:

	sem_mainWait.release(1); // incrementa semáforo liberando main

	mut_cout.lock();
		std::cout << "*** TestThread(#" << _m_nThreadNumber << ")::run: liberei o main thread" << std::endl;
	mut_cout.unlock();
		
	int n;
	for ( n=0; n<100 && g_bTestThreadsProcess; ++n )
	{
		mut_cout.lock();
			std::cout << "TestThread(#" << _m_nThreadNumber << ")::run: agora vou trabalhar... " << n << std::endl;
		mut_cout.unlock();
	
		usleep( 20 ); // simula uma tarefa a executar
			// com duração de 20 MICRO-segundos.
	}

	mut_cout.lock();
		std::cout << "*** TestThread(#" << _m_nThreadNumber << ")::run: vou encerrar." << std::endl;
	mut_cout.unlock();
}

int main()
{
	g_bTestThreadsProcess = true;

	enum { TOTAL_TEST_THREADS = 3};
	TestThread testThreads[ TOTAL_TEST_THREADS ];

	int nTh;

	// garante que "main" conseguirá imprimir antes dos "TestThreads":
	mut_cout.lock();

	for ( nTh = 0 ; nTh < TOTAL_TEST_THREADS ; ++nTh )
	{

		testThreads[ nTh ].setNumber( nTh+1 );
		testThreads[ nTh ].start();

		// 'main' espera que cada instância de 'TestThread' inicie:
		sem_mainWait.acquire( 1 );
	}

		std::cout << "\n* main: as 3 instancias de TestThread iniciaram" << std::endl; 
		std::cout << "* main: tecle <enter> para encerrar" << std::endl;
	mut_cout.unlock();

	std::cin.get();

	mut_cout.lock();
		std::cout << "\n* main: agora vou fazer com que encerrem." << std::endl;
	mut_cout.unlock();

	g_bTestThreadsProcess = false; // posiciona o flag para encerramento

	// aguarda o encerramento dos threads:
	for ( nTh = 0 ; nTh < TOTAL_TEST_THREADS ; ++nTh )
		testThreads[ nTh ].wait();

	std::cout << "\n* main: threads encerraram; agora, aplicacao vai encerar.\nFIM" << std::endl;
	return 0;
}


