// gto219_hw7_q1.cpp : 

#include <iostream>

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main()
{
    int numOfDaysInt, startingDayInt;
    int lastDayOfMonthInt, userYearInt;
    std::cout << "Please enter the number of days in the month: ";
    std::cin >> numOfDaysInt;

    std::cout << "Please enter a number from 1-7 which represents " <<
        "the starting day:\nMonday = 1\nTuesday = 2\nWednesday = 3\nThursday = 4\n"
        << "Friday = 5\nSaturday = 6\nSunday = 7\nEnter your number: ";
    std::cin >> startingDayInt;

    std::cout << "\n\nSection A:\n";
    lastDayOfMonthInt = printMonthCalender(numOfDaysInt, startingDayInt);
    std::cout << "\nLast day of the month(Mon-Sun: 1-7) is: " << lastDayOfMonthInt;

    std::cout << "\n\nSection B:\n";
    std::cout << "Please enter a year: ";
    std::cin >> userYearInt;
    if (isLeapYear(userYearInt)) {
        std::cout << userYearInt << " is a leap year.";
    }
    else {
        std::cout << userYearInt << " is not a leap year.";
    }

    std::cout << "\n\nSection C/D:\n";
    std::cout << "Please enter a year: ";
    std::cin >> userYearInt;
    std::cout << "Please enter a number from 1-7 which represents " <<
        "the starting day:\nMonday = 1\nTuesday = 2\nWednesday = 3\nThursday = 4\n"
        << "Friday = 5\nSaturday = 6\nSunday = 7\nEnter your number: ";
    std::cin >> startingDayInt;
    std::cout << "\n";
    printYearCalender(userYearInt, startingDayInt);

    return 0;

}

int printMonthCalender(int numOfDays, int startingDay) {
    const int numDaysInWeek = 7;
    int initNumTabsInt = 0;
    int daysInTheWeekInt = startingDay;
    int dayOfWeekInt = startingDay;
    int lastDayOFLastWeek = (startingDay + numOfDays) - 1;
    
    switch (startingDay) {
    case 1:
        initNumTabsInt = 0;
        break;
    case 2:
        initNumTabsInt = 1;
        break;
    case 3:
        initNumTabsInt = 2;
        break;
    case 4:
        initNumTabsInt = 3;
        break;
    case 5:
        initNumTabsInt = 4;
        break;
    case 6:
        initNumTabsInt = 5;
        break;
    case 7:
        initNumTabsInt = 6;
        break;
    default:
        std::cout << "Incorrect number entered.\n";
        break;
    }

    std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";
    for (int i = 0; i < initNumTabsInt; i++) {
        std::cout << "\t";
    }
    for (int i = 1; i <= numOfDays; i++) {
        std::cout << i << "\t";
        if (daysInTheWeekInt % numDaysInWeek == 0 && daysInTheWeekInt < lastDayOFLastWeek) {
            std::cout << "\n";
        }
        daysInTheWeekInt++;

        if (i > 1) {
            if (dayOfWeekInt <= numDaysInWeek) {
                dayOfWeekInt++;
            }
            if (dayOfWeekInt > numDaysInWeek) {
                dayOfWeekInt = 1;
            }
        }

    }
    


    return dayOfWeekInt;
}

bool isLeapYear(int num) {
    const int lowNum = 4;
    const int midNum = 100;
    const int highNum = 400;
    int divLowRemInt, divMidRemInt, divHighRemInt;
    divLowRemInt = num % lowNum;
    divMidRemInt = num % midNum;
    divHighRemInt = num % highNum;

    if (divLowRemInt == 0 && divMidRemInt != 0) {
        return true;
    }
    else if (divLowRemInt == 0 && divMidRemInt == 0) {
        if (divHighRemInt == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

}

void printYearCalender(int year, int startingDay) {
    int month = 1;
    int numDaysInMonth;
    int lastDayPreviousMonth, newStartingDay = startingDay;
    while (month < 13) {
        switch (month) {
        case 1:
            std::cout << "January " << year <<std::endl;
            numDaysInMonth = 31;
            break;
        case 2:
            std::cout << "February " << year << std::endl;
            if (isLeapYear(year)) {
                numDaysInMonth = 29;
            }
            else {
                numDaysInMonth = 28;
            }
            break;
        case 3:
            std::cout << "March " << year << std::endl;
            numDaysInMonth = 31;
            break;
        case 4:
            std::cout << "April " << year << std::endl;
            numDaysInMonth = 30;
            break;
        case 5:
            std::cout << "May " << year << std::endl;
            numDaysInMonth = 31;
            break;
        case 6:
            std::cout << "June " << year << std::endl;
            numDaysInMonth = 30;
            break;
        case 7:
            std::cout << "July " << year << std::endl;
            numDaysInMonth = 31;
            break;
        case 8:
            std::cout << "August " << year << std::endl;
            numDaysInMonth = 31;
            break;
        case 9:
            std::cout << "September " << year << std::endl;
            numDaysInMonth = 30;
            break;
        case 10:
            std::cout << "October " << year << std::endl;
            numDaysInMonth = 31;
            break;
        case 11:
            std::cout << "November " << year << std::endl;
            numDaysInMonth = 30;
            break;
        case 12:
            std::cout << "December " << year << std::endl;
            numDaysInMonth = 31;
            break;
        }
        lastDayPreviousMonth = printMonthCalender(numDaysInMonth, newStartingDay);
        std::cout << "\n\n";
        
        newStartingDay = lastDayPreviousMonth + 1;
        if (newStartingDay > 7) {
            newStartingDay = 1;
        }
        month++;
    }
}