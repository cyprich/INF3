#include "Generator.h"
#include <random>
#include <iostream>

Generator::Generator()
{
	int* pole = NULL;
	int pocet_prvkov = 0;
	srand(time(NULL));
}

Generator::~Generator()
{
	delete[] this->pole;
	this->pole = NULL;
	this->pocet_prvkov = 0;
}

int Generator::generuj_cislo(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

int* Generator::generuj_zoznam(int min, int max, int pocet_prvkov)
{
	if (pocet_prvkov == 0)
	{
		std::cout << "Pocet prvkov pola nemoze byt mensi ako 1" << std::endl;
		return NULL;
	}

	this->pocet_prvkov = pocet_prvkov;

	delete[] this->pole;
	this->pole = new int[pocet_prvkov];

	for (int i = 0; i < pocet_prvkov; i++)
	{
		this->pole[i] = generuj_cislo(min, max);
	}

	return this->pole;
}