#include "data.h"
#include <malloc.h>

// definicia celociselnej premennej a jej inicializacia
unsigned int CelkovyPocetZrebov = 0;

// definicia premennej typu smernik
struct Zreb* Zreby = NULL;


// definicia funkcie 
bool PripravZreby()
{
	if (CelkovyPocetZrebov == 0) return false;

	Zreby = malloc(CelkovyPocetZrebov * sizeof(struct Zreb));
	// Zreby = calloc(CelkovyPocetZrebov, sizeof(struct Zreb));  // malloc + vynuluje obsah prvkov

	if (Zreby != NULL) {
		for (unsigned i = 0; i < CelkovyPocetZrebov; i++)
		{
			Zreby[i].Cislo = i + 1;
			Zreby[i].Kod = 'A' + i % 26;
		}
		return true;
	}

	return false;
}


void ZrusZreby()
{
	if (Zreby != NULL) {
		free(Zreby);
	}

	Zreby = NULL;  // dolezite!!
}
