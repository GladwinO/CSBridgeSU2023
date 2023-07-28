// gto219_hw4_q1.cpp 

#include <iostream>

int main()
{
    int userPosInt, counter = 0;
    std::cout << "Please enter a positive integer: ";
    std::cin >> userPosInt;


    std::cout << "section a" << std::endl;

    while (counter != userPosInt) {
        counter += 1;
        std::cout << 2 * counter << std::endl;
    }

    std::cout << "section b" << std::endl;

    for (int i = 1; i <= userPosInt; i++) {
        std::cout << 2 * i << std::endl;
    }
    return 0;
}

