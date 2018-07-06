#pragma once
#include "FNode.h"
/*  Flight List  */

class FList
{
public:
	FList();
	~FList();
	void addFlight(const string airline, const string flightNum, const int capacity);
	void removeFlight();
	void printFlights();
	int checkFlight(string fNum);
	bool Fempty();
	void incAvalSeats(string fNum);
	void decAvalSeats(string fNum);

private:
	FNode * head;

	friend class PList;
};


/*  External initialization of class objects  */
// Avalible airlines
extern FList delta;
extern FList aa;
extern FList sw;
//