# First-Year-Final
<span style="color: blue;">Word Guessing Game</span>
### In this program we will play a word guessing game. In this game, we will randomly select a five-letter word from a computer-generated dictionary.

All the words read from the file will be kept in set <string> words, valid words will be transferred into vector <string> secrets and random secret will be selected from this vector. Examples of these structures are given in the files below. You can carefully examine and use the relevant sections in your own code.
Each round the player will guess a word. If the prediction is correct, the computer will report how many estimates it has made and the program will end. If the guess is wrong, the computer will tell you how many letters are matched in the secret word and guess and how many of these letters are at the right spot.
> The player will then make the next guess. If the user enters the hint code **'xxxxx'** (hint word: hidden word), the program should show the secret word. Using the hint code should be counted as a guess and should not end the program
.
>
>> 
#### Any letter in your secret word should only be matched once. For example,
>
> - Secret word: cable
> - Guess: eagle
>
> *Results* in 3,3 , **not** 4,3.

This program must be coded using two classes. (In addition, the "main function" and preferably the source file from which the functions are defined).
*  The class called **Dictionary** must perform the search functions to enter and store words, to select a random word from the list, and to verify that they are in the dictionary. Dictionary will use a set <string> for efficient search. The function that selects a random word should not select a word with a repeated letter. (The guesswork might be a repeated letter word.)
*  Another class named **Words** will pay attention to the game rules, follow the game status and manage the user input and output.

![Adsız](https://user-images.githubusercontent.com/67970973/88230862-d54f2900-cc7b-11ea-8fe9-9b52ce89020c.png)


![Adsız2](https://user-images.githubusercontent.com/67970973/88231360-c61cab00-cc7c-11ea-8a8a-49e5d1f49be3.png)
