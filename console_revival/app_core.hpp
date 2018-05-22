#pragma once // console apps base stuff is here because fuck you, that's why.

// program stuff
static const std::string g_botName = ("11348: ");

// FORWARD DECLARE GLOBAL FUNCTIONS HERE
int main();
void chat();
void fileManager(std::string file);

namespace appCore
{
	void Sleep(int ms);

	void clearScreen();

	void pause();
}
