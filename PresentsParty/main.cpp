/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 3 (The Brithday Presents Party)
 */

#include "Timer.h"
#include "Party.h"

#include <iostream>



int main(int argc, char **argv, char **env) {

	int mPresents = 500000;

	int mServents = 4;

	Timer mTimer;

	mTimer.startTimer();

	Party presentsParty(mPresents, mServents);
	labrinthParty.work();
	labrinthParty.printStatistics();

	mTimer.stopTimer();

	return 0;
}