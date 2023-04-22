/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Present Party)
 */

#ifndef PRESENT_H
#define PRESENT_H

//#include "Card.h"
#include "Party.h"

#include <thread>

class Party;

class Present
{

public:

	Present();

	~Present();

	Present(const Present &present);

	Present& operator= (const Present &other);

	void raiseFlag();

	void lowerFlag();

	bool checkFlag();

	void setFlag(bool status);

	int getId();

	void setId(int id);

	Present* getNext();

	void setNext(Present *next);

	int remove(Present *prev);

	void link(Present *prev, Present *next);
	
private:
	int mId;
	std::atomic<bool> mFlag;
	Present *mNext;
	bool mHead;
};

#endif // !PRESENT_H