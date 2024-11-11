#pragma once
/// <summary>
/// Manager sifrovania textovania textoveho suboru
/// </summary>
class Sifrator
{
private:
	char cinnost = 'h';
	unsigned char* heslo = nullptr;
	char* nazovVstupnySubor = nullptr;
	bool konzola = true;
	char* nazovVystupnySubor = nullptr;

public:
	/// <summary>
	/// Konverzny konstruktor
	/// Konvertuje 2 parametre na objekt triedy Sifrator
	/// </summary>
	/// <param name="pPocetParametrov">Pocet vstpnych parametrov</param>
	/// <param name="pParametre">Pole retazcov s parametrami</param>
	Sifrator(unsigned int pPocetParametrov, const char* pParametre[]);
	~Sifrator()
	{
		delete[] nazovVystupnySubor;
		delete[] nazovVstupnySubor;
		delete[] heslo;
	};
	void Start();
};
