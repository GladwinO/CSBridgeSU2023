// gto219_hw3_q3.cpp

#include <iostream>
#include <cmath>

int main()
{

    /*	(b2 -4ac) if positive 2 solutions, if 0 1 solution, if negative 0 solutions  */

    double userAVal, userBVal, userCVal, sol1, sol2, discriminant, sqrtdiscr;

    std::cout << "Please enter value of a: ";
    std::cin >> userAVal;
    std::cout << "Please enter value of b: ";
    std::cin >> userBVal;
    std::cout << "Please enter value of c: ";
    std::cin >> userCVal;

    discriminant = std::pow(userBVal, 2) - (4 * userAVal * userCVal);
    sqrtdiscr = std::sqrt(discriminant);
    std::cout.precision(1);
    if (discriminant > 0 && userAVal != 0) {
        sol1 = (-userBVal + sqrtdiscr) / (2 * userAVal);
        sol2 = (-userBVal - sqrtdiscr) / (2 * userAVal);
        std::cout << "This equation has a two real solutions: x=" << std::fixed << sol1 << " and x=" << sol2 << std::endl;
    }
    else if (discriminant == 0 && userAVal != 0) {
        sol1 = -userBVal/ (2 * userAVal);
        std::cout << "This equation has a single real solution x=" << std::fixed << sol1 << std::endl;
    }
    else if (discriminant < 0 && userAVal != 0) {
        std::cout << "There are no real solutions" << std::endl;
    }
    else if (userBVal == 0 && userAVal == 0 && userCVal != 0) {
        std::cout << "There is no solution" << std::endl;
    }
    else {
        std::cout << "There are an infinite number solutions" << std::endl;
    }

    return 0;
}
