#pragma once
enum eSortTyp {RASTUCO, KLESAJUCO};

class MyLib
{
private:
	friend int main(int argc, char* argv[]);
	friend int Porovnaj(const void* p1, const void* p2);
	static eSortTyp sortTyp;
public:
	static void Start(char* param);
	int* Kopia(int pocetPrvkov, const int* zdroj);
	void SortTyp(eSortTyp typ) { sortTyp = typ; };
};

