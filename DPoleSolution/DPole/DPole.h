#pragma once
#include <ostream>

using namespace std;

class DPole
{
private:
	int dolnyIndex = 0;
	int pocetPrvkov = 0;
	double* data = nullptr;
public:
	DPole(int pDolnyIndex = 0, int pPocetPrvkov = 0, double pInitHodnota = 0.0);
	DPole(const DPole& zdroj);
	~DPole();

	DPole& operator= (const DPole& zdroj);
	double& operator[] (int index);
	friend ostream& operator<< (ostream& os, DPole& pObjekt);
};
