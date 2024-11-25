#pragma once
#include <exception>
#include <iostream>

using namespace std;

class VynimkaIndex : public exception
{
private:
	int index = 0;
public:
	VynimkaIndex(int pIndex, const char* pOznam) : exception(pOznam), index(pIndex) {};
	int Index() const { return index; };
	virtual const char* Oznam() { return what(); };
};


class VynimkaDolnyIndex : public VynimkaIndex
{
public: 
	VynimkaDolnyIndex(int pIndex) : VynimkaIndex(pIndex, "Dolny index mimo rozsah!") {};
	const char* Oznam() override
	{
		cout << "Pozor! ";
		return VynimkaIndex::Oznam();
	}
};


class VynimkaHornyIndex : public VynimkaIndex
{
public:
	VynimkaHornyIndex(int pIndex) : VynimkaIndex(pIndex, "Horny index mimo rozsah!") {};
	const char* Oznam() override
	{
		cout << "Pozor, Pozor! ";
		return VynimkaIndex::Oznam();
	}
};
