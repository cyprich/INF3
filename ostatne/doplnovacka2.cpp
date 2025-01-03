#include <cstdio>

class VynimkaA {
public:
  void Oznam() { printf("A\n"); }
};

class VynimkaB : public VynimkaA {
public:
  void Oznam() { printf("B\n"); }
};

void Fun(int typ) {
  switch (typ) {
  case 0:
    throw VynimkaA();
    break;
  case 1:
    throw VynimkaB();
    break;
  }
}

// doplnte catch blok aby sa zachytili obidva typy vynimiek a v catch bloku sa
// vypisal oznam o vynimke, t.j. zavolajte metodu Oznam()

int main() {
  for (int i = 0; i < 2; i++) {
    try {
      Fun(i);
    } catch (VynimkaB e) {
      e.Oznam();
    } catch (VynimkaA e) {
      e.Oznam();
    }
  }

  return 0;
}
