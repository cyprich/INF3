#pragma once
#include "Data.h"

class Pole
{
private:
	MUINT pocetPrvkov;
	MUINT* pole;

public:
	Pole(MUINT pocetPrvkov);
	~Pole();

	// gettery
	MUINT* getPole() { return pole; }
	MUINT getHodnota(MUINT poradoveCisloHodnoty);
	MUINT getPocetPrvkov() { return pocetPrvkov; };

	void pridajDoPola(MUINT pozicia, MUINT hodnota);
};

