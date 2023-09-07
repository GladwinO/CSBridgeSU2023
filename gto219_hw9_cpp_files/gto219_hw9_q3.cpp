// gto219_hw9_q3.cpp:

#include <iostream>

int numOfPosInts(int* arr, int arrSize);
void printArr(int* arr, int arrSize);
int* createArr(int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);


int main()
{
    int arrSize, arrSizePos1, posNum2Size, posNum3Size, posNum4Size;
    std::cout << "Please provide the number of integers that will be entered: ";
    std::cin >> arrSize;
    int* userArr;
    int* userPosArr1 = nullptr, * userPosArr2 = nullptr, * userPosArr3 = nullptr, * userPosArr4 = nullptr;
    int* outPosArrSizePtr = &posNum2Size;
    int* outPosArrSizePtr2 = &posNum4Size;

    std::cout << "Please enter " << arrSize << " numbers separated by a space or enter:\n";
    userArr = createArr(arrSize);
    std::cout << std::endl;

    std::cout << "Section A:\n";
    userPosArr1 = getPosNums1(userArr, arrSize, arrSizePos1);
    std::cout << "The number of positve integers in the array is " << arrSizePos1 << std::endl;
    printArr(userPosArr1, arrSizePos1);


    std::cout << "\n\nSection B:\n";
    userPosArr2 = getPosNums2(userArr, arrSize, outPosArrSizePtr);
    std::cout << "The number of positve integers in the array is " << *outPosArrSizePtr << std::endl;
    printArr(userPosArr2, *outPosArrSizePtr);


    std::cout << "\n\nSection C:\n";
    getPosNums3(userArr, arrSize, userPosArr3, posNum3Size);
    std::cout << "The number of positve integers in the array is " << posNum3Size << std::endl;
    printArr(userPosArr3, posNum3Size);

    std::cout << "\n\nSection D:\n";
    getPosNums4(userArr, arrSize, &userPosArr4, outPosArrSizePtr2);
    std::cout << "The number of positve integers in the array is " << *outPosArrSizePtr2 << std::endl;
    printArr(userPosArr4, *outPosArrSizePtr2);



    delete[] userArr;
    delete[] userPosArr1;
    delete[] userPosArr2;
    delete[] userPosArr3;

    userArr = nullptr;
    userPosArr1 = nullptr;
}

int numOfPosInts(int* arr, int arrSize) {
    int numPosInts = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            numPosInts++;
        }
    }
    return numPosInts;
}

void printArr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
}

int* createArr(int arrSize) {
    int* createdArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        std::cin >> createdArray[i];
    }
    return createdArray;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {

    outPosArrSize = numOfPosInts(arr, arrSize);
    int* posArr = new int[outPosArrSize];
    int posArrLoc = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posArrLoc] = arr[i];
            posArrLoc++;
        }
    }

    return posArr;

}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {

    *outPosArrSizePtr = numOfPosInts(arr, arrSize);
    int* posArr = new int[*outPosArrSizePtr];
    int posArrLoc = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posArrLoc] = arr[i];
            posArrLoc++;
        }
    }

    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
   
    outPosArrSize = numOfPosInts(arr, arrSize);
    outPosArr = new int[outPosArrSize];
    int posArrLoc = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[posArrLoc] = arr[i];
            posArrLoc++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    
    *outPosArrSizePtr = numOfPosInts(arr, arrSize);
    *outPosArrPtr = new int[*outPosArrSizePtr];
    int posArrLoc = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[posArrLoc] = arr[i];
            posArrLoc++;
        }
    }
}
