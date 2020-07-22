# First-Year-Final
### In this program we will play a word guessing game. In this game, we will randomly select a five-letter word from a computer-generated dictionary.

All the words read from the file will be kept in set <string> words, valid words will be transferred into vector <string> secrets and random secret will be selected from this vector. Examples of these structures are given in the files below. You can carefully examine and use the relevant sections in your own code.
Each round the player will guess a word. If the prediction is correct, the computer will report how many estimates it has made and the program will end. If the guess is wrong, the computer will tell you how many letters are matched in the secret word and guess and how many of these letters are at the right spot.
> The player will then make the next guess. If the user enters the hint code 'xxxxx' (hint word: hidden word), the program should show the secret word. Using the hint code should be counted as a guess and should not end the program
.
>
>> 
Any letter in your secret word should only be matched once. For example,
 
Secret word: cable Guess: eagle results in 3,3 , not 4,3.
