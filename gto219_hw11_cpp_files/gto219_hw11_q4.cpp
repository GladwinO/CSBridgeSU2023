// gto219_hw11_q4.cpp:

#include <iostream>
int lowestCostJumps(int* arr, int arrSize);
void createJumpItArrayPtr(int*& arr, int& arrSize);

int main()
{
    int* userArr;
    int arrSize = 0;
    int leastJumpsCost;
    createJumpItArrayPtr(userArr, arrSize);
    leastJumpsCost = lowestCostJumps(userArr, arrSize);
    std::cout << leastJumpsCost;


    delete[] userArr;
}

int lowestCostJumps(int* arr, int arrSize) {
    int posLowCost1, posLowCost2;
    int curPos = arrSize - 1;
    
    if (arrSize <= 1) {
        return 0;
    }
    else {

        posLowCost1 = lowestCostJumps(arr, arrSize - 1);
        posLowCost1 = posLowCost1 + arr[curPos];

        posLowCost2 = lowestCostJumps(arr, arrSize - 2);
        posLowCost2 = posLowCost2 + arr[curPos];

        if (posLowCost1 <= posLowCost2) {
            return posLowCost1;
        }
        return posLowCost2;

    }
}

void createJumpItArrayPtr(int*& arr, int& arrSize) {
    const int startNum = 0;
    const int initPos = 0;
    int numPosInt;
    std::cout << "Please enter the number of positive integers you will enter. \n(The first column will automatically start with " <<
        "zero): "; 
    std::cin >> numPosInt;

    //the user enters n positive numbers, excluding zero, so the total arrSize must be incremented by one to include zero.
    arrSize = numPosInt + 1;
    arr = new int[arrSize];
    arr[initPos] = startNum;
    std::cout << "\nPlease enter your " << numPosInt << " positive integer(s).\n" <<
        "If there is more than 1 integer enter each separated by a space:\n";

    //i starts at 1 so the zero does not get overwritten
    for (int i = 1; i < arrSize; i++) {
        std::cin >> arr[i];
    }
}