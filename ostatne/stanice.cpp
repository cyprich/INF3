#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class Kolaj {
public:
  int stanica = 0;
  int cislo = 0;
  Kolaj **kolaje = nullptr;

  Kolaj(int pstanica, int pcislo) : stanica(pstanica), cislo(pcislo) {};
};

class Stanica {
public:
  int cislo = 0;
  std::string nazov = "";
  std::vector<Kolaj> kolaje = std::vector<Kolaj>();

  Stanica(int pcislo, std::string pnazov) : cislo(pcislo), nazov(pnazov) {}
  void vypis(bool vypisat_stanice = false) {
    std::cout << "Stanica " << nazov << " c. " << cislo;
    if (!kolaje.empty()) {
      std::cout << "\n----------" << "\n";
      for (auto &k : kolaje) {
        std::cout << k.cislo << "\n";
      }
    }
    std::cout << std::endl;
  }

  void pridajKolaj(Kolaj kolaj) { kolaje.push_back(kolaj); }
};

int main(int argc, char *argv[]) {
  // otvaranie suboru so stanicami
  std::ifstream suborStanice("stanice.txt");
  if (!suborStanice.is_open()) {
    std::cout << "Subor stanice.txt sa nepodarilo otvorit" << std::endl;
  }
  // nacitavanie zo suboru so stanicami
  std::string riadok;
  std::vector<Stanica> stanice;
  while (std::getline(suborStanice, riadok)) {
    int cislo;
    std::string nazov;

    std::istringstream iss(riadok);
    iss >> cislo >> nazov;

    stanice.push_back(Stanica(cislo, nazov));
  }

  // vypisovanie stanic
  for (auto &s : stanice) {
    s.vypis();
  }
  std::cout << "\n\n" << std::endl;

  // otvaranie suboru s kolajami
  std::ifstream suborKolaje("stanice_kolaje.txt");
  if (!suborKolaje.is_open()) {
    std::cout << "Subor stanice_kolaje.txt sa nepodarilo otvorit" << std::endl;
  }
  // nacitavanie zo suboru s kolajami
  std::vector<Kolaj> kolaje;
  while (std::getline(suborKolaje, riadok)) {
    int stanica, cislo;

    std::istringstream iss(riadok);
    iss >> stanica >> cislo;

    kolaje.push_back(Kolaj(stanica, cislo));
    // priradovanie kolaje prislusnej stanici
    for (auto &s : stanice) {
      if (s.cislo == stanica) {
        s.pridajKolaj(kolaje.back());
      }
    }
  }

  // usporiadanie kolaji v staniciach
  for (auto &s : stanice) {
    std::sort(s.kolaje.begin(), s.kolaje.end(),
              [](const Kolaj &a, const Kolaj &b) { return a.cislo > b.cislo; });
  }

  // vypisovanie stanic s kolajami
  for (auto &s : stanice) {
    s.vypis(true);
  }

  return 0;
}
