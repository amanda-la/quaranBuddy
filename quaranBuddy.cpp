#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "periodCalen.cpp"
#include "activities.cpp"
#include "quotes.cpp"
#include "dialogue.cpp"

std::string quaranBuddy = "quaranBuddy: ";
std::string input = "";
std::string diary_input = "";
std::string activity_input = "";
std::string entry = "";
int numDiaryEntries = 3;
std::ofstream diary;
// std::fstream data;
std::string diaryEntry = "";
bool engaging = true;
char compare = '~';
bool typing;
// std::string path = "c:/Users/amandala/Personal_Projs/terminal_proj/diary_entries/";

int main(int argc, char* argv[]){
	// storeStartOfPeriod();
	// data.open("data.txt");
	if(isOnPeriod){
			std::cout<<quaranBuddy<< "Hey friend! Welcome back :). I've missed you so much? How's your flow today?\n";
		}
	else{
		std::cout<<quaranBuddy<< "Hey friend! Welcome back :), I've missed you! What can I help you with?\n";
		// std::cout << "\033[5;31mbold red text\033[0m\n";
		// std::cout << "\033[30;107mbold red text\033[0m\n";

		//couple of questions, did you take your vitamins today? have you showered yet?
		//okay, how can i help you?
	}
	typesOfQuotes relax;
	typesOfQuotes self_care;
	relax.init_quotes();
	self_care.init_quotes();
	relax.addQuote("It was Thich Nhat Hanh who said...\n\n\tWe humans have lost the wisdom of genuinely resting and relaxing.\n\tWe worry too much.\n\tWe dont allow our bodies to heal,\n\tand we dont allow our minds and hearts to heal.\n\nEnjoy your time to yourself and dont let anyone make you feel bad for it :).");
	self_care.addQuote("Here's a quote from Nikke Rowe..\n\n\tYou are here, alive and awake \n\tand for whatever reasons you have fought your battles, \n\tit's time to start focusing on what strengths pulled you up \n\twhen the entire world had knocked you down. \n\tThat's where the virtue in self grows.\n\n");
	while(engaging){
		std::cin >> input;
	
		const char * ptr = input.c_str();
		if(strcmp(ptr, "diary") == 0){
			std::cout<<quaranBuddy<<"Let it out, big or small, this computer can handle it all <3. When you're done writing, sign your name in this format: ~name\nIt's polite to say goodbye :)..."<< std::endl;
			entry = std::to_string(numDiaryEntries);
			entry.append(".txt");
			// path.append(entry);
			diary.open(entry);
			typing = true;
			while(typing){
				std::cin >> diary_input;
				std::size_t found = diary_input.find(compare);
				if(found == std::string::npos){
					diary << diary_input;
					diary << " ";
				}
				else{
					typing = false;
				}
			}
			diary.close();	
			std::cout <<quaranBuddy<< "Gotcha, hear ya, storing your entry as diary entry: "<< numDiaryEntries<< std::endl;
			++numDiaryEntries;
			std::cout<< quaranBuddy<<"What else can I help you with?"<<std::endl;
		}
		else if(strcmp(ptr, "erase diary entry") == 0){
			std::cout<<"I see you want to erase a diary entry, which one would you like to erase?"<<'\n';
			//searches for .txt files with numbers
			//allow function for pulling up past entries and shooting them to the terminal
		}
		else if(strcmp(ptr, "activity") == 0){
			activityLog today;
			today.initLog("June 8th, 2020");
			// head = &today;
			std::string input;
			std::cout<<quaranBuddy<<"today's date for your activity log is: "<< today.accessDate()<< '\n' << quaranBuddy <<
			"Time to enter your activites! What'd you do today?"<<std::endl;
			std::getline(std::cin, input);
			today.storeActivities(input);
			while(enteringData){
				// std::cin >> activity_input;
				std::getline(std::cin, input);
				const char * act = input.c_str();
				std::size_t search = input.find("done");
				if(strcmp(act, "nothing") == 0){
				// if(strstr(input, "nothing")){
					std::cout<<quaranBuddy<< "Awesome!\n"<< relax.retQuote() << std::endl; //randomize "awesome"
					enteringData = false;
				}
				else if(search != std::string::npos){
					std::cout<< quaranBuddy<< "Great!\n"<< self_care.retQuote()<<std::endl;
					enteringData = false;
				}
				else{
					// today.storeActivities(act);
					today.storeActivities(input);
					std::cout<<quaranBuddy<<"So far today I have:\n\n\t"<< today.accessDate()<<"\n\t--------------\t"<<today.accessActivities()<<'\n';
					std::cout<<quaranBuddy<<"What else did you do today?"<<std::endl;
				}
			}
			today.freeAct();
			std::cout<<quaranBuddy<<"Done with the activities list! Woo! That was a lot of work :)"<<'\n'<<quaranBuddy<<"What else can I help you with today?"<<std::endl;
		}
		else if(strcmp(ptr, "done") == 0){
			std::cout<<quaranBuddy<< "Sad to see you go, but happy to see you came at all :D" <<std::endl;
			engaging = false;
		}
		// else if(strcmp(ptr, "period") == 0){
		// 	std::cout<<quaranBuddy<<"Did you get your period today?"<<std::endl;

		// }
		else{
			std::cout<<quaranBuddy<< "I'm sorry, I didn't catch that. My services so far are:\n\tactivity,diary.\n" <<std::endl;
		}
	}
	std::cout<<quaranBuddy<< "Thanks for checking in! Have a good rest of your day, night, whateva ya doin <3"<< std::endl;
	return 0;
}
