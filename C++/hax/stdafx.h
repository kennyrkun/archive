#pragma once

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <time.h>

// initializing global functions that can be used anywhere
void home();
void programSelector();

namespace coreFunctions
{
	void waitFor(unsigned int mseconds);

	void clear_screen();

	void errorReporter(std::string errorType, std::string location);
}
