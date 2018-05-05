#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

void doesUserWantToWriteToFile()
{
	std::cout << "is that all? Y/N < ";

	std::string userInput;
	std::cin >> userInput;

	if (userInput == "y")
	{
		void reset();
		reset();

	}

	if (userInput == "n")
	{
		void writeToFile();
		writeToFile();
	}

	else // this not what I want right now, but I need to finish the first part first.
	{
		system("cls");
		std::cout << "You did not enter a valid character, try again." << std::endl;
		doesUserWantToWriteToFile();
	}
}

void writeToFile()
{
	std::cout << "enter a todo item < ";

	std::string todoInput;
	std::cin >> todoInput;

	std::ofstream ofs;
	ofs.open("todo.txt", std::ofstream::out | std::ofstream::app);

	ofs << todoInput << "\n\n";

	ofs.close();

	doesUserWantToWriteToFile();
}