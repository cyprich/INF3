#include "Klient.h"
#include <iostream>
#include "VynimkaIndex.h"
#include "StreamLogger.h"
#include "Clogger.h"

using namespace std;

ILogger* Logovac = new CLogger("klient.log");

int main()
{
	Logovac->Log(DEBUG, "Start programu DPole...");

	try
	{
		Klient client; 
		client.Data()[-1] = 7.6;

		cout << client.Data() << endl;
	} 
	catch (VynimkaDolnyIndex& ex)
	{
		Logovac->Log(ERROR, ex.Oznam());
	} 
	catch (VynimkaHornyIndex& ex)
	{
		Logovac->Log(ERROR, ex.Oznam());
	} 
	catch (VynimkaIndex& ex)
	{
		Logovac->Log(ERROR, ex.Oznam());
	}

	Logovac->Log(DEBUG, "Koniec programu DPole...");
	return 0;
}
