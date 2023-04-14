/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Present Party)
 */

#include <iostream>

#include "Party.h"
#include "Present.h"
#include "Card.h"


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
	mCardHead = NULL;
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

		int randomTask = 1 + (rand() % 3);
	}

	//endParty();
}

void Party::getTask()
{
	int randomTask = 1 + (rand() % 3);

	switch (randomTask) {
	case 1: 
		sortPresent();
	case 2:
		writeCard();
	case 3:
		// Minotaur gives you a present id to search for
		int id = (1 + rand() % mPresentCount);
		checkForPresent(id);
	default:
		// error, go back and get another task
	}
}

void Party::gatherPresents()
{
	std::vector<Present> presents(mPresentCount);
	
	for (int i = 0; i < presents.size(); i++)
	{
		presents[i].setId(i+1);
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
	Present *peek = this->mHead;

	while ((peek->getId() != presentId) && (peek->getId() < presentId) && (peek != NULL))
	{
		peek = &peek->getNext();
	}

	if (peek->getId() == presentId)
	{
		std::cout << "Present requested was found in the stack." << std::endl;
	}
	else
	{
		std::cout << "Present requested was not found in the stack." << std::endl;
	}
}

void Party::writeCard()
{
	if (this->mHead != NULL)
	{
		Present *temp = this->mHead;

		while (temp->checkFlag() == true && &temp->getNext() != NULL)
		{
			temp = &temp->getNext();
		}

		temp->raiseFlag();
		
		temp = &temp->getNext();
		Card tyCard;
		
		if (mCardHead == NULL)
		{
			tyCard.makeHead();
		}

		if (&temp != NULL)
		{
			tyCard.setId(temp->remove());
		}
		else
		{
			tyCard.setId(this->mHead->getId());
			this->mHead = NULL;
		}

		tyCard.insert(mCardHead);
		mCardHead = &tyCard;

		std::cout << "Card written." << std::endl;

		mCardCount++;

		temp->lowerFlag();
	}
	else if (this->mUnsortedPresents.empty())
	{
		std::cout << "All presents have been sorted and all cards written." << std::endl;
		this->mAnnouncment = true;
	}
	else
	{
		std::cout << "More presents need to be sorted before cards can be written." << std::endl;
	}
}

void Party::sortPresent()
{
	//pop gift from unordered stack
	Present *present = &mUnsortedPresents.back();
	this->mUnsortedPresents.pop_back();
	
	if (this->mHead == NULL)
	{
		this->mHead = present;
	}
	else
	{
		Present *temp = this->mHead;

		while (temp->getId() <= present->getId() && &temp->getNext() == NULL)
		{
			temp = &temp->getNext();
		}

		temp->raiseFlag();

		if (temp->getId() == present->getId())
		{
			// Oops, this gift has already been sorted
			// Do nothing
		}
		if (&temp->getNext() == NULL)
		{
			present->link(temp, NULL);
		}
		else
		{
			present->link(&temp->getPrev(), temp);
		}

		temp->lowerFlag();
	}
}