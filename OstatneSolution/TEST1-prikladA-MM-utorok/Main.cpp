#include <iostream>
#include "Generator.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

void vymen(int& a, int& b);

int main(int argc, char* argv[])
{
	// kontrola poctu parametrov
	if (argc < 4)
	{
		std::cout << "Zadany pocet parametrov je " << argc - 1 << " namiesto 3" << std::endl;
		std::cout << "Prosim zadajte parametre pre minimalnu a maximalnu hodnotu a pocet prvkov, potom spustite program znova" << std::endl;
		return 1;
	}

	// konverzia parametrov na integer
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int pocet = atoi(argv[3]);

	// prehodenie min a max v pripade min > max
    if (min > max)
	{
		vymen(min, max);
	}

	// vytvorenie generatora a pola
	Generator* generator = new Generator();
	int* pole = generator->generuj_zoznam(min, max, pocet);
	generator->vypis_zoznam();
	
	// indexy na vymenenie elementov v poli
	int index1 = generator->generuj_cislo(pocet);
	int index2 = generator->generuj_cislo(pocet);	

	// ak by sa nahodou indexy rovnali
	while (index1 == index2) { int index2 = generator->generuj_cislo(pocet); } 
	
	// kod by fungoval aj bez tohto, ale lepsie to takto vyzera vo vypise
	if (index1 > index2) { vymen(index1, index2); }

	// vymena elementov
	std::cout << "Vymienam " << (index1 - 1) << ". a " << (index2 - 1) << ". element pola (" << pole[index1] << " a " << pole[index2] << ")" << std::endl;
	vymen(pole[index1], pole[index2]);
	generator->vypis_zoznam();

	delete generator;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

void vymen(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
