#pragma once
#include "ILogger.h"
#include <fstream>

using namespace std;

class StreamLogger : public ILogger
{
private:
    ofstream* file = nullptr;

public:
    StreamLogger(const char* pMenoSuboru = nullptr);

    // Inherited via ILogger
    void Log(eLogLevel pLevel, const char* pOznam) override;
};
