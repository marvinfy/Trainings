#include <QList>
#include <QMap>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QTime>
#include <QApplication>
#include <QMutex>

QMutex mut_cout;
bool g_verbose = false;

#include <qtconcurrentmap.h>

#include <iostream>

#ifndef QT_NO_CONCURRENT

using namespace QtConcurrent;

// função para buscar arquivos recursivamente
// percorrendo subdiretórios a partir de um diretório inicial:
QStringList findFiles(const QString &startDir, QStringList filters);

 // função que contará as palavras em um arquivo
// usando um único thread;
//  retorna um "map" que tem como chave um conjunto de strings
// e como seu valor associado a quantidade de ocorrências de cada string

QMap<QString, int> singleThreadedCountWords(QStringList files);

 // A função "countWords" conta  as diferentes palavras existentes em um dos arquivos processados.
 // Essa função pode ser chamada paralelamente por diversos threads.
// Por isso, deve ser "thread-safe".
QMap<QString, int> countWords(const QString &file);

 // A função "reduce" totaliza os resultados do "map" que recebe como segundo argumento
//  - e que será o resultado da função "countWords"-
// de forma a criar um totalizador único para a quantidade de palavras encontradas em todos os arquivos processados.
// Esse resultado é gravado no "map" que é o seu primeiro argumento.
 // Ela é executada em um único thread a cada vez.
