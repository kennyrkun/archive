#include "stdafx.h"

void check_loaded()
{
	bool func1loaded(false);
	bool func2loaded(true);

	std::cout << std::boolalpha;

	std::cout << "loading function 1" << std::endl; coreFunctions::waitFor(100);
	if (func1loaded == false)
	{
		// load

		func1loaded = true;
		std::cout << "function 1 loaded\n" << std::endl;
	}
	else
	{
		std::cout << "function 1 already loaded" << std::endl;
	}
	coreFunctions::waitFor(100);

	std::cout << "loading function 2" << std::endl; coreFunctions::waitFor(100);

	if (func2loaded == false)
	{
		// load

		func2loaded = true;
		std::cout << "function 2 loaded\n" << std::endl;
	}
	else
	{
		std::cout << "function 2 already loaded" << std::endl;
	}
	coreFunctions::waitFor(100);

	std::cin.get();

	home();
}