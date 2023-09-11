// gto219_hw10_q1.cpp:

#include <iostream>
#include <string>
#include <vector>

std::string* createWordsArray(std::string sentence, int& outWordsArrSize);


int main()
{
    std::string userStr;
    std::string* userStrArr;
    int wordArrSize;
   
    std::cout << "Please enter a sentence without punctuation:\n";
    std::getline(std::cin, userStr);
 

    userStrArr = createWordsArray(userStr, wordArrSize);
    std::cout << "[ ";
    for (int i = 0; i < wordArrSize; i++) {
        std::cout << userStrArr[i] << ", ";
    }
    std::cout << "]";


    delete[] userStrArr;

    return 0;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize) {
    size_t spaceLoc = 0;
    std::string subString = " ";
    int numSpaces = 0, wordStartPos = 0;
    int strStartPos = 0, curWordLen = 0;
    std::vector<int> spaceLocVec;
    
    /*this call to the find method outside the while loop sets the code up so spaceLocVec does not
    take in the integer representation of std::string:npos if a space is not found */
    spaceLoc = sentence.find(subString, spaceLoc);
    while (spaceLoc != std::string::npos) {
        spaceLocVec.push_back(spaceLoc);
        spaceLoc++;
        spaceLoc = sentence.find(subString, spaceLoc);
    }

    numSpaces = spaceLocVec.size();
    //this code assumes that every word is spaced correctly from the next
    outWordsArrSize = numSpaces + 1;
    std::string* wordArray = new std::string[outWordsArrSize];
    for (int i = 0; i < outWordsArrSize; i++) {
        if (i == 0) {
            wordArray[i] = sentence.substr(strStartPos, spaceLocVec[i]);
        }
        else if (i < numSpaces) {
            wordStartPos = spaceLocVec[i - 1] + 1;
            curWordLen = spaceLocVec[i] - wordStartPos;
            wordArray[i] = sentence.substr(wordStartPos, curWordLen);
        }
        else {
            wordStartPos = spaceLocVec[i - 1] + 1;
            wordArray[i] = sentence.substr(wordStartPos);
        }
    }

    return wordArray;
}
