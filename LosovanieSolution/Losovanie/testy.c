#include "testy.h"
#include "data.h"
#include <stdlib.h>

bool Testuj()
{
    CelkovyPocetZrebov = 30;
    PripravZreby();

    if (Zreby == NULL) return false;

    if (Zreby[5].Cislo != 6) return false;
    if (Zreby[5].Kod != 'F') return false;

    return true;
}
