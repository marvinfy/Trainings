#include <QList>
#include <QMap>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QTime>
#include <QApplication>
#include <QMutex>
#include <qtconcurrentmap.h>
#include <iostream>

QMutex mut_cout;

using namespace QtConcurrent;

// Teremos uma lista de vetores de inteiros.
// A função "countNumbers" ira totalizar os números existentes em cada vetor,
// isto é, em cada elemento da lista.
// Ela retorna um "map" que tem como chave
// cada número diferente localizado no vetor
// e, como valor associado à chave, a quantidade de ocorrências desse número.
// Esse retorno sera passado para a função "reduce" (abaixo)
// a qual deverá criar um total único de toda a lista,
// ou seja, uma única ocorrência para cada número diferente,
// com o respectivo total de ocorrências.
// A função "countNumbers" pode ser chamada paralelamente
// por diversos threads.
// Por isso, deve ser "thread-safe".
QMap<int, int> countNumbers( const QVector < int > & listVecInt);

// A função "reduce" totaliza os resultados do "map"
// que ela receberá como segundo argumento ("numbersInOneVector")
// - e que será o resultado de cada chamada à função "countNumbers"-
// de forma a criar um totalizador único para
// a quantidade de números encontrados em todos os vetores processados.
// Esse resultado é gravado em outro "map", que é o seu primeiro argumento
// ("result_NumbersInAllVectors), e será o resultado final do processamento.
// A função "reduce" é executada em um único thread a cada vez.
void reduce(QMap<int, int>
			&result_NumbersInAllVectors,
			const QMap<int, int> &numbersInOneVector);

 int main(int argc, char** argv)
 {
	QApplication app(argc, argv);
	std::cout << "main iniciando no thread: "
			<< (unsigned int)(QThread::currentThreadId()) << "\n\n";

	QList < QVector< int > > listVecInt;
	// Alimentar a lista de vetores.
	// Cada vetor conterá os números 1, 2 e 3 - duplicados (duas ocorrências de cada um).
	// A lista conterá 5 vetores.
	// Logo, cada número deverá ter um total final de 10 ocorrências:
	for ( int nlist=0; nlist<5; ++nlist )
	{
		QVector< int > vecInt;
		for ( int nvec = 0; nvec < 3; ++nvec  )
		{
			vecInt.append( nvec+1 );
			vecInt.append( nvec+1 );
		}
		listVecInt.append( vecInt );
	}

	// - conta a quantidade de números em cada vetor da lista
	//     usando diversos threads:
	std::cout << "\n* main: processando com multiplos threads:\n" << std::endl;
	QMap<int, int> total = mappedReduced(listVecInt,
										 countNumbers, reduce);

	std::cout << "\n ========= resultado da totalizacao final\n";
	QMap<int, int>::iterator it;
	for ( it=total.begin() ; it!= total.end() ; ++it )
	{
		std::cout << it.key() << " : " << it.value() << '\n';
	}

	std::cout << "tecle <enter> para sair" << std::endl;
	std::cin.get();
	return 0;
 }
 
// "countNumbers" : conta os números existentes em um único vetor da lista,
// criando um mapa de totais para os números diferentes existentes nesse vetor.
// Chamada por diversos threads, cada qual tratando um vetor.
// Deve ser "thread-safe".
QMap<int, int> countNumbers(const QVector<int> & vecInt)
{
	mut_cout.lock();
	std::cout << "begin countNumbers() - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
	mut_cout.unlock();


	QMap<int, int> numbersInThisVector;
	int size = vecInt.size();
	for ( int n =0; n<size; ++n)
	{
		const int & number = vecInt[n];
		numbersInThisVector[ number ] += 1; // busca "number" no map; se já estiver lá apenas soma mais 1 no valor associado
											// do contrário, insere "number" e inicia o valor associado com 0+1.
	}
	mut_cout.lock();
	std::cout << "end countNumbers() - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
	mut_cout.unlock();

	return numbersInThisVector;

}

 // A função "reduce" totaliza os resultados do "map"
// que ela receberá como segundo argumento ("numbersInOneVector")
// - e que será o resultado de cada chamada à função "countNumbers"-
// de forma a criar um totalizador único para
// a quantidade de números encontrados em todos os vetores processados.
// Esse resultado é gravado em outro "map", que é o seu primeiro argumento
// ("result_NumbersInAllVectors), e será o resultado final do processamento.
// A função "reduce" é executada em um único thread a cada vez.
void reduce(QMap<int, int> &result_NumbersInAllVectors,
			const QMap<int, int> & numbersInOneVector)
{
	mut_cout.lock();
	std::cout << "\tbegin reduce() -resultSize: " << result_NumbersInAllVectors.size() << " -inputSize: " << numbersInOneVector.size()
								<< " - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
	mut_cout.unlock();

	QMapIterator<int, int> i (numbersInOneVector);
	while (i.hasNext()) 
	{
		i.next();
		result_NumbersInAllVectors[i.key()] += i.value();
	}

	mut_cout.lock();
	std::cout    << "\tend reduce() -resultSize: " << result_NumbersInAllVectors.size()
						<< " -inputSize: " << numbersInOneVector.size()
						<< " - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
	mut_cout.unlock();
}

/*
 // ==== Resultado de uma execução deste programa em uma máquina com 2 cores.
 // OBS: em cada execução, a ordem com que os números serão tratados poderá ser diferente,
 //  bem como o id do thread em que são tratados.

  main iniciando no thread: 528


* main: processando com multiplos threads:

begin countNumbers() - thread 524
end countNumbers() - thread 524
		begin reduce() -resultSize: 0 -inputSize: 3 - thread 524
		end reduce() -resultSize: 3 -inputSize: 3 - thread 524
begin countNumbers() - thread 524
end countNumbers() - thread 524
		begin reduce() -resultSize: 3 -inputSize: 3 - thread 524
begin countNumbers() - thread 2788
		end reduce() -resultSize: 3 -inputSize: 3 - thread 524
end countNumbers() - thread 2788
begin countNumbers() - thread 524
		begin reduce() -resultSize: 3 -inputSize: 3 - thread 2788
end countNumbers() - thread 524
		end reduce() -resultSize: 3 -inputSize: 3 - thread 2788
begin countNumbers() - thread 524
		begin reduce() -resultSize: 3 -inputSize: 3 - thread 2788
end countNumbers() - thread 524
		end reduce() -resultSize: 3 -inputSize: 3 - thread 2788
		begin reduce() -resultSize: 3 -inputSize: 3 - thread 2788
		end reduce() -resultSize: 3 -inputSize: 3 - thread 2788

 ========= resultado da totalizacao final
1 : 10
2 : 10
3 : 10
tecle <enter> para sair

*/
