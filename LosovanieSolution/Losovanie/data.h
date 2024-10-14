#pragma once
#include <stdbool.h>

// defincia datoveho typu
struct Zreb
{
	unsigned int Cislo;
	char Kod;
};

// #define	MUINT unsigned int;  // nerobi sa typova kontrola

// better definicia vlastneho typu
typedef unsigned int MUINT;


// deklaracia celociselnej premennej
extern unsigned int CelkovyPocetZrebov;

// deklaracia smernika typu struct Zreb
extern struct Zreb* Zreby;

// deklaracia (hlavicka, prototyp) funkcie
// alokuje (vytvori) miesto v pamati pre pole zrebov
bool PripravZreby();

// dealokuje (uvolni) pole zrebov v pamati
void ZrusZreby();
