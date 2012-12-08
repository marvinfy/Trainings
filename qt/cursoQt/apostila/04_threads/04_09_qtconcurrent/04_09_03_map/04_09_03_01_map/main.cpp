
#include <QtCore>
#include <iostream>
#include <cmath>

using namespace QtConcurrent;

 // vetor para armazenar resultado do processamento;
 QVector<double> vecResult;
 // estrutura que será vetorizada e passada para "map":
struct item
{
	size_t index;
	int value;
};
// função que será aplicada a cada elemento de um vetor de "item":
 void funSqrt( item & it )
 {
	qDebug() << "valor sendo processado: " << it.value << " -  thread"
									<< (unsigned int)QThread::currentThreadId();

	vecResult[ it.index ] = sqrt ( double ( it.value ) );
 }

 int main(int argc, char **argv)
 {
	QCoreApplication app(argc, argv);
	std::cout << "main iniciando no thread: "
			<< (unsigned int)(QThread::currentThreadId()) << "\n\n";

	const int iterations = 6;

	//  cria e alimenta um vetor de "item".
	QVector< item > vecItem;
	for (int i = 0; i < iterations; ++i)
	{
		item it;
		it.index = i;
		it.value = (i+1) * (i+1);
		vecItem.append( it );
	}
	// dimensiona o vetor de resultados:
	vecResult.resize( iterations );

	// inicia processamento:
	QFuture < void > future = QtConcurrent::map(vecItem, funSqrt);

	// ... main continua trabalhando aqui.
	
	// aguarda encerramento.
	future.waitForFinished();

	// agora imprimimos os elementos de "vecResult":
	std::cout << "\n=== resultados no vetor 'vecResult'\n--- (lista com a raiz quadrada dos numeros tratados: " << std::endl;
	for (int i = 0; i < iterations; ++i)
		qDebug() << vecResult[i] ;

	std::cout << "tecle <enter> para sair" << std::endl;
	std::cin.get();
	return 0;
}
/*
  // ==== Resultado de uma execução deste programa em uma máquina com 2 cores.
 // OBS: em cada execução, a ordem com que os números serão tratados poderá ser diferente,
 //  bem como o id do thread em que são tratados.

 main iniciando no thread: 2244

valor sendo processado:  1  -  thread 4044
valor sendo processado:  4  -  thread 4044
valor sendo processado:  9  -  thread 3300
valor sendo processado:  16  -  thread 4044
valor sendo processado:  25  -  thread 3300
valor sendo processado:  36  -  thread 3300

=== resultados no vetor 'vecResult'
--- (lista com a raiz quadrada dos numeros tratados:
1
2
3
4
5
6

tecle <enter> para sair

*/
