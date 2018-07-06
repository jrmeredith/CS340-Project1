#include "stdafx.h"
#include "PNode.h"
#include "FNode.h"
#include "PList.h"
#include "FList.h"
#include <string>


PList::PList()
{
	head = NULL;
	//cout << "Passenger List Created!" << endl;	// debugging print
}


PList::~PList()
{
//	while (!Pempty()) {
//		removePass();
//	}
	//cout << "Passenger List Destroyed!" << endl;	// debugging print
}



void PList::addPass(string name, string pFlightNum, int row, char seat) {
	if (head == NULL) {
		PNode *v = new PNode;
		v->passName = name;
		v->pFlightNum = pFlightNum;
		v->row = row;
		v->seat = seat;
		v->next = NULL;
		v->prev = NULL;
		head = v;
		tail = v;
	}
	else {
		PNode *v = new PNode;
		v->passName = name;
		v->pFlightNum = pFlightNum;
		v->row = row;
		v->seat = seat;
		v->prev = tail;
		tail->next = v;
		tail = v;
		tail->next = NULL;
	}

	delta.decAvalSeats(pFlightNum);
	aa.decAvalSeats(pFlightNum);
	sw.decAvalSeats(pFlightNum);

	// print statement
	cout << endl << "Passenger " << name << " Added" << endl;		// debugging print
}



void PList::removePass(string fNum, string name) {
	// These functions will increase the avalible seats, before removing the passenger
	//delta.incAvalSeats(fNum); cout << "delta decreased" << endl;
	//aa.incAvalSeats(fNum); cout << "aa decreased" << endl;
	//sw.incAvalSeats(fNum); cout << "sw decreased" << endl;
	
	PNode *old = head;

	if (old == nullptr) {
		//cout << "Sorry, there are no reservations currently held for " << name << "." << endl;
		return;
	}

	else if (old != nullptr) {
		while (old != nullptr) {
			if ((old->prev == nullptr) && (old->next == nullptr)) {
				delete old;
				old = NULL;
				head = NULL;
			}
			else if ((old->prev == NULL) && (old->next != NULL)) {
				PNode *temp = old->next;
				if ((old->pFlightNum == fNum) && (old->passName == name)) {
					temp->prev = NULL;
					delete old, temp;
					old = temp = NULL;
				}
			}
			else if (old->next == nullptr) {
				PNode *temp = old->prev;
				if ((old->pFlightNum == fNum) && (old->passName == name)) {
					temp->next = NULL;
					delete old, temp;
					old = temp = NULL;
				}
			}
			else if ((old->next != nullptr) && (old->prev != nullptr)) {
				PNode *temp = old;
				if ((old->pFlightNum == fNum) && (old->passName == name)) {
					temp->prev->next = temp->next->prev;
					temp->next->prev = temp->prev->next;
					delete old, temp;
					old = temp = NULL;
				}
			}
			else {
				cout << "Sorry, that passenger/flight combination does not exist." << endl;
				return;
			}
			if (old != nullptr) {
				old = old->next;
			}
		}
	}


}



void PList::checkPass(string name) {
	PNode *temp = head;
	while (temp != nullptr) {
		if (temp->passName != name) {
			temp = temp->next;
			continue;
		}
		else if (temp->passName == name) {
			cout << temp->pFlightNum << endl;
		}
		temp = temp->next;
	}

}

bool PList::checkSeat(int row, char seat, string fNum) {
	PNode *v = head;

	while (v != nullptr) {
		if ((v->row == row) && (v->seat == seat) && (v->pFlightNum == fNum)) {
			cout << "Sorry, this seat has been reserved.  Please choose another seat/row combination." << endl;
			return true;
			break;
		}
		v = v->next;
	}
	return false;
}

void PList::printSeats() {
	int fRows[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	char fSeats[] = { 'A', 'B', 'C', 'D' };
	int fRowsSize = (sizeof(fRows) / (sizeof(int)));
	int fSeatsSize = (sizeof(fSeats) / sizeof(char));
	PNode *v = head;

	cout << "Rows:                   Seats:" << endl;

	if (v == nullptr) {
		for (int i = 0; i < fRowsSize; i++) {
			cout << fRows[i] << "                   " << flush;
			for (int j = 0; j < fSeatsSize; j++) {
				cout << fSeats[j] << ", " << flush;
			}
			cout << endl;
		}
	}

	if (v != nullptr) {
		for (int i = 0; i < fRowsSize; i++) {
			cout << fRows[i] << "                   " << flush;
			for (int j = 0; j < fSeatsSize; j++) {
				cout << fSeats[j] << ", " << flush;
			}
			cout << endl;
		}
	}
}


/* Create a List of Passengers */
PList deltaPass;
PList aaPass;
PList swPass;