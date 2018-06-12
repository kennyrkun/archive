#include "stdafx.h"	

namespace coreFunctions
{
	void coreFunctions::waitFor(unsigned int mseconds)
	{
		clock_t goal = mseconds + clock();
		while (goal > clock());
	}

	void clear_screen()
	{
		#ifdef _WIN32
		#define CLEAR "cls"
		#else //In any other OS
		#define CLEAR "clear"
		#endif
		system(CLEAR);
	}

	void errorReporter(std::string errorType, std::string location)
	{
		if (errorType == "internal")
			std::cerr << "something went terribly wrong at " << location << std::endl;
		else // normally we would call internal error here!
			std::cerr << "you broke my fucking program good job" << std::endl;
	}
}
