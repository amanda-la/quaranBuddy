#include "activities.hpp"

void activityLog::initLog(const char * x){
	date = (char*) calloc(strlen(x), sizeof(char));
	strcpy(date, x);
	acts = (char *) calloc(256,sizeof(char)); 
	// strcpy(acts, y);
	// acts
	prev = NULL;
	next = NULL;
	enteringData = true;
}


// void activityLog::storeActivities(const char * activity){
// 	strcat(this->acts,activity);
// 	strcat(this->acts,"\n\t");
// }

void activityLog::storeActivities(std::string activity){
	this->acts.append(activity);
	this->acts.append("\n\t");
}

std::string activityLog::accessActivities(){
	return this->acts;
}

void activityLog::freeAct(){
	free(this->date);
}

char* activityLog::accessDate(){
	return this->date;
}

void activityLog::changeDate(){

}