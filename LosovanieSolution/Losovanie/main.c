#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define _TESTY

#ifdef _DEBUG
#include "testy.h"
#endif 

int main(int argc, char* argv[]) {
	bool ok = true;

	#ifdef _DEBUG
	ok = Testuj();
	#endif // _DEBUG

	if (ok) {
		MUINT celkovyPocet = 0;
		MUINT pocetZrebovanych = 0;
		
		if (argc > 1) {
			celkovyPocet = atoi(argv[1]);
			//sscanf(argv[1], "%", &celkovyPocet);
			
			if (argc > 2) {
				pocetZrebovanych = atoi(argv[2]);
			}
			else {
				pocetZrebovanych = celkovyPocet;
			}

			TahLoterie(celkovyPocet, pocetZrebovanych);
		}
	}
	else {
		printf("Chyba! Testy neprebehli\n");
	}

	return 0;
}
