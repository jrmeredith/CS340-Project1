// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainFunctions.h"
#include "PNode.h"
#include "FNode.h"
#include "PList.h"
#include "FList.h"

int main()
{
	//cout << "Program starting..." << endl;
	createFlights();

	//deltaPass.printSeats();



	do {
		mainMenu();
		if (cin.fail()) {
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Invalid input." << endl << endl;
			continue;
		}
	} while (getInput());


	//cout << "Program closing..." << endl;
	//system("pause");
    return 0;
}

