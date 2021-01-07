// #include <iostream>
// #include <vector>
#include "periodCalen.hpp"

//intializes calendar
//calendar can be a matrix of size 31, refreshes every month
//calendar holds the start date of a period and the end date
void initializeCalendar(){
}

// stores the date that a period started
// must parse the date given by the user
//triggers the isOnPeriod helper function
void storeStartOfPeriod(){
	isOnPeriod = true;
}

//if you're on period, buddy will ask if the period has finished
void storeEndOfPeriod(){
}

//stores period information based on month such as:
//	length of the period for previous months (will retrieve said info based on command asked by user)
//	flow on the day of a period 