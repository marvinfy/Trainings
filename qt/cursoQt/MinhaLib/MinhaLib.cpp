#include <MinhaLib.h>

MinhaLib::MinhaLib()
{
}

int MinhaLib::func0()
{
	return 0;
}

MINHALIBSHARED_EXPORT int func1()
{
	return 1;
}

extern "C" MINHALIBSHARED_EXPORT int func2()
{
	return 2;
}

int func3()
{
	return 3;
}
