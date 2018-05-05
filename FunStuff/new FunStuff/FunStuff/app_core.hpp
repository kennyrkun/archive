#pragma once
// I/O Operations
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

// TIME
#include <time.h>

// MISC
#include <tchar.h>  

// FORWARD DECLARE GLOBAL FUNCTIONS HERE
int main();
void startup_animation();
void funStuffMain();
void logansChoice();

namespace appCore
{
	void Sleep(int sleepMs);

	void timer(short type, long seconds);

	void clearScreen(int time);

	void pause();
} //end namespace
