#pragma once
#include "DPole.h"
#include "ILogger.h"

class Klient
{
private:
	DPole data;

public:
	Klient() : data(-3, 3, 1999.0) { Logovac->Log(INFO, "Alokujem Pole..."); }
	~Klient() {}
	DPole& Data() { return data; };
};

