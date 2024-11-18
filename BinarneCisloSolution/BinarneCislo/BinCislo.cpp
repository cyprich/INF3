#include "BinCislo.h"
#include <algorithm>

long long BinCislo::BinToDec(const char* pBinCislo)
{
    long long dekadickeCislo = 0;

    string pomCislo(pBinCislo);
    reverse(pomCislo.begin(), pomCislo.end());

    long long jednotka = 1;
    int i = 0;
    while (pomCislo[i])
    {
        if (pomCislo[i] == '1')
        {
            dekadickeCislo += jednotka << i;  // mocniny dvojky
        }
        i++;
    }

    // ak je zaporne
    if (pBinCislo[0] == '-')
    {
        dekadickeCislo = -dekadickeCislo;
    }

    return dekadickeCislo;
}

string BinCislo::DecToBin() const
{
    string ciel; 
    long long pomCisco = abs(cislo);

    do
    {
        ciel += pomCisco % 2 + '0';  // konverzia na ?
        // pomCisco /= 2; 
        pomCisco >>= 1;
    } while (pomCisco > 0);

    if (cislo < 0)
    {
        ciel += '-';
    }

    reverse(ciel.begin(), ciel.end());
    return ciel;
}

// ma skryty prvy parameter BinCislo* this;
// friend BinCislo operator+(BinCislo op1, BinCislo op2) {...}  // tuto uz nema prvy skryty parameter
BinCislo BinCislo::operator+(BinCislo op2)
{
    //return BinCislo(cislo + op2.cislo);  // robi to toto, ale implicitne vdaka konverznemu konstruktoru
    return cislo + op2.cislo;
}

BinCislo BinCislo::operator-(BinCislo op2)
{
    return cislo - op2.cislo;
}

BinCislo BinCislo::operator*(BinCislo op2)
{
    return cislo * op2.cislo;
}

BinCislo BinCislo::operator/(BinCislo op2)
{
    return cislo / op2.cislo;
}

ostream& operator<<(ostream& os, const BinCislo& op)
{
    os << op.toString();
    return os;
}
