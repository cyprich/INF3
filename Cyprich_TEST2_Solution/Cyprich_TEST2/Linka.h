#pragma once
#include <string>
#include "Let.h"

using namespace std;

class Linka
{
private:
	int cena = 0, maxKapacita = 0, pocetLetov = 0, celkovaTrzba = 0, celkovyPocetCestujucich = 0;
	string cislo, prepravca;

	Let** lety = new Let*[pocetLetov];
	double vyuzitelnost = 0;

public:
	Linka(string pCislo, string pPrepravca, int pCena, int pMaxKapacita, int pPocetLetov);
	~Linka();

	string get();
	double getVyuzitelnost() { return vyuzitelnost; };
};
