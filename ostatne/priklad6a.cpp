#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Nezadali ste parameter pre pocet generovanych cisel..."
              << std::endl;
    exit(1);
  }

  int pocet = std::stoi(argv[1]);
  int pole[pocet];

  srand(time(NULL));
  for (int i = 0; i < pocet; i++) {
    pole[i] = rand() % 100 + 1;
    std::cout << pole[i] << std::endl;
  }

  std::ofstream output("priklad6a_min50.out");
  for (int i = 0; i < pocet; i++) {
    if (pole[i] < 50) {
      output << pole[i] << "\n";
    }
  }

  output.close();

  return 0;
}
