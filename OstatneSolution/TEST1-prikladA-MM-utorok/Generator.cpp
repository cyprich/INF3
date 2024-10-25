#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "Generator.h"

Generator::Generator()
{
	pole = nullptr;
	velkost_pola = 0;
	srand(time(NULL));
}

Generator::~Generator()
{
	delete[] pole;
}

int Generator::generuj_cislo(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int Generator::generuj_cislo(int limit)
{
	return generuj_cislo(1, limit);
}

int* Generator::generuj_zoznam(int min, int max, int pocet_prvkov)
{
	pole = new int[pocet_prvkov];
	velkost_pola = pocet_prvkov;

	for (int i = 0; i < velkost_pola; i++)
	{
		pole[i] = generuj_cislo(min, max);
	}

	return pole;
}

void Generator::vypis_zoznam()
{
	if (pole == nullptr || velkost_pola == 0) {
		std::cout << "Zoznam zatial nebol vygenerovany..." << std::endl;
		std::cout << "Vygenerujte zoznam pomocou metody generuj_zoznam() a potom skuste znova" << std::endl;
		return;
	}

	for (int i = 0; i < velkost_pola; i++)
	{
		std::cout << pole[i] << " ";
	}
	std::cout << std::endl;
}
