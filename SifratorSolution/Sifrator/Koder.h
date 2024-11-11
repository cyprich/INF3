#pragma once
class Koder
{
public:
	
	unsigned char* Koduj(const unsigned char* pHeslo, const unsigned char* pTextNaZakodovanie);
	unsigned char* Dekoduj(const unsigned char* pHeslo, const unsigned char* pTextNaDekodovanie);
};

