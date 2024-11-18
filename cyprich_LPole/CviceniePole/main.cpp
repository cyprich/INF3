#include "LPole.h"
#include <iostream>

long Vyber(LPole& pole, int index);

int main()
{
	long mpole[] = { 7l, 9l, 4l, 12l, 5l };
	LPole PoleA(5, mpole), PoleB(5);
	long l = Vyber(PoleA, 3);
	std::cout << l << std::endl;
	
	PoleB = PoleA;

	return 0;
}

	
long Vyber(LPole& pole, int index)
{
	if (index >= pole.getVelkost())
	{
		std::cout << "Nie je mozne z pola vybrat " << index << ". prvok, pretoze pole ma len " << pole.getVelkost() << " prkov" << std::endl;
		return -1;
	}

	return pole.getData()[index];
}
