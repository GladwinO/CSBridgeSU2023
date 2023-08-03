// gto219_hw5_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int randNumInt, userGuessInt, numGuessInt  = 5, lowerBound = 1, upperBound = 100;
    

    std::srand(time(0));

    randNumInt = (rand() % 100) + 1;
    std::cout << randNumInt << std::endl;

    std::cout << "I thought of a number between 1 and 100! Try to guess it." << std::endl;
    
    while (numGuessInt > 0) {
        std::cout << "Range: [" << lowerBound << ", " << upperBound << "]," <<
            " Number of guesses left: " << numGuessInt << std::endl;
        std::cout << "Your guess: ";
        std::cin >> userGuessInt;

        if (userGuessInt == randNumInt) {
            if (numGuessInt > 1) {
                std::cout << "Congrats! You guessed my number in " << numGuessInt << " guesses.";
                break;
            }
            else {
                std::cout << "Congrats! You guessed my number in " << numGuessInt << " guess.";
                break;
            }
            
        }
        else {
            if (userGuessInt > randNumInt && numGuessInt > 1) {
                std::cout << "Wrong! My number is smaller.\n" << std::endl;
                if (userGuessInt >= lowerBound && userGuessInt <= upperBound) {
                    upperBound = userGuessInt - 1;
                }
                else {
                    std::cout << "Your guess was out of the range. Tsk Tsk, what a waste " <<
                        "of a guess! They are your guesses and not mine.\n" << std::endl;
                }
                
                numGuessInt--;
            }
            else if (userGuessInt < randNumInt && numGuessInt > 1) {
                std::cout << "Wrong! My number is bigger.\n" << std::endl;
                if (userGuessInt >= lowerBound && userGuessInt <= upperBound) {
                    lowerBound = userGuessInt + 1;
                }
                else {
                    std::cout << "Your guess was out of the range. Tsk Tsk, what a waste " <<
                        "of a guess! They are your guesses and not mine.\n" << std::endl;
                }
                numGuessInt--;
            }
            else if (userGuessInt < randNumInt && numGuessInt == 1) {
                std::cout << "Out of guesses! My number is " << randNumInt << std::endl;
                numGuessInt--;
            }
            
        }
    }


    return 0;
}
