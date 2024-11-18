#include "Vstup.h"
#include <fstream>

using namespace std;

size_t Vstup::DlzkaSuboru(const char* pNazovSuboru)
{
	ifstream citac(pNazovSuboru);
	if (citac.is_open())
	{
		citac.seekg(0, SEEK_END);
		int dlzka = citac.tellg();
		return dlzka;
	}

	return 0;
}

unsigned char* Vstup::Citaj(const char* pNazovSuboru)
{
	int dlzka = DlzkaSuboru(pNazovSuboru);
	
	if (dlzka > 0)
	{
		ifstream citac(pNazovSuboru);
		unsigned char* text = new unsigned char[dlzka + 1] {};
		citac.read((char*)text, dlzka);
		return text;
	}
	
	return nullptr;
}
