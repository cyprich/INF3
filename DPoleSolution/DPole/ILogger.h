#pragma once

enum eLogLevel {INFO, WARNING, ERROR, DEBUG};

class ILogger
{
public:
	virtual void Log(eLogLevel pLevel, const char* pOznam) = 0;  // = 0 z neho spravi rozhranie (no idea what that is)
	virtual ~ILogger() {};  // ak by nebol virtual, volal by sa iba destruktor predka, co nechceme
};

extern ILogger* Logovac;
