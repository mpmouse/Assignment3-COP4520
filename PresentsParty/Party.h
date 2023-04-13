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

class Party {

public:

	Party(int guests);

	~Party();	

	void gatherPresents();

	void work();

	void printStatistics();

private:
	int mPresentCount;
	int mServents;
	int mCardCount;
	std::vector<Present> mSortedPresents;
	std::vector<Present> mUnsortedPresents;
	std::atomic<bool> mAnnouncment;
	std::mt19937 mRandomizer;
	std::uniform_int_distribution<int> mRandomDistribution;
};

#endif // !PARTY_H