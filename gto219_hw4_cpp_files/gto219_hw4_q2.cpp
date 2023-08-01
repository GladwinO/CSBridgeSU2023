// gto219_hw4_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string romanNumConvStr;
    int originalPosInt;
    int userPosInt, numD = 0, numL = 0, numV = 0, numC = 0, numX = 0, numI = 0;
    const int romanM = 1000, romanD = 500, romanC = 100, romanL = 50, romanX = 10, romanV = 5, romanI = 1;
    std::cout << "Enter decimal number:\n";
    std::cin >> userPosInt;
    originalPosInt = userPosInt;
    while (userPosInt > 0) {
        if (userPosInt - romanM >= 0) {
            userPosInt -= romanM;
            romanNumConvStr += "M";
        }
        else if (userPosInt - romanD >= 0 && numD < 1) {
            numD++;
            userPosInt -= romanD;
            romanNumConvStr += "D";
        }
        else if (userPosInt - romanC >= 0 && numD < 4) {
            numC++;
            userPosInt -= romanC;
            romanNumConvStr += "C";
        }
        else if (userPosInt - romanL >= 0 && numD < 1) {
            numL++;
            userPosInt -= romanL;
            romanNumConvStr += "L";
        }
        else if (userPosInt - romanX >= 0 && numD < 4) {
            numX++;
            userPosInt -= romanX;
            romanNumConvStr += "X";
        }
        else if (userPosInt - romanV >= 0 && numD < 1) {
            numV++;
            userPosInt -= romanV;
            romanNumConvStr += "V";
        }
        else if (userPosInt - romanI >= 0 && numD < 4) {
            numI++;
            userPosInt -= romanI;
            romanNumConvStr += "I";
        }
        else {
            std::cout << "An unknown error occurred." << std::endl;
            break;
        }
        
    }
    if (!romanNumConvStr.empty()) {
        std::cout << originalPosInt << " is " << romanNumConvStr << std::endl;
    }
    else {
        std::cout << "A viable number was not entered." << std::endl;
    }
    

    return 0;
}
