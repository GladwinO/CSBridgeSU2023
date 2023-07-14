

#include <iostream>
using namespace std;

int main()
{
    int days = 0, hours = 0, minutes = 0;
    int total_days = 0, total_hours = 0, total_minutes = 0;
    const int hours_in_day = 24, minutes_in_hour = 60;

    cout << "Please enter the number of days John has worked: ";
    cin >> days; 
    cout << "Please enter the number of hours John has worked: ";
    cin >> hours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutes;

    cout << "\n\n";

    total_days += days;
    total_hours += hours;
    total_minutes += minutes;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> days;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutes;

    total_days += days;
    total_hours += hours;
    total_minutes += minutes;

   

    total_hours += total_minutes / minutes_in_hour;
    total_minutes %= minutes_in_hour;

    total_days += total_hours / hours_in_day;
    total_hours %= hours_in_day;

    cout << "The total time both of them worked together is: " << total_days << " days, " <<
        total_hours << " hours and " << total_minutes << " minutes." << endl;

    return 0;

}

