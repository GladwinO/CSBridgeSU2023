// Exam 1 Practice Coding part 1.cpp :

#include <iostream>
#include <string>

int main()
{
    int userPosInt, initnumSpaces, changingNumSpaces, totalLines, letterLoc = 0, internalSpaces = 1;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    bool reachedLastLet = false;

    std::cout << "Please provide a positive number: ";
    std::cin >> userPosInt;
    totalLines = 2 * userPosInt;

    initnumSpaces = userPosInt - 1;
    changingNumSpaces = initnumSpaces;

    for (int i = 0; i < totalLines - 1; i++) {
        
        for (int j = 0; j < changingNumSpaces; j++) {
            std::cout << ' ';
        }
        std::cout << alphabet[letterLoc];
        if (letterLoc > 0 && reachedLastLet == false) {
            for (int k = 0; k < internalSpaces; k++) {
                std::cout << ' ';
                
            }
            std::cout << alphabet[letterLoc];
            internalSpaces+=2;
            
        }
        
        if (letterLoc < userPosInt && reachedLastLet == false) {
            letterLoc++;
            changingNumSpaces--;
            
        }
        
        if (letterLoc > 0 && reachedLastLet == true) {
            for (int k = 0; k < internalSpaces; k++) {
                std::cout << ' ';

            }
            std::cout << alphabet[letterLoc];
            internalSpaces -= 2;
            letterLoc--;
            changingNumSpaces++;

        }
        if (letterLoc == userPosInt) {
            reachedLastLet = true;
            letterLoc-= 2;
            changingNumSpaces+= 2;
            internalSpaces -= 4;
        }
        std::cout << "\n";
    }
}

