
#include <QtCore>

#include <iostream>
#include <cstdlib>

enum { TOTAL_TEST_THREADS = 3 , TOTAL_PROCESS = 2 };

// "wait-condition" para que os "TestThreads" aguardem
// que "main" notifique que uma tarefa deve ser executada:
QWaitCondition wc_TestThreadWait;
// uma "wait condition" deve trabalhar em conjunto com um mutex:
QMutex mut_TestThreadWait;

// mutex para proteger o acesso ao console:
QMutex mut_cout;

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

	while ( g_bTestThreadsProcess )
	{
		// aguarda até que exista algo para fazer
		// (isto é, quando o main-thread liberar "acordar" a wait-condition):
		mut_TestThreadWait.lock();
	
				mut_cout.lock();
					std::cout << "TestThread(#" << _m_nThreadNumber << ")::run: vou entrar em espera" << std::endl;
				mut_cout.unlock();

				wc_TestThreadWait.wait ( &mut_TestThreadWait );

		mut_TestThreadWait.unlock();

		if ( g_bTestThreadsProcess )
		{
			mut_cout.lock();	
				std::cout << "TestThread(#" << _m_nThreadNumber << ")::run: agora vou trabalhar." << std::endl;
			mut_cout.unlock();
			
			// Tarefa_a_Executar(); // aqui estaria o processamento deste thread...				
		}
	
	}

	mut_cout.lock();
		std::cout << "TestThread(#" << _m_nThreadNumber << ")::run: vou encerrar." << std::endl;
	mut_cout.unlock();
}

int main(int argc, char * argv[] )
{
        QCoreApplication app (argc, argv);

	g_bTestThreadsProcess = true;
	TestThread testThreads[ TOTAL_TEST_THREADS ];

	mut_cout.lock();  // garante que o primeiro cout será de main

	// 'main' inicia os threads
	int nTh;
	for ( nTh = 0 ; nTh < TOTAL_TEST_THREADS ; ++nTh )
	{
		testThreads[ nTh ].setNumber( nTh+1 );
		testThreads[ nTh ].start();
	}

	std::cout << "\n* main: as 3 instancias de TestThread iniciaram" << std::endl;
	mut_cout.unlock();

	int nProc; // manda os TestThreads executar uma tarefa diversas vezes
	for ( nProc = 0; nProc < TOTAL_PROCESS; ++nProc )
	{
		mut_cout.lock();
			std::cout << "\n* main: Vou fazer com que trabalhem : " << nProc+1 << std::endl;
		mut_cout.unlock();
		
		mut_TestThreadWait.lock();
			wc_TestThreadWait.wakeAll(); // acorda todos os TestThreads que estejam em "wait" neste momento
		mut_TestThreadWait.unlock();
		// cede tempo de processamento:
		QThread::yieldCurrentThread();
	
	}
	
        // main vai encerrar logo abaixo.
        // Então, cede tempo de processamento para que os "testThreads"
        // tenham tempo de encerrar seu procesamento.
  //     QTest::qWait(1000);

        mut_cout.lock();
                std::cout << "\n* main: agora vou fazer com que encerrem." << std::endl;
        mut_cout.unlock();

	g_bTestThreadsProcess = false; // posiciona o flag para encerramento
	
	// acorda todos os TestThreads que estejam em "wait" neste momento
	mut_TestThreadWait.lock();
	wc_TestThreadWait.wakeAll(); 
	mut_TestThreadWait.unlock();

	// aguarda o encerramento dos threads:
	for ( nTh = 0 ; nTh < TOTAL_TEST_THREADS ; ++nTh )
		testThreads[ nTh ].wait();

	std::cout << "\n* main: threads encerraram; tecle <enter> para encerar\n";
	std::cin.get();
	std::cout << "\nFIM" << std::endl; 

	return 0;
}
