#include <stdio.h>
#include "vystup.h"

void VypisVylosovaneZreby(MUINT pocetLosovanychZrebov)
{
	if (pocetLosovanychZrebov > CelkovyPocetZrebov) {
		pocetLosovanychZrebov = CelkovyPocetZrebov;
	}

	for (MUINT i = 0; i < pocetLosovanychZrebov; i++)
	{
		printf("%5u. %c%u\n", i + 1, Zreby[i].Kod, Zreby[i].Cislo);

	}



}
