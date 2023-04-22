/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Present Party)
 */


#include "Card.h"

Card::Card()
{
	mNext = NULL;
	mHead = false;
	mId = NAN;
}

Card::~Card() = default;

void Card::insert(Card *head)
{
	this->mNext = head;
}

void Card::makeHead()
{
	this->mHead = true;
}

void Card::setId(int id)
{
	this->mId = id;
}

int Card::getId()
{
	return mId;
}

Card* Card::getNext()
{
	return mNext;
}