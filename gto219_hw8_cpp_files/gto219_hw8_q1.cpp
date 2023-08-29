// gto219_hw8_q1.cpp:

#include <iostream>

int minInArray(int arr[], int arrSize);
int minInArrayLoc(int minNum, int arr[], int arrSize, int locArr[]);

int main()
{
    const int maxSize = 20;
    int userArr[maxSize];
    int minNum;
    int filledSpaceLocArrSize;
    int minLocArr[maxSize];
    
    std::cout << "Please enter 20 integers separated by a space:\n";
    for (int i = 0; i < maxSize; i++) {
        std::cin >> userArr[i];
    }
    minNum = minInArray(userArr, maxSize);
    std::cout << minNum << "\n";
    filledSpaceLocArrSize = minInArrayLoc(minNum, userArr, maxSize, minLocArr);

    std::cout << "The minimum value is " << minNum << " and it is located in" <<
        " the following indices: ";
    for (int i = 0; i < filledSpaceLocArrSize; i++) {
        std::cout << minLocArr[i] << " ";
    }
}

int minInArray(int arr[], int arrSize) {
    int minNum;
    minNum = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= minNum) {
            minNum = arr[i];
        }
    }
    return minNum;
}

int minInArrayLoc(int minNum, int arr[], int arrSize, int locArr[]) {
    int locArrPos = 0;
    int filledArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == minNum) {
            locArr[locArrPos] = i;
            locArrPos++;
            filledArrSize++;
        }
    }

    return filledArrSize;
}