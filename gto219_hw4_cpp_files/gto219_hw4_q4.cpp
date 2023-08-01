// gto219_hw4_q4.cpp :

#include <iostream>
#include <cmath>

int main()
{
    int userSeqLen;
    double userNum, currNum = 1.0;

    std::cout << "Section a:" << std::endl;

    std::cout << "Please enter the length of the sequence: ";
    std::cin >> userSeqLen; 
    std::cout << "Please enter your sequence:\n";
    double exponent = 1.0 / userSeqLen;

    for (int i = 0; i < userSeqLen; i++) {
        std::cin >> userNum;
        currNum *= userNum;
    }
    currNum = pow(currNum, exponent);
    std::cout.precision(4);
    std::cout << "The geometric mean is: " << std::fixed << currNum << std::endl;

    std::cout << "Section b:" << std::endl;

    userSeqLen = 0;
    currNum = 1;
    userNum = 0;
    
    std::cout << "Please enter  non-empty sequence of positive integers, each one in " <<
        "a separate line. End your\nsequence by typing -1:" << std::endl;

    while (userNum != -1) {
        std::cin >> userNum;
        
        if (userNum != -1) {
            currNum *= userNum;
            userSeqLen++;
        }
        

    }
    exponent = 1.0 / userSeqLen;
    currNum = pow(currNum, exponent);
    std::cout.precision(4);
    std::cout << "The geometric mean is: " << std::fixed << currNum << std::endl;





    return 0;
}

