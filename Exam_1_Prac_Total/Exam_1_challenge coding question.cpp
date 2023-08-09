// Exam_1_challenge coding question.cpp : 

#include <iostream>
using namespace std;
int main() {
    int input;
    char frame = '#';
    char planks = '$';
    char space = ' ';
    cout << "Enter positive integer: ";
    cin >> input;
    for (int i = 0; i < input; i++) { //rows
        for (int j = 0; j < input; j++) {
            // left or right or top or bottom
            if (j == 0 || j == input - 1 || i == 0 || i == input - 1) {
                cout << frame;
            }
            // left diagonal going right || right diagonal going left
            else if (i == j || i + j == input - 1) {
                cout << planks;
            }
            else {
                cout << space;
            }
        }
        cout << endl;
    }
}

/*int main()
{
    int userPosInt, firstNumSpaces = 0, secondNumSpaces;
    std::cout << "Please enter a positive even 1number: ";
    std::cin >> userPosInt;
    secondNumSpaces = userPosInt - 4;
    bool hitZero = false, firstRun = true;

    for (int i = 0; i < userPosInt; i++) {
        
        if (i == 0 || i == userPosInt - 1) {
            for (int j = 0; j < userPosInt; j++) {
                std::cout << '#';
            }
            std::cout << "\n";
        }
        else {
            std::cout << '#';
            for (int k = 0; k < firstNumSpaces; k++) {
                std::cout << ' ';
            }
            std::cout << '$';
            for (int l = 0; l < secondNumSpaces; l++) {
                std::cout << ' ';
            }
            std::cout << '$';
            for (int k = 0; k < firstNumSpaces; k++) {
                std::cout << ' ';
            }
            if (i == (userPosInt/2)) {
                firstRun = false;
            }
            if (hitZero == false)
            {
                firstNumSpaces++;
                secondNumSpaces-= 2;
                if (secondNumSpaces == 0) {
                    hitZero = true;

                }
                
            }
            else if(firstRun == false && hitZero == true) {
                firstNumSpaces--;
                secondNumSpaces += 2;
            }
            
            std::cout << '#';
            std::cout << "\n";
        }
        //std::cout << firstNumSpaces << " " << secondNumSpaces;
    }


}*/

