#pragma once
class LPole
{
private:
	long* data = nullptr;
	int velkost = 0;

public:
	// konverzny konstruktor - alokuje zadany pocet hodnot
	LPole(int pocet);

	// konverzny konstruktor - alokuje zadany pocet hodnot + naplni
	LPole(int pocet, long* hodnoty);


    // kopirovaci konstruktor
    LPole(const LPole& other)
    {
        velkost = other.velkost;
        data = new long[velkost];
        for (int i = 0; i < velkost; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // operator priradenia
    LPole& operator=(const LPole& other)
    {
        if (this == &other) return *this;  // kontrola ci nepriradujeme samemu sebe

        delete[] data;

        velkost = other.velkost;
        data = new long[velkost];
        for (int i = 0; i < velkost; ++i)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    // destruktor
    ~LPole();

	// gettery
	int getVelkost() { return velkost; };
	long* getData() { return data; };
};
