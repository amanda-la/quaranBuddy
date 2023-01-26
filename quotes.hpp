#include <vector>
#include <iostream>
#include <string.h>
#include<random>

enum quoteType {relax, self_care, confidence, self_love};

class typesOfQuotes{
	quoteType t;
	std::vector<std::string> quotes;
	int currentQ;
	typesOfQuotes * prev;
	typesOfQuotes * next;
public:
	void init_quotes();
	void setEnum(const quoteType& val);
	void addQuote(std::string);
	void populateQuotes();
	std::string retQuote();
};

