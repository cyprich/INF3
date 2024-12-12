#pragma once
#include <fstream>
#include "ZoznamLiniek.h"

using namespace std;

class Vypisovac
{
private:
	string nazovSuboru = "";
	ofstream subor;
public:
	Vypisovac() {};
	Vypisovac(string nazovSuboru);
	~Vypisovac();

	void Vypis(ZoznamLiniek* zoznam);
};

