// gto219_hw10_q2.cpp:

#include <iostream>
#include <vector>

std::vector<int> sortArray(int arr[], int arrSize, int& missingNumArrSize);
int* findMissing(int arr[], int n, int& resArrSize);

int main()
{
    /*current plan: sort the array, remove repeating numbers, then compare i to arr[i] and see if
    they match because now each number in i should match up to the ordered position in arr[]*/
  

    const int arrSize = 6;
    int arr[arrSize];
    int missingNumArrSize = 0;
    int* missingNumArr;
    std::cout << "Please enter 6 numbers in the range of 0 - 6, each number separated by a space:\n";
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }
    missingNumArr = findMissing(arr, arrSize, missingNumArrSize);
    for (int i = 0; i < missingNumArrSize; i++) {
        std::cout << missingNumArr[i] << " ";
    }


    
}

std::vector<int> sortArray(int arr[], int arrSize, int& missingNumArrSize) {
    int* numExistArr = new int[arrSize + 1];
    int numInArray = 0;
    const int numExist = 1;
    int orgArrPos = 0;
    std::vector<int> orderedArr;
    for (int i = 0; i < arrSize; i++) {
        numInArray = arr[i];
        numExistArr[numInArray] = numExist;
    }

   
    for (int j = 0; j < arrSize + 1; j++) {
        if (numExistArr[j] == numExist) {
            orderedArr.push_back(j);
        }
        else {
            missingNumArrSize++;
        }
    }
    delete[] numExistArr;
    return orderedArr;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    std::vector<int> orderedExistArr;
    int orderedArrSize, missingNumInd = 0;
    int orderedArrInd = 0;
    orderedExistArr = sortArray(arr, n, resArrSize);
    orderedArrSize = orderedExistArr.size();
    int* missingNumArr = new int[resArrSize];

    for (int i = 0; i < n + 1; i++) {
        if (orderedExistArr[orderedArrInd] == i) {
            if (orderedArrInd < orderedArrSize - 1) {
                orderedArrInd++;
            }
            
        }
        else {
            missingNumArr[missingNumInd] = i;
            missingNumInd++;
        }
    }

    return missingNumArr;
}
