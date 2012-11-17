#ifndef FUNCOESDLL_H
#define FUNCOESDLL_H

#include "08_01_Dll_global.h"

// classe exportável:
class DLL_08_01_DLLSHARED_EXPORT FuncoesDll
{
public:
    FuncoesDll();
	int  func(int x);
};

// função exportável:
extern "C" DLL_08_01_DLLSHARED_EXPORT int func1(int x );

// função NÃO-exportável (checar versão do GCC)
int  func2(int x );

#endif // FUNCOESDLL_H
