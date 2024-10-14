#include "Pole.h"
#include <iostream>

Pole::Pole(static MUINT pocetPrvkovPola)
{
	pocetPrvkov = pocetPrvkovPola;
	pole = new MUINT[pocetPrvkov];
}

Pole::~Pole()
{
	delete[] pole;
}

MUINT Pole::getHodnota(MUINT poradoveCisloHodnoty)
{
	if (poradoveCisloHodnoty < pocetPrvkov)
	{
		return pole[poradoveCisloHodnoty];
	}

	return 0;
}


void Pole::pridajDoPola(MUINT pozicia, MUINT hodnota)
{
	if (pozicia < pocetPrvkov)
	{
		pole[pozicia] = hodnota;
	}
}

