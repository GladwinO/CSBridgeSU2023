// gto219_hw6_q1.cpp :

#include <iostream>

int fib(int n);

int main()
{
    int fibSeqElement, userPosInt;

    std::cout << "Please enter a positive number: ";
    std::cin >> userPosInt;

    fibSeqElement = fib(userPosInt);
    std::cout << fibSeqElement;
}

int fib(int n) {
    int fibSeqElement = 0, preFibSeqElement, tempVar = 1;
    for (int i = 0; i < n; i++) {
        if (i < 2) {
            preFibSeqElement = 1;
            fibSeqElement = 1;
        }
        else {
            fibSeqElement += tempVar;
            tempVar = preFibSeqElement;
            preFibSeqElement = fibSeqElement;
        }
    }
    return fibSeqElement;
}

