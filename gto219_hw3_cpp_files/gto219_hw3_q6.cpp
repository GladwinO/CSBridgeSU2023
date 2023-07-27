// gto219_hw3_q6.cpp

#include <iostream>
#include <string>

int main()
{
    std::string callStrtTime, hoursStr, minutesStr, day;
    int numMinutes, hoursInt, minutesInt, totalTimeInt;
    double totalCharge;
    size_t colonPos;
    const double weekendCharge = 0.15;
    const double mornAndEvenCharge = 0.25;
    const double mornToEvenCharge = 0.40;
    const int beginningCutOff = 800;
    const int endingCutOff = 1800;

    std::cout << "Please enter the time the call started in 24-hour notation. " <<
        "Ex. 1.30 P.M. is input as 13:30: ";
    std::getline(std::cin, callStrtTime);
    std::cout << "Please enter the day of the week the call occurred from the options below:\n" <<
        "Mo\nTu\nWe\nTh\nFr\nSa\nSu\n";
    std::getline(std::cin, day);
    std::cout << "Please enter the length of the call (in minutes): ";
    std::cin >> numMinutes;

    //std::cout << callStrtTime << " " << day << " " << numMinutes;
    colonPos = callStrtTime.find(":");
    if (colonPos != std::string::npos) {
        hoursStr = callStrtTime.substr(0, colonPos);
        minutesStr = callStrtTime.substr(colonPos + 1, 2);
        hoursInt = stoi(hoursStr);
        minutesInt = stoi(minutesStr);
        hoursInt *= 100;
        totalTimeInt = hoursInt + minutesInt;
        //std::cout << hoursStr << " " << minutesStr;
    }
    else {
        std::cout << "The correct format for the time was not used. Ex. 13:30" << std::endl;
    }
    
    if (!day.empty()) {
        if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr") {
            if (!hoursStr.empty() && !minutesStr.empty()) {
                if (totalTimeInt >= beginningCutOff && totalTimeInt <= endingCutOff) {
                    totalCharge = numMinutes * mornToEvenCharge;
                    std::cout.precision(2);
                    std::cout << "Your total charge is $" << std::fixed << totalCharge << ".";
                }
                else {
                    totalCharge = numMinutes * mornAndEvenCharge;
                    std::cout.precision(2);
                    std::cout << "Your total charge is $" << std::fixed << totalCharge << ".";
                }
            }
            else {
                std::cout << "An incorrect time was given." << std::endl;
            }
        }
        else if (day == "Sa" || day == "Su") {
            totalCharge = numMinutes * weekendCharge;
            std::cout.precision(2);
            std::cout << "Your total charge is $" << std::fixed << totalCharge << ".";
        }
        else {
            std::cout << "Incorrect day format entered.";
        }
    }
    else {
        std::cout << "A day was not entered.";
    }
    

   
    

    
}
