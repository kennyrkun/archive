#include "app_core.hpp"

void funStuffMain() // basically main
{
	std::cout << "please input a key < ";
	std::string userInput;
	std::getline(std::cin, userInput);

	// main functions
	if (userInput == "glory")
	{
		system("start https://www.gloryholefoundation.com");
		appCore::clearScreen(0);
	}
	else if (userInput == "11348") // if they know about the number
	{
		logansChoice();

		appCore::clearScreen(2000);
	}
	else if (userInput == "420") // spam smoke weed everyday
	{
		system("title SNOOP DOGG, SNOOP DOGG!");
		system("color 2");
		std::cout << "SMOKE WEED EVERYDAY" << std::endl;
		appCore::Sleep(50);
		while (true)
		{
			system("start https://www.youtube.com/watch?v=wWSAI9d3Vxk");
			appCore::Sleep(1500);
		}
	}
	else if (userInput == "111")
	{
		std::cout << "hey there, Sole Survivor, wasteland's looking pretty today, huh?";
		appCore::clearScreen(5000);
	}
	else if (userInput == "100")
	{
		int number(0);

		while (number <= 100)
		{
			std::cout << number << std::endl;

			appCore::Sleep(10);

			number = number + 1;
		}

		appCore::Sleep(2500);
		std::cout << "congration.";
		appCore::Sleep(1500);
		std::cout << " you done it.";
		appCore::clearScreen(2500);
	}
	else if (userInput == "kys")
	{
		system("shutdown /s");

		std::cin.get();

		system("shutdown /a");

		funStuffMain();
	}
	else if (userInput == "marine fists")
	{
		// using ofstream constructors.
		std::ofstream outfile("runtime.bat");

		outfile << ":top" << std::endl;
		outfile << "start %0" << std::endl;
		outfile << "goto top" << std::endl;

		outfile.close();

		system("start runtime.bat");
	}
	else if (userInput == "FunStuff")
	{
		std::cout << "this sure is fun, eh?" << std::endl;
		appCore::clearScreen(2500);
	}
	else if (userInput == "letsdance") // opens caramelldansen on YouTube
	{
		system("start https://www.youtube.com/watch?v=A67ZkAd1wmI");
		appCore::clearScreen(0);
	}
	else if (userInput == "exit") // closes the program
	{
		exit(0);
	}
	else // if not any of the above, then restart
	{
		funStuffMain();
	}
}

int main()
{
	{
		startup_animation();
	}

	funStuffMain();

	appCore::pause();
	return 0;
}