#include "app_core.hpp"

void startup_animation()
{
	appCore::Sleep(1500);

	for (int i = 0; i < 7; ++i)
	{
		std::cout << std::endl;
	}

	std::cout << "		    ______           _____ _          __  __ " << std::endl;
	appCore::Sleep(60);
	std::cout << "		    |  ___|         /  ___| |        / _|/ _|" << std::endl;
	appCore::Sleep(60);
	std::cout << "		    | |_ _   _ _ __ \\ `--.| |_ _   _| |_| |_ " <<  std::endl;
	appCore::Sleep(60);
	std::cout << "		    |  _| | | | '_ \\ `--. \\ __| | | |  _|  _|"<< std::endl;
	appCore::Sleep(60);
	std::cout << "		    | | | |_| | | | /\\__/ / |_| |_| | | | |  "<< std::endl;
	appCore::Sleep(60);
	std::cout << "		    \\_|  \\__,_|_| |_\\____/ \\__|\\__,_|_| |_|  " << std::endl;

	std::cout << std::endl;

	std::cout << "				version 1.5.0" << std::endl;

	for (int i = 0; i < 7; ++i)
	{
		std::cout << std::endl;
	}

	std::cout << std::endl; 
	appCore::Sleep(2500);

	std::cout << std::endl;
	appCore::Sleep(100);
		
	std::cout << "please input a key <";

	for (int i = 0; i < 23; ++i)
	{
		appCore::Sleep(100);
		std::cout << std::endl;
	}

	appCore::clearScreen(0);

	funStuffMain();
}