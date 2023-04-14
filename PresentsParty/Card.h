/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Present Party)
 */

#ifndef CARD_H
#define CARD_H

#include "Party.h"

#include <thread>

class Card
{

public:

	Card();

	~Card();

	void insert(Card *prev);

	void setId(int id);

	void makeHead();

private:
	int mId;
	Card *mNext;
	bool mHead;
	const char *message = "Thank you!";
};

#endif // !CARD_H