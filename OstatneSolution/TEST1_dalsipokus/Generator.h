#pragma once
class Generator
{
private:
	int* pole;
	int pocet_prvkov;
	
public:
	Generator();
	~Generator();
	int generuj_cislo(int min, int max);
	int* generuj_zoznam(int min, int max, int pocet_prvkov);
};
