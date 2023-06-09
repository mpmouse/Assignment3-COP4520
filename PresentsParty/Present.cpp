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
	mNext = NULL;
	mId = 0;
	mHead = false;
}

Present::~Present() = default;

Present::Present(const Present &present)
{
	mFlag.store(present.mFlag);
	mNext = NULL;
	mId = present.mId;
	mHead = present.mHead;
}

Present& Present::operator =(const Present &other)
{
	mFlag.store(other.mFlag);
	mNext = other.mNext;
	mId = other.mId;

	return *this;
}

void Present::raiseFlag()
{	
	bool expected = false;
	
	while (mFlag.compare_exchange_strong(expected, true))
	{
		// Wait on flag/lock
	}

	// If next is null, do not wait on a lock for a non-existant present

	while (this->mNext != NULL && this->mNext->mFlag.compare_exchange_strong(expected, true))
	{
		// Wait on flag/lock
	}

}

void Present::lowerFlag()
{
	mFlag = false;

	if (this->mNext != NULL)
	{
		this->mNext->mFlag = false;
	}	
}

bool Present::checkFlag()
{
	return mFlag;
}

void Present::setFlag(bool status)
{
	this->mFlag = status;
}

int Present::getId()
{
	return mId;
}

void Present::setId(int id)
{
	mId = id;
}

Present* Present::getNext()
{
	return mNext;
}

void Present::setNext(Present *next)
{
	mNext = next;
}

int Present::remove(Present *prev)
{
	prev->setNext(this->mNext);
	int id = this->mId;

	return id;
}

void Present::link(Present *prev, Present *next)
{
	this->mNext = next;
}