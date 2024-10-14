#pragma once
#include <cstdio>
#include "Data.h"


class Vstup
{
private:
	FILE* fHandle = nullptr;
public:
	/// <summary>
	/// Konstruktor. Otvara subor na citanie
	/// </summary>
	/// <param name="menoSuboru">Nazov suboru</param>
	Vstup(const char* menoVstupnehoSuboru);

	/// <summary>
	/// Destruktor. Zatvara subor
	/// </summary>
	~Vstup();

	DataTyp Citaj();
};


