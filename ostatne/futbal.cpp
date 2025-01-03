#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class Klub {
public:
  // parametre by mali byt private, ale nechce sa mi vypisovat gettery
  std::string nazov = "";
  std::string krajina = "";
  int pocet_zapasov = 0;
  int vyhrate_zapasy = 0;
  int body = 0;
  float uspesnost = 0;
  int *vysledky = nullptr;

  Klub(std::string riadok) {
    // ocakava riadok suboru ako vstupny parameter a nacita z neho potrebne
    // udaje
    int pocet_medzier = 0;
    int koniec = 0; // predchadzajuci koniec stringu
    // prechadza riadok znak po znaku a hlada medzeru,
    // for (int i = 0; i < riadok.size(); i++) {
    //   if (riadok[i] == ' ') {
    //     if (pocet_medzier == 0) {
    //       nazov = riadok.substr(0, i);
    //       koniec = i;
    //       pocet_medzier = 1;
    //     } else {
    //       krajina = riadok.substr(koniec + 1, i - koniec - 1);
    //       pocet_zapasov = std::stoi(riadok.substr(i));
    //     }
    //   }
    // }

    std::istringstream iss(riadok);
    iss >> nazov >> krajina >> pocet_zapasov;
  }

  ~Klub() {
    if (vysledky != nullptr) {
      delete[] vysledky;
      vysledky = nullptr;
    }
  }
  // Copy constructor
  Klub(const Klub &other)
      : nazov(other.nazov), krajina(other.krajina),
        pocet_zapasov(other.pocet_zapasov),
        vyhrate_zapasy(other.vyhrate_zapasy), body(other.body),
        uspesnost(other.uspesnost), vysledky(nullptr) {
    if (other.vysledky != nullptr) {
      vysledky = new int[pocet_zapasov];
      std::copy(other.vysledky, other.vysledky + pocet_zapasov, vysledky);
    }
  }

  // Copy assignment operator
  Klub &operator=(const Klub &other) {
    if (this != &other) {
      delete[] vysledky;
      nazov = other.nazov;
      krajina = other.krajina;
      pocet_zapasov = other.pocet_zapasov;
      vyhrate_zapasy = other.vyhrate_zapasy;
      body = other.body;
      uspesnost = other.uspesnost;
      vysledky = nullptr;
      if (other.vysledky != nullptr) {
        vysledky = new int[pocet_zapasov];
        std::copy(other.vysledky, other.vysledky + pocet_zapasov, vysledky);
      }
    }
    return *this;
  }
  void vypis() {
    std::cout << "Klub " << nazov << "\t\tkrajina " << krajina << "\t\t"
              << pocet_zapasov << " zapasov\t\t" << body << " bodov\t\t"
              << uspesnost * 100 << "% uspesnost" << std::endl;
    ;
  };
  void generuj_vysledky() {
    vysledky = new int[pocet_zapasov];
    for (int i = 0; i < pocet_zapasov; i++) {
      vysledky[i] = rand() % 3;

      switch (vysledky[i]) {
      case 1:
        body++;
        break;
      case 2:
        body += 3;
        vyhrate_zapasy++;
        break;
      }
    }

    uspesnost = (0.0 + vyhrate_zapasy) / pocet_zapasov;
  }
};

int main(int argc, char *argv[]) {
  // kontrola vstupneho parametra
  if (argc < 2) {
    std::cout << "Nebol zadany paramter pre nazov textoveho suboru s klubmi..."
              << std::endl;
    exit(1);
  }
  std::string nazov_suboru = argv[1];

  // citanie zo suboru
  std::ifstream subor(nazov_suboru);
  if (!subor.is_open()) {
    std::cout << "Subor " << nazov_suboru << " sa nepodarilo otvorit..."
              << std::endl;
    exit(1);
  }
  std::string riadok;
  std::vector<Klub> kluby;
  while (std::getline(subor, riadok)) {
    kluby.push_back(Klub(riadok));
  }

  // generovanie vysledkov
  srand(time(NULL));
  for (auto &klub : kluby) {
    klub.generuj_vysledky();
  }

  // zoradenie klubov podla poctu bodov
  std::sort(kluby.begin(), kluby.end(),
            [](const Klub &a, const Klub &b) { return a.body > b.body; });

  // vypisovanie klubov
  for (auto &klub : kluby) {
    klub.vypis();
  }

  return 0;
}
