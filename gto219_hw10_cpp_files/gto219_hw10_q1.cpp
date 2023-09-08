// gto219_hw10_q1.cpp:

#include <iostream>
#include <string>

//std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
//int numSpaceFinder(std::string sentence);
void spaceLocator(std::string sentence, int*& spaceLocArr, int& numSpaces);

int main()
{
    std::string userStr;
    int* spaceLocArr = nullptr;
    int numSpaces;
    std::cout << "Please enter a sentence without punctuation:\n";
    std::getline(std::cin, userStr);
    spaceLocator(userStr, spaceLocArr, numSpaces);
    /*std::cout << numSpaces << std::endl;

    for (int i = 0; i < numSpaces; i++) {
        std::cout << spaceLocArr[i] << " ";
    }*/
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize) {
    size_t spaceLoc = 0;
    std::string subString = " ";
    int startSearchPos = 0;
    int posNumWords = 0;
    
    std::string* wordArray = new std::string[posNumWords];

    /*while (spaceLoc != std::string::npos) {
        spaceLoc = sentence.find(subString, spaceLoc);
        spaceLoc++;8
    }*/
 
}



void spaceLocator(std::string sentence, int*& spaceLocator, int& numSpaces) {
    int sentSize = sentence.size();
    int spacLocArrInd = 0;
    
    numSpaces = 0;
    for (int i = 0; i < sentSize; i++) {
        if (sentence[i] == ' ') {
            numSpaces++;
        }
    }
    spaceLocator = new int[numSpaces];
   
    for (int j = 0; j < sentSize; j++) {
        if (sentence[j] == ' ') {
            spaceLocator[spacLocArrInd] = j;
            spacLocArrInd++;
        }
    }
}

/*int numSpaceFinder(std::string sentence) {
    int stringSize = sentence.size();
    int numSpaces = 0;
    for (int i = 0; i < stringSize; i++) {
        if (sentence[i] == ' ') {
            numSpaces++;
        }
    }
    return numSpaces;
}*/