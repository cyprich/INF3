#include <stdlib.h>
#include <time.h>
#include "losovanie.h"

void Vymen(MUINT index, MUINT i);

void LosujZreby(MUINT pocetLosovanych) {
	if (pocetLosovanych > CelkovyPocetZrebov) {
		pocetLosovanych = CelkovyPocetZrebov;
	}

	srand(time(NULL));
	
	for (MUINT i = 0; i < pocetLosovanych; i++) {
		MUINT index = rand() % (CelkovyPocetZrebov - i) + i;
		Vymen(index, i);
	}
}

// vymeni 2 prvky pola
void Vymen(MUINT index, MUINT i) {
	struct Zreb pomocna;

	pomocna = Zreby[index];
	Zreby[index] = Zreby[i];
	Zreby[i] = pomocna;
}
