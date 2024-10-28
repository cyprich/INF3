#include <iostream>
#include "Generator.h"

void vypis_zoznam(int* zoznam, int dlzka);

int main(int argc, char* argv[])
{
	// neboli zadane vsetky parametre
	if (argc < 4)
	{
		std::cout << "Neboli zadane vsetky parametre" << std::endl;
		std::cout << "Prosim zadajte: pocet prvkov, minimum a maximum. Potom spustite program znova" << std::endl;
		return 1;
	}

	// konverzia vstupnych parametrov na int
	int pocet = atoi(argv[1]);
	int min = atoi(argv[2]);
	int max = atoi(argv[3]);

	// vytvorenie a vypisanie pola
	Generator* generator = new Generator();
	int* pole = generator->generuj_zoznam(min, max, pocet);
	vypis_zoznam(pole, pocet);
	std::cout << std::endl;

	// vypisanie prvku pola s nahodnym indexom
	int index1 = generator->generuj_cislo(0, pocet - 1);
	std::cout << "Prvok s poradovym cislom " << index1+1 << " je " << pole[index1] << std::endl << std::endl;


	// vypis pola bez indexu vygenerovanom v predchadzajucom kroku
	std::cout << "Vsetky prvky pola okrem prvku cislo " << index1+1 << " (" << pole[index1] << "):" << std::endl;
	for (int i = 0; i < pocet; i++)
	{
		if (i != index1)
		{
			std::cout << pole[i] << " ";
		}
	}
	std::cout << std::endl << std::endl;



	return 0;
}

void vypis_zoznam(int* zoznam, int dlzka)
{
	if (zoznam == NULL || dlzka == 0)
	{
		std::cout << "Boli zadane nespravne parametre funkcie" << std::endl;
		return;
	}

	for (int i = 0; i < dlzka; i++)
	{
		std::cout << zoznam[i] << ' ';
	}

	std::cout << std::endl;
}
