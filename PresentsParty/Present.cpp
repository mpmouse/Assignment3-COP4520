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
	mHead = false;
}

Present::~Present() = default;

Present::Present(const Present &present)
{
	mFlag.store(present.mFlag);
	mPrev = NULL;
	mNext = NULL;
	mId = present.mId;
	mHead = present.mHead;
}

Present& Present::operator =(const Present &other)
{
	mFlag.store(other.mFlag);
	mPrev = other.mPrev;
	mNext = other.mNext;
	mId = other.mId;

	return *this;
}

void Present::raiseFlag()
{	
	bool expected = false;
	
	while (!mFlag.compare_exchange_strong(expected, true))
	{
		// Wait on flag/lock
	}

	// If next is null, do not wait on a lock for a non-existant present
	if (this->mNext != NULL)
	{
		while (!this->mNext->mFlag.compare_exchange_strong(expected, true))
		{
			// Wait on flag/lock
		}
	}
}

void Present::lowerFlag()
{
	mFlag = false;

	if (this->mNext != NULL)
	{
		this->mNext->lowerFlag();
	}	
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

Present Present::getPrev()
{
	return *mPrev;
}

void Present::setPrev(Present *prev)
{
	mPrev = prev;
}

Present Present::getNext()
{
	return *mNext;
}

void Present::setNext(Present *next)
{
	mNext = next;
}

int Present::remove()
{
	this->mPrev->setNext(this->mNext);
	this->mNext->setPrev(this->mPrev);

	if (this->mPrev == NULL)
	{
		this->mHead = true;
	}

	return this->mId;
}

void Present::link(Present *prev, Present *next)
{
	this->mPrev = prev;
	this->mNext = next;
}