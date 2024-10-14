#pragma once
#include <cstdio>
#include "Data.h"

class Vystup
{
private:
	FILE* fHandle = nullptr;
public:
	/// <summary>
	/// Konstruktor. Otvara subor na zapis
	/// </summary>
	/// <param name="menoSuboru">Nazov suboru</param>
	Vystup(const char* menoSuboru);

	/// <summary>
	/// Destruktor. Zatvara subor
	/// </summary>
	~Vystup();

	void Zapis(DataTyp hodnota);
};
