#pragma once
class Let
{
private:
	int pocetCestujucich = 0, kapacita = 0;

public:
	Let(int pKapacita);
	~Let() {};

	int getPocet() { return pocetCestujucich; };
};
