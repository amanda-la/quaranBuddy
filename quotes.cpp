#include "quotes.hpp"

//Initializes the quote structure to hold 10 quotes
void typesOfQuotes::init_quotes(){
	quotes.reserve(10);
	currentQ = 0;
	for(int i = 0; i < 10; ++i){
		quotes[i] = "";
	}
	prev = NULL;
	next = NULL;
}

//improvement: check if enum is within range of listed enums
void typesOfQuotes::setEnum(const quoteType& val){
	if(val == quoteType::relax){
		t = relax;
	}
}

//Adds a quote to the quote structure
void typesOfQuotes::addQuote(std::string quote){
	if(quotes.size() < 10){
		quotes.push_back(quote);
	}
}

//Fills up typeOfQuotes object with quotes based on enum
//TODO: add quotes based on quoteBank
//improvement: add tags or separate files based on quoteBank
void typesOfQuotes::populateQuotes(){
	if(t == quoteType::relax){
		this->addQuote("It was Thich Nhat Hanh who said...\n\n\tWe humans have lost the wisdom of genuinely resting and relaxing.\n\tWe worry too much.\n\tWe dont allow our bodies to heal,\n\tand we dont allow our minds and hearts to heal.\n\nEnjoy your time to yourself and dont let anyone make you feel bad for it :).");
		this->addQuote("\n\tSometimes, this is my busy -\n\tand I will not apologize for it.”\n\t― Brittin Oakman\n\t");
		this->addQuote("\n\tToday and onwards, I stand proud, for the bridges I've climbed, for the battles I've won,\n\tand for the examples I've set, but most importantly, for the person I have become. I like who I am now, \n\tfinally, at peace with me...”― Heather James, Things A Mother Should Know: For The World's Most Important Mum");
		this->addQuote("\n\t“I lied and said I was busy.\n\tI was busy; but not in a way most people understand.\n\t");
	}
}

//Returns a random quote from the quote bank
std::string typesOfQuotes::retQuote(){
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,quotes.size());
	return quotes[distribution(generator)];
}
