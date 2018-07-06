#include "stdafx.h"
#include "MainFunctions.h"
#include "FList.h"
#include "PList.h"
#include "PNode.h"

// Function Definitions //

// Main Menu
void mainMenu() {
	cout << "====================================" << endl;
	cout << "|       Flight Booking System      |" << endl;
	cout << "|----------------------------------|" << endl;
	cout << "|     Please select an option.     |" << endl;
	cout << "|                                  |" << endl;
	cout << "|  1. Reserve a ticket             |" << endl;
	cout << "|  2. Cancel a reservation         |" << endl;
	cout << "|  3. Check a reservation          |" << endl;
	cout << "|  4. Display all flights          |" << endl;
	cout << "|  5. Quit                         |" << endl;
	cout << "====================================" << endl;
	cout << ":>" << flush;
}
//


// Main Menu input switch
int getInput() {
	int input;
	cin >> input;

	switch (input) {
	case 1:
		resTicket();		// reserve a ticket
		break;
	case 2:
		canTicket();		// cancel a ticket
		break;
	case 3:
		checkTicket();		// check for a specific reservation
		break;
	case 4:
		displayTickets();	// display all reservations
		break;
	case 5:
		return 0;			// exits the program
		break;
	default:
		cout << endl << "Invalid input." << endl << endl;
	}
}



// Avalible flights (airline, flight number, capacity)
void createFlights() {
	delta.addFlight("Delta", "DE131", 80);
	delta.addFlight("Delta", "DE121", 80);
	delta.addFlight("Delta", "DE241", 80);

	aa.addFlight("American Airlines", "AA113", 80);
	aa.addFlight("American Airlines", "AA342", 80);
	aa.addFlight("American Airlines", "AA221", 80);

	sw.addFlight("Southwest", "SW222", 80);
	sw.addFlight("Southwest", "SW121", 80);
	sw.addFlight("Southwest", "SW423", 80);
}


// Lists of passengers
void createPassengers() {
	deltaPass.addPass("Jake", "DE131", 12, 'A');
	aaPass.addPass("Jake", "AA131", 12, 'A');
	swPass.addPass("Jake", "SW131", 12, 'A');
}


void resTicket() {
	string name;
	string fNum;
	int row;
	char seat;
	string flightTable[] = { "DE131", "DE121", "DE241", "AA113", "AA342", "AA221", "SW222", "SW121", "SW423" };
	int flightTableSize = (sizeof(flightTable) / sizeof(string));

	cout << "======================" << endl;
	cout << "| Ticket Reservation |" << endl;
	cout << "======================" << endl << endl;
	cout << "Please enter your name: " << flush;

	cin >> name;

	system("cls");

	// Displays the different airlines
	int ticket = displayTickets();
	if (ticket == 0) {
		return;
	}

	cout << "Please type the number of the flight you wish to reserve: " << flush;
	cin >> fNum;

	

	system("cls");

	// Checks for the flight number
	int i = 0;
	while (i < flightTableSize) {
		if (flightTable[i] == fNum) {
			break;
		}
		i++;
	}
	if (fNum != flightTable[i]) {
		cout << "Sorry, that flight does not exist." << endl;
		return;
	}
	
	
 

	if (ticket == 1) {
		int xx = delta.checkFlight(fNum);
		//cout << "Delta checked" << endl;
		if (xx == 1) {
			return;
		}
	}
	else if (ticket == 2) {
		int yy = aa.checkFlight(fNum);
		//cout << "AA checked" << endl;
		if (yy = 1) {
			return;
		}
	}
	else if (ticket == 3) {
		int zz = sw.checkFlight(fNum);
		//cout << "SW checked" << endl;
		if (zz == 1) {
			return;
		}
	}
	

	

	system("cls");


	// Prints avalible seats for selected airline
	if (ticket == 1) {
		deltaPass.printSeats();	//cout << "Pinted delta seats" << endl;
	}
	else if (ticket == 2) {
		aaPass.printSeats();	//cout << "Pinted aa seats" << endl;
	}
	else if (ticket == 3) {
		swPass.printSeats();	//cout << "Pinted sw seats" << endl;
	}

	

	// Selecting a row
	cout << endl << "Which row would you like? (1-20): " << flush;
	cin >> row;
	if (row > 20 || row < 1) {
		cout << "Invalid input. Please try again." << endl;
		return;
	}

	// Selecting a seat
	cout << endl << "Which seat would you like? (A-D): " << flush;
	cin >> seat;
	system("cls");
	if (seat > 'D') {
		cout << "Invalid input. Please try again." << endl;
		return;
	}

	// Checking if the seat/row combination is avalible
	bool dCheck = deltaPass.checkSeat(row, seat, fNum);
	bool aCheck = aaPass.checkSeat(row, seat, fNum);
	bool sCheck = swPass.checkSeat(row, seat, fNum);
	if ((dCheck == 1) || (aCheck == 1) || (sCheck == 1)) {
		return;
	}

	// Switch to add a passenger to an airline list
	switch (ticket) {
	case 1:
		deltaPass.addPass(name, fNum, row, seat);
		break;
	case 2:
		aaPass.addPass(name, fNum, row, seat);
		break;
	case 3:
		swPass.addPass(name, fNum, row, seat);
		break;
	default:
		cout << "Invalid input." << endl;
	}


	cout << endl << "Registration was successful! Thank you!" << endl << endl;
}



// Cancel a ticket reservation
void canTicket() {
	string name;
	string fNum;

	cout << "=======================" << endl;
	cout << "| Ticket Cancellation |" << endl;
	cout << "=======================" << endl << endl;
	cout << "Please enter your name: " << flush;

	cin >> name;
	system("cls");
	cout << endl << "================================" << endl;
	cout << "Reservations currently held for " << name << ": " << endl;
	deltaPass.checkPass(name);
	aaPass.checkPass(name);
	swPass.checkPass(name);
	cout << "================================" << endl << endl;

	
	cout << "Please enter the number for the flight you wish to cancel: " << flush;
	cin >> fNum;
	deltaPass.removePass(fNum, name);
	aaPass.removePass(fNum, name);
	swPass.removePass(fNum, name);

	delta.incAvalSeats(fNum); //cout << "delta decreased" << endl;	// debug
	aa.incAvalSeats(fNum); //cout << "aa decreased" << endl;		// debug
	sw.incAvalSeats(fNum); //cout << "sw decreased" << endl;		// debug

	cout << endl << endl << "Cancellation was successful!" << endl << endl;
}



void checkTicket() {
	string name;

	cout << "======================" << endl;
	cout << "| Ticket Reservation |" << endl;
	cout << "======================" << endl << endl;
	cout << "Please enter your name to check for a reservation: " << flush;

	cin >> name;
	system("cls");
	cout << endl << "================================" << endl;
	cout << "Reservations currently held for " << name << ": " << endl;
	deltaPass.checkPass(name);
	aaPass.checkPass(name);
	swPass.checkPass(name);
	cout << "================================" << endl << endl;
}



int displayTickets() {
	string flightTable[] = { "Delta", "American Airlines", "Southwest" };
	int flightSize = (sizeof(flightTable) / sizeof(string));

	cout << "=====================" << endl;
	cout << "|  Current Flights  |" << endl;
	cout << "=====================" << endl << endl;
	cout << "Please choose an airline: " << endl;

	int count = 1;
	for (int i = 0; i < flightSize; i++) {
		cout << count << ". " << flightTable[i] << endl;
		++count;
	}
	cout << "====================" << endl;
	cout << ":>" << flush;
	int x = selectAirline();
	if (x == 0) {
		return 0;
	}
	return x;
	//system("pause");
}



int selectAirline() {
	int input;
	cin >> input;
	system("cls");

	switch (input) {
	case 1:
		delta.printFlights();
		return 1;
		break;
	case 2:
		aa.printFlights();
		return 2;
		break;
	case 3:
		sw.printFlights();
		return 3;
		break;
	default:
		cout << "Invalid input." << endl;
		return 0;
		break;
	}
}



void readFile() {

}