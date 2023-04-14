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

#include <thread>


Party::Party(int presents) :
	mRandomDistribution(0, presents),
	mPresentCount(presents),
	mServants(4),
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

		std::vector<std::thread> servants(4);

		for (std::thread &t : servants)
		{
			t = std::thread(&Party::getTask, this);
		}

		for (std::thread &t : servants)
		{
			if (t.joinable())
			{
				t.join();
			}
		}
	}
}


void Party::getTask()
{
	int randomTask = 1 + (rand() % 3);

	if (randomTask == 1)
	{
		sortPresent();
	}
	else if (randomTask == 2)
	{
		writeCard();
	}
	else if (randomTask == 3)
	{
		// Minotaur gives you a present id to search for
		int id = (1 + rand() % mPresentCount);
		checkForPresent(id);
	}
	else
	{
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
	std::cout << "Present Count: " << mPresentCount << std::endl;
	std::cout << "Thank you cards written: " << mCardCount << std::endl;

	for (Present present : mUnsortedPresents)
	{
		std::cout << present.getId() << std::endl;
	}
}


bool Party::checkForPresent(int presentId)
{
	bool result = false;
	
	Present *peek = this->mHead;

	while ((peek != NULL) && (peek->getId() != presentId) && (peek->getId() < presentId))
	{
		peek = peek->getNext();
	}

	if (peek != NULL && peek->getId() == presentId)
	{
		std::cout << "Present requested was found in the stack." << std::endl;
		result = true;
	}
	else
	{
		std::cout << "Present requested was not found in the stack." << std::endl;
		result = false;
	}

	return result;
}

void Party::writeCard()
{
	if (this->mHead != NULL)
	{
		Present *temp = this->mHead;

		while (temp->checkFlag() == true && temp->getNext() != NULL)
		{
			temp = temp->getNext();
		}

		temp->raiseFlag();
		
		Present *curr = temp->getNext();
		Card tyCard;
		
		if (mCardHead == NULL)
		{
			tyCard.makeHead();
		}

		if (curr != NULL)
		{
			tyCard.setId(curr->remove());
			delete curr;
		}
		else
		{
			tyCard.setId(this->mHead->getId());
			delete this->mHead;
			this->mHead = NULL;
		}

		tyCard.insert(mCardHead);
		mCardHead = &tyCard;

		std::cout << "Card written." << std::endl;

		mCardCount++;

		temp->setFlag(false);
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
	if (!mUnsortedPresents.empty())
	{
		Present *present = new Present(mUnsortedPresents.back());
		this->mUnsortedPresents.pop_back();

		if (this->mHead == NULL)
		{
			this->mHead = present;
		}
		else
		{
			Present *temp = this->mHead;

			while (temp->getId() <= present->getId() && temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}

			temp->raiseFlag();

			if (temp->getId() == present->getId())
			{
				// Oops, this gift has already been sorted
				// Do nothing
			}
			if (temp->getNext() == NULL)
			{
				present->link(temp, NULL);
			}
			else
			{
				present->link(temp->getPrev(), temp);
			}

			temp->lowerFlag();
		}
	}
	else
	{
		std::cout << "No more presents need to be sorted." << std::endl;
	}

}