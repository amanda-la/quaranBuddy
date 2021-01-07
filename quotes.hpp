#include <vector>
#include <iostream>
#include <string.h>

class typesOfQuotes{
	std::vector<std::string> quotes;
	int currentQ;
	typesOfQuotes * prev;
	typesOfQuotes * next;
public:
	void init_quotes();
	void addQuote(std::string);
	std::string retQuote();
};

