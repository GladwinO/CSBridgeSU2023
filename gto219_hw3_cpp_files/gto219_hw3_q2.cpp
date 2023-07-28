// gto219_hw3_q2.cpp

#include <iostream>
#include <string>

int main()
{
    std::string userName, classRank;
    int gradYear, currYear, yearToGrad;
    const int freshman = 4, sophomore = 3, junior = 2, senior = 1, graduated = 0;
    std::cout << "Please enter your name: ";
    std::cin >> userName;
    std::cout << "Please enter your graduation year: ";
    std::cin >> gradYear;
    std::cout << "Please enter current year: ";
    std::cin >> currYear;

    yearToGrad = gradYear - currYear;

    if (yearToGrad > freshman) {
        classRank = "not in college yet.";
    }
    else if (yearToGrad == freshman) {
        classRank = "Freshman.";
    }
    else if (yearToGrad == sophomore) {
        classRank = "Sophomore.";
    }
    else if (yearToGrad == junior) {
        classRank = "Junior.";
    }
    else if (yearToGrad == senior) {
        classRank = "Senior.";
    }
    else {
        classRank = "Graduated!";
    }

    if (classRank != "Graduated!" && classRank != "not in college yet.") {
        std::cout << userName << ", you are a " << classRank << std::endl;
    }
    else if (classRank == "Graduated!") {
        std::cout << userName << ", you have " << classRank << std::endl;
    }
    else {
        std::cout << userName << ", you are " << classRank << std::endl;
    }
   

    //return 0;
}


