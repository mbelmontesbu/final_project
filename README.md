# Michael Belmonte Final Project
Michael Belmonte
Final Project Repo for PHY 504

## Wordle
I have recreated Wordle in C++ to be run on the command line.
The list of all available words that could be selected as the answer are in dictionary.txt.

Some assumptions that were made when creating this project are that I will not test whether the guess entered is an actual word in the english dictionary.

### letter_block.H
  A header file that creates a class called letter_block. To be used for ease of printing out the letters to the console and storing the character, color, and position of the letter in a word.
### color.H
  A header file that adds "global" variables for inserting the ASCII codes for highlighting the color blocks.
### gen_random_word.cpp/rand.H
  Adds a function to create a random word from the list of words given in dictionary.txt.
### get_entry.cpp/get_entry.H
  Adds a function to prompt the user for a guess word. The function asserts that the word is 5 characters long and the characters are a-z.
 ### wordle_project.cpp
  The complete game logic for Wordle. Allows the user to make 6 guesses to guess the correct word. Includes the game logic for determining the colors of the letters in the guess given. 


As a test, when compiling in debug mode (make DEBUG=TRUE), the answer will always be "sheep" and the program will display the answer as well, allowing you to guess while knowing what the answer is. I found this word the best to test double letters against. A usual test I would try is guessing words like "essay" to test how the program would deal with double s's and double e's. Also in debug mode, the program asserts that you enter a correct character of the alphabet in letter_block.H.





