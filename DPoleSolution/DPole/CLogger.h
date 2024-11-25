#pragma once
#include "ILogger.h"
#include <fstream>
#include "StreamLogger.h"

using namespace std;

// composite logger - aj displej aj konzola
class CLogger : public ILogger
{
private:
    StreamLogger* subor = nullptr;
    StreamLogger* displej = nullptr;

public:
    CLogger(const char* pMenoSuboru = nullptr) {
        if (pMenoSuboru && *pMenoSuboru)
        {
            subor = new StreamLogger(pMenoSuboru);
        }
        displej = new StreamLogger();
    };

    ~CLogger() { delete displej; delete subor; };

    // Inherited via ILogger
    void Log(eLogLevel pLevel, const char* pOznam) override {
        subor->Log(pLevel, pOznam);
        displej->Log(pLevel, pOznam);
    };
};
