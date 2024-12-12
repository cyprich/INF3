#include <string>
#include <iostream>
#include "ZoznamLiniek.h"
#include "Vypisovac.h"

using namespace std;

int main(int argc, char* argv[])
{
	char* cesta;
	if (argc < 2)
	{
		cout << "Nezadali ste vstupny parameter - cesta k suboru na nacitanie..." << endl;
		exit(1);
	} 

	srand(time(NULL));

	cesta = argv[1];
	
	ZoznamLiniek* zoznam = new ZoznamLiniek();
	zoznam->nacitajZoSuboru(argv[1]);

	Vypisovac* vypisovacKonzola = new Vypisovac();
	Vypisovac* vypisovacSubor = new Vypisovac("out.txt");
	
	vypisovacKonzola->Vypis(zoznam);
	vypisovacSubor->Vypis(zoznam);

	delete vypisovacSubor;
	delete vypisovacKonzola;
	delete zoznam;

	return 0;
}

