#include "FBullCowGame.h"


using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "best";
	MyHidenWord = HIDDEN_WORD;
	GatMax();
	GetCurrentTry();

}

bool FBullCowGame::CheckGuessValidatity(FString) const
{
	return false;
}

//Recives a valid guess, increments turns and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number 
	MyCurrentTry++;
	//setup a return varible
	FBullCowCount BullCowCount;
	//loop through all letters 
	int32 HiddenWordLength = MyHidenWord.length();


	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		if (Guess[i] != MyHidenWord[i]) //increment bulls if yes
		{
			BullCowCount.Cows++;
		}
		//compere letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			//if they match then
			if (Guess[j] == MyHidenWord[i]) //increment bulls if yes
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}

			}


		}



	}
	return BullCowCount;
}



int32 FBullCowGame::GatMax() const {
	return MyMaxTries;
}


int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon()const
{
	return false;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHidenWord.length();
}

