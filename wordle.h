#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int wordCount = 2315;
const int wordSize = 5;

class Wordle {
public:
	// default constructor
	Wordle();

	//prints a welcome message and explains rules
	void WelcomeMessage();

	void initializeArray();

	// reads in the words from a txt file and puts them in an array
	void ReadWords();
	
	// randomly picks a word from the array
	void PickWord();
	
	//prints the word
	void PrintWord();

	//prints the 0's,1's, and 2's depending on your guess
	void PrintCheck();

	void getInput();

	//check the answer
	bool checkAnswer();

	void checkInput();

private:
	string gameWord; // the word to be found
	string usrWord;
	string wordList[wordCount]; // the list of possible words
	int wordCheck[wordSize]; // checks each letter as the user guesses, setting index to 2 if letter is correct, 1 if it is in the word but in the wrong place, and 0 otherwise


};