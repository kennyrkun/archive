#include "app_core.hpp"

int getUserInput() //TODO: make it work properly
{
	std::cout << "\nenter a number < ";
	long number;
	std::cin >> number;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');

		std::cout << "\ninvalid input" << std::endl;

		getUserInput();
	}

	return number;
}

int tryAgain()
{
	std::cout << " try again? < ";

	std::string userInput;
	getline(std::cin, userInput);

	if (userInput == "y")
	{
		int main(); main();
	}
	else if (userInput == "n")
	{
		exit(0);
	}
	else
	{
		std::cout << "you did not enter a valid input! y/n, you wanna to try again? < "; std::cin.get(); tryAgain();
	}
}

void guess()
{
	srand(time(NULL));
	long seed = rand() % 1000;

	srand(time(NULL));
	long answer = rand() % 10000 + seed;

	std::cout << answer;

	long userInput(-1);
	long numberOfGuesses = 0;

	while (userInput != answer)
	{
		numberOfGuesses = numberOfGuesses + 1;

		userInput = getUserInput();

		if (userInput < answer)
		{
			std::cout << "\nhigher" << std::endl;
		}
		else if (userInput > answer)
		{
			std::cout << "\nlower" << std::endl;
		}
		else
		{
			appCore::setColour(10); std::cout << "\ncorrect! "; appCore::setColour(0);
			std::cout << "the number was ";
			appCore::setColour(12); std::cout << answer; appCore::setColour(0);
			std::cout << "! it took you ";
			appCore::setColour(12); std::cout << numberOfGuesses; appCore::setColour(0);

			if (numberOfGuesses == 1)
			{
				std::cout << " guess!";
			}
			else
			{
				std::cout << " guesses!";
			}
			
			tryAgain();
		}
	}
}

int main()
{
	system("cls");
	system("title Guessing Game"); // still needing to find a way to change console title without system();
	system("color f0");

	std::cout << "+-------------------------------------------------------+" << std::endl
	std::cout << "| Welcome to the Guessing Game! try to guess my number! |" << std::endl;
	std::cout << "+-------------------------------------------------------+" << std::endl;

	guess();
	
	std::cin.get();

    return 0;
}