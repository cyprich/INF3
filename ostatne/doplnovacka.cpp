// upravte kod triedy Obdlznik tak,
class Obdlznik {
  int stranaA = 0;
  int stranaB = 0;

public:
  Obdlznik(int pStranaA, int pStranaB)
      : stranaA(pStranaA), stranaB(pStranaB) {};
  Obdlznik() {}; // toto som doplnik
};

// aby obolo mozne vykonat nasledujuci kod:
int main() {
  Obdlznik pole[10];
  return 0;
}
