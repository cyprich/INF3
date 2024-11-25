#include "DPole.h"
#include "VynimkaIndex.h"
#include <iostream>

DPole::DPole(int pDolnyIndex, int pPocetPrvkov, double pInitHodnota)
	: dolnyIndex(pDolnyIndex), pocetPrvkov(pPocetPrvkov),
		data(pocetPrvkov > 0 ? new double[pocetPrvkov] : nullptr)
{
	for (size_t i = 0; i < pocetPrvkov; i++)
	{
		data[i] = pInitHodnota;
	}

	//if (_DEBUG) { cout << "Konstruktor DPole" << endl; }
}

DPole::DPole(const DPole& zdroj): DPole{zdroj.dolnyIndex, zdroj.pocetPrvkov}
{
	for (size_t i = 0; i < pocetPrvkov; i++)
	{
		data[i] = zdroj.data[i];
	}
}
/*
DPole::DPole(const DPole& zdroj) : dolnyIndex(zdroj.dolnyIndex), pocetPrvkov(zdroj.pocetPrvkov), data(pocetPrvkov > 0 ? new double[pocetPrvkov] : nullptr);
{
	for (size_t i = 0; i < pocetPrvkov; i++)
	{
		data[i] = zdroj.data[i];
	}
}
*/

DPole::~DPole()
{
	delete[] data;
	pocetPrvkov = 0;
	dolnyIndex = 0;

	//if (_DEBUG) { cout << "Destruktor DPole" << endl; }
}

DPole& DPole::operator=(const DPole& zdroj)
{
	if (this != &zdroj)
	{
		DPole::~DPole();
		dolnyIndex = zdroj.dolnyIndex;
		pocetPrvkov = zdroj.pocetPrvkov;
		data = pocetPrvkov > 0 ? new double[pocetPrvkov] : nullptr;
		
		for (size_t i = 0; i < pocetPrvkov; i++)
		{
			data[i] = zdroj.data[i];
		}
	}

	return *this;
}

double& DPole::operator[](int index)
{
	if (data != nullptr)
	{
		if (index < dolnyIndex)
		{
			throw VynimkaDolnyIndex(dolnyIndex);
		}

		int hornyIndex = dolnyIndex + pocetPrvkov - 1;

		if (index > hornyIndex)
		{
			throw VynimkaHornyIndex(hornyIndex);
		}

		return data[index - dolnyIndex];
	}
	
	throw VynimkaIndex(-1, "Prazdne pole!");
}

ostream& operator<<(ostream& os, DPole& pObjekt)
{
	for (int i = pObjekt.dolnyIndex; i < pObjekt.pocetPrvkov + pObjekt.dolnyIndex; i++)
	{
		os << "[" << i << "] " << pObjekt[i] << endl;
	}
	
	return os; 
}
