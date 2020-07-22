#pragma once
#include "Dictionary.h"
#include <set>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;
class Words {
public:
	Words(); //Default Constructor    
	~Words(); //Destructor 
	string userWord;
	int invalidPreCount = 0;
	int validPreCount = 0;
	void playGame();
private:
	char fileName[20] = "words.txt";
	string randomSecret;
	int countOfMatchLetters(string);
	int truePlaceCount(string);
	int numberGuesses();
	// flag set to true if cheat code is used bool cheated;   
	bool cheated();
};