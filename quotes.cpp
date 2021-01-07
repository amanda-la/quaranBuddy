#include "quotes.hpp"

void typesOfQuotes::init_quotes(){
	quotes.reserve(10);
	currentQ = 0;
	for(int i = 0; i < 10; ++i){
		quotes[i] = "";
	}
	prev = NULL;
	next = NULL;
}

void typesOfQuotes::addQuote(std::string quote){
	if(quotes.size() < 10){
		quotes.push_back(quote);
	}
}

std::string typesOfQuotes::retQuote(){
	int index = currentQ;
	++currentQ;
	if(index < 10){
		return quotes[index];
	}
	else{
		currentQ = 0;
		return quotes[currentQ];
	}
}