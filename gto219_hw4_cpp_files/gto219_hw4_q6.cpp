// gto219_hw4_q6.cpp 

#include <iostream>

int main()
{
    int userPosInt, modRemainder, divRemainder;
    int numEven = 0 , numOdd = 0, evenRemainder;
    const int lastDigitFinder = 10;
    const int evenFinder = 2;
    std::cout << "Please provide a positive integer: ";
    std::cin >> userPosInt;
    for (int i = 1; i <= userPosInt; i++) {
        divRemainder = i;
        while (divRemainder != 0) {
            //part of the code that isolates the last digit
            modRemainder = divRemainder % lastDigitFinder;
            evenRemainder = modRemainder % evenFinder;

            // part of the code that checks if the digit is even or odd
            if (evenRemainder == 0) {
                numEven += 1;
            }
            else {
                numOdd += 1;
            }

            divRemainder /= lastDigitFinder;

        }
        //prints out number if there are more even digits than odd digits
        if (numEven > numOdd) {
            std::cout << i << std::endl;
        }
        //resets numEven and numOdd for next number i
        numEven = 0;
        numOdd = 0;
    }



    return 0;
}

