// gto219_hw9_q3.cpp:

#include <iostream>

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

int main()
{
    std::cout << "Hello World!\n";
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int* posArr = new int[outPosArrSize];
    int* tempArr = new int[outPosArrSize];
    int posArrLoc = 0;
    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) == 0) {
            for (int j = 0; j < outPosArrSize; j++) {
                tempArr[j] = posArr[j];
            }
            outPosArrSize++;
            delete[] posArr;
            posArr = nullptr;
            posArr = new int[outPosArrSize];
            posArr[posArrLoc] = arr[i];
            
        }
    }
}