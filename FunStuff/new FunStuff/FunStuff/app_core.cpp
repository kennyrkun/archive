#pragma once

#pragma region HEADERS
// I/O Operations
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

// TIME
#include <time.h>
#include <chrono>
#include <thread>

// MISC
#include <tchar.h>  
#pragma endregion

// FORWARD DECLARE GLOBAL FUNCTIONS HERE
int main();
void startup_animation();
void funStuffMain();
void logansChoice();

namespace appCore
{
	void Sleep(int ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	void timer(short type, long seconds)
	{
		if (type == -1)
		{
			for (int i = seconds; i > 0; i--)
			{
				std::cout << "\r" << i << std::flush;
				Sleep(1000);
			}
			std::cout << "\r" << std::flush;
		}

		if (type == 1)
		{
			for (int i = 1; i < seconds; i++)
			{
				std::cout << "\r" << i << std::flush;
				Sleep(1000);
			}
			std::cout << "\r" << std::flush;
		}
	} // end timer

	void clearScreen(int time)
	{
		Sleep(time);

		#ifdef _WIN32
		#define CLEAR "cls"
		#else //In any other OS
		#define CLEAR "clear"
		#endif

		system(CLEAR);
	}

	void pause()
	{
		std::cout << "press enter to continue"; 
		
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
} //end namespace
