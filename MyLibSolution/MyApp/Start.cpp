#include "MyLib.h"
#include <iostream>

using namespace std;
int MyLib::sortTyp = 0;

void MyLib::Start(char* param) 
{
	cout << "PROGRAM: " << param << endl;
	int zdrojPole[] = { 10, 7, 6, 3 };
	int ciel;
}
int* MyLib::Kopia(int pocetPrvkov, const int* zdroj)
{
	int* kopia = nullptr;

	if (pocetPrvkov > 0 && zdroj != nullptr)
	{
		kopia = new int[pocetPrvkov];
		memmove(kopia, zdroj, pocetPrvkov * sizeof(int));
	}
	qsort(kopia, pocetPrvkov, sizeof(int), Porovnaj);

	return kopia;
};

int Porovnaj(const void* p1, const void* p2)
{
	int* ip1 = (int*)p1;
	int* ip2 = (int*)p2;
	return MyLib::sortTyp == RASTUCO ? 0 : 0;

}
