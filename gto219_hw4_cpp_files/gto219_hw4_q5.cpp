// gto219_hw4_q5.cpp 

#include <iostream>

int main()
{
    int userPosInt, numLinesInt, numStarsInt, hrglassorientationInt, numSpacesInt = 0;
    char star = '*';
    int maxNumSpacesInt;
    const int minNumStarsInt = 1;
    const int starLineDifInt = 2;
    std::cout << "Please provide a positive integer: ";
    std::cin >> userPosInt;

    maxNumSpacesInt = userPosInt - 1;
    numLinesInt = 2 * userPosInt;
    numStarsInt = numLinesInt - 1;
    hrglassorientationInt = numStarsInt;
    if (userPosInt > 0) {
        for (int i = 0; i < numLinesInt; i++) {
            for (int i = 0; i < numSpacesInt; i++) {
                std::cout << " ";
            }
            if (hrglassorientationInt > 0) {
                for (int i = 0; i < numStarsInt; i++) {
                    std::cout << star;
                }
                std::cout << std::endl;

                if (numSpacesInt < maxNumSpacesInt) {
                    numSpacesInt++;
                }
                hrglassorientationInt -= starLineDifInt;
                if (numStarsInt > minNumStarsInt) {
                    numStarsInt -= starLineDifInt;
                }

            }
            else {
                for (int i = 0; i < numStarsInt; i++) {
                    std::cout << star;
                }
                std::cout << std::endl;
                numSpacesInt--;
                numStarsInt += starLineDifInt;
            }
        }
    }
    else {
        std::cout << "You did not enter a positive integer." << std::endl;
    }
    
}
