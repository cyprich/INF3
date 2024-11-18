#include "LPole.h"

LPole::LPole(int pocet)
{
	velkost = pocet;
	data = new long[velkost];
}

LPole::LPole(int pocet, long* hodnoty)
{
	velkost = pocet;
	data = new long[pocet];

	for (int i = 0; i < pocet; i++)
	{
		data[i] = hodnoty[i];
	}
}

LPole::~LPole()
{
	delete[] data;
}
