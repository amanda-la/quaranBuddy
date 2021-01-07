#include <iostream>
#include <vector>
#include <string.h>

//visualization of a log
/*
June 8th, 2020
--------------
took my vitamins
showered
played games
worked on a project
*/

class activityLog{
	char * date;
	std::string acts;
	activityLog * prev;
	activityLog * next;
public:
	void initLog(const char*);
	void freeAct();
	char* accessDate();
	void changeDate();
//parses a string and stores activites done in a day, 
//listing the activities with a newline char
	// void storeActivities(const char*);
	void storeActivities(std::string);
	std::string accessActivities();
};

activityLog * head;
activityLog * current;

bool enteringData;

//can store the activities as a comma separated list, and when asked for activites
//return them in the listed fashion

//creates an ascii art border around the text
void createBorder();

//initialize activities data structure
void initializeActivityLog();

//frees memory held by activities
// void freeAct(activityLog * head);


