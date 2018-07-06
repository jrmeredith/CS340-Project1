#pragma once
#ifndef PNODE_H
#define PNODE_H


/*  Passenger Node   */

class PNode {
private:
	string passName;
	string pFlightNum;
	int row;
	char seat;
	PNode *next;
	PNode *prev;

	friend class PList;
	friend class FList;
};

#endif // !PNODE_H