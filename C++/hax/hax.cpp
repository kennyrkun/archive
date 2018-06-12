#include "stdafx.h"

void home()
{
	coreFunctions::clear_screen();

	std::cout << "1. controller batch" << std::endl;
	std::cout << "2. chartest" << std::endl;;
	std::cout << "3. loading" << std::endl;
	
	std::cout << std::endl;

	programSelector();
}

void programSelector()
{
	std::cout << "please enter a program name < ";

	std::string programChoice;
	std::getline(std::cin, programChoice);

	if ((programChoice == "controller batch") || (programChoice == "1"))
	{
		std::system("controller.bat");
	}
	else if ((programChoice == "chartest") || (programChoice == "2"))
	{
		coreFunctions::clear_screen();

		void chartest();
		chartest();

		coreFunctions::waitFor(5000);
		coreFunctions::clear_screen();
		programSelector();
	}
	else if ((programChoice == "loading") || (programChoice == "3"))
	{
		coreFunctions::clear_screen();

		void check_loaded();
		check_loaded();

		coreFunctions::clear_screen();
		programSelector();
	}
	else if (programChoice == "exit")
	{
		exit(0);
	}
	else
	{
		std::cout << "you did not enter a valid option"; 
		std::cin.get();
		std::cout << std::endl;
		programSelector();
	}
}

int main()
{
	home();

    return 0;
}