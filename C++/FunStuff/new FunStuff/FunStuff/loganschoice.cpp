#include "app_core.hpp"

void logansChoice()
{
	appCore::clearScreen(0);

	std::cout << "is logan stupid? Yes or No < ";

	std::string chosenAnswer;
	getline(std::cin, chosenAnswer);

	if ((chosenAnswer == "Yes") || (chosenAnswer == "yes")) // the user chose 1, and they're amazing.
	{
		std::cout << "I commend you. You deserve a cookie." << std::endl;

		appCore::clearScreen(1500);

		funStuffMain();
	}
	else if ((chosenAnswer == "No") || (chosenAnswer == "no")) // the user chose 2, no, and they're fucking retarded.
	{
		std::cout << "You deserve this." << std::endl;
		appCore::Sleep(500);

		system("shutdown /s");

		appCore::clearScreen(0);
		std::cin.get();

		system("shutdown /a");
	}
	else
	{
		std::cout << "don't think you can get out of this.";
		appCore::clearScreen(2500);
		logansChoice();
	}


	appCore::Sleep(250);
	funStuffMain();
}
