/*
you find an old abandoned room. what do you do?
leave or search it
if search > you found a ghost!
what do you do? 
get the fuck out of there or bend over and spread your ass cheeks?
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>  
#include <string>

/*
int adventure();
void adventureStart()
{
	system("cls");
	system("color 2");
	cout << "loading your adventure" << endl;
	adventure();
}
*/

int loadingAdventure()
{
	using namespace std;

	system("ping 1.1.1.1 -n 1 -w 5000>nul");
	system("title LOADING ADVENTURE");
	system("ping 1.1.1.1 -n 1 -w 50>nul");
	system("cls");
	system("title %random%%random%%random%%random%");
	cout << "PREPARING 1/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 640>nul");
	cout << "PREPARING 2/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 98>nul");
	cout << "PREPARING 3/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 100>nul");
	cout << "PREPARING 4/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 98>nul");
	cout << "PREPARING 5/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 2568>nul");
	cout << "PREPARING 6/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 98>nul");
	cout << "PREPARING 7/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 4894>nul");
	cout << "PREPARING 8/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 98>nul");
	cout << "PREPARING 9/10" << endl;
	system("ping 1.1.1.1 -n 1 -w 454>nul");
	cout << "PREPARING 10/10" << endl;
	cout << "DONE!" << endl;
	cout << "READY!" << endl;

	system("cls");
	return 0;
}

int main();
void reset();

int getCharacterInfo()
{
	std::cout << "choose a name < ";

	std::string name;
	std::cin >> name;

	std::cout << "Alright, " << name << ". How old are you? < ";

	std::string age;
	std::cin >> age;

	std::cout << "Okay, " << age << " years old." << std::endl;
}

void town()
{
	using namespace std;

	system("cls");
	cout << "Jonathan wakes up in a convient store. He can either:" << endl;

	cout << "A. Ransack the place and cheese it." << endl;
	cout << "B. UNDEFINED" << endl;
	cout << "C. UNDEFINED" << endl;

	cout << "\nWhat will Jonathan do? < ";

	string choiceAdefinition = "ransack the place and cheese it.";
	string choiceBdefinition = "stay and make it a shelter.";
	string choiceCdefinition = "UNDEFINED";
	string choiceDdefinition = "%random%NDE%random%INED";

	string choice;
	cin >> choice;


	if (choice == "a")
	{
		cout << "\nYou chose to " << choiceAdefinition << endl;
	}

	if (choice == "b")
	{
		cout << "You chose 2." << endl;
	}

	if (choice == "c")
	{
		cout << "You chose 3." << endl;
	}

	if (choice == "d")
	{
		abort();
	}
}

int adventure()
{
//	loadingAdventure();
//	getCharacterInfo();
	town();
	return 0;
}