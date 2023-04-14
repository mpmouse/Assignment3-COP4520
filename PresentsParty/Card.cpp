/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Present Party)
 */


#include "Card.h"

Card::Card(int id) : mId(id)
{
	mPrev = NULL;
	mHead = false;
}

Card::~Card() = default;

void Card::insert(Card *prev)
{
	this->mPrev = prev;
}

void Card::makeHead()
{
	this->mHead = true;
}