#include "Dictionary.h"
Dictionary::Dictionary() {}

Dictionary::Dictionary(char* fileName)
{
	fstream dataFile;
	string allWords;
	dataFile.open(fileName, ios::in);
	if (!dataFile)
	{
		cout << "Error! File could not be opened." << endl;
		exit(0);
	}
	else
	{
		//cout << "File opened successfully!" << endl;
	}
	dataFile >> allWords;
	while (!dataFile.eof())
	{
		words.insert(allWords);
		dataFile >> allWords;
	}
}

Dictionary::~Dictionary(){}

string Dictionary::bringValidWord()
{
	int size = 0;
	secret.assign(words.begin(), words.end());
	cout << "                                    ----WELCOME TO WORD GUESSING GAME----" << endl;
	cout << "(Please enter a 5 letter word)" << endl;
	for (int a = 0; a < secret.size(); a++)
	{
		if (isSecretWord(secret[a]) != 0)
		{
			secrets.push_back(secret[a]);
			size++;
		}
	}
	string randomSecret;
	randomSecret = secrets[rand() % secrets.size()];//Choose random word in secrets
	return randomSecret;
}

bool Dictionary::wordValid(string word)
{
	//bool check = true;
	int flag = 0;
	for (set<string>::iterator c = words.begin(); c != words.end(); ++c)
	{
		if (word == *c || word == "xxxxx")
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool Dictionary::isSecretWord(string word)
{
	for (int rw = 0; rw < secret.size(); rw++)
	{
		for (int cl = rw + 1; cl < 5; cl++)
		{
			if (word[rw] == word[cl])
			{
				return 0;
			}
		}
	}
}