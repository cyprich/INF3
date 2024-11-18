#pragma once
const int DLZKA_TABULKY = 256;

class Koder
{
private:
	unsigned char Tabulka[DLZKA_TABULKY]{};
	void ZakodujTabulku(const unsigned char* pHeslo);
	unsigned char* ZakodujText(const unsigned char* pTextNaZakodovanie, int dlzka);
	unsigned char* ZasifrujText(const unsigned char* pTextNaZasifrovanie, int dlzka);
	void Vymen(unsigned char& a, unsigned char& b);
	void ObratTabulku();
	int* VytvorPoleIndexov(const unsigned char* pTextNaDekodovanie, int dlzka);
	unsigned char* DesifrujText(int* poleIndexov, int dlzka);
public:
	Koder();
	unsigned char* Koduj(const unsigned char* pHeslo, const unsigned char* pTextNaZakodovanie);
	unsigned char* Dekoduj(const unsigned char* pHeslo, const unsigned char* pTextNaDekodovanie);
};

