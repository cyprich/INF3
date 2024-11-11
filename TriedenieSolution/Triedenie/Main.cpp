#include "Vystup.h"
#include "Zoznam.h"

// Vystup globalZapisovac("GData.out");

int main() {
	Zoznam triedic;
	triedic.Usporiadaj("data.in");
	triedic.Vypis();
	triedic.Uloz("data.out");

	return 0;
}
