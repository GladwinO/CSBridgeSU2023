// Practice_Exam4_September_2020.cpp :

#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    int vecSize;
    std::vector<std::list<int>> hashTableVec;
    int hash(int userNum) { return userNum % vecSize; }
public:
    HashTable(int newVecSize = 100) : vecSize(newVecSize), hashTableVec(newVecSize){}
    void insert(int userNum) {
        int vecPos = hash(userNum);
        hashTableVec[vecPos].push_back(userNum);
    }
    bool search(int userNum) {
        int vecPos = hash(userNum);
        for (const int& num : hashTableVec[vecPos]) {
            if (num == userNum) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

