// Practice_Exam4_Decemeber_2021.cpp :

#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    int vecSize;
    int numVal = 0;
    std::vector<std::list<int>> hashTableVec;
    int hash(int userNum) {
        return userNum % vecSize;
    }
public:
    HashTable(int newSize = 10) : vecSize(newSize), hashTableVec(newSize) {}
    void insert(int userNum) {
        numVal += 1;
        int vecPos = hash(userNum);
        hashTableVec[vecPos].push_back(userNum);
    }
    void remove(int userNum) {
        numVal -= 1;
        int vecPos = hash(userNum);
        hashTableVec[vecPos].remove(userNum);
    }
    bool find(int userNum) {
        int vecPos = hash(userNum);
        //std::list<int>::iterator it;
        for (const int& num : hashTableVec[vecPos]) {
            if (num == userNum) {
                return true;
            }

        }
        return false;
    }
    int size() { return vecSize; }
    void resize(int newSize) {
        std::vector<std::list<int>> tempHashTable(newSize);
        for (const std::list<int>& orgVecPos : tempHashTable) {
            for (const int& num : orgVecPos) {
                int newVecPos = num % newSize;
                tempHashTable[newVecPos].push_back(num);
            }
        }
        hashTableVec = tempHashTable;
        vecSize = newSize;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}