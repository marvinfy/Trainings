#ifndef MINHALIB_H
#define MINHALIB_H

#include <QtCore/qglobal.h>

// no arquivo .pro, esta definido:
// DEFINES += MINHALIB_LIBRARY

#if defined(MINHALIB_LIBRARY)

// estou compilando a biblioteca "MinhaLib"

#  define MINHALIBSHARED_EXPORT Q_DECL_EXPORT

#else

		// estou compilando um cliente da biblioteca "MinhaLib"

#  define MINHALIBSHARED_EXPORT Q_DECL_IMPORT
#endif

class MINHALIBSHARED_EXPORT MinhaLib {
public:
    MinhaLib();

	 int func0();  // função membra
};

// funções globais:
MINHALIBSHARED_EXPORT int func1();
extern "C" MINHALIBSHARED_EXPORT int func2();
int func3();

#endif // MINHALIB_H
