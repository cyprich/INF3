#include "Heslo.h"
class Heslo
{
private:
	union
	{
		const unsigned char heslo[8]{};
		long long nasada;
	};
public:
	Heslo(const unsigned char* pHeslo)
	{
		strcpy((char*) heslo, (char*)pHeslo);
	}
	int dajNasadu()
	{
		int pom = nasada & 0x00000000ffffffff;
		int pom2 = (nasada >> 32) & 0xffffffff00000000;
		return pom | pom2;
	}
};
