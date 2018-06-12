#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main();

void error() // used when something goes wrong
{
	system("color 2");
	cout << "\n\nit appears you've found an error, you should report this to the author\nalong with what you did to cause it, that would be much appreciated :D";
	abort();
}

void reset() // used to go back to the start
{
	system("cls");
	system("color 7");
	main();
}

void pause()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\npress any key to exit.";
	std::cin.get();
}

int programMain() // main part asking user for input and returning the stuff
{
	cout << "please input a character or command < ";

	string userInput; //initialize userinput
	cin >> userInput; //define userinput

	if (!cin) // if proper input
	{
		// user didn't the right thing
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input	next, request user reinput
	}

	// main functions
	if (userInput == "69") // the user input 69, so open gloryholefoundation
	{
		system("start http://www.pornhub.com/view_video.php?viewkey=ph575bf0cb7d7e5");
		reset();
	}

	if (userInput == "glory")
	{
		system("title FUCK ME JERRY");
		system("start https://www.gloryholefoundation.com");
		reset();
	}

	if (userInput == "11348") // if they know about the number
	{
		// prepare logan's choice for 11348
		int logansChoice();
		int loganAnswerQuestion();

		logansChoice();
		system("ping 1.1.1.1 -n 1 -w 1000>nul");
		reset();
	}

	if (userInput == "41") // spams rick roll then shutdown the computer
	{
		system("title NEVER GONNA GIVE YOU UP");
		reset();
		system("color 2");
		std::cout << "you shouldn't have done that..." << std::endl;
		while (1)
		{
			system("ping 1.1.1.1 -n 1 -w 750>nul");
			system("start http://www.mehsworld.com/en-us/");
		}
	}

	if (userInput == "420") // spam smoke weed everyday
	{
		system("title SNOOP DOGG, SNOOP DOGG!");
		system("color 2");
		std::cout << "SMOKE WEED EVERYDAY" << std::endl;
		system("ping 1.1.1.1 -n 1 -w 50>nul");
		while (1)
		{
			system("start https://www.youtube.com/watch?v=wWSAI9d3Vxk");
			system("ping 1.1.1.1 -n 1 -w 1500>nul");
		}
	}

	if (userInput == "14") // asks them for a code, if it is correct, let them into the un-finished subprograms area
	{
		system("cls");
		cout << "code < ";
		int code;
		cin >> code;

		if (code == 13614)
		{
			cout << "pin < ";
			int pin;
			cin >> pin;

			if (pin == 6914)
			{
				system("cls");

				cout << "what sub-program would you like to access?\n1 = Adventure Game, 2 = File Writer, END = Exit" << endl;
				cout << "please choose an option < ";

				string selectedSubProgram;
				cin >> selectedSubProgram;

				if (selectedSubProgram == "1")
				{
					int adventure();
					adventure();
				}

				if (selectedSubProgram == "2")
				{
					void writeToFile();
					writeToFile();
				}

				if (selectedSubProgram == "END")
				{
					reset();
				}

				else
				{
					cout << "You did not pick a valid option." << endl;
				}
			}

			else
			{
				reset();
			}

		}
		else
		{
			system("color 4");
			cout << "INCORRECT";
			system("ping 1.1.1.1 -n 1 -w 5000>nul");
			reset();
			system("color 7");
			programMain();
		}
	}

	if (userInput == "111")
	{
		cout << "hey there, Sole Survivor, wasteland's looking pretty today, huh?";
		system("ping 1.1.1.1 -n 1 -w 500>nul");
		reset();
	}

	if (userInput == "100")
	{
		int number = 1;

		while (number <= 100)
		{
			cout << number << endl;

			system("ping 1.1.1.1 -n 1 -w 1>nul");

			number = number + 1;
		}

		system("ping 1.1.1.1 -n 1 -w 3000>nul");
		cout << "congration.";
		system("ping 1.1.1.1 -n 1 -w 1500>nul");
		cout << " you done it.";
		system("ping 1.1.1.1 -n 1 -w 3000>nul");
		reset();

	}

	if (userInput == "kys")
	{
		system("shutdown /r");
	}

	if (userInput == "marine-fists")
	{
		int writeMatrix();
		writeMatrix();
	}

	if (userInput == "FunStuff")
	{
		cout << "this sure is fun, eh?" << endl;
		reset();
	}

	if (userInput == "dividebyZero")
	{
		cout << "it looks like you might be trying to devide 1 by zero, is that true? Y/N < ";

		string divideByZeroAnswer; //initialize userinput
		cin >> divideByZeroAnswer; //define userinput

		if (divideByZeroAnswer == "y")
		{
			cout << "okay, we'll do it for you!" << endl;
			system("ping 1.1.1.1 -n 1 -w 400>nul");
			abort();
		}

		if (divideByZeroAnswer == "n")
		{
			cout << "oh, okay. In that case we'll send you back to the main program" << endl;
			system("ping 1.1.1.1 -n 1 -w 1000>nul");
			reset();
		}
	}

	if (userInput == "letsdance")
	{
		system("start https://www.youtube.com/watch?v=A67ZkAd1wmI");
		reset();
	}

	// commands
	if (userInput == "clear")
	{
		reset();
	}

	if (userInput == "exit")
	{
		return 0;
	}

	if (userInput == "asciiConvert")
	{
		reset();
		int ascii();
		ascii();
		reset();
	}

	if (userInput == "crash")
	{
		abort();
	}

	if (userInput == "start_seq")
	{
		int main_startup();
		main_startup();
	}

	if (userInput == "todo")
	{
		void writeToFile();
		writeToFile();
		reset();
	}

	else // if not any of the above, then start over
	{
		programMain();
	}
}

int main()
{
	system("title FunStuff 1.1.5");

	programMain();

	pause();
	return 0;
}