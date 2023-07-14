

#include <iostream>
using namespace std;

int main()
{
    int dollars = 0, cents = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    const int quart_val = 25, dime_val = 10, nickel_val = 5, pennie_val = 1;
    int total_cents, remaining_total_cents;
    cout << "Please enter your amount in the format of dollars and cents separated by a space:" 
        << endl;
    cin >> dollars >> cents;
    
    total_cents = (dollars * 100) + cents;
    
    quarters = total_cents / quart_val;
    remaining_total_cents = total_cents - (quarters * quart_val);
    dimes = remaining_total_cents / dime_val;
    remaining_total_cents -= dimes * dime_val;
    nickels = remaining_total_cents / nickel_val;
    remaining_total_cents -= nickels * nickel_val;
    pennies = remaining_total_cents / pennie_val;

    cout << dollars << " dollars and " << cents << " cents are:\n" <<
        quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " <<
        pennies << " pennies." << endl;

    return 0;

}
