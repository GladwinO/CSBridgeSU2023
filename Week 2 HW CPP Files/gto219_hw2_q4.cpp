

#include <iostream>
using namespace std;

int main()
{
    int userPosInt1 = 0, userPosInt2 = 0;
    int addInts = 0, subInts = 0, multInts = 0, divInts = 0, modInts = 0;
    double divideInts = 0;
    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> userPosInt1 >> userPosInt2;
    cout << "\n";
    
    addInts = userPosInt1 + userPosInt2;
    subInts = userPosInt1 - userPosInt2;
    multInts = userPosInt1 * userPosInt2;
    divideInts = (double)userPosInt1 / userPosInt2;
    divInts = userPosInt1 / userPosInt2;
    modInts = userPosInt1 % userPosInt2;

    cout << userPosInt1 << " + " << userPosInt2 << " = " << addInts << "\n" << endl;
    cout << userPosInt1 << " - " << userPosInt2 << " = " << subInts << "\n" << endl;
    cout << userPosInt1 << " * " << userPosInt2 << " = " << multInts << "\n" << endl;
    cout << userPosInt1 << " / " << userPosInt2 << " = " << divideInts << "\n" << endl;
    cout << userPosInt1 << " div " << userPosInt2 << " = " << divInts << "\n" << endl;
    cout << userPosInt1 << " mod " << userPosInt2 << " = " << modInts << "\n" << endl;


    return 0;

}

