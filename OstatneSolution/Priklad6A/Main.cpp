/*
zadanie z discordu s nazvom "Priklad 6 A (2022)"

vytvorte projekt pre konzolovu aplikaciu, ktora:  
- pomocou generatora nahodnych cisel vygeneruje pole celych cisel z intervalu <1, 100>
- pocet cisel ktore sa maju vygenerovat bude zadavany ako parameter programu pri jeho starte (napr. "generator 300")
- na obrazovku vypiste vsetky cisla z vygenerovanej postupnosti
- do suboru s nazvom "min50.out" vypiste vsetky cisla z postupnosti ktore su mensie ako 50
*/

#include <iostream>
#include "Data.h"
#include "Generator.h"
#include "Pole.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Nie je zadany parameter o pocte cisel, ktore treba vygenerovat... Program teraz skonci" << std::endl;
		return 1;
	}

	MUINT pocetPrvkov = atoi(argv[1]);

	GeneratorPola generator;
	Pole pole = generator.generujPole(pocetPrvkov);
	//std::cout << pole.getPole() << std::endl;
	//std::cout << pole.getPocetPrvkov() << std::endl;

	return 0;
}
