#include "funcoesdll.h"


FuncoesDll::FuncoesDll()
{
}
int FuncoesDll::func(int x)
{
	return x + 1;
}

// função exportável:
extern "C" DLL_08_01_DLLSHARED_EXPORT int func1(int x )
{
	return x + 2;
}

// função NÃO-exportável (checar versão do GCC)
int func2(int x )
{
	return x + 3;
}

