/*
This implementation generates a random code of 10 digits between 0 and 9 and prompts the user to guess the code.
The program then checks the guess and gives feedback on the number of correct digits and correct positions,
as well as the number of almost correct digits (i.e., digits that are in the code but in a different position).
The user can continue to guess until they correctly guess the entire code.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CODE_LENGTH = 10;

// Generate a random code of given length
void generateCode(int code[], int length)
{
    srand(time(0)); // Initialize random seed
    for (int i = 0; i < length; i++)
    {
        code[i] = rand() % 10; // Generate a random digit between 0 and 9
    }
}

// Calculate the number of correct digits and correct positions
void checkGuess(int code[], int guess[], int length, int &correct, int &almost)
{
    correct = almost = 0;
    bool usedCodeDigits[length] = {false};
    bool usedGuessDigits[length] = {false};
    for (int i = 0; i < length; i++)
    {
        if (guess[i] == code[i])
        {
            correct++;
            usedCodeDigits[i] = true;
            usedGuessDigits[i] = true;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (!usedGuessDigits[i])
        {
            for (int j = 0; j < length; j++)
            {
                if (!usedCodeDigits[j] && guess[i] == code[j])
                {
                    almost++;
                    usedCodeDigits[j] = true;
                    break;
                }
            }
        }
    }
}

int main()
{
    int code[CODE_LENGTH];
    generateCode(code, CODE_LENGTH);
    cout << "Welcome to Mastermind!\n";
    cout << "Guess the " << CODE_LENGTH << " digit code.\n";
    cout << "Digits range from 0 to 9.\n";
    cout << "You have unlimited tries.\n";
    while (true)
    {
        int guess[CODE_LENGTH];
        cout << "Enter your guess: ";
        for (int i = 0; i < CODE_LENGTH; i++)
        {
            cin >> guess[i];
        }
        int correct, almost;
        checkGuess(code, guess, CODE_LENGTH, correct, almost);
        cout << "Result: ";
        cout << correct << " correct digit" << (correct == 1 ? "" : "s");
        cout << " and " << almost << " almost correct digit" << (almost == 1 ? "" : "s");
        cout << endl;
        if (correct == CODE_LENGTH)
        {
            cout << "Congratulations, you won!\n";
            break;
        }
    }
    return 0;
}
