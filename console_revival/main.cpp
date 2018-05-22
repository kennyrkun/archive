#include "app_core.hpp"

#include <iostream>

void startup()
{
	{
		std::cin.get();

		/*
		SetConsoleTitle(TEXT("god is dead"));
		appCore::Sleep(10);
		SetConsoleTitle(g_appTitle.c_str());
		*/
	}

//	appCore::playsound(TEXT("resources/213.wav"));
	std::cout << "startup" << std::endl;
	appCore::Sleep(1400);

	{ // progress stuff
		int loading_progress(0);

		while (loading_progress <= 12)
		{
			std::cout << loading_progress << "%" << std::endl;

			appCore::Sleep(5);

			loading_progress = loading_progress + 1;
		}

		appCore::Sleep(500);

//		appCore::setColour(12); // red
		std::cout << "ERROR" << std::endl;
//		appCore::playsound(TEXT("resources/202.wav"));
//		appCore::setColour(7);	// white (default)
		fileManager("dump_data");          
										   
		appCore::Sleep(1000);

		while (loading_progress <= 100)
		{
			std::cout << loading_progress << "%" << std::endl;

			appCore::Sleep(10);

			loading_progress = loading_progress + 1;
		}

		/* REPORT 001 */
		std::cout << "error?3D1c1U5_ // some assets may not be available... proceeding." << std::endl;
//		appCore::playsound(TEXT("resources/202.wav"));
		std::cout << "dumping error report... bin/report_***.txt" << std::endl;

		appCore::Sleep(500);

		std::cout << "done!\ntype \"error_access\" to see details..." << std::endl;
		fileManager("report_001");
	}

	std::cout << "\n==========\nwelcome :D\n==========" << std::endl;

	chat();
}

int main()
{
	void startup(); 
	startup();

	exit(0); // is this necessary? i'm fairly certain we never end from main.
}
