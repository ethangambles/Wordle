#include "wordle.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Wordle::Wordle() {
	gameWord = " ";
	usrWord = " ";
}

void Wordle::WelcomeMessage() {
	cout << "Welcome to Wordle! You have six tries to guess the word" << endl;
	cout << "Each guess must be a valid five-letter word. Hit enter to submit." << endl;
	cout << "After each guess, the numbers corresponding to the positions of the letters will change to show how close your guess was to the word." << endl;
	cout << "If the position has a 2, that means it is the right letter in the right position." << endl;
	cout << "A 1 in the position means it is a correct letter in the wrong position." << endl;
	cout << "A 0 in the position means it is incorrect." << endl;
	cout << "That's it! Good luck and have fun!" << endl;
}

void Wordle::initializeArray() {
	for (int i = 0; i < wordSize; i++)
		wordCheck[i] = 0;
}

void Wordle::ReadWords() {
	ifstream file("words.txt");
	if (file.is_open()) {
		for (int i = 0; i < wordCount; i++)
			file >> wordList[i];
	}
	else
		cout << "Unable to open file";
	return;
}

void Wordle::PickWord() {
	srand(time(NULL));
	int randIndex = rand() % wordCount;  // generates random number from 0 to 2315
	gameWord = wordList[randIndex];
}

void Wordle::PrintWord() {
	cout << gameWord;
}

void Wordle::getInput() {
	cout << endl;
	cin >> usrWord;
	checkInput();
}

void Wordle::PrintCheck() {
	for (int i = 0; i < wordSize; i++) {
		cout << wordCheck[i] << " ";
	}
	cout << endl;
}

bool Wordle::checkAnswer() {
	int cnt = 0;
	//check each letter and compare
	for (int i = 0; i < wordSize; i++) {
		if (usrWord[i] == gameWord[i])
			wordCheck[i] = 2;
		else 
			for (int j = 0; j < wordSize; j++) {
				if (usrWord[i] == gameWord[j])
					wordCheck[i] = 1;
		}
	}
	// check wordCheck to see if it is correct
	for (int i = 0; i < wordSize; i++) {
		if (wordCheck[i] == 2)
			cnt++;
	}
	//return 1 if the word is correct, 0 otherwise
	if (cnt == 5)
		return 1;
	else
		return 0;

}

void Wordle::checkInput() {
	for (int i = 0; i < wordSize; i++) {
		if (isupper(usrWord[i]))
			usrWord[i] = tolower(usrWord[i]);
	}
	for (int i = 0; i < wordCount; i++) {
		if (usrWord == wordList[i])
			return;
	}
	cout << "Bad input, try again.";
	getInput();
}