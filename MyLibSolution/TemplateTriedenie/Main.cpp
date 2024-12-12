#include "TZoznam.h"

int main(int argc, char* argv[])
{
	TZoznam<double>* dList = new TZoznam<double>();
	dList->Usporiadaj("DData.txt");
	
	return 0;
}