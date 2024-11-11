#include "Test.h"
#include "Sifrator.h"
#include "Vstup.h"
#include "Vystup.h"
#include "VystupSubor.h"
#include "VystupDisplej.h"
#include "Koder.h"
#include "Heslo.h"

bool Test::Start()
{
	const char* parametre[]{ "xxx" };
	Sifrator(1, parametre).Start();

	Vstup citac;
	citac.Citaj("test.txt");

	Vystup* zapisovacPrt(new Vystup);
	zapisovacPrt->VystupKonzola((const unsigned char*)"");
	zapisovacPrt->VystupSubor((const char*)"test.out", (const unsigned char*)"");
	delete zapisovacPrt;

	VystupSubor zapisovacSubor("test.out");
	zapisovacSubor.Uloz((const unsigned char*)"xxxx");

	VystupDisplej zapisovacKonzola;
	zapisovacKonzola.Vypis((const unsigned char*)"abcd");

	Koder koder;
	unsigned char* zakodovanyText = koder.Koduj((unsigned char*)"1234", (unsigned char*)"ABC");
	koder.Dekoduj((unsigned char*)"1234", zakodovanyText);

	Heslo paswd((unsigned char*)"1234");
	int nasada = paswd.DajNasadu();

	return true;
}
