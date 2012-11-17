#ifndef _THREAD_H_INC_
#define _THREAD_H_INC_

#include <QThread>
#include <QDateTime>


class workerThread : public QThread
{
	Q_OBJECT

	public:
		workerThread()
		{}

	protected:
		void run()// para a aplicação o thread começa a rodar aqui
		{
			// inicia o gerador de randômicos
			// que serão usados na tarefa executada neste exemplo:
			qsrand ( QDateTime::currentDateTime().toTime_t() );

			// entra no event-loop:
			exec();  // da classe base QThread.
			// a partir daqui o thread só trabalhará se receber 
			// um "signal" ou um evento (postEvent)
		}

	public:	
		signals:
			// o thread emite este signal para notificar a janela principal
			// de que sua tarefa foi executada e qual foi o resultado:
		void taskDone( const QString & taskResult );
	
	private slots:
		// o thread oferece esse slot para executar uma tarefa:
		void on_doTask( )
		{
			static int times = 0;
			// a tarefa é gerar a soma de uma quantidade de números randômicos;
			// então, gera esse soma e emite o signal
			// para que o resultado seja recuperado em outro thread:
			unsigned long sum = 0;
			enum { TOTAL_RANDS = 50*1000*1000 };
			for (int n=0; n < TOTAL_RANDS; ++n )
			{
				sum += qrand(); // será que "qrand" é "thread-safe"?
			}

			++times;
			QString result =
					QString( "Execucão #%0 - resultado=[%1]").arg(times).arg(sum) ;

			emit taskDone ( result );
		}
	
};

#endif // ( _THREAD_H_INC_ )

