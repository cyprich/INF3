#include "Sifrator.h"
#include "Helper.h"
#include "Help.h"
#include "Vstup.h"
#include "Vystup.h"
#include "Koder.h"
#include <cctype>
#include <cstring>

Sifrator::Sifrator(unsigned int pPocetParametrov, const char* pParametre[])
{
	if (pPocetParametrov > 0)
	{
		cinnost = tolower(pParametre[0][0]);

		cinnost = cinnost != 's' && cinnost != 'd' ? 'h' : cinnost;

		if (pPocetParametrov > 1)
		{
			heslo = KopirujText(pParametre[1]);

			if (pPocetParametrov > 2)
			{
				nazovVstupnySubor = (char*)KopirujText(pParametre[2]);

				if (pPocetParametrov > 3)
				{
					konzola = tolower(pParametre[3][0] != 's');

					if (pPocetParametrov > 4)
					{
						nazovVystupnySubor = (char*)KopirujText(pParametre[4]);
					}
				}
			}

			if (!(heslo && *heslo)) { cinnost = 'h'; }
			if (!(nazovVstupnySubor && *nazovVstupnySubor)) { cinnost = 'h'; }
			if (!(nazovVystupnySubor && *nazovVystupnySubor)) { konzola = true; }
		}
	}
}

void Sifrator::Start()
{
	if (cinnost == 'h')
	{
		Help().Napoveda();
	} else
	{
		unsigned char* zdrojText = Vstup().Citaj(nazovVstupnySubor);
		if (zdrojText)
		{
			unsigned char* zasifrovanyText = cinnost == 's' ? Koder().Koduj(heslo, zdrojText) : Koder().Dekoduj(heslo, zdrojText);
			if (zasifrovanyText != nullptr)
			{
				if (konzola)
				{
					Vystup().VystupKonzola(zasifrovanyText);
				} else
				{
					Vystup().VystupSubor(nazovVystupnySubor, zasifrovanyText);
				}
				// dealokuj zasifrovany text
				// delete[] zasifrovanyText;
			}
			// dealokuj zdrojovy text
			// delete[] zdrojText;
		}
	}
}
