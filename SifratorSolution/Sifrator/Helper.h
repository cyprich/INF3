#pragma once
#include <cstring>

/// <summary>
/// skopirovanie zdrojoveho retazca do noveho retazca
/// POZOR - vraciam adresu dynamickej pamati - nutny delete
/// </summary>
/// <param name="zdroj"></param>
/// <returns></returns>
unsigned char* KopirujText(const char* zdroj);
unsigned char* KopirujText(char* zdroj);
