#pragma once
#include "Linka.h"
#include <string>

class ZoznamLiniek
{
private:
	int kapacita = 2;
	int pocetLiniek = 0;
	Linka** zoznam = nullptr;
public:
	ZoznamLiniek();
	~ZoznamLiniek();

	void pridajLinku(string pCislo, string pPrepravca, int pCena, int pMaxKapacita, int pPocetLetov);
	void nacitajZoSuboru(char* nazovSuboru);
	string get();
};

