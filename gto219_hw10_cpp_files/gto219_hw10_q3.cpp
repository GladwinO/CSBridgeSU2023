// gto219_hw10_q3.cpp:

#include <iostream>
#include <vector>

//Code used for Section A
void resizeArrayPtr(int*& arr, int& resizeArrSize);
void createUserArrayPtr(int*& userArr, int& arrSize);
void searchUserNumInArrayPtr(int* userArr, int userArrSize);
void main1();

//Code used for Section B
void createUserVec(std::vector<int>& userVec);
void searchUserNumInVec(std::vector<int> userVec);
void main2();

int main()
{
    std::cout << "Section A:\n";
    std::cout << "Code that uses new dynamic array to store and search to find user number:" << std::endl;
    main1();
    std::cout << "\n";
    std::cout << "Section B:\n";
    std::cout << "Code that uses the vector data structure to store and search to find user number:" << std::endl;
    main2();
    
}

//////////////////////////////////// SECTION A CODE //////////////////////////////////////////////
void main1() {
    /*will have to create a function that uses a while loop that uses new dynamic array. The array 
    needs to be resized, so I call the resize function that has an average linear time complexity
    beacuse I double the size of the array everytime the resize is called. Then the search function 
    isolates the position of the searched num, stores it in a dynamic array, and then prints out 
    only the positions that have a value above 0, preventing any "empty" index position from 
    getting printed*/

    int* userArr = nullptr;
    int userArrSize = 1;
    createUserArrayPtr(userArr, userArrSize);
    searchUserNumInArrayPtr(userArr, userArrSize);
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
    int userNum = 0;
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

void searchUserNumInArrayPtr(int* userArr, int userArrSize) {
    int userNum, numTimesFound = 0, numCommas = 0;
    const int lowerBound = 0;
    const int  initialPos = 0;
    std::cout << "Please enter a number you want to search.\n";
    std::cin >> userNum;
    int numShowed = 0, numShowedArrSize = 1;
    int* numShowedArr = new int[numShowedArrSize];
    for (int i = 0; i < userArrSize; i++) {
        if (userNum == userArr[i]) {
            numTimesFound++;
            if (numShowed < numShowedArrSize) {
                numShowedArr[numShowed] = i + 1;
                // i is incremented by 1 to convert to a num base that starts with 1 instead of 0
                numShowed++;
            }
            else {
                resizeArrayPtr(numShowedArr, numShowedArrSize);
                numShowedArr[numShowed] = i + 1;
                // i is incremented by 1 to convert to a num base that starts with 1 instead of 0
                numShowed++;
            }
        } 
    }
   /* here I am using the fact that if there is no number added to numShowedArr the only
   possible number that will show will be a random negative number. So if numShowedArr has
   not had a number added to it then no postive numnber will be present in the first position*/
    if (numShowedArr[initialPos] > lowerBound) {
        std::cout << userNum << " shows in line(s) ";
        for (int j = 0; j < numShowedArrSize; j++) {
            if (numShowedArr[j] > lowerBound && numCommas < numTimesFound - 1) {
                std::cout << numShowedArr[j] << ", ";
                numCommas++;
            }
            else if (numShowedArr[j] > lowerBound) {
                std::cout << numShowedArr[j] << ".";
            }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << userNum << " does not show up at all within the sequence." << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////// SECTION B CODE /////////////////////////////////////////////

void main2() {
    std::vector<int> userVec;
    createUserVec(userVec);
    searchUserNumInVec(userVec);
    
}

void createUserVec(std::vector<int>& userVec) {
    std::cout << "Please enter a sequence of positive integers, each in a separate line.\n" <<
        "End your input by typing -1." << std::endl;
    int userNum = 0;
    const int stopCond = -1;
    while (userNum != stopCond) {
        std::cin >> userNum;
        userVec.push_back(userNum);
    }
}

void searchUserNumInVec(std::vector<int> userVec) {
    std::vector<int> linesExistVec;
    int userVecSize = userVec.size();
    int userSearchNum, linesExistVecSize, numCommas = 0;
    std::cout << "Please enter a number you want to search.\n";
    std::cin >> userSearchNum;
    for (int i = 0; i < userVecSize; i++) {
        if (userSearchNum == userVec[i]) {
            //need to increment i to fit num base starting with 1 instead of 0;
            linesExistVec.push_back(i + 1);
        }
    }

    linesExistVecSize = linesExistVec.size();
    
    if (linesExistVecSize > 0) {
        std::cout << userSearchNum << " shows in line(s) ";
        for (int j = 0; j < linesExistVecSize; j++) {
            if (numCommas < linesExistVecSize - 1) {
                std::cout << linesExistVec[j] << ", ";
            }
            else {
                std::cout << linesExistVec[j] << ".";
            }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << userSearchNum << " does not show up at all within the sequence." << std::endl;
    }
    
}
