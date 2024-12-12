#include "Vypisovac.h"
#include <iostream>

Vypisovac::Vypisovac(string pNazovSuboru)
{
	nazovSuboru = pNazovSuboru;

	if (nazovSuboru != "")
	{
		subor = ofstream(nazovSuboru);
	}
}

Vypisovac::~Vypisovac()
{
	if (subor.is_open())
	{
		subor.close();
	}
	nazovSuboru = "";
}


void Vypisovac::Vypis(ZoznamLiniek* zoznam)
{
	if (subor.is_open())
	{
		subor << zoznam->get();
	} else
	{
		cout << zoznam->get();
	}
}
