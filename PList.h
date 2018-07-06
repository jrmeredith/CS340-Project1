#pragma once

class PList
{
public:
	PList();
	~PList();
	void addPass(string name, string pFlightNum, int row, char seat);
	void removePass(string fNum, string name);
	void checkPass(string name);
	void printSeats();
	bool checkSeat(int row, char seat, string fNum);
	

private:
	PNode *head;
	PNode *tail;
	friend class FList;
};


extern PList deltaPass;
extern PList aaPass;
extern PList swPass;