#include "stdafx.h"
#include <iostream>

int asciiConverter()
{
	std::cout << "input a keyboard character: ";

	char ch;
	std::cin >> ch;
	std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;

	return 0;
}

int ascii()
{
	// std::cout << "pick a function\n";
	// functionPicker();

	asciiConverter();

	system("pause");
	return 0;
}