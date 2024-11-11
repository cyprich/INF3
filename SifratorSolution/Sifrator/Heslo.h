#pragma once
#include <cstring>

class Heslo
{
	union
	{
		const unsigned char heslo[8];
		long long nasada;
	};

public:
	Heslo(const unsigned char* pHeslo)
	{
		strcpy((char*)heslo, (char*)pHeslo);
	};
	int DajNasadu() { return nasada; };
};

