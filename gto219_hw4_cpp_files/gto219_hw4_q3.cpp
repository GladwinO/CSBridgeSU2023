// gto219_hw4_q3.cpp 

#include <iostream>
#include <cmath>

int main()
{
    int userPosInt, largestMultOfTwo = 0, exponentDigitPlac = 0, twoBitLoc, currMultOfTwo;
    int posIntRemain = 0, binaryRep = 0;
    std::cout << "Enter decimal number:\n";
    std::cin >> userPosInt;
    posIntRemain = userPosInt;

    while (largestMultOfTwo < userPosInt) {
        largestMultOfTwo = std::pow(2.0, exponentDigitPlac);
        if (largestMultOfTwo <= userPosInt) {
            exponentDigitPlac++;
        }
        
    }
    twoBitLoc = exponentDigitPlac - 1;
    
    while (twoBitLoc >= 0) {
        currMultOfTwo = pow(2.0, twoBitLoc);
        if (posIntRemain - currMultOfTwo >= 0) {
            posIntRemain -= currMultOfTwo;
            binaryRep += (1.0 * pow(10.0, twoBitLoc));
        }
        twoBitLoc -= 1;
         
    }
    std::cout << binaryRep;

    return 0;
}

