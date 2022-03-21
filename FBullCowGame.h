#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame
{
public:
    FBullCowGame();

    int32 GatMax() const;
    int32 GetCurrentTry() const;
    bool IsGameWon()const;
    int32 GetHiddenWordLength()const;
    bool CheckGuessValidatity(FString)const;

    void Reset();
    FBullCowCount SubmitGuess(FString);

private:
    int32 MyCurrentTry = 1;
    int32 MyMaxTries = 5;
    FString MyHidenWord;
};