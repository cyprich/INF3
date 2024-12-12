#pragma once
#include <iostream>
#include "TUzol.h"

using namespace std;

template<typename T>
class TCitac
{
private:
	ifstream* insubor = nullptr;
public:
	TCitac<T>(const char* menoSuboru);
	~TCitac<T>();

	T Citaj();
};

template<typename T>
inline TCitac<T>::TCitac(const char* menoSuboru)
	:insubor(menoSuboru&&* menoSuboru ? new ifstream(menoSuboru : nullptr) {};

template<typename T>
inline TCitac<T>::~TCitac()
{
	delete insubor;
	insubor = nullptr;
}

template<typename T>
inline T TCitac<T>::Citaj()
{
	if (insubor)
	{
		T hodnota;
		*insubor >> hodnota;
		return hodnota;
	}
};
