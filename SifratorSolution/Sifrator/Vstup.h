#pragma once
#include <cstdlib>

class Vstup
{
private: 
	size_t DlzkaSuboru(const char* pNazovSuboru);
public:
	unsigned char* Citaj(const char* pNazovSuboru);
};

