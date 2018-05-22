#include "app_core.hpp"

#include <fstream>
#include <iostream>

void fileManager(std::string file)
{
	if (file == "dump_data")
	{
		std::ofstream file("bin\\dump_data.txt");
 
		// If we couldn't open the output file stream for writing
		if (!file)
		{
			std::cerr << "\n" << "unable to open file \"dump_data.txt\" for writing! (IS THERE A BIN FOLDER?)" << std::endl;
		}
		else
		{
			// print stuff
			file << "error?fatal//1110110110" << std::endl;

			// close just in case
			file.close();
		} // auto-close here
	}

	if (file == "report_001")
	{
		std::ofstream file("bin\\report_001.dat");

		if (!file)
		{
			std::cerr << "\n" << "unable to open file \"report_001.dat\" for writing! (IS THERE A BIN FOLDER?)" << std::endl;
		}
		else
		{
			file << "error?001//" << "01011001I01001100R01001110O01001111M01000101O01001110T01001111N01000101E01001000M01010011E01000101M01001000_01010100L01010011O01000001V01010111E" << std::endl;
			file.close();
		}
	}
	
	if (file == "report_002")
	{
		std::ofstream file("bin\\report_002.dat");

		if (!file)
		{
			std::cerr << "\n" << "unable to open file \"report_002.dat\" for writing! (IS THERE A BIN FOLDER?)";
		}
		else
		{
			file << "error?002//" << "01010011E01001001I01001000L01010100S01000100E01001100S01010010N01001111E01010111S01011001R01000010U01011001O01001101N01000100U01000101R01001110E01001001V01010101E01010010I01000101L01010010E01010101B01010000T01000111O01001110N01001001O01001100D01010010I01000001E01000100" << std::endl;

			file.close();
		}
	}

	// TODO: refactor spaz_error
	if (file == "spaz_error")
	{
		std::ofstream dump_data("bin\\dump_data.txt");

		if (!dump_data)
		{
			std::cerr << "\n" << "could not open file \"dump_data.txt\" for writing! (IS THERE A BIN FOLDER?)";
		}
		else
		{
			dump_data << "im suffering for her.";

			dump_data.close();
		}
	}
}
