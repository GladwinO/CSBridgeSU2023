// DataStrucAlgoCh7QuickSortQuestions.cpp : 

#include <iostream>
#include <vector>

/*Sort 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 using quicksort with median - of - three partitioning
and a cutoff of 3.*/

//the quicksort algorithm uses insertion/bubble sort for arrays of a implementer 
//determined length usually length = 10;

void insertionSort(std::vector<int>& vec, int start, int end);
void quickSort(std::vector<int>& vec, int start, int end);
void quickSort(std::vector<int>& vec);


int main()
{
    std::vector<int> userVec = { 4,23,354,32,2,4,6 };
    insertionSort(userVec, 0, userVec.size() - 1);
    for (int i = 0; i < userVec.size(); i++) {
        std::cout << userVec[i] << " ";
    }
    std::cout << "\n";

    std::vector<int> userVec2 = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    quickSort(userVec2);
    for (int i = 0; i < userVec2.size(); i++) {
        std::cout << userVec2[i] << " ";
    }

}

void insertionSort(std::vector<int>& vec, int start, int end) {
    int j;
    for (int p = 1; p <= end; p++) {
        int temp = vec[p];
        for (j = p; j > start && temp < vec[j - 1]; j--) {
            vec[j] = vec[j - 1];
        }
        vec[j] = temp;
    }
}

void quickSort(std::vector<int>& vec, int start, int end) {
    if (end - start + 1 <= 3) {
        insertionSort(vec, start, end);
    }
    else {
        
        int pivotLoc = (end + start) / 2;
        int pivotVal = vec[pivotLoc];
        
        if (pivotVal < vec[start]) {
            vec[pivotLoc] = vec[start];
            vec[start] = pivotVal;
        }
        if (pivotVal > vec[end]) {
            vec[pivotLoc] = vec[end];
            vec[end] = pivotVal;
        }
        if (vec[pivotLoc] > vec[end]) {
            int temp = vec[pivotLoc];
            vec[pivotLoc] = vec[end];
            vec[end] = temp;
        }
        
        int temp2 = vec[pivotLoc];
        vec[pivotLoc] = vec[end - 1];
        vec[end - 1] = temp2;

        

        int i = start;
        int j = end - 1;
        for (;;) {
            while (vec[++i] < temp2) {}
            while (vec[--j] > temp2) {}
            if (i < j) {
                int temp3 = vec[i];
                vec[i] = vec[j];
                vec[j] = temp3;
            }
            else {
                break;
            }
            
            vec[end - 1] = vec[i];
            vec[i] = temp2;
        }
        

        quickSort(vec, start, i - 1);
        quickSort(vec, i + 1, end);

    }
}

void quickSort(std::vector<int>& vec) {
    quickSort(vec, 0, vec.size() - 1);
}
