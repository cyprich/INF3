#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int get_pocet_riadkov_suboru(std::string cesta_suboru);
void zamiesaj_tabulku(char tabulka[], int velkost, int nasada);
int get_nasada(std::string datum);
void zamiesaj_osobu(std::string clovek);

int main(int argc, char *argv[]) {
  std::string cesta_suboru = "osoby.txt";
  // nacitavanie zo suboru
  std::ifstream subor(cesta_suboru);
  if (!subor.is_open()) {
    std::cout << "Subor " << cesta_suboru << " sa nepodarilo nacitat..."
              << std::endl;
    exit(1);
  }

  int pocet_riadkov = get_pocet_riadkov_suboru(cesta_suboru);
  std::string osoby[pocet_riadkov];
  std::string line;
  int x = 0;

  while (std::getline(subor, line)) {
    osoby[x] = line;
    x++;
  }
  subor.close();

  // vytvorenie tabulky
  char tabulka[27];
  for (int i = 0; i < 26; i++) {
    tabulka[i] = 'A' + i;
  }
  tabulka[26] = ' ';
  zamiesaj_tabulku(tabulka, 27, get_nasada("01.01.2025"));

  return 0;
}

int get_pocet_riadkov_suboru(std::string cesta_suboru) {
  std::ifstream subor(cesta_suboru);
  if (!subor.is_open()) {
    std::cout << "Subor " << cesta_suboru << " sa nepodarilo nacitat..."
              << std::endl;
    exit(1);
  }

  int pocet = 0;
  std::string line;
  while (std::getline(subor, line)) {
    pocet++;
  }

  subor.close();
  return pocet;
}

void zamiesaj_tabulku(char tabulka[], int velkost, int nasada) {
  srand(nasada);

  for (int i = 0; i < velkost; i++) {
    int x = rand() % velkost;
    char temp = tabulka[i];
    tabulka[i] = tabulka[x];
    tabulka[x] = temp;
  }
}

int get_nasada(std::string datum) {
  return std::stoi(datum.substr(0, 2)) + std::stoi(datum.substr(3, 2)) * 100 +
         std::stoi(datum.substr(6, 4)) * 10000;
}

void zamiesaj_osobu(std::string clovek) {}
