// gto219_hw7_q1.cpp : 

#include <iostream>

int printMonthCalender(int numOfDays, int startingDay);

int main()
{
    int numOfDaysInt, startingDayInt;
    int lastDayOfMonth;
    std::cout << "Please enter the number of days in the month: ";
    std::cin >> numOfDaysInt;

    std::cout << "Please enter a number from 1-7 which represents " <<
        "the starting day:\nMonday = 1\nTuesday = 2\nWednesday = 3\nThursday = 4\n"
        << "Friday = 5\nSaturday = 6\nSunday = 7\nEnter your number: ";
    std::cin >> startingDayInt;

    lastDayOfMonth = printMonthCalender(numOfDaysInt, startingDayInt);
    std::cout << "\n" << lastDayOfMonth;


}

int printMonthCalender(int numOfDays, int startingDay) {
    const int numDaysInWeek = 7;
    int initNumTabsInt = 0;
    int daysInTheWeekInt = startingDay;
    int dayOfWeekInt = startingDay;
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
        if (daysInTheWeekInt % numDaysInWeek == 0) {
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