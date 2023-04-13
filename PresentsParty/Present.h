/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Present Party)
 */

#ifndef PRESENT_H
#define PRESENT_H

#include "Card.h"
#include "Party.h"

#include <thread>

class Party;

class Present
{

public:

	Present();

	~Present();

	bool raiseFlag();

	bool lowerFlag();

	bool checkFlag();

	int getId();

	void setId(int id);

	std::shared_ptr<Present> getPrev();

	void setPrev(std::shared_ptr<Present> prev);

	std::shared_ptr<Present> getNext();

	void setNext(std::shared_ptr<Present> next);
	
private:
	int mId;
	std::atomic<bool> mFlag;
	std::shared_ptr<Present> mPrev;
	std::shared_ptr<Present> mNext;
};

#endif // !PRESENT_H