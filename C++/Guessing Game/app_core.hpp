// a stripped down version of Console Applications Base

#pragma region PREPROCESSING

#if !defined(__cplusplus)
#error A C++ compiler is require to use the Console Applications Base.
#endif

#pragma endregion

#pragma region HEADERS
// stdafx.h : include file for standard system include files, or project specific include files that are used frequently, but are changed infrequently
// comment out the ones you don't need/want in your program and keep the ones you need. !! DO NOT COMMENT <SDKDKVer.h> !!

// TODO: reference additional headers your program requires here
#pragma once

/* IMPORTANT */
#include <SDKDDKVer.h>
/* IMPORTANT */

// Windows API
#include <windows.h>

// I/O Operations
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

// TIME
#include <time.h>

// MICSC
#include <tchar.h>  
#pragma endregion

#pragma region VARIABLES

// DECLARE GLOBAL VARIABLES HERE
extern	std::wstring g_programName;
extern	std::wstring g_programVersion;
extern	std::wstring g_consoleTitle;

// FORWARD DECLARE GLOBAL FUNCTIONS HERE
int main();

#pragma endregion

#pragma region FUNCTIONS

namespace appCore
{
	inline void clearScreen(int time)
	{
		Sleep(time);
		system("cls");
	}

	inline void setColour(int colour)
	{
		/*-------------+-----+
		| BLACK        | 0   |
		| BLUE         | 1   |
		| GREEN        | 2   |
		| CYAN         | 3   |
		| RED          | 4   |
		| MAGENTA      | 5   |
		| BROWN        | 6   |
		| LIGHTGREY    | 7   |
		| DARKGREY     | 8   |
		| LIGHTBLUE    | 9   |
		| LIGHTGREEN   | 10  |
		| LIGHTCYAN    | 11  |
		| LIGHTRED     | 12  |
		| LIGHTMAGENTA | 13  |
		| YELLOW       | 14  |
		| WHITE        | 15  |
		| BLINK        | 128 |
		+--------------+----*/

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(hConsole, &csbi);

		SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)colour);
	}
} //end namespace

#pragma endregion