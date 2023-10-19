// DataStrucAlgoCh7MergeSortQuestions.cpp : 

//Ch7.15 Sort 3, 1, 4, 1, 5, 9, 2, 6 using mergesort.
//Ch7.16 How would you implement mergesort without using recursion?

#include <iostream>
#include <vector>

//I will create a merge sort driver and then the actual mergeSort recurssive code
void mergeSort(std::vector<int>& vec);
void mergeSort(std::vector<int>& vec, int low, int high, std::vector<int>& tempVec);
void merge(std::vector<int>& vec, int low, int mid, int high, std::vector<int>& tempVec);

int main()
{
    std::vector<int> userVec = { 3,1, 4, 1, 5, 9, 2, 6 };
    mergeSort(userVec);
    for (int i = 0; i < userVec.size(); i++) {
        std::cout << userVec[i] << " ";
    }
    
}

void mergeSort(std::vector<int>& vec) {
    // the temporary vector is created on the stack instead of the heap for better 
    //performance for small to mid-sized arrays
    if (vec.size() > 0) {
        std::vector<int> tempVec(vec.size());
        mergeSort(vec, 0, vec.size() - 1, tempVec);
    }
   
}

void mergeSort(std::vector<int>& vec, int low, int high, std::vector<int>& tempVec) {
    if (low == high) {
        return;
    }
    else {
        int mid = (low + high) / 2;
        mergeSort(vec, low, mid, tempVec);
        mergeSort(vec, mid + 1, high, tempVec);
        merge(vec, low, mid + 1 , high, tempVec);
    }
}

void merge(std::vector<int>& vec, int low, int mid, int high, std::vector<int>& tempVec) {
    int leftEnd = mid - 1;
    int tempInd = low;
    int originalStart = low;

    //compare each index in each list and see if the value in one subarray
    //is less then the other subarray and whichever subarray has the lower value
    //will be added to tempVec
    while (low <= leftEnd && mid <= high) {
        if (vec[low] < vec[mid]) {
            tempVec[tempInd++] = vec[low++];
        }
        else {
            tempVec[tempInd++] = vec[mid++];
        }
    }

    // this part will attach the rest of an ordered subarray
    //only one will be true at any time because the code above only stops running
    //when one of the below conditions are false
    while (low <= leftEnd) {
        tempVec[tempInd++] = vec[low++];
    }
    while (mid <= high) {
        tempVec[tempInd++] = vec[mid++];
    }
    //this code must act on the current recursive range
    //that is why it starts at the orginal position of the current range and
    //ends at the end position of the current range
    for (int i = originalStart; i < high; i++) {
        vec[i] = tempVec[i];
    }

}
