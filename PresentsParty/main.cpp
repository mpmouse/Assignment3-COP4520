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

	int presents = 50;

	int servents = 4;

	Timer mTimer;

	mTimer.startTimer();

	Party presentsParty(presents);
	presentsParty.printStatistics();

	mTimer.stopTimer();

	return 0;
}