# Michael Belmonte Final Project
Michael Belmonte
Final Project Repo for PHY 504

## Wordle
I have recreated Wordle in C++ to be run on the command line.
The list of all available words that could be selected as the answer are in dictionary.txt.

Some assumptions that were made when creating this project are that I will not test whether the guess entered is an actual word and that there are no 5 letter words that have two of the same double letter pairs in it. For example, "eetee", which is not a word, if guessed could properly color the first two e's as yellow, however, improprly color the third e as white for the correct answer of "sheep". However, this is an extreme edge case for those who are not guessing real words.

As a test, when compiling in debug mode (make DEBUG=TRUE), the answer will always be "sheep" and the program will display the answer as well, allowing you to guess while knowing what the answer is. I found this word the best to test double letters against. A usual test I would try is guessing words like "essay" to test how the program would deal with double s's and double e's. Also in debug mode, the program asserts that you enter a correct character of the alphabet.





