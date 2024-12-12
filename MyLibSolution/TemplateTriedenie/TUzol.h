#pragma once
template<typename T>  // <class T> podla starsej normy

class TUzol
{
private: 
	static T NEPLATNA_HODNOTA;
	T hodnota = NEPLATNA_HODNOTA;
	TUzol<T>* nasledujuci = nullptr;
public:
	TUzol<T>(T pData, TUzol<T>* pNasledujuci);
	
	T Hodnota();
	void Hodnota(T pHodnota);

	TUzol<T> Nasledujuci();
	void Nasledujuci(T pNasledujuci);
};

template<typename T>
T TUzol<T>::NEPLATNA_HODNOTA{};

template<typename T>
TUzol<T>::TUzol(T pData, TUzol<T>* pNasledujuci) 
: hodnota(pData), nasledujuci(pNasledujuci) {};

template<typename T>
inline T TUzol<T>::Hodnota() { return hodnota; };

template<typename T>
inline void TUzol<T>::Hodnota(T pHodnota) { hodnota = pHodnota; }
