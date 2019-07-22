#include <iostream>
#include "Log.h"

void InitLog()
{
	Log("Initialized log");
}

void Log(const char* message)
{
	std::cout << message << std::endl;
}
