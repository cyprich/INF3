#pragma once
#include "TUzol.h"

template<typename T>

class TZoznam
{
private:
	TUzol<T>* zaciatok = nullptr;
	void ZaradDoZoznamu(T pHodnota);
	void Vymaz(TUzol<T>* pUzol);

public:
	~TZoznam();
	void Usporiadaj(const char* menoSuboru);
	void Vypis();
};

template<typename T>
inline void TZoznam<T>::ZaradDoZoznamu(T pHodnota)
{
	if (!zaciatok)
	{
		zaciatok = new TUzol<T>(pHodnota, nullptr);
	} else
	{
		TUzol<T> predchodca = nullptr;
		TUzol<T> aktualny = zaciatok;
		T aktialnaHodnota = aktualny->Hodnota();

		while (aktualny && pHodnota > aktialnaHodnota)
		{
			predchodca = aktualny;
			aktualny = aktualny->Nasledujuci();
			
			if (aktualny)
			{
				aktialnaHodnota = aktualny->Hodnota();
			}
		}
		TUzol<T> novy = new TUzol<T>(pHodnota, aktualny);

		if (predchodca)
		{
			predchodca->Nasledujuci(novy);
		} else
		{

		}
	}
}

template<typename T>
inline void TZoznam<T>::Vymaz(TUzol<T>* pUzol)
{
	if (pUzol->Nasledujuci())
	{
		Vymaz(pUzol->Nasledujuci());
	}

	delete pUzol;
}

template<typename T>
inline TZoznam<T>::~TZoznam()
{
	if (zaciatok)
	{
		Vymaz(zaciatok)
	}
	zaciatok = nullptr;
}

template<typename T>
inline void TZoznam<T>::Usporiadaj(const char* menoSuboru)
{
	TZoznam::~TZoznam();
	if (menoSuboru && *menoSuboru)
	{
		TCitac<T> citac(menoSuboru);
		T hodnota = citac.Citaj();

		while (hodnota != TUzol<T>::NEPLATNA_HODNOTA)
		{
			ZaradDoZoznamu(hodnota);
			cislo = citac.Citaj();
		}
	}
}

template<typename T>
inline void TZoznam<T>::Vypis()
{
	if (zaciatok)
	{
		TUzol<T>* pUzol = zaciatok; 
		while (pUzol != nullptr)
		{
			cout << pUzol->Hodnota() << endl;
			pUzol = pUzol->Nasledujuci();
		}
	}
}
