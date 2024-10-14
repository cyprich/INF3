#include "Zoznam.h"
#include "Vstup.h"

void Zoznam::Usporiadaj(const char* menoVstupnehoSuboru)
{

	Vstup citac(menoVstupnehoSuboru);

	DataTyp  nacitanaHodnota = citac.Citaj();

	while (nacitanaHodnota != NEPLATNA_HODNOTA) {
		if (zaciatok != nullptr) {
			Data* predchodca = nullptr;
			Data* aktualnyPrvok;

			for (Data* aktualnyPrvok = zaciatok; aktualnyPrvok != nullptr; aktualnyPrvok = aktualnyPrvok->Dalsi()) {
				DataTyp aktualnaHodnota = aktualnyPrvok->Hodnota();

				if (nacitanaHodnota < aktualnaHodnota) {
					if (predchodca != nullptr) {
						predchodca->Dalsi(new Data(nacitanaHodnota, aktualnyPrvok));
					}
					else {
						zaciatok = new Data(nacitanaHodnota, aktualnyPrvok);
					}

					break;
				}

				predchodca = aktualnyPrvok;
			}

			if (aktualnyPrvok == nullptr) {
				predchodca->Dalsi(new Data(nacitanaHodnota, aktualnyPrvok));
			}
		}
		else {
			zaciatok = new Data(nacitanaHodnota, nullptr);
		}

		nacitanaHodnota = citac.Citaj();
	}
}
