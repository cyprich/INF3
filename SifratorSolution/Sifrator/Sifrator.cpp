#include "Sifrator.h"
#include "Helper.h"
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
}
