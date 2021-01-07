#include "dialogue.hpp"

void initVec(std::vector<std::string> vec){
	vec.reserve(10);
	for(int i = 0; i < 10; ++i){
		vec[i] = "";
	}
}

void addPhrase(std::vector<std::string> vec, std::string phrase){
	if(vec.size() < 10){
		vec.push_back(phrase);
	}
}
