#include "stdafx.h"
#include <iostream>
using namespace std;

int reset();

int loganAnswerQuestion()
{
	cout << "is logan stupid? 1 = Yes : 2 = No < ";

	int chosenAnswer;
	cin >> chosenAnswer;

	if (chosenAnswer == 1) // the user chose 1, yes, and they're fucking retarded.
	{
		cout << "I commend you. You deserve a cookie." << endl;
	}

	if (chosenAnswer == 2) // the user chose 2, no.
	{
		cout << "You deserve this." << endl;
		system("ping 1.1.1.1 -n 1 -w 500>nul");
		system("shutdown -r");
	}

	// what if the user enters an invalid character?
	// we will ignore this possibility for now.
	return chosenAnswer;
}

int logansChoice()
{
	system("title Logan's Choice");
	loganAnswerQuestion();
	system("ping 1.1.1.1 -n 1 -w 250 >nul");

	return 0;
}