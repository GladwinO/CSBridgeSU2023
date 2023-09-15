// gto219_hw11_q2.cpp:

#include <iostream>
#include <cmath>

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void createArray(int arr[], int arrSize);

int main()
{
    int sumSquares;;
    bool numSorted;
    const int arrSize = 6;
    int array[arrSize];
    
    std::cout << "Section A:\n" << std::endl;
    createArray(array, arrSize);
    sumSquares = sumOfSquares(array, arrSize);
    std::cout << sumSquares << std::endl;

    std::cout << "\nSection B:\n" << std::endl;
    createArray(array, arrSize);
    numSorted = isSorted(array, arrSize);
    if (numSorted == true) {
        std::cout << "The array is sorted in an ascending order." << std::endl;
    }
    else {
        std::cout << "The array is not sorted in an ascending order." << std::endl;
    }


}

int sumOfSquares(int arr[], int arrSize) {
    int sumSquares = 0;
    int curPosInArr = arrSize - 1;
    if (arrSize == 1) {
        sumSquares = std::pow(arr[curPosInArr], 2);
        return sumSquares;
    }
    else {
        sumSquares = sumOfSquares(arr, arrSize - 1);
        sumSquares = sumSquares + std::pow(arr[curPosInArr], 2);
        return sumSquares;
    }
}

bool isSorted(int arr[], int arrSize) {
    bool arrSort;
    int curPosInArr = arrSize - 1;
    if (arrSize == 1) {
        return true;
    }
    else {
        arrSort = isSorted(arr, arrSize - 1);
        if (arrSort == true && arr[curPosInArr] > arr[curPosInArr - 1]) {
            return true;
        }
        else {
            return false;
        }
    }
}

void createArray(int arr[], int arrSize) {
    std::cout << "Please enter " << arrSize << " integers separated by a space:\n";
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }
}