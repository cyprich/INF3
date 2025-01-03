#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

int get_pocet_lyziarov(std::string nazov_suboru);

class Lyziar {
private:
  std::string meno = "";
  std::string priezvisko = "";
  int pocet_pretekov = 0;
  int *umiestnenia = nullptr;
  float priemer_umiestneni = 0;
  int body = 0;

public:
  Lyziar(std::string pmeno, std::string ppriezvisko, int ppreteky) {
    meno = pmeno;
    priezvisko = ppriezvisko;
    pocet_pretekov = ppreteky;

    umiestnenia = new int[pocet_pretekov];
    int temp_priemer = 0;

    // generovanie nahodneho umiestnenia, vypocet bodov a pomocna premenna pre
    // vypocet priemeru
    for (int i = 0; i < pocet_pretekov; i++) {
      umiestnenia[i] = rand() % 30 + 1;
      body += 30 - umiestnenia[i] - 1;
      temp_priemer += umiestnenia[i];
    }

    priemer_umiestneni = (0.0 + temp_priemer) / pocet_pretekov;
  }

  ~Lyziar() {
    if (umiestnenia != nullptr) {
      delete[] umiestnenia;
      umiestnenia = nullptr;
    }
  }

  int get_body() const { return body; }

  friend std::ostream &operator<<(std::ostream &os, const Lyziar &lyziar) {
    os << lyziar.priezvisko << " " << lyziar.meno << " " << lyziar.body << " "
       << lyziar.pocet_pretekov << " " << lyziar.priemer_umiestneni << " - ["
       << lyziar.pocet_pretekov << "] ";

    for (int i = 0; i < lyziar.pocet_pretekov; i++) {
      os << lyziar.umiestnenia[i] << " ";
    }

    return os;
  }
};

int main(int argc, char *argv[]) {
  // kontrola vstupnych parametrov
  if (argc < 2) {
    std::cout << "Nezadali ste vstupny parameter pre nazov textoveho suboru..."
              << std::endl;
    exit(1);
  }

  srand(time(NULL));

  // citanie suboru
  std::string nazov_suboru = argv[1];
  std::ifstream subor(nazov_suboru);
  if (!subor.is_open()) {
    std::cout << "Subor " << nazov_suboru << " sa nepodarilo otvorit..."
              << std::endl;
  }

  int pocet_lyziarov = get_pocet_lyziarov(nazov_suboru);
  Lyziar **lyziari = new Lyziar *[pocet_lyziarov];

  // vytvaranie instancii lyziarov
  std::string riadok;
  int i = 0;
  while (std::getline(subor, riadok)) {
    std::string meno;
    std::string priezvisko;
    int pocet_pretekov;

    std::istringstream iss(riadok);
    iss >> meno >> priezvisko >> pocet_pretekov;

    lyziari[i] = new Lyziar(meno, priezvisko, pocet_pretekov);
    i++;
  }
  subor.close();

  // zoradenie
  std::sort(lyziari, lyziari + pocet_lyziarov,
            [](Lyziar *a, Lyziar *b) { return a->get_body() > b->get_body(); });

  // vypisovanie na konzolu a do suboru
  std::ofstream outsubor("lyziari.out");
  for (int i = 0; i < pocet_lyziarov; i++) {
    std::cout << *lyziari[i] << std::endl;
    outsubor << *lyziari[i] << "\n";
  }

  // dealokacia pamati
  for (int i = 0; i < pocet_lyziarov; i++) {
    delete lyziari[i];
  }
  delete[] lyziari;

  return 0;
}

int get_pocet_lyziarov(std::string nazov_suboru) {
  std::ifstream subor(nazov_suboru);
  if (!subor.is_open()) {
    std::cout << "Subor " << nazov_suboru << " sa nepodarilo otvorit..."
              << std::endl;
  }

  int pocet_riadkov = 0;
  std::string riadok;
  while (std::getline(subor, riadok)) {
    pocet_riadkov++;
  }

  subor.close();

  return pocet_riadkov;
}
