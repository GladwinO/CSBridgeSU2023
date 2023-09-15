// gto219_hw11_q3.cpp:

#include <iostream>
int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);
void createArray(int arr[], int arrSize);

int main() {
    int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    std::cout << res1 << " " << res2 << std::endl; //should both be -9

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
    std::cout << res3 << " " << res4 << std::endl; //should both be 3
    return 0;
}

int minInArray1(int arr[], int arrSize) {
    int minNum;
    int curPosInArr = arrSize - 1;
    if (arrSize == 1) {
        minNum = arr[curPosInArr];
        return minNum;
    }
    else {
        minNum = minInArray1(arr, arrSize - 1);
        if (arr[curPosInArr] < minNum) {
            minNum = arr[curPosInArr];
            return minNum;
        }
        else {
            return minNum;
        }
    }
}

int minInArray2(int arr[], int low, int high) {
    int minNum;
    if (low == high) {
        minNum = arr[high];
        return minNum;
    }
    else {
        minNum = minInArray2(arr, low, high - 1);
        if (arr[high] < minNum) {
            minNum = arr[high];
            return minNum;
        }
        else {
            return minNum;
        }

    }
}




void createArray(int arr[], int arrSize) {
    std::cout << "Please enter " << arrSize << " integers separated by a space:\n";
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }
}