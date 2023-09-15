// gto219_hw11_q1.cpp:

#include <iostream>

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main()
{
    int userNum;

    std::cout << "Please enter a positive integer: ";
    std::cin >> userNum;

    std::cout << "Section A:\n" << std::endl;
    printTriangle(userNum);

    std::cout << "Section B:\n" << std::endl;
    printOppositeTriangles(userNum);

    std::cout << "Section C:\n" << std::endl;
    printRuler(userNum);
}

void printTriangle(int n) {
    if (n == 1) {
        std::cout << '*' << std::endl;
    }
    else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
 }

void printOppositeTriangles(int n) {
    if (n == 0) {
        //do nothing, start FILO
    }
    else {
        //doing the for loop before calling the function again will print the numbers in First In First Out (FIFO)
        //and then the code after will print in order of First In Last Out (FILO)
        for (int i = 0; i < n; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;
        printOppositeTriangles(n - 1);
        for (int i = 0; i < n; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void printRuler(int n) {
    /*okay I can not think of how to do this so im just going to have to start with a simplier problem and 
    increase the complexity until it should work universally*/

    /*when calling the second recursive call for print ruler the max n changes so it is as if im just calling for a lower n
    in the case of the lowest call that is not 1, i.e. 2, the base case would be called, then the next line prints 2, then the 
    base case is called again which ends the code becuase the second printRuler's max input was 1. This idea extrapolates 
    to large n's, where the top half up to n is called and created, and then everything apart from n is basically copied 
    down below since the max n for the second printRuler call is n - 1*/
    if (n == 1) {
        std::cout << '-' << std::endl;
    }
    else {
        
        printRuler(n - 1); 
        for (int i = 0; i < n; i++) {
            std::cout << '-';
        }
        std::cout << std::endl;
        printRuler(n - 1);
        
        
    }
}