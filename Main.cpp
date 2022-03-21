#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess(int32);
bool AskPlayAgain();

FBullCowGame BDGame;

int main()
{

    bool AskAgain = false;
    do
    {
        PrintIntro();
        PlayGame();
        AskAgain = AskPlayAgain();
        std::cout << std::endl;
    } while (AskAgain);

    //TODO Implement IsGameWon function

    std::cout << "Game ower" << std::endl;
    std::cout << std::endl;
    return 0;
}

void PrintIntro()
{

    std::cout << "Welcome to the Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << BDGame.GetHiddenWordLength();
    std::cout << " letter isogram that I`m thinking of ?\n";
}

void PlayGame()
{
    BDGame.Reset();
    int32 CurrentValue = BDGame.GetCurrentTry();
    int32 MaxValue = BDGame.GatMax();
    std::cout << "You have " << MaxValue << " trys" << std::endl;
    std::cout << std::endl;

    //TODO Chang from FOR in WHILE
    for (int32 i = 1; i <= MaxValue; i++)
    {
        FText Guess = GetGuess(CurrentValue++);

        FBullCowCount BullCowCount = BDGame.SubmitGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;

        std::cout << "Cows = " << BullCowCount.Cows << std::endl;

        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }

    //TODO Set words

    //TODO Calculat Bulls and Cows

    //TODO Set check result Isometry to exit from WHILE

}

FText GetGuess(int32 i)
{
    std::cout << "Try " << i << ". Enter your guess: ";
    FText Guess = "";
    getline(std::cin, Guess);
    return Guess;
}

bool AskPlayAgain()
{

    FText Response = "";
    std::cout << "Do you wont play again ?" << std::endl;
    std::cout << "Press y or n " << std::endl;
    getline(std::cin, Response);

    while ((Response[0] != 'y') && (Response[0] != 'n') && (Response[0] == 'Y') && (Response[0] == 'N'))
    {
        std::cout << "Wrong button only y/n try again" << std::endl;
        getline(std::cin, Response);
        std::cout << std::endl;
    }

    if (Response[0] == 'y' || Response[0] == 'Y')
    {
        std::cout << "You said yes" << std::endl;
        return true;
    }
    else if (Response[0] == 'n' || Response[0] == 'N')
    {
        std::cout << "You said no" << std::endl;
        return false;
    }
    return 0;
}