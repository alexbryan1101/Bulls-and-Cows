#include "FBullsandCows.h"

using int32 = int;


FBullsAndCows::FBullsAndCows()
{
	Reset();
}

int32 FBullsAndCows::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullsAndCows::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullsAndCows::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
	 
}

bool FBullsAndCows::isGameWon() const
{
	return false;
}

EGuessStatus FBullsAndCows::CheckGuess(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullsAndCows::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

FBullCowCount FBullsAndCows::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		for (int32 Gchar = 0; Gchar < HiddenWordLength; Gchar++) 
		{
			if(Guess[MHWChar] == MyHiddenWord[Gchar])
			{
				if (MHWChar == Gchar) 
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
			
	return BullCowCount;
}
