// gto219_hw9_q1.cpp :

#include <iostream>
#include <vector>
#include <string>

void makeStrLowerCase(std::string userString, std::vector<char>& orgVec);
std::vector<int> numOfLetterFinder(const std::vector<char>& charVec);
std::vector<char> createAlphaVec();
void printNumLetters(std::vector<int> alphaFound);
void printNumWords(std::string userString);

int main()
{
    std::string userStr;
    std::vector <char> lowVecStr;
    std::vector<int> alphaFound;

    std::cout << "Please enter a line of text:\n";
    std::getline(std::cin, userStr);

    

    makeStrLowerCase(userStr, lowVecStr);
    
    printNumWords(userStr);
    alphaFound = numOfLetterFinder(lowVecStr);
    printNumLetters(alphaFound);
    
    

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

std::vector<char> createAlphaVec() {
    //97-122 a-z ASCII
    const int frtAlpha = 97;
    const int lstAlpha = 122;
    std::vector<char> alphaVec;
    for (int i = frtAlpha; i <= lstAlpha; i++) {
       alphaVec.push_back((char)i);
     }
    return alphaVec;
}

void printNumLetters(std::vector<int> alphaFound) {
    std::vector <char> alphaVec;
    alphaVec = createAlphaVec();

    int alphaFoundSize = alphaFound.size();

    for (int i = 0; i < alphaFoundSize; i++) {
        if (alphaFound[i] > 0) {
            std::cout << alphaFound[i] << "\t" << alphaVec[i] << std::endl;
        }
    }
}

void printNumWords(std::string userString) {
    int userStrSize = userString.size();
    int start = 0;
    int numWords = 0;
    int numWhiteSpaces = 0, numPeriods = 0, numCommas = 0;
    for (int i = 0; i < userStrSize; i++) {
        if (start == 0) {
            if (userString[i] == ' ') {
                numWords++;
                start = 1;
                numWhiteSpaces++;
            }
            else if (userString[i] == ',') {
                numWords++;
                start = 1;
                numCommas++;
            }
            else if (userString[i] == '.') {
                numWords++;
                start = 1;
                numPeriods++;
            }

        }
        else {
            if (numWhiteSpaces == 1) {
                if (userString[i] == ' ') {
                    numWords++;
                    numWhiteSpaces++;
                }
                else if (userString[i] == ',') {
                    numWords++;
                    numCommas++;
                    if (userString[i + 1] == ' ') {
                        i++;
                    }
                }
                else if (userString[i] == '.') {
                    numWords++;
                    numPeriods++;
                    if (userString[i + 1] == ' ') {
                        i++;
                    }
                }
                else if ((i + 1) == userStrSize) {
                    numWords++;
                }
            }
        }
        if (numWhiteSpaces == 2) {
            numWhiteSpaces = 1;
        }

    }

    std::cout << numWords << "\t" << "words" << std::endl;
}
