#include "stdafx.h"
#include "FNode.h"
#include "FList.h"
#include "PList.h"


/*  Flight Function Definitions  */


// Flight Constructor.
FList::FList()
{
	head = NULL;
	//cout << "Flight Created!" << endl;		// for debugging purposes
}

// Flight Destructor
FList::~FList()
{
//	while (!Fempty()) {
//		removeFlight();
//	}
	//cout << "Flight Destroyed!" << endl;	// for debugging purposes
}

bool FList::Fempty() {
	return head == NULL;
}

// Add flights; (airline name, unique flight number, plane's capacity)
void FList::addFlight(const string airline, const string flightNum, const int capacity) {
	FNode *v = new FNode;
	v->airline = airline;
	v->flightNum = flightNum;
	v->capacity = capacity;
	v->avalSeats = capacity;
	v->next = head;
	head = v;
}

void FList::removeFlight() {
	FNode *old = head;
	head->next = old->next;
	delete old;
}

void FList::printFlights() {
	FNode *temp = head;

	cout << endl << "======================================" << endl;
	cout << "--Flights for " << temp->airline << "--" << endl;
	while (temp != nullptr) {
		cout << "(" << temp->flightNum << ", " << temp->avalSeats << "/" << temp->capacity << " seats avalible)" << endl;
		temp = temp->next;
	}
	cout << "======================================" << endl << endl;
}


int FList::checkFlight(string fNum) {
	FNode *v = head;

	while (v != nullptr) {
		if (v->avalSeats == 0 && v->flightNum == fNum) {
			cout << "Sorry, that flight is full." << endl;
			return 1;
			break;
		}
		else if (v->avalSeats != 0 && v->flightNum == fNum) {
			return 0;
			break;
		}
		else {
			v = v->next;
		}
	}
	return 1;
}


// The following is for removing the avalible seats from the planes
void FList::decAvalSeats(string fNum) {
	FNode *d = head;

	if (d == nullptr) {
		cout << "This airline does not exist!" << endl;
	}
	else {
		while (d != nullptr) {
			if (fNum == d->flightNum) {
				d->avalSeats = (d->avalSeats - 1);
			}
			d = d->next;
		}

	}
}


void FList::incAvalSeats(string fNum) {
	FNode *i = head;

	if (i == nullptr) {
		cout << "incAvalSeats error." << endl;
	}
	else {
		while (i != nullptr) {
			if (fNum == i->flightNum) {
				i->avalSeats = (i->avalSeats + 1);
				//cout << i->flightNum << endl;			// debug
				//cout << "Pass completed" << endl;		// debug
			}
			i = i->next;
		}
	}
}

/* Create Three Lists of Airlines */
FList delta;
FList aa;
FList sw;