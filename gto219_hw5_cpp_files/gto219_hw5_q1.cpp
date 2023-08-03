// gto219_hw5_q1.cpp :

#include <iostream>

int main()
{
    int userPosInt, userPosSqInt;
    std::cout << "Please enter a positive integer:\n";
    std::cin >> userPosInt;
    userPosSqInt = userPosInt * userPosInt;

    for (int i = 1; i <= userPosSqInt; i++) {
        std::cout << i << "\t";
        if (i % userPosInt == 0) {
            std::cout << std::endl;
        }
    }
}