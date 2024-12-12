#include "Let.h"
#include <random>

Let::Let(int pKapacita)
{
	pocetCestujucich = 10 + rand() % (kapacita - 10 + 1);  // nahodne z intervalu <10, maxKapacita>
}
