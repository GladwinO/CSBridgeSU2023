// DataStrucAlgoCh7MergeSortQuestions.cpp : 

//Ch7.15 Sort 3, 1, 4, 1, 5, 9, 2, 6 using mergesort.
//Ch7.16 How would you implement mergesort without using recursion?

#include <iostream>
#include <vector>
//I will create a merge sort driver and then the actual mergeSort recurssive code
void mergeSort(std::vector<int>& vec);
void mergeSort(std::vector<int>& vec, const int& low, const int& high);
void merge(std::vector<int>& vec, const int& low, const int& mid, const int& high);

int main()
{
    std::cout << "Hello World!\n";
}

void mergeSort(std::vector<int>& vec) {
    if (vec.size() > 0) {
        mergeSort(vec, 0, vec.size() - 1);
    }
   
}

void mergeSort(std::vector<int>& vec, const int& low, const int& high) {
    if (low == high) {
        return;
    }
    else {
        int mid = (low + high) / 2;
        mergeSort(vec, low, mid);
        mergeSort(vec, mid + 1, high);
        //merge(vec, low, mid, high);
    }
}

void merge(std::vector<int>& vec, const int& low, const int& mid, const int& high) {

}