void reduce(QMap<QString, int> &result_WordsInAllFiles,
								const QMap<QString, int> &wordsInOneFile);

 int main(int argc, char** argv)
 {
	QApplication app(argc, argv);
	std::cout << "main iniciando no thread: "
			<< (unsigned int)(QThread::currentThreadId()) << "\n\n";

	std::cout << "verbose (0)-nao ; !0-sim" << std::endl;
	int verbose;
	std::cin >> verbose; std::cout << std::endl;
	g_verbose = verbose!=0;
	const int totalFiles = 1000;
	std::cout << "* main: gerando " << totalFiles << " arquivos para teste do mapreduce..." << std::endl;
	qsrand((unsigned int)QDateTime::currentDateTime().toTime_t() );
	int totalChars = 'Z'-'A'+1;
	// cria uma lista de palavras que será inserida em cada arquivo
	// para testar a totalização do reduce:
	QStringList wordsList;
	const int totalWords = 1000;
	for ( int word = 0; word < totalWords ; ++ word )
	{
		QString wordStr;
		// monta uma palavra aleatória:
		for ( int ch = 0 ; ch < 5; ++ ch)
			wordStr += QChar( 'A' + (qrand()%totalChars));

		wordsList << wordStr;
	}

	for ( int file = 0; file < totalFiles; ++file )
	{
		QFile file_test(QString("file_%1.dat").arg(file+1, 3, 10, QChar('0')));
		file_test.open(QIODevice::WriteOnly| QIODevice::Text);
		QTextStream out_test(&file_test);
		// acrescenta cada palavra a cada arquivo:
		foreach( const QString & wordStr, wordsList )
			out_test << wordStr << '\n';

		// acrescenta uma palavra que poderá ser diferente para cada arquivo:
		out_test << QString("AAAAA_") + QChar('A' + qrand()%totalChars) + '\n';
	}

	std::cout << "* main: buscando arquivos..." << std::endl;
	// busca arquivos ".dat" e ".cpp" iniciando no diretório corrente:
	QStringList files = findFiles(".", QStringList() << "*.dat" << "*.cpp");
	std::cout << '\n';
	std::cout << "* main: " << files.count() << " files" << std::endl;

	// faz um "aquecimento" prévio, de modo a que o tempo de início da aplicacão
	// interfira o mínimo possível na posterior contagem de tempo de execução
	// de cada método empregado:
	std::cout << "\n* main: aquecendo..." << std::endl;

	{
		QTime time;
		time.start();
		singleThreadedCountWords(files);
	}

	std::cout << "* main: aquecimento concluido" << std::endl;

	// 1- conta a quantidade de  palavras nos arquivos localizados
	//     usando um único thread:
	std::cout << "\n* main: processando com um unico thread:\n" << std::endl;
	int singleThreadTime = 0;
	{
		QTime time;
		time.start();
		QMap<QString, int> total = singleThreadedCountWords(files);
		singleThreadTime = time.elapsed(); // tempo total em milisegundos
	}

	// 2- conta a quantidade de  palavras nos arquivos localizados
	//     usando diversos threads:
	std::cout << "\n* main: processando com multiplos threads:\n" << std::endl;
	int mapReduceTime = 0;
	QMap<QString, int> total ;
	{
		QTime time;
		time.start();
		total = mappedReduced(files, countWords, reduce);
		mapReduceTime = time.elapsed(); // tempo total em milisegundos
	}
	
	// imprime o tempo total empregado pelos dois métodos acima;
	// (obs: se "verbose" estiver em uso, os tempos exibidos estarão comprometidos)
	std::cout << "\n* ======= main: Tempos de cada processamento:\n" ;
	std::cout << "* main: single thread time " << singleThreadTime << std::endl;
	std::cout << "* main: MapReduce time " << mapReduceTime << std::endl;
	std::cout << "* main: MapReduce speedup x "
			<< (((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1) << std::endl;

	// grava o resultado ("QMap<QString, int> total"):
	std::cout << "\n* ======= main: veja totais das palavras localizadas gravados no arquivo 'result'\n" ;

	QFile file_res("result");
	file_res.open(QIODevice::WriteOnly| QIODevice::Text);  
	QTextStream out_res(&file_res);
	QMap<QString, int>::iterator it;
	for ( it=total.begin() ; it!= total.end() ; ++it )
	{
		out_res << it.key() << " : " << it.value() << '\n';
	}

	std::cout << "tecle <enter> para sair" << std::endl;
	std::cin.ignore( 0xFFFF, '\n');
	std::cin.get();

	std::cout << "* main: removendo os arquivos de teste" << std::endl;
	for ( int file = 0; file < totalFiles; ++file )
		QFile::remove (QString("file_%1.dat").arg(file+1, 3, 10, QChar('0')));

	return 0;
 }
 
 // função para buscar arquivos recursivamente
// percorrendo subdiretórios a partir de um diretório inicial:
 QStringList findFiles(const QString &startDir, QStringList filters)
 {
	QStringList names;
	QDir dir(startDir);

	foreach (QString file, dir.entryList(filters, QDir::Files))
		names += startDir + "/" + file;

	foreach (QString subdir, dir.entryList
							(QDir::AllDirs | QDir::NoDotAndDotDot))
	{
		names += findFiles(startDir + "/" + subdir, filters);
		std::cout << ".";
	}
	return names;
 }

 // função que contará as palavras em um arquivo
// usando um único thread:
QMap<QString, int> singleThreadedCountWords(QStringList files)
{
	if ( g_verbose )
		std::cout << "begin singleThreadedCountWords<QString, int>() - thread " << (unsigned int)(QThread::currentThreadId())  << std::endl;
	
	QMap<QString, int> wordsTotal;
	foreach (QString file, files) 
	{
		QFile f(file);
		f.open(QIODevice::ReadOnly);
		QTextStream textStream(&f);
		while (textStream.atEnd() == false)
		{
			foreach(QString word, textStream.readLine().split(" "))
			{
				word = word.trimmed(); // retira brancos, '\n', etc, no início e no fim da palavra;
				if ( !word.isEmpty() )
					wordsTotal[word] += 1;
			}
		}
	}
	if ( g_verbose )
		std::cout << "end singleThreadedCountWords<QString, int>() - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
	
	return wordsTotal;
}

// Conta as palavras existentes em um único arquivo,
// criando um mapa de totais para as palavras diferentes existentes nesse arquivo.
// Chamada por diversos threads, cada qual tratando um arquivo.
// Deve ser "thread-safe".
QMap<QString, int> countWords(const QString &file)
{
	if ( g_verbose )
	{
		mut_cout.lock();
		std::cout << "begin countWords() - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
		mut_cout.unlock();
	}

	QFile f(file);
	f.open(QIODevice::ReadOnly);
	QTextStream textStream(&f);
	QMap<QString, int> wordsInThisFile;

	while (textStream.atEnd() == false)
	{
		// separa palavras entre espaços em branco:
		foreach (QString word, textStream.readLine().split(" "))
		{
			word = word.trimmed(); // retira brancos, '\n', etc, no início e no fim da palavra;
			if ( !word.isEmpty() )
				wordsInThisFile[word] += 1; // busca "word" no map; se já estiver lá apenas soma mais 1 no valor associado
											// do contrário, insere "word" e inicia o valor associado com 0+1.
		}
	}

	if ( g_verbose )
	{
		mut_cout.lock();
		std::cout << "end countWords() - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
		mut_cout.unlock();
	}
	return wordsInThisFile;

}

 // A função "reduce" totaliza os resultados do "map" que recebe como segundo argumento
//  - e que será o resultado da função "countWords"-
// de forma a criar um totalizador único para a quantidade de palavras encontradas em todos os arquivos processados.
// Esse resultado é gravado no "map" que é o seu primeiro argumento.
 // Ela é executada em um único thread a cada vez.
void reduce(QMap<QString, int> &result_WordsInAllFiles, const QMap<QString, int> & wordsInOneFile)
{
	if ( g_verbose )
	{
		mut_cout.lock();
		std::cout << "\tbegin reduce() -resultSize: " << result_WordsInAllFiles.size() << " -wSize: " << wordsInOneFile.size()
								<< " - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
		mut_cout.unlock();
	}

	QMapIterator<QString, int> i (wordsInOneFile);
	while (i.hasNext()) 
	{
		i.next();
		result_WordsInAllFiles[i.key()] += i.value();
	}

	if ( g_verbose )
	{
		mut_cout.lock();
			std::cout << "\tend reduce() -resultSize: " <<result_WordsInAllFiles.size() << " -wSize: " << wordsInOneFile.size()
								<< " - thread " << (unsigned int)(QThread::currentThreadId()) << std::endl;
		mut_cout.unlock();
	}
}

 #else

int main()
{
	std::cout << "Qt Concurrent is not yet supported on this platform" << std::endl;
	return 0;
}

#endif


