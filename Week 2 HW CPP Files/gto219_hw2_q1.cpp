

#include <iostream>
using namespace std;

int main()
{
	int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
	int total_amount_cents = 0;
	int dollars, cents;
	const int quart_val = 25, dime_val = 10, nickel_val = 5, pennie_val = 1;
	cout << "Please enter number of coins:" << endl;
	cout << "# of quarters:";
	cin >> quarters;
	cout << "# of dimes:";
	cin >> dimes;
	cout << "# of nickels:";
	cin >> nickels;
	cout << "# of pennies";
	cin >> pennies;

	total_amount_cents = (quarters * quart_val) + (dimes * dime_val) + (nickels * nickel_val)
		+ (pennies * pennie_val);
	dollars = total_amount_cents / 100;
	cents = total_amount_cents % 100;

	cout << "The total is " << dollars << " dollars and " << cents << " cents." << endl;
}

