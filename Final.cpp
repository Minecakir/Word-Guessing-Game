#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;
char filename[20] = "words.txt";
class Dictionary {
public:
	//Default Constructor
	Dictionary() {};
	//opens file and assign all words into set<string> words;
	Dictionary(char* filename)
	{
		fstream dataFile;
		string allwords;
		dataFile.open("words.txt", ios::in);
		if (!dataFile)
		{
			cout << "Error! File could not be opened." << endl;
			exit(0);
		}
		else
		{
			//cout << "File opened successfully!" << endl;
		}
		dataFile >> allwords;
		while (!dataFile.eof())
		{
			words.insert(allwords);
			dataFile >> allwords;
		}
		/*for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
		{
			cout << *it << endl;
		}*/
	}
	~Dictionary()
	{
	}//Destructor
	// return a random word (without repeated letters) 
	string BringValidWord()
	{
		int size = 0;
		secret.assign(words.begin(), words.end());
		cout << "                                    ----WELCOME TO WORD GUESSING GAME----" << endl;
		cout << "(Please enter a 5 letter word)" << endl;
		for (int a = 0; a < secret.size(); a++)
		{
			if (IsSecretWord(secret[a]) != 0)
			{
				secrets.push_back(secret[a]);
				size++;
			}
		}
		string randomSecret;
		randomSecret = secrets[rand() % secrets.size()];//Choose random word in secrets
		return randomSecret;
	}
	// check if word is in Dictionary
	bool WordValid(string word)
	{
		//bool check = true;
		int flag = 0;
		for (set<string>::iterator c= words.begin(); c != words.end(); ++c)
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
private:
	set<string> words;
	vector <string>secret;
	vector<string> secrets;

	bool IsSecretWord(string word)
	{
		int count = 0;
		for (int rw = 0; rw < secret.size(); rw++)
		{
			count = 0;
			for (int cl = rw + 1; cl < 5; cl++)
			{
				if (word[rw] == word[cl])
				{
					return 0;
				}
			}
		}
	}
};

class Words {
public:
	Words() {}; //Default Constructor    
	~Words() {}; //Destructor 
	string userWord;
	int count = 0;
	int count2 = 0;
	void playgame(Words&)
	{
		int döngü;
		Dictionary obj(filename);
		randomSecret = obj.BringValidWord();
		while (1)
		{
			numberguesses();
			if (obj.WordValid(userWord) == 1)
			{
				if (cheated() == 1)
				{
					cout << endl << "Secret word is:";
					cout <<"|" << this->randomSecret << "|";
					cout << endl;
				}
				else
				{
					if (userWord == randomSecret)
					{
						break;
					}
					cout << endl << "Same letter: " << countofMatchLetters(userWord);
					cout << endl << "Count of true place letter(s): " << TruePlacecount(userWord);
					cout << endl << "***********************************" << endl;
				}
			}
			else
			{
				cout << "Word is not in dictionary.Try again!" << endl;
				count--;
			}
		}
	}
private:
	string randomSecret;
	int countofMatchLetters(string userWord)
	{
		int count2 = 0;
		int count = 0;
		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (userWord[k] == randomSecret[j])
				{
					count2 = 0;
					for (int m = k + 1; m < 5; m++)
					{
						if (userWord[k] == userWord[m])
						{
							count2++;
						}
					}
					if (count2 == 0)
					{
						count++;
					}
				}
			}
		}
		return count;
	}
	int TruePlacecount(string userWord)
	{
		int control = 0;
		for (int i = 0; i < 5; i++)
		{
			if (userWord[i] == randomSecret[i])
			{
				control++;
			}
		}
		return control;
	}
	int numberguesses()
	{
		cout << endl << "WORD: ";
		cin >> userWord;
		Dictionary obj;
		count++;
		if (userWord == "xxxxx")
		{
			count2++;
		}
		if (userWord == randomSecret)
		{
			cout << endl << "------------------------------------";
			cout << endl << "Congratulations!!";
			cout << endl << "You have reached the correct result in " << count << " prediction(s).";
			if (count2 != 0)
			{
				cout << endl << "You used clue.";
			}
		}
		return count;
	}
	// flag set to true if cheat code is used bool cheated;   
	bool cheated()
	{
		if (userWord == "xxxxx")
		{
			return 1;
		}
		else
			return 0;
	}
};
int main()
{
	srand(time(NULL));

	Words obj2;
	obj2.playgame(obj2);//Call playgame() function.

	cout << endl;
	system("pause");
	return 0;
}