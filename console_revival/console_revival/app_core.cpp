#include "app_core.hpp"

#include <chrono>
#include <thread>
#include <string>
#include <iostream>

namespace appCore
{
	void Sleep(int ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	void clearScreen()
	{
		#ifdef _WIN32
		#define CLEAR "cls"
		#else //In any other OS
		#define CLEAR "clear"
		#endif

		system(CLEAR);
	}

	void pause()
	{
		std::cout << "press return to continue...";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
