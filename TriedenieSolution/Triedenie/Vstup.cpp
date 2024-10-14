#include "Vstup.h"

Vstup::Vstup(const char* menoSuboru)
{
	if (menoSuboru && *menoSuboru) {
		// rt = read text 
		fHandle = fopen(menoSuboru, "rt");
	}
}

Vstup::~Vstup()
{
	if (fHandle) {
		fclose(fHandle);
		fHandle = nullptr;
	}
}

DataTyp Vstup::Citaj()
{
	if (fHandle != nullptr) {
		if (!feof(fHandle)) {
			DataTyp cislo;
			fscanf(fHandle, "%d", &cislo);
			return cislo;
		}
	}
	return NEPLATNA_HODNOTA;
}
