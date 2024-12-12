#include "Linka.h"
#include <iostream>
#include "random"
#include <cmath>
#include <sstream>
#include <iomanip>


Linka::Linka(string pCislo, string pPrepravca, int pCena, int pMaxKapacita, int pPocetLetov)
	: cislo(pCislo), prepravca(pPrepravca), cena(pCena), maxKapacita(pMaxKapacita), pocetLetov(pPocetLetov)
{
	for (int i = 0; i < pocetLetov; i++)
	{
		lety[i] = new Let(pMaxKapacita);
		celkovyPocetCestujucich += lety[i]->getPocet();
		celkovaTrzba += lety[i]->getPocet() * cena;
	}

	vyuzitelnost = (double)celkovyPocetCestujucich / (maxKapacita * pocetLetov);
}

Linka::~Linka()
{
	for (int i = 0; i < pocetLetov; i++)
	{
		delete lety[i];
	}

	delete[] lety;
	pocetLetov = 0;
}

string Linka::get()
{
	std::stringstream vyuzitelnost_zaokr;
	vyuzitelnost_zaokr << std::fixed << std::setprecision(2) << vyuzitelnost;

	//string out = cislo + " [" + to_string(celkovyPocetCestujucich) + "] " + to_string((int)celkovaTrzba) + " " + to_string(vyuzitelnost) + "\n";
	string out = cislo + " - " + prepravca + " [" + to_string(celkovyPocetCestujucich) + "] " + to_string((int)celkovaTrzba) + " " + vyuzitelnost_zaokr.str() + "\n";

	return out;
}
