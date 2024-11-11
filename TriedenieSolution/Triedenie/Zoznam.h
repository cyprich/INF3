#pragma once
#include "Data.h"

class Zoznam
{
private:
	Data* zaciatok = nullptr;
	
public:
	void Usporiadaj(const char* menoSuboru);
	void Uloz(const char* menoVystupnehoSuboru);
	void Vypis()
};
