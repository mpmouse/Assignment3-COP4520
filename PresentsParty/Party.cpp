/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Present Party)
 */

#include <iostream>

#include "Party.h"
#include "Present.h"


Party::Party(int presents) :
	mRandomDistribution(0, presents),
	mPresentCount(presents),
	mServents(4),
	mCardCount(0),
	mTicket(0)
{
	std::atomic<bool> mAnnouncment;
	std::random_device seeder;
	mRandomizer.seed(seeder());
	mPresentCount = presents;
	srand(time(NULL));
	gatherPresents();
	mHead = NULL;
	mCardList = NULL;
	gatherPresents();
}

Party::~Party() = default;


void Party::work()
{

	while (!mAnnouncment)
	{
		/**
		 * The things that happen TODO
		 */
	}

	//endParty();
}

void Party::gatherPresents()
{
	std::vector<Present> presents(mPresentCount);
	
	for (int i = 0; i < presents.size(); i++)
	{
		presents[i].setId(i);
	}

	std::shuffle(presents.begin(), presents.end(), mRandomizer);

	mUnsortedPresents = presents;
}

void Party::printStatistics()
{
	std::cout << "Guest Count: " << mPresentCount << std::endl;
	std::cout << "Thank you cards written: " << mCardCount << std::endl;

	for (Present present : mUnsortedPresents)
	{
		std::cout << present.getId() << std::endl;
	}

	/*
	if (allNotesWritten())
	{
		std::cout << "All Thank You cards have been written." << std::endl;

	}
	else
	{
		std::cout << "Not all Thank You notes have been written." << std::endl;
	}
	*/

}

/*
bool Party::checkForAnnouncment()
{
	return mAnnouncment;
}

void Party::makeAnnouncment()
{
	mAnnouncment.store(true);
}
*/

bool Party::checkForPresent(int presentId)
{

}

void Party::writeCard()
{
	if (this->mHead != NULL)
	{
		//take gift from next

	}
	else if (this->mUnsortedPresents.empty())
	{
		// All presents have been processed
	}
	else
	{
		// More presents need to be sorted first
	}
}

void Party::sortPresent()
{

}