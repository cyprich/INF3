// do nasledujucej triedy doplnte potrebnu metodu, aby sa kod vykonaval korektne

class Pole {
private:
  unsigned aVelkost = 0;
  int *aData = nullptr;

public:
  Pole(unsigned velkost)
      : aVelkost(velkost), aData(aVelkost > 0 ? new int[aVelkost] : nullptr) {}
  ~Pole() { delete[] aData; }
};

void Fun(Pole p) {
  // tu sa ma nieco doplnit ale nechapem akoze co ma ten kod robit akoze
}

int main() {
  Pole pole(100);
  Fun(pole);
}
