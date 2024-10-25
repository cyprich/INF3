#include <iostream>

void vypis_hodnoty_pola(int* pole, int velkost_pola);
void vymen_hodnoty_pola(int& a, int& b);

int main()
{
	// smernik na jednu hodnotu
	int plat = 1500;
	int* plat_ptr = &plat;

	*plat_ptr += 100;

	int** ptr_ptr = &plat_ptr;


	// polia
	int pole_platov[3] = { 1500, 1600, 1700 };
	int tim_pocet = 4;
	int* tim_pole_platov = new int[tim_pocet];
	tim_pole_platov[0] = 1600;
	tim_pole_platov[1] = 1450;
	tim_pole_platov[2] = 1700;
	tim_pole_platov[3] = 1550;

	vypis_hodnoty_pola(tim_pole_platov, tim_pocet);
	int* clen2 = &tim_pole_platov[1];
	*clen2 = 1800;
	vypis_hodnoty_pola(tim_pole_platov, tim_pocet);

	int* clen = clen2 + 1;

	std::cout << (clen > clen2) << std::endl << std::endl;

	vymen_hodnoty_pola(tim_pole_platov[1], tim_pole_platov[2]);
	vypis_hodnoty_pola(tim_pole_platov, tim_pocet);


	// viacrozmerne polia
	


	delete[] tim_pole_platov;

	return 0;
} 


void vypis_hodnoty_pola(int* pole, int velkost_pola)
{
	for (int i = 0; i < velkost_pola; i++)
	{
		std::cout << pole[i] << std::endl;
	}
	std::cout << std::endl;
}

void vymen_hodnoty_pola(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
