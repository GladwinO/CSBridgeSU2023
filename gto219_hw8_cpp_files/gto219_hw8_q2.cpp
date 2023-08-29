// gto219_hw8_q2.cpp:

#include <iostream>
#include <string>
bool isPalindrome(std::string str);

int main()
{
    bool isPalindromeAns = false;
    std::string userStr;
    
    std::cout << "Please enter a word: ";
    std::getline(std::cin, userStr);
    isPalindromeAns = isPalindrome(userStr);
    if (isPalindromeAns == true) {
        std::cout << userStr << " is a palindrome";
    }
    else {
        std::cout << userStr << " is not a palindrome";
    }
}

bool isPalindrome(std::string str) {
    int strSizeInt = str.size();
    int endOfStrInt = strSizeInt - 1;
    bool isPalindrome = false;
    const int divBy = 2;
    for (int i = 0; i < (strSizeInt/divBy); i++) {
        if (str[i] == str[endOfStrInt]) {
            isPalindrome = true;
            endOfStrInt--;
        }
        else {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}
