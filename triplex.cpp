#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a secure facility...\n";
    std::cout << "You are currently on level "<< Difficulty << std::endl;
    std::cout << "Enter the correct codeline to continue...\n\n";
    
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Declare 3 number code
    const int CodeA = rand() %Difficulty +Difficulty;
    const int CodeB = rand() %Difficulty +Difficulty;
    const int CodeC = rand() %Difficulty +Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "+There are 3 numbers in the code" << std::endl;
    std::cout << "+The codes add up to: " << CodeSum << std::endl;
    std::cout << "+The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Condition checker
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***You win! Please continue.***";
        return true;
    }
    else
    {
        std::cout << "\n***You have failed. Start over if you dare***";
        return false;    
    }
}



int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 15;

    while (LevelDifficulty <= MaxDifficulty) // Loops game until levels are completed 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** Great work, you have the files you needed. Hurry out! ***\n";
    system("pause");
    return 0;
}