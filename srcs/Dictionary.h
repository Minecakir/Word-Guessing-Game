#pragma once
#include "Words.h"
#include <set>
#include <vector>
#include <fstream>
using namespace std;

class Dictionary {
public:
	//Default Constructor
	Dictionary();
	//opens file and assign all words into set<string> words;
	Dictionary(char*);
	~Dictionary();//Destructor
	// return a random word (without repeated letters) 
	string bringValidWord();
	// check if word is in Dictionary
	bool wordValid(string);
private:
	set<string> words;
	vector<string> secret;
	vector<string> secrets;
	bool isSecretWord(string);
};