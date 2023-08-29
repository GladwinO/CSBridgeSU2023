// gto219_hw8_q3.cpp: 

#include <iostream>

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);


int main()
{
    const int arrConstSize = 5;
    int arrSize = arrConstSize;
    int userArr[arrConstSize];

    /*std::cout << "Please enter 5 numbers separated by a space: ";
    for (int i = 0; i < arrConstSize; i++) {
        std::cin >> userArr[i];
    }

    

    std::cout << "Section A :\n";
    reverseArray(userArr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        std::cout << userArr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Please enter 5 numbers separated by a space: ";
    for (int i = 0; i < arrConstSize; i++) {
        std::cin >> userArr[i];
    }

    std::cout << "Section B :\n";
    removeOdd(userArr, arrSize);

    std::cout << "The new array size is: ";
    std::cout << arrSize << std::endl;

    for (int i = 0; i < arrSize; i++) {
        std::cout << userArr[i] << " ";
    }
    std::cout << "\n";
    arrSize = arrConstSize;
    */
    std::cout << "Please enter 5 numbers separated by a space: ";
    for (int i = 0; i < arrConstSize; i++) {
        std::cin >> userArr[i];
    }

    std::cout << "Section C :\n";
    splitParity(userArr, arrSize);
    
    for (int i = 0; i < arrSize; i++) {
        std::cout << userArr[i] << " ";
    }
    
    
}

void reverseArray(int arr[], int arrSize) {
    const int divBy = 2;
    int temp;
    int endOfArrLoc = arrSize - 1;
    for (int i = 0; i < (arrSize / divBy); i++) {
        temp = arr[i];
        arr[i] = arr[endOfArrLoc];
        arr[endOfArrLoc] = temp;
        endOfArrLoc--;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int numEvenInt = 0;
    const int even = 2;
    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) == 0) {
            arr[numEvenInt] = arr[i];
            numEvenInt++;
        }
    }
    arrSize = numEvenInt;
}

void splitParity(int arr[], int arrSize) {
    int evenNum;
    int endOfArr = arrSize - 1;
    const int even = 2;
    int numEven = 0;
    int numOdd = 0;
    for (int j = 0; j < arrSize; j++) {
        if ((arr[j] % 2) == 0) {
            numEven++;
        }
        else {
            numOdd++;
        }
    }

    /*So i want to count how many even and odd numbers exist. if there are no even number
    then the code just will not run and will output there are only even/odd numbers. If there 
    is an odd number then I will set up the code to continue running until there are no more odd numbers
    and I need to double check what happens when the odd number is at the end of the array*/

    for (int i = 0; i < (arrSize/even) + 1; i++) {
        if ((arr[i] % even) == 0) {
            evenNum = arr[i];
            if ((arr[endOfArr] % even) != 0) {
                arr[i] = arr[endOfArr];
                arr[endOfArr] = evenNum;
                endOfArr--;
            }
            else {
                if (i != (arrSize / even)) {
                    i = i - 1;
                    endOfArr--;
                }
                
            }
        }
    }
}


    




