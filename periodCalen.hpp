#include <iostream>
#include <vector>

bool isOnPeriod;

//intializes calendar
//calendar can be a matrix of size 31, refreshes every month
void initializeCalendar();

// stores the date that a period started
// must parse the date given by the user
void storeStartOfPeriod();

//if you're on period, buddy will ask if the period has finished
void storeEndOfPeriod();

//calculates when you should be getting your period next, triggers a q: "hey you should be getting your period today! did you get it yet?"

//if did not get period, clears when period should start, waits till you get period and resets calculator 

