#include <iostream>
#include <string>
#include "FBullsandCows.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullsAndCows BCGame;

int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;
}

void PrintIntro() 
{
	//Introduce the game
	std::cout << "Welcome to Bulls and Cows\n\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	//Get the guess from the user
	std::cout << "Try " << CurrentTry << ": What is your guess? ";
	FText Guess;
	getline(std::cin, Guess);
	return Guess;
}

void PlayGame()
{
	BCGame.Reset();
	//create a game instance
	int32 MaxTries = BCGame.GetMaxTries();

	//loop number of guesses
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess();

		EGuessStatus Status = BCGame.CheckGuess(Guess);

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	// TODO print summary of game 
}

bool AskToPlayAgain() 
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}