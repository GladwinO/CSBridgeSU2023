// gto219_hw16_1.cpp:

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

void openInputFile(std::ifstream& inputFile);
bool symbBalanceCheck(std::ifstream& inputFile);



int main()
{
    std::ifstream inputFile;
    bool isBalanced;
    openInputFile(inputFile);
    isBalanced = symbBalanceCheck(inputFile);
    if (isBalanced) {
        std::cout << "The file's symbols are balanced" << std::endl;
    }
    else {
        std::cout << "The file's symbols are imbalanced" << std::endl;
    }
}

void openInputFile(std::ifstream& inputFile) {
    std::string filename;
    std::cout << "Please enter a filename: ";
    std::cin >> filename;
    inputFile.open(filename);
    while (!inputFile) {
        std::cout << "Incorrect filename entered. Please enter a new filename: ";
        std::cin >> filename;
        inputFile.clear();
        inputFile.open(filename);
    }
}

bool symbBalanceCheck(std::ifstream& inputFile) {
    //current limitations: the code assumes that there is nothing before the begin and nothing following the end
    //if there is the code will not work, ex. ;begin or end; or end.
    std::string temp1;
    std::string posBeginStr;
    std::string posEndStr;
    bool balanced = true;
    inputFile >> temp1;
    posBeginStr = temp1.substr(0, 5);
    temp1 = temp1.substr(5);

    if (posBeginStr == "begin") {
        std::stack<char> symbStack;
        while (temp1 != "end") {
            for (char c : temp1) {
                if (c == '{' || c == '(' || c == '[') {
                    symbStack.push(c);
                }
                else if ((c == '}' || c == ')' || c == ']') && symbStack.empty()) {
                    balanced = false;
                    break; //no need to continue checking symbols once imbalance is found
                }
                else if (c == '}') {
                    char topStack = symbStack.top();
                    if (topStack == '{') {
                        balanced = true;//not necessary but used as a sanity check
                        symbStack.pop();
                    }
                    else {
                        balanced = false;
                        break;//no need to continue checking symbols once imbalance is found
                    }
                }
                else if (c == ')') {
                    char topStack = symbStack.top();
                    if (topStack == '(') {
                        balanced = true;//not necessary but used as a sanity check
                        symbStack.pop();
                    }
                    else {
                        balanced = false;
                        break;//no need to continue checking symbols once imbalance is found
                    }
                }
                else if (c == ']') {
                    char topStack = symbStack.top();
                    if (topStack == '[') {
                        balanced = true;//not necessary but used as a sanity check
                        symbStack.pop();
                    }
                    else {
                        balanced = false;
                        break;//no need to continue checking symbols once imbalance is found
                    }
                }
                
            }
            if (!balanced) {//used to break out of while loop
                break;//no need to continue checking symbols once imbalance is found
            }
            if (temp1.size() > 3) {
                posEndStr = temp1.substr(temp1.size() - 3, 3);
                if (posEndStr == "end") {
                    break;
                }
            }
            
            inputFile >> temp1;//if balanced is still true continue to next string
        }
        if (!symbStack.empty()) {
            balanced = false;
        }
        return balanced;
    }
    balanced = false;//set to false if temp1 != begin
    return balanced; //if the first string does not equal begin then no code will run 
    //and balanced is set to false
}