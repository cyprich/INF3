#include "Helper.h"

unsigned char* KopirujText(const unsigned char* zdroj)
{
	int dlzka = strlen((char*)zdroj);
	unsigned char* ciel(new unsigned char[dlzka + 1]);
	strcpy((char*)ciel, (char*)zdroj);
	return ciel;
}

unsigned char* KopirujText(char* zdroj)
{
	return KopirujText((unsigned char*) zdroj);
}
