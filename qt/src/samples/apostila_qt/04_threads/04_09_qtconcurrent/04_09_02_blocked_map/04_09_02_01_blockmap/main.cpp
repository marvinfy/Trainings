 #include <QtCore/QCoreApplication>
 #include <QList>
 #include <qtconcurrentmap.h>

#include <iostream>
#include <iomanip>
#include <cmath>

QMutex mut_cout;

// função  que será usada por "blockingMapped"
// para executar um cálculo (raiz quadrada):
double funSqrt( int n );

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	std::cout << "main iniciando no thread: "
			<< (unsigned int)(QThread::currentThreadId()) << "\n\n";
	const int count = 6;

	// criar uma lista de inteiros
	QList<int> inteiros;
	for (int i = 0; i < count; ++i)
	{
		// acrescenta um inteiro na lista
		inteiros.append( (i+1) * (i+1) );
	}

	// QtConcurrent::blockingMapped irá executar "funSqrt" para cada elemento da lista,
	// retornando uma lista de resultados:
	QList<double> result = QtConcurrent::blockingMapped(inteiros,
																										funSqrt);

	// agora imprimimos os elementos de "result":
	std::cout << "\n=== resultados na lista 'result'\n--- (lista com a raiz quadrada dos numeros tratados: " << std::endl;
	foreach ( double  rquad, result )
	{
		std::cout << rquad << std::endl;
	}
	std::cout << "\ntecle <enter> para sair" << std::endl;
	std::cin.get();
	return 0;
}

double funSqrt(int n)
{
	double result = sqrt( double(n) );

	mut_cout.lock();

		// imprime mensagem informando qual número está sendo tratado
		// e qual o thread que está fazendo isso:
		std::cout.fill('0');
		std::cout << "tratando numero : ["	<< std::setw(3) << n
			<<  "] no thread: " << (unsigned int)(QThread::currentThreadId()) << std::endl;

	mut_cout.unlock();

	return result;
}
/*

// ==== Resultado de uma execução deste programa em uma máquina com 2 cores.
// OBS: em cada execução, a ordem com que os números serão tratados poderá ser diferente,
//  bem como o id do thread em que são tratados.

main inciando no thread: 2548

tratando numero : [001] no thread: 2340
tratando numero : [016] no thread: 2340
tratando numero : [004] no thread: 600
tratando numero : [009] no thread: 2548
tratando numero : [036] no thread: 600
tratando numero : [025] no thread: 2340

=== resultados na lista 'result':
1
2
3
4
5
6

tecle <enter> para sair
*/
