#include "loteria.h"
#include "losovanie.h"
#include "vystup.h"

void TahLoterie(MUINT celkovyPocetZrebov, MUINT pocetZrebovanych)
{
	CelkovyPocetZrebov = celkovyPocetZrebov;

	if (PripravZreby()) {
		LosujZreby(pocetZrebovanych);
		VypisVylosovaneZreby(pocetZrebovanych);
		ZrusZreby();
	};
}
