#pragma once
#include <string>
#include <ostream>

using namespace std;

class BinCislo
{
private:
	long long cislo{};  // {}  je to iste ako  = 0
	long long BinToDec(const char* pBinCislo);
	string DecToBin() const;
public:
	BinCislo(long long pCislo = 0) : cislo(pCislo) {};  // obidva konstruktory - konverzny aj standardny
	BinCislo(const char* pBinCislo) : cislo(BinToDec(pBinCislo)) {};

	BinCislo operator+(BinCislo op2);
	BinCislo operator-(BinCislo op2);
	BinCislo operator*(BinCislo op2);
	BinCislo operator/(BinCislo op2);

	friend bool operator< (BinCislo op1, BinCislo op2) { return op1.cislo < op2.cislo; };
	friend bool operator> (BinCislo op1, BinCislo op2) { return op1.cislo > op2.cislo; };
	friend bool operator>= (BinCislo op1, BinCislo op2) { return !(op1.cislo < op2.cislo); };
	friend bool operator<= (BinCislo op1, BinCislo op2) { return !(op1.cislo > op2.cislo); };

	string toString() { return DecToBin(); };

	friend ostream& operator<< (ostream& os, const BinCislo& op);
};
