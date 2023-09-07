// gto219_hw9_q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


void oddsKeepEvensFlip(int arr[], int arrSize);
void copyArray(int arr[], int* arrPtr, int arrSize);
void printArr(int arr[], int arrSize);

int main()
{
    const int arrSize = 6;
    int userArr[arrSize];

    std::cout << "Please enter 6 integers separated by a space:\n";
    for (int i = 0; i < arrSize; i++) {
        std::cin >> userArr[i];
    }

    oddsKeepEvensFlip(userArr, arrSize);
    printArr(userArr, arrSize);

}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* tempArr = new int[arrSize];
    int tempArrLoc = 0;
    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) != 0) {
            tempArr[tempArrLoc] = arr[i];
            tempArrLoc++;
        }
    }
    for (int j = arrSize - 1; j >= 0; j--) {
        if ((arr[j] % 2) == 0) {
            tempArr[tempArrLoc] = arr[j];
            tempArrLoc++;
        }
    }

    copyArray(arr, tempArr, arrSize);

    delete[] tempArr;
}

void copyArray(int arr[], int* arrPtr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = arrPtr[i];
    }
}

void printArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
}
