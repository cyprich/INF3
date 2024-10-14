#include "Vystup.h"

Vystup::Vystup(const char* menoSuboru) {
	// ak nie null a existuje nulty znak 
	// if (menoSuboru != nullptr && menoSuboru[0] != '\0')
	if (menoSuboru != nullptr && *menoSuboru) {

	// wt = write text - mozeme zapisovat plain text (nie binary)
	fHandle = fopen(menoSuboru, "wt");
	}
}

Vystup::~Vystup()
{
	if (fHandle) {
		fclose(fHandle);
	}

	fHandle = nullptr;
}

void Vystup::Zapis(DataTyp hodnota)
{
	if (fHandle) {
		fprintf(fHandle, "%d\n", hodnota);
	}
	else {
		printf("%d\n", hodnota);
	}
}
