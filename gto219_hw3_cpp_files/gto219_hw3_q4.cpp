// gto219_hw3_q4.cpp 

#include <iostream>
#include <string>

int main()
{
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    int roundChoice, userRealNumOnesPlace;
    double userRealNum, userRealNumAddfifty;
    


    std::cout << "Please enter a real number:\n";
    std::cin >> userRealNum;
    std::cout << "Choose your rounding method:\n1.Floor round\n2.Ceiling round\n3.Round to the nearest whole number\n";
    std::cin >> roundChoice;

    userRealNumOnesPlace = int(userRealNum);
    userRealNumAddfifty = userRealNumOnesPlace + .50;

    switch (roundChoice) {
    case 1:
        if (userRealNum >= 0) {
            std::cout << userRealNumOnesPlace;
            
        }
        else {
            userRealNumOnesPlace -= 1;
            std::cout << userRealNumOnesPlace;
        }
        break;
    case 2:
        if (userRealNum >= 0) {
            std::cout << userRealNumOnesPlace + 1;
        }
        else {
            std::cout << userRealNumOnesPlace;
        }
        break;
    case 3:
        if (userRealNum >= 0) {
            if (userRealNum >= userRealNumAddfifty) {
                userRealNumOnesPlace += 1;
                std::cout << userRealNumOnesPlace;
            }
            else {
                std::cout << userRealNumOnesPlace;
            }
        }
        else {
            if (userRealNum <= userRealNumAddfifty) {
                userRealNumOnesPlace -= 1;
                std::cout << userRealNumOnesPlace;
            }
            else {
                std::cout << userRealNumOnesPlace;
            }
        }
        break;
    default:
        std::cout << userRealNum << " does not work. Please try again and choose a real number.";
        break;
    }

    return 0;

    

   

    

    
    
   


}


