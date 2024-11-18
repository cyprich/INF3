#include "Koder.h"
#include "Heslo.h"
#include <cstdlib>
#include <cstring>
#include <stdio.h>

void Koder::ZakodujTabulku(const unsigned char* pHeslo)
{
    int nasada = Heslo(pHeslo).DajNasadu();
    srand(nasada);
    for (int i = 0; i < DLZKA_TABULKY; i++)
    {
        int index = rand() % DLZKA_TABULKY-i;
        Vymen(Tabulka[i], Tabulka[index]);
    }
}

unsigned char* Koder::ZakodujText(const unsigned char* pTextNaZakodovanie, int dlzka)
{
    unsigned char* zakodovanyText = new unsigned char[dlzka];
    for (int i = 0; i < dlzka; i++)
    {
        zakodovanyText[i] = Tabulka[pTextNaZakodovanie[i]];
    }
    return zakodovanyText;
}

unsigned char* Koder::ZasifrujText(const unsigned char* pTextNaZasifrovanie, int dlzka)
{
    unsigned char* zasifrovanyText = new unsigned char[dlzka * 3 + 1] {};
    unsigned char* pomPtr = zasifrovanyText;

    for (int i = 0; i < dlzka; i++)
    {
        sprintf((char*)pomPtr, "%03u", pTextNaZasifrovanie[i]);
        pomPtr += 3;
    }

    return zasifrovanyText;
}

void Koder::Vymen(unsigned char& a, unsigned char& b)
{
    unsigned char c = a;
    a = b;
    b = c;
}

void Koder::ObratTabulku()
{
    unsigned char pomTabulka[DLZKA_TABULKY];

    for (int i = 0; i < DLZKA_TABULKY; i++)
    {
        pomTabulka[Tabulka[i]] = i;
    }
    memmove(Tabulka, pomTabulka, DLZKA_TABULKY*sizeof(unsigned char));
}

int* Koder::VytvorPoleIndexov(const unsigned char* pTextNaDekodovanie, int dlzka)
{
    int* poleIndexov = new int[dlzka/3];
    unsigned char* pomBuf[4]{};
    int k = 0;
    for (int i = 0; i < dlzka; i+=3)
    {
        memmove(pomBuf, &pTextNaDekodovanie[i], 3*sizeof(unsigned char));
        poleIndexov[k++] = atoi((char*)pomBuf);
    }

    return poleIndexov;
}

unsigned char* Koder::DesifrujText(int* poleIndexov, int dlzka)
{
    unsigned char* desifrovanyText = new unsigned char[dlzka + 1] {};
    
    for (int i = 0; i < dlzka; i++)
    {
        desifrovanyText[i] = Tabulka[poleIndexov[i]];
    }

    return desifrovanyText;
}


Koder::Koder()
{
    for (int i = 0; i < DLZKA_TABULKY; i++)
    {
        Tabulka[i] = i;
    }
}

unsigned char* Koder::Koduj(const unsigned char* pHeslo, const unsigned char* pTextNaZakodovanie)
{
    ZakodujTabulku(pHeslo);
    int dlzka = strlen((char*) pTextNaZakodovanie);
    unsigned char* zakodovanyText = ZakodujText(pTextNaZakodovanie, dlzka);
    unsigned char* zasifrovanyText = ZasifrujText(zakodovanyText, dlzka);
    delete[] zakodovanyText;
    
    return zasifrovanyText;
}

unsigned char* Koder::Dekoduj(const unsigned char* pHeslo, const unsigned char* pTextNaDekodovanie)
{
    ZakodujTabulku(pHeslo);
    ObratTabulku();
    int dlzka = strlen((char*)pTextNaDekodovanie);

    int* poleIndexov = VytvorPoleIndexov(pTextNaDekodovanie, dlzka); 
    unsigned char* desifrovanyText = DesifrujText(poleIndexov, dlzka/3);
    delete[] poleIndexov;

    return desifrovanyText;
}
