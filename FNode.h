#pragma once
#ifndef FNODE_H
#define FNODE_H
#include "PNode.h"


/*  Flight Node   */

class FNode {
private:
	string airline;		// name of the airline (ie Delta)
	string flightNum;	// unique flight number
	int capacity;		// total capacity of plane
	int avalSeats;		// capacity - reservations
	PList *passList;
	FNode *next;		// next FNode

	friend class PNode;
	friend class FList;
	friend class PList;
};

#endif // !FNODE_H