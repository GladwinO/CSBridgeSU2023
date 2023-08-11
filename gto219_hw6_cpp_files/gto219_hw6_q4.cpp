// gto219_hw6_q4.cpp :

//need to look into the big-o notation aspect of this question
#include <iostream>
#include <cmath>

void printDivisors(int num);

int main()
{
    int userPosInt;

    std::cout << "Please provide a postive number: ";
    std::cin >> userPosInt;

    std::cout << "Section A:\n";
    printDivisors(userPosInt);

    return 0;
}

void printDivisors(int num) {
    int sqRootUserPosInt, divisorRemainder, halfWayPerfDivNum= 1, perfDivNum;
    sqRootUserPosInt = std::sqrt(num);
    
    
    for (int i = 1; i <= sqRootUserPosInt; i++) {
        divisorRemainder = num % i;
        if (divisorRemainder == 0) {
            halfWayPerfDivNum = i;
            std::cout << i << " ";
        }
    }
    for (int i = halfWayPerfDivNum; i >= 1; i--) {
        divisorRemainder = num % i;
        if (divisorRemainder == 0) {
            perfDivNum = num / i;
            std::cout << perfDivNum << " ";
        }
        

    }
}
