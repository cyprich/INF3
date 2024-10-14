#include "Generator.h"
#include "Pole.h"
#include <iostream>
#include <random>

MUINT GeneratorPola::generujCislo()
{
	MUINT n = rand() % 100 + 1;
	return n;
}

Pole GeneratorPola::generujPole(MUINT pocetPrvkov)
{
	Pole Pole(pocetPrvkov);

	srand(time(NULL));

	for (MUINT i = 0; i < pocetPrvkov; i++)
	{
		MUINT n = generujCislo();
		Pole.pridajDoPola(i, n);
		std::cout << Pole.getPole() << std::endl << std::endl;
	}

	return Pole;
}

/*
Pole GeneratorPola::generujPole(MUINT pocetPrvkov)
{
	Pole pole(pocetPrvkov);

	srand(time(NULL));

	for (MUINT i = 0; i < pocetPrvkov; i++)
	{
		MUINT n = generujCislo();
		pole.pridajDoPola(i, n);
	}

	return pole;
}
*/
