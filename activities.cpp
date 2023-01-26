#include "activities.hpp"


//call grab date
//call set date
void activityLog::initLog(){
	system("date > date.txt");
	// setDate(grabDate());
	date = (char*) calloc(strlen(grabDate()), sizeof(char));
	strcpy(date, grabDate());
	acts = (char *) calloc(256,sizeof(char)); 
	// strcpy(acts, y);
	// acts
	prev = NULL;
	next = NULL;
	enteringData = true;
}

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
//reads date from file
char* activityLog::grabDate(){
	char curr_date[40];
	std::ifstream f (date_file, std::ifstream::in);
	if(f){
		f.seekg(0, f.end);
		int length = f.tellg();
		f.seekg(0, f.beg);

		// char* buffer = new char [length];
		char buffer[length];
		f.read(buffer, length);
		// std::cout<<"value of buffer: " <<buffer<<'\n';
		if(f){
			//could add logging statements... how can we have a logging system in place?
			// curr_date = buffer;
			strcpy(curr_date,buffer);
			// std::cout<<"here:"<<curr_date<<'\n';
			// strcpy(curr_date, buffer);
		}
		else{
			std::cout<< "error with grabbing date";
		}
		f.close();
		// delete[] buffer;
		// return buffer;
	}
	// std::cout<<"end of grab date"<<curr_date<<'\n';

	return curr_date;
	// return NULL;
}

//issue here... for some reason new_date parameter doesn't correctly contain the date passed in
void activityLog::setDate(const char * new_date){
	std::cout<<new_date<<'\n';
	date = (char*) calloc(strlen(new_date), sizeof(char));
	strcpy(date, new_date);
	// std::cout<<date<<'\n';
	std::cout<<new_date<<'\n';
}

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