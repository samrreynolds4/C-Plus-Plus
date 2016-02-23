// Sam Reynolds
// Simple number guessing game in you chose a number between 1 - 10 and the computer tries to guess it 
// while removing the numbers already guessed


#include <iostream>
#include <time.h>
using namespace std;

int playerWins = 0;
int comWins = 0;

bool newGame()
   {
	int compNum, compGuess, myGuess, turns, play;
	int myNum = 11; // set to 11 so the while loop will run
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // an array of numbers for the computer to check
	
	myGuess = 0; 
	turns = 1; // set to 1 because there will always be one turn



	srand(time(0));
	
	// get a number while the number is not between 1-10
	while (myNum > 10 || myNum < 1)
	{
		cout << "Enter a number between 1-10 you wish the computer to guess: ";
		cin >> myNum;
	}
		
		cout << endl << "Your number: " << myNum << endl;
		compNum = rand() % 10 + 1;
	
	// while players guess is incorrect, guess again.
	while (myGuess != compNum)
	{
		cout << "Enter your Guess: ";
		cin >> myGuess;
		 
		if (myGuess == compNum)
		{
			++playerWins;
			cout << endl <<"Game Over" << endl << "You guessed correctly after " << turns << " turns " << endl;
			cout << endl << "Computer wins: " << comWins << endl;
			cout << "Player wins: " << playerWins << endl;
			break;
		}
		
		// Find out if the number has already been used
		int index = rand() % 10;
		while(list[index] == -1)
			index = rand() % 10;

		compGuess = list[index];
		cout << "Gussing number... " << compGuess << endl;

		if (compGuess == myNum)
		{
			++comWins;
			cout << endl << "Game Over" << endl << "Computer guessed correctly after " << turns << " turns" << endl;
			cout << endl << "Computer wins: " << comWins << endl;
			cout << "Player wins: " << playerWins << endl;
			break;
		}
		else {
			list[index] = -1; // set the element at index to -1 if it's not the number
		}


		turns++;
		
	}

	// Ask the player if they want to play again.
	cout << endl << "Play Again? (1/0): ";
	cin >> play;
	if (play == 1)
		return true; // make a new game
	else return false; // Quit game
}

int main()
{
	while (newGame()); // while this returns true, make a new game

	return 0;
}