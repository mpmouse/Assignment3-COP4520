/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Present Party)
 */


#include "Present.h"
#include "Party.h"

Present::Present()
{
	mFlag = false;
	mPrev = NULL;
	mNext = NULL;
	mId = NAN;
}

Present::~Present() = default;

bool Present::raiseFlag()
{
	mFlag = true;
	this->getPrev()->raiseFlag();
}

bool Present::lowerFlag()
{
	mFlag = false;
	this->getPrev()->lowerFlag();
}

bool Present::checkFlag()
{
	return mFlag;
}

int Present::getId()
{
	return mId;
}

void Present::setId(int id)
{
	mId = id;
}

std::shared_ptr<Present> Present::getPrev()
{
	return mPrev;
}

void Present::setPrev(std::shared_ptr<Present> prev)
{
	mPrev = prev;
}

std::shared_ptr<Present> Present::getNext()
{
	return mNext;
}

void Present::setNext(std::shared_ptr<Present> next)
{
	mNext = next;
}