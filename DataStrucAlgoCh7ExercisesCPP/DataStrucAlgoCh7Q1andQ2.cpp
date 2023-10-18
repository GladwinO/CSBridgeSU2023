// DataStrucAlgoCh7Q1.cpp :
//Question: Sort the sequence 3, 1, 4, 1, 5, 9, 2, 6, 5 using insertion sort.

#include <iostream>
#include <vector>

//I will create an insertion sort that just takes the vector and an insertion sort that takes the beginning and 
//end positions of the vector

void insertionSort(std::vector<int>& vec);
void insertionSort(std::vector<int>& vec, const int& beginning, const int& end);

int main()
{
    std::vector<int> userVec = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    insertionSort(userVec);
    for (int i = 0; i < userVec.size(); i++) {
        std::cout << userVec[i] << " ";
    }
    std::cout << "\n\n";
    userVec = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    insertionSort(userVec, 1, 7);
    for (int i = 0; i < userVec.size(); i++) {
        std::cout << userVec[i] << " ";
    }
}

void insertionSort(std::vector<int>& vec) {
    //this will sort the entire vector
    for (int p = 1; p < vec.size(); p++) {
        int temp = vec[p];
        int j;
        for (j = p; j > 0 && temp < vec[j - 1]; j--) {
            vec[j] = vec[j - 1];
        }
        vec[j] = temp;
    }
}

void insertionSort(std::vector<int>& vec, const int& beginning, const int& end) {
    //this version provides control over the desired sort range within a vector
    for (int p = beginning + 1; p <= end; p++) {
        int temp = vec[p];
        int j;
        for (j = p; j > beginning && temp < vec[j - 1]; j--) {
            vec[j] = vec[j - 1];
        }
        vec[j] = temp;
    }
}


/*ch7.2:
What is the running time of insertion sort if all elements are equal?
When all the elements are equal the the inner for loop never runs, so the function will run 
the desired range which is N. It will have big-o notation of O(N)*/