#include "Words.h"

Words::Words() {}
Words::~Words() {}
void Words::playGame()
{
	Dictionary obj(fileName);
	randomSecret = obj.bringValidWord();
	while (1)
	{
		numberGuesses();
		if (obj.wordValid(userWord) == 1)
		{
			if (cheated() == 1)
			{
				cout << endl << "Secret word is:";
				cout << "|" << this->randomSecret << "|";
				cout << endl;
			}
			else
			{
				if (userWord == randomSecret)
				{
					break;
				}
				cout << endl << "Same letter: " << countOfMatchLetters(userWord);
				cout << endl << "Count of true place letter(s): " << truePlaceCount(userWord);
				cout << endl << "***********************************" << endl;
			}
		}
		else
		{
			cout << "Word is not in dictionary.Try again!" << endl;
			invalidPreCount--;
		}
	}
}
int Words::countOfMatchLetters(string userWord)
{
	int countLetters = 0;
	int fiveLettersWord = 0;
	for (int k = 0; k < 5; k++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (userWord[k] == randomSecret[j])
			{
				countLetters = 0;
				for (int m = k + 1; m < 5; m++)
				{
					if (userWord[k] == userWord[m])
					{
						countLetters++;
					}
				}
				if (countLetters == 0)
				{
					fiveLettersWord++;
				}
			}
		}
	}
	return fiveLettersWord;
}
int Words::truePlaceCount(string userWord)
{
	int controlLetters = 0;
	for (int i = 0; i < 5; i++)
	{
		if (userWord[i] == randomSecret[i])
		{
			controlLetters++;
		}
	}
	return controlLetters;
}
int Words::numberGuesses()
{
	cout << endl << "WORD: ";
	cin >> userWord;
	Dictionary obj;
	invalidPreCount++;
	if (userWord == "xxxxx")
	{
		validPreCount++;
	}
	if (userWord == randomSecret)
	{
		cout << endl << "------------------------------------";
		cout << endl << "Congratulations!!";
		cout << endl << "You have reached the correct result in " << invalidPreCount << " prediction(s).";
		if (validPreCount != 0)
		{
			cout << endl << "You used clue.";
		}
	}
	return invalidPreCount;
}
bool Words::cheated()
{
	if (userWord == "xxxxx")
	{
		return 1;
	}
	else
		return 0;
}