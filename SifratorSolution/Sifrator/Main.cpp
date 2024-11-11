#define TESTY

#ifdef TESTY
#include "Test.h"
#endif

int main(int argc, char* argv[])
{
	bool OK(true);
#ifdef TESTY
	OK = Test().Start();
#endif 

	if (OK)
	{
		;
	}

	return 0;
}