#include "wordle.h"
using namespace std;

const int numTries = 6;
int main() {
	Wordle gameWord;
	int counter = 0;
	gameWord.ReadWords();
	gameWord.PickWord();
	gameWord.WelcomeMessage();
	for (int i = 1; i < numTries + 1; i++) {
		gameWord.initializeArray();
		cout << "Guess " << i;
		gameWord.getInput();
		if (gameWord.checkAnswer()) {
			cout << "You win!";
			gameWord.PrintWord();
			return 0;
		}
		else
			gameWord.PrintCheck();
	}
	cout << "Sorry, out of tries. Better luck next time!" << endl;
	gameWord.PrintWord();
	return 0;
}