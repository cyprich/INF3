#include "MyLib.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    char dir[1000];
    char drive[10];
    char fname[1000];  // filename
    char ext[100];  // extension
    char cieldir[1000];

    _splitpath(argv[0], drive, dir, fname, ext);
    _makepath(cieldir, drive, dir, "app", ".config");

    FILE* f = fopen(cieldir, "rt");

    if (f)
    {
        MyLib::Start(argv[0]);
    } else
    {
        cout << "Subor '" << cieldir << "' neexistuje\nKniznica sa neda aktivovat!" << endl;
    }

    return 0;
}
