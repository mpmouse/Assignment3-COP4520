/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (Minotaur's Birthday Present Party)
 */

#ifndef PARTY_H
#define PARTY_H

#include <mutex>
#include <vector>
#include <random>

class Guest;
class Present;
class Card;

class Party {

public:

	Party(int guests);

	~Party();	

	void getTask();

	void gatherPresents();

	void work();

	void printStatistics();

	bool checkForPresent(Present *peek, int presentId);

	void writeCard();

	void sortPresent();

private:
	int mPresentCount;
	int mServants;
	int mCardCount;
	int mSortedCount;
	std::atomic<int> mTicket;
	Present *mHead;
	Card *mCardHead;
	std::vector<Present> mUnsortedPresents;
	std::atomic<bool> mAnnouncment;
	std::mt19937 mRandomizer;
	std::uniform_int_distribution<int> mRandomDistributionTask;
	std::uniform_int_distribution<int> mRandomDistributionPresent;
	std::mutex mDoor;
};

#endif // !PARTY_H