#include "Vystup.h"
#include "VystupSubor.h"
#include "VystupDisplej.h"

void Vystup::VystupSubor(const char* pNazovSuboru, const unsigned char* pText)
{
	VystupSubor::VystupSubor(pNazovSuboru).Uloz(pText);
}

void Vystup::VystupKonzola(const unsigned char* pText)
{
	VystupDisplej::VystupDisplej().Vypis(pText);
}
