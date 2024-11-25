#include "StreamLogger.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

StreamLogger::StreamLogger(const char* pMenoSuboru)
	// pMenoSuboru != nullptr && *pMenoSuboru != '\0'
	: file(pMenoSuboru && *pMenoSuboru ? new ofstream(pMenoSuboru, ios_base::app) : nullptr) // app = append
{

}

void StreamLogger::Log(eLogLevel pLevel, const char* pOznam)
{
	bool OK = true;

#ifndef _DEBUG
	if (pLevel == DEBUG) { OK = false; }
#endif // _DEBUG

	if (OK)
	{
		const char* sLevel[] = { "INFO", "WARNING", "ERROR", "DEBUG" };
		time_t cas = time(nullptr);
		char* scas = ctime(&cas);
		scas[strlen(scas) - 1] = '\0';

		if (file)
		{
			(*file) << sLevel[pLevel] << "\t[" << scas << "]\t" << pOznam << endl;
		} else
		{
			cout << sLevel[pLevel] << "\t[" << scas << "]\t" << pOznam << endl;
		}
	}
}
