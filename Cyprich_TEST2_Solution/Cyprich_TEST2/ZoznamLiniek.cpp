#include "ZoznamLiniek.h"
#include <fstream>
#include <iostream>

ZoznamLiniek::ZoznamLiniek()
{
	zoznam = new Linka * [kapacita];
}

ZoznamLiniek::~ZoznamLiniek()
{
	for (int i = 0; i < pocetLiniek; i++)
	{
		delete zoznam[i];
	}

	delete[] zoznam;
	pocetLiniek = 0;
}

void ZoznamLiniek::pridajLinku(string pCislo, string pPrepravca, int pCena, int pMaxKapacita, int pPocetLetov)
{
	if (pocetLiniek >= kapacita)
	{
		kapacita *= 2;
		Linka** temp_zoznam = new Linka * [kapacita];
		for (int i = 0; i < pocetLiniek; i++)
		{
			temp_zoznam[i] = zoznam[i];
		}

		delete[] zoznam;
		zoznam = temp_zoznam;
	}

	zoznam[pocetLiniek] = new Linka(pCislo, pPrepravca, pCena, pMaxKapacita, pPocetLetov);	
	pocetLiniek++;
}

void ZoznamLiniek::nacitajZoSuboru(char* nazovSuboru)
{
	ifstream subor(nazovSuboru);

	if (!subor.is_open())
	{
		cout << "Nepodarilo sa nacitat subor " << nazovSuboru << "..." << endl;
		exit(1);
	}

	int temp_cena, temp_maxKapacita, temp_pocetLetov;
	string temp_cislo, temp_prepravca;

	while (subor >> temp_cislo >> temp_prepravca >> temp_cena >> temp_maxKapacita >> temp_pocetLetov)
	{
		pridajLinku(temp_cislo, temp_prepravca, temp_cena, temp_maxKapacita, temp_pocetLetov);
	}

	subor.close();
}

string ZoznamLiniek::get()
{
	string out;

	for (int i = 0; i < pocetLiniek; i++)
	{
		out += zoznam[i]->get();
	}

	return out;
}


