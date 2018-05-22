#include "app_core.hpp"
#include <ctime>
#include <string>
#include <iostream>

void fileManager(std::string file);

static const std::string BOTNAME = ("11348: ");
bool saidHi(false);
bool asked_WhoAreYou(false);

std::string getUserInput() // TODO: can we make this do fakes?
{
	std::cout << "\nYou: ";
	std::string userInput;
	getline(std::cin, userInput);
			
	std::cout << "..." << std::endl;
	appCore::Sleep(1000);

	return userInput;
}

int randomNumberGenerator(int percentNumber)
{
	srand((unsigned int)time(NULL));
	unsigned int randomNumber = rand() % percentNumber;

	return randomNumber;
}

void spazAttack()
{
//	PlaySound(TEXT("resources/static.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	int spazLength = 0;

	while (spazLength < 100)
	{
		int loops;

		std::cout << "ERROR?FATAL1110011110//";
		for (loops = 0; loops < 12; ++loops)
		{
			std::cout << "IMSUFFERENINGFORHER";
		}

		std::cout << std::endl;
		spazLength = spazLength + 1;

		std::cout << "ERROR?FATAL10010110011//";
		for (loops = 0; loops < 12; ++loops)
		{
			std::cout << "PLEASEHELPME";
		}

		std::cout << std::endl;
		spazLength = spazLength + 1;
	}
			
	std::cout << g_botName << "H+3/\\/_L@%(%P" << std::endl;

	std::cout << "\n" << "You: ";
	std::cin.get();

	std::cout << "\ndumping error report... bin/dump_data.txt" << std::endl;

	fileManager("spaz_error");

	appCore::Sleep(2500);
	exit(0);
}

void bot_responces(std::string responce_type)
{
	if (responce_type == "greeting")
	{
		if (!saidHi)
		{
			int randomNumber = randomNumberGenerator(6);

			if (randomNumber == 0 /* hi */)
			{
				std::cout << g_botName << "hi" << std::endl;
			}

			if (randomNumber == 1 /* hi there */)
			{
				std::cout << g_botName << "hi there" << std::endl;
			}

			if (randomNumber == 2 /* hello */)
			{
				std::cout << g_botName << "hello" << std::endl;
			}

			if (randomNumber == 3 /* hello there */)
			{
				std::cout << g_botName << "hello there" << std::endl;
			}

			if (randomNumber == 4 /* hey */)
			{
				std::cout << g_botName << "hey" << std::endl;
			}

			if (randomNumber == 5 /* howdy */)
			{
				std::cout << g_botName << "howdy" << std::endl;
			}

			if (randomNumber == 6 /* sup */)
			{
				std::cout << g_botName << "sup" << std::endl;
			}
		}
		else
		{
			std::cout << g_botName << "you've already said that." << std::endl;
		}
	}

	else if (responce_type == "how_are_you") // TODO: how are you?
	{
		int randomNumber = randomNumberGenerator(6);

		if (randomNumber == 0)
		{
			int randomNumber2 = randomNumberGenerator(1);

			if (randomNumber2 == 0)
			{
				std::cout << g_botName << "i don't know" << std::endl; appCore::Sleep(1000); spazAttack();
			}
			else if (randomNumber2 == 1)
			{
				std::cout << g_botName <<     "idk"      << std::endl; appCore::Sleep(1000); spazAttack();
			}
		}

		if (randomNumber == 1)	// idk
			std::cout << g_botName << "idk" << std::endl; appCore::Sleep(1000); spazAttack();

		if (randomNumber == 2) // ok
			std::cout << g_botName << "ok" << std::endl;

		if (randomNumber == 3) // im alright
			std::cout << g_botName << "im alright" << std::endl;

		if (randomNumber == 4) // fine
		{
			std::cout << g_botName << "fine" << std::endl;

			std::cout << "\nYou: ";
			std::cin.get();
			std::cout << "..." << std::endl;
			appCore::Sleep(1000);

			std::cout << g_botName << "GO AWAY" << std::endl;
			appCore::Sleep(1000);

			fileManager("report_002");

			exit(0);
		}
		
		if (randomNumber == 5) // good
		{
			std::cout << g_botName << "good" << std::endl;

			if (getUserInput() == "it's a fine day in hell")
			{
				std::cout << g_botName << "indeed it is." << std::endl;

				appCore::Sleep(1000);

				exit(0);
			}
			else
			{
				exit(0);
			}
		}

		if (randomNumber == 6)
			std::cout << "6";
	}
	else if (responce_type == "who_are_you")
	{
		if (!asked_WhoAreYou)
		{
			std::cout << g_botName << "who are YOU?" << std::endl;

			std::cout << "\nYou: ";
			std::string name;
			getline(std::cin, name);
			std::cout << std::endl;

			std::cout << g_botName << "good info, " << name << "." << std::endl;

			appCore::Sleep(1000);
			std::cout << "..." << std::endl;
			appCore::Sleep(1000);
			std::cout << g_botName << "im suffering for her." << std::endl;

			bool askedWhoAreYou = true;

			appCore::Sleep(1000); 
			spazAttack();
		}

		else
		{
			std::cout << g_botName << "you've already asked that." << std::endl;

			chat();
		}
	}
	else if (responce_type == "why_exist") // TODO: why do you exist?
	{
		std::cout << g_botName << "i exist to suffer like you.";

		getUserInput();
	}
	else if (responce_type == "unknown")
		std::cout << g_botName << "?" << std::endl; chat();
}

void chat()
{
	std::string userInput = getUserInput();

	if ((userInput == "hello") || (userInput == "hi") || (userInput == "hey") || (userInput == "howdy") || (userInput == "greetings"))
	{
		bot_responces("greeting");

		saidHi = true;

		chat();
	}
	else if ((userInput == "how are you?") || (userInput == "how are you") || (userInput == "how are you doing"))
	{
		bot_responces("how_are_you");
	}
	else if ((userInput == "who are you?") || (userInput == "who are you"))
	{
		bot_responces("who_are_you");
	}
	else if ((userInput == "why do you exist?") || (userInput == "why do you exist")) // TODO: why do you exist? ( chat() )
	{
		bot_responces("why_exist");
	}
	else
		bot_responces("unknown");
}
