#pragma once

const int NEPLATNA_HODNOTA = 0;
typedef int DataTyp;

// by default je vsetko private
class Data
{
private:
	DataTyp hodnota = NEPLATNA_HODNOTA;
	Data* dalsi = nullptr;

public:
	Data(DataTyp phodnota, Data* pDalsi);

	// getter a setter na hodnota
	DataTyp Hodnota() { return hodnota; }
	void Hodnota(DataTyp pHodnota) { hodnota = pHodnota; }

	// getter a setter na dalsi
	Data* Dalsi() { return dalsi; }
	void Dalsi(Data* pDalsi) { dalsi = pDalsi; }
};
