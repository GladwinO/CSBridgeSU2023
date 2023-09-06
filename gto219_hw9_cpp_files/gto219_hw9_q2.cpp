// gto219_hw9_q2.cpp:

#include <iostream>
#include <string>
#include <vector>
void makeStrLowerCase(std::string userString, std::vector<char>& orgVec);
std::vector<int> numOfLetterFinder(const std::vector<char>& charVec);
bool isAnagram(std::vector<int> intVec1, std::vector<int> intVec2);
bool isSameSize(std::vector<int> intVec1, std::vector<int> intVec2);
void printIsAnagram(bool isAnagram);

int main()
{
    std::string userStr1, userStr2;
    std::vector <char> lowVecStr1, lowVecStr2;
    std::vector<int> alphaFound1, alphaFound2;
    bool twoStringsAnagram = false;

    std::cout << "Please enter the first line of text:\n";
    std::getline(std::cin, userStr1);

    makeStrLowerCase(userStr1, lowVecStr1);
    alphaFound1 = numOfLetterFinder(lowVecStr1);

    //Requesting second word
    std::cout << "Please enter the second line of text:\n";
    std::getline(std::cin, userStr2);

    makeStrLowerCase(userStr2, lowVecStr2);
    alphaFound2 = numOfLetterFinder(lowVecStr2);

    twoStringsAnagram = isAnagram(alphaFound1, alphaFound2);
    printIsAnagram(twoStringsAnagram);


}


void makeStrLowerCase(std::string userString, std::vector<char>& orgVec) {
    int userStrSize = userString.size();
    for (int i = 0; i < userStrSize; i++) {
        orgVec.push_back((char)tolower(userString[i]));
        
    }
}

std::vector<int> numOfLetterFinder(const std::vector<char>& charVec) {

    const int numAlpha = 26;
    std::vector<int> alphaFound;

    for (int i = 0; i < numAlpha; i++) {
        alphaFound.push_back(0);
    }

    for (char j : charVec) {
        switch (j) {
        case 'a':
            alphaFound[0] = alphaFound[0] + 1;
            break;
        case 'b':
            alphaFound[1] = alphaFound[1] + 1;
            break;
        case 'c':
            alphaFound[2] = alphaFound[2] + 1;
            break;
        case 'd':
            alphaFound[3] = alphaFound[3] + 1;
            break;
        case 'e':
            alphaFound[4] = alphaFound[4] + 1;
            break;
        case 'f':
            alphaFound[5] = alphaFound[5] + 1;
            break;
        case 'g':
            alphaFound[6] = alphaFound[6] + 1;
            break;
        case 'h':
            alphaFound[7] = alphaFound[7] + 1;
            break;
        case 'i':
            alphaFound[8] = alphaFound[8] + 1;
            break;
        case 'j':
            alphaFound[9] = alphaFound[9] + 1;
            break;
        case 'k':
            alphaFound[10] = alphaFound[10] + 1;
            break;
        case 'l':
            alphaFound[11] = alphaFound[11] + 1;
            break;
        case 'm':
            alphaFound[12] = alphaFound[12] + 1;
            break;
        case 'n':
            alphaFound[13] = alphaFound[13] + 1;
            break;
        case 'o':
            alphaFound[14] = alphaFound[14] + 1;
            break;
        case 'p':
            alphaFound[15] = alphaFound[15] + 1;
            break;
        case 'q':
            alphaFound[16] = alphaFound[16] + 1;
            break;
        case 'r':
            alphaFound[17] = alphaFound[17] + 1;
            break;
        case 's':
            alphaFound[18] = alphaFound[18] + 1;
            break;
        case 't':
            alphaFound[19] = alphaFound[19] + 1;
            break;
        case 'u':
            alphaFound[20] = alphaFound[20] + 1;
            break;
        case 'v':
            alphaFound[21] = alphaFound[21] + 1;
            break;
        case 'w':
            alphaFound[22] = alphaFound[22] + 1;
            break;
        case 'x':
            alphaFound[23] = alphaFound[23] + 1;
            break;
        case 'y':
            alphaFound[24] = alphaFound[24] + 1;
            break;
        case 'z':
            alphaFound[25] = alphaFound[25] + 1;
            break;
        default:
            //do nothing
            break;
        }


    }

    return alphaFound;
}

bool isAnagram(std::vector<int> intVec1, std::vector<int> intVec2) {
    int sizeVec = intVec1.size();
    bool sameNumLet = false;
    if (isSameSize(intVec1, intVec2)) {
        for (int i = 0; i < sizeVec; i++) {
            if (intVec1[i] == intVec2[i]) {
                sameNumLet = true;
            }
            else {
                sameNumLet = false;
                break;
            }
        }
    }

    return sameNumLet;
}

bool isSameSize(std::vector<int> intVec1, std::vector<int> intVec2) {
    int vecSize1 = intVec1.size();
    int vecSize2 = intVec2.size();
    if (vecSize1 == vecSize2) {
        return 1;
    }
    else {
        return 0;
    }
}

void printIsAnagram(bool isAnagram) {
    if (isAnagram) {
        std::cout << "The two strings entered are anagrams." << std::endl;
    }
    else {
        std::cout << "The two strings entered are not anagrams." << std::endl;
    }
}