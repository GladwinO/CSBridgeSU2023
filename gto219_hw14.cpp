// gto219_hw14.cpp : Gladwin Osakwe

#include <iostream>
#include <vector>
#include <string>

std::vector<int> findMinMax(const std::vector<int>& searchVec);
std::vector<int> findMinMax(const std::vector<int>& searchVec, int indexLow, int indexHigh);
void compareMinMax(std::vector<int>& vec1, const std::vector<int>& vec2);
void createUserVec(std::vector<int>& userVec);
void entireProg();

int main()
{
    entireProg();
    return 0;
}

std::vector<int> findMinMax(const std::vector<int>& searchVec) {
    //I will nee a vector to store the min and max
    if (searchVec.size() == 0) {
        std::cout << "The vector is empty." << std::endl;
        return std::vector<int>();
    }
    const int numOptions = 2;
    std::vector<int> minMax(numOptions);
    minMax = findMinMax(searchVec, 0, searchVec.size() - 1);
    return minMax;
}

std::vector<int> findMinMax(const std::vector<int>& searchVec, int indexLow, int indexHigh) {
    const int numOptions = 2;
    const int firPos = 0;
    const int secPos = 1;
    std::vector<int> vec1(numOptions);
    std::vector<int> vec2(numOptions);
    if (indexLow == indexHigh) {
        std::vector<int> vecOneVal(numOptions);
        vecOneVal[firPos] = searchVec[indexLow];
        vecOneVal[secPos] = searchVec[indexHigh];
        return vecOneVal;
    }
    else {
        int indexMid = (indexLow + indexHigh) / 2;
        vec1 = findMinMax(searchVec, indexLow, indexMid);
        vec2 = findMinMax(searchVec, indexMid + 1, indexHigh);
        compareMinMax(vec1, vec2);
        return vec1;
    }

}

void compareMinMax(std::vector<int>& vec1, const std::vector<int>& vec2) {
    const int firPos = 0;
    const int secPos = 1;
    if (vec2[firPos] < vec1[firPos]) {
        vec1[firPos] = vec2[firPos];
    }
    else if (vec2[firPos] > vec1[secPos]) {
        vec1[secPos] = vec2[firPos];
    }
    if (vec2[secPos] > vec1[secPos]) {
        vec1[secPos] = vec2[secPos];
    }
}

void createUserVec(std::vector<int>& userVec) {
    std::string userNumStr;
    std::cout << "Please enter a list of numbers. After each number press enter.\nWhen you are done entering"
        << " numbers type x and press enter." << std::endl;

    while (std::getline(std::cin, userNumStr) && userNumStr != "x" && userNumStr != "X") {
        int userNumInt = std::stoi(userNumStr);
        userVec.push_back(userNumInt);
    }
}
void entireProg() {
    const int numOptions = 2;
    std::vector<int> userVec;
    std::vector<int> minMax(numOptions);
    
    createUserVec(userVec);
    minMax = findMinMax(userVec);

    if (minMax.size() != 0) {
        std::cout << "\nMinimum number: " << minMax[0] << std::endl;
        std::cout << "Maximum number: " << minMax[1] << std::endl;
    }
}