// gto219_hw7_q2.cpp :

#include <iostream>
#include <cmath>

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
    int userPosInt, numOfDivsInt = 0, sumOfDivsInt = 0, userMaxNumInt, numPerfectInt = 0;
    const int numColumnInt = 10;
    int amicPair = 0, amicPairTotal = 0, placeHolder = 0;
    int numAmicLoops = 0;
    std::cout << "Please enter a positive number n >= 2: ";
    std::cin >> userPosInt;

    std::cout << "Section A:" << std::endl;
    analyzeDividors(userPosInt, numOfDivsInt, sumOfDivsInt);

    std::cout << "The number of proper divisors are " << numOfDivsInt <<
        " and the sum of the divisors is " << sumOfDivsInt << "." << std::endl;

    std::cout << "\nSection B:" << std::endl;
    if (isPerfect(userPosInt)) {
        std::cout << userPosInt << " is a perfect number." << std::endl;
    }
    else {
        std::cout << userPosInt << " is not a perfect number." << std::endl;
    }

    std::cout << "\nSection C:" << std::endl;
    std::cout << "Please enter another positive number M >= 2: ";
    std::cin >> userMaxNumInt;

    std::cout << "The list of perfect numbers from 2 to " << userMaxNumInt << " is:\n";
    if (userMaxNumInt >= 2) {
        for (int i = 2; i <= userMaxNumInt; i++) {
            if (isPerfect(i)) {
                std::cout << i << " ";
                numPerfectInt++;
                if (numPerfectInt == numColumnInt)
                {
                    std::cout << "\n";
                }
            }
        }
        std::cout << "\n\n";
        for (int j = 2; j <= userMaxNumInt; j++) {
            
            analyzeDividors(j, placeHolder, amicPair);
            analyzeDividors(amicPair, placeHolder, amicPairTotal);
            
            if (numAmicLoops == 0) {
                std::cout << "\nThe list of amicable pairs are:\n";
                numAmicLoops++;
            }
            if (amicPairTotal == j) {
                std::cout << j << " " << amicPair << "\n";
            }

        }
    }
    else {
        std::cout << "The number entered is less than 2." << std::endl;
    }
    

}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    int numSqredInt, division;
    const int noRemainder = 0;
    numSqredInt = std::sqrt(num);
    
    if (num >= 2) {
        outCountDivs = 1;
        outSumDivs = 1;
    }
    if (num > 3) {
        for (int i = 2; i <= numSqredInt; i++) {
            if (num % i == noRemainder) {
                outCountDivs += 1;
                outSumDivs += i;
                division = num / i;
                if (num % division == noRemainder) {
                    outCountDivs += 1;
                    outSumDivs += division;
                }
            }
            
        }
    }
}

bool isPerfect(int num) {
    int numOfDivsInt = 0, sumOfDivsInt = 0;
    analyzeDividors(num, numOfDivsInt, sumOfDivsInt);
    if (sumOfDivsInt == num) {
        return true;
    }
    else {
        return false;
    }
}
