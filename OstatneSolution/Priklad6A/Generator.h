#pragma once
#include "Data.h"
#include "Pole.h"

class GeneratorPola
{
public:
	GeneratorPola() = default;
	MUINT generujCislo();
	Pole generujPole(MUINT pocetPrvkov);
};

