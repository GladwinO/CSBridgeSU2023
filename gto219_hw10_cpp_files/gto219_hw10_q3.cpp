// gto219_hw10_q3.cpp:

#include <iostream>
#include <vector>

void resizeArrayPtr(int*& arr, int& resizeArrSize);
void createUserArrayPtr(int*& userArr, int& arrSize);

 
int main()
{
    std::cout << "Hello World!\n";
}

void main1() {
    /*will have to create a function that uses a while loop that uses new dynamic array, but
    I will also have to update the size of the array over and over which will lead to me needing 
    to make a copy of the array. The way I am thinking about it now, it will lead to a quadratic 
    time complexity becuase creating a new array will either be quadratic or linear, but that 
    generation of a new array will be in the while loop, but somehow when using the vector push back 
    i can get a constant time complexity from the addition of something to the vector due to some interesting 
    concepts around the process.*/
    /*apparently by creating a copy/resizing that doubles the capacity of the array and does not need 
    to call the copy/resizing function often averages out to a linear time complexity, but I wonder if 
    that is a concept I will be allowed to use in trying to keep linear complexity here. I mean I probably can 
    since I will be using vectors in the main2*/

    //function that calls to the user to add numbers to an array (can return array pointer or do reference/double)

        //function withing the function that resizes the array when the max size is reached
}

void resizeArrayPtr(int*& arr, int& resizeArrSize) {
    const int arrSizeMultBy = 2;
    int orgArrSize = resizeArrSize;
    resizeArrSize = resizeArrSize * arrSizeMultBy;
    int* temp = new int[resizeArrSize];
    for (int i = 0; i < orgArrSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

void createUserArrayPtr(int*& userArr, int& arrSize) {
    //function that calls to the user to add numbers to an array (can return array pointer or do reference/double)
    int userNum;
    int numInArrInd = 0;
    arrSize = 1;
    const int stopCond = -1;
    int startArrSize = 1;
    userArr = new int[arrSize];
    
    std::cout << "Please enter a sequence of positve integers, each in a separate line.\nEnd your inputby typing -1.\n";
    while (userNum != stopCond) {
        std::cin >> userNum;
        if (numInArrInd < arrSize) {
            userArr[numInArrInd] = userNum;
            numInArrInd++;
        }
        else {
            //call the resize fucntion then add the usernum to the new array
            resizeArrayPtr(userArr, arrSize);
            userArr[numInArrInd] = userNum;
            numInArrInd++;
        }
        
    }
}