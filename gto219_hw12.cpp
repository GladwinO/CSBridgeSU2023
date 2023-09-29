//gto219)hw12.cpp:

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>

class Money {

private:
    long all_cents;

public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money(double totalAmount);
    Money();
    //Initializes the object so its value represents $0.00.
    double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.
    friend std::istream& operator >>(std::istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend std::ostream& operator <<(std::ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

};


///////////////////////////////////////////////////// Check Class Declarations /////////////////////////////////////////////////////////
class Check {
private:
    int num;
    Money amount; // checkAmount will call a constructor that initalizes its private memeber to 0 if no input is given
    bool isCashed;
public:
    Check() : num(0), isCashed(false) {/*blank intentionally*/ };
    Check(double userAmount);
    Check(int checkNum, double userAmount);
    Check(int checkNum, double userAmount, bool userCashed);



    int get_num();
    double get_amount();//this will return the double data type of the total amount of money in the money class (the private mem is an int in cents form)
    bool get_isCashed();
    void set_num(const int& userNum);
    void set_amount(const double& userAmount);
    void set_isCashed(const bool& userCashed);

    friend std::istream& operator >>(std::istream&, Check& checkInfo);

    friend std::ostream& operator <<(std::ostream&, const Check& checkInfo);

    friend bool operator <=(const Check& checkInfo1, const Check& checkInfo2);

    friend bool operator <(const Check& checkInfo1, const Check& checkInfo2);

    friend bool operator >(const Check& checkInfo1, const Check& checkInfo2);

};

/////////////////////////////////////////////// Genereal Non-Memeber Function Declarations //////////////////////////////////////////////////

void createArrayPtr(Check*& checkArr, int& size); //Takes check array pointer

void reSizeArrPtr(Check*& checkArr, int& size); //Takes check array pointer

double totalAmount(Check* checkArr, const int& size); //Takes check array pointer

void createArrayPtr(double*& depositArr, int& size); //Takes double array pointer

void reSizeArrPtr(double*& depositArr, int& size); //Takes double array pointer

double totalAmount(double* depositArr, const int& size); //Takes double array pointer

void leastToGreatest(Check*& checkList, const int& size);

void checkListPrint(Check* checkList, const int& size);


int main()
{
    Check* checkList;
    int checkSize = 0;
    double* depositList;
    int depositSize;
    double totalCheckAmount, totalDepositAmount;
    double userOldBalance, userNewBalance, bankNewBalance, balanceDiff, balanceDiffAbs;
    createArrayPtr(checkList, checkSize);
    std::cout << std::endl;
    createArrayPtr(depositList, depositSize);
    std::cout << std::endl;

    std::cout << "Please enter the old balance and your new balance separated by a space:\nFormat: Old balance New Balance\nEx: 23.23 300.23" << std::endl;
    std::cin >> userOldBalance >> userNewBalance;
    std::cout << std::endl;
    totalCheckAmount = totalAmount(checkList, checkSize);
    totalDepositAmount = totalAmount(depositList, depositSize);
    bankNewBalance = (userOldBalance + totalDepositAmount) - totalCheckAmount;
    balanceDiff = userNewBalance - bankNewBalance;
    balanceDiffAbs = std::abs(balanceDiff);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The total of the checks cashed amounts to: $" << totalCheckAmount << "." << std::endl;
    std::cout << "The total of the deposits amounts to: $" << totalDepositAmount << "." << std::endl;
    std::cout << "The new balance should be $" << userNewBalance << "." << std::endl;
    if (balanceDiff < 0) {
        std::cout << "The new balance is $" << balanceDiffAbs << " less than the bank stated balance.\n" << std::endl;
    }
    else if (balanceDiff > 0) {
        std::cout << "The new balance is $" << balanceDiffAbs << " more than the bank stated balance.\n" << std::endl;
    }
    else {
        std::cout << "The new balance is the same as the bank state balance.\n" << std::endl;
    }

    leastToGreatest(checkList, checkSize);

    checkListPrint(checkList, checkSize);
    







}



////////////////////////////////// Money Class Definitions and non-member functions ////////////////////////////////////

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) /*If one is negative and one is positive*/ {
        std::cout << "Illegal values for dollars and cents.\n";
        std::exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100) {
    //Body intentionally blank.
}

Money::Money(double totalAmount) : all_cents(totalAmount * 100) {
    //Body intentiaonally blank
}

Money::Money() : all_cents(0) {
    //Body intentionally blank.
}

double Money::get_value() const {
    return (all_cents * 0.01);
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator <(const Money& amount1, const Money& amount2) {
    if (amount1.all_cents < amount2.all_cents) {
        return true;
    }
    return false;
}

int digit_to_int(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}

//Uses iostream, cctype, cstdlib:
std::istream& operator >>(std::istream& ins, Money& amount) {
    char one_char, decimal_point,
        digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.
    ins >> one_char;
    if (one_char == '−') {
        negative = true;
        ins >> one_char; //read '$' 
    }
    else {
        negative = false;
    }

    //if input is legal, then one_char == '$'
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2)) {
        std::cout << "Error illegal form for money input\n";
        std::exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative) {
        amount.all_cents = -amount.all_cents;
    }

    return ins;
}

std::ostream& operator <<(std::ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0) {
        outs << "− $" << dollars << '.';
    }
    else {
        outs << "$" << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }
    outs << cents;

    return outs;
}





////////////////////////////////////// Check Class Member Definitions and non-member functions ////////////////////////////////////////


Check::Check(double userAmount) : num(0), amount(userAmount), isCashed(false) {
    if (userAmount <= 0) { //a check with 0 amount should be tossed
        std::cout << "An incorrect check amount was entered." << std::endl;
        std::exit(1);
    }
}

Check::Check(int checkNum, double userAmount) : num(checkNum), amount(userAmount), isCashed(false) {

    if (checkNum < 0) { //checks less than 0 do not exist
        std::cout << "An incorrect check number was entered." << std::endl;
        std::exit(1);
    }
    else if (userAmount <= 0) {//a check with 0 amount should be tossed
        std::cout << "An incorrect check amount was entered." << std::endl;
        std::exit(1);
    }

}

Check::Check(int checkNum, double userAmount, bool userCashed) : num(checkNum), amount(userAmount), isCashed(userCashed) {

    if (checkNum < 0) { //checks less than 0 do not exist
        std::cout << "An incorrect check number was entered." << std::endl;
        std::exit(1);
    }
    else if (userAmount <= 0) {//a check with 0 amount should be tossed
        std::cout << "An incorrect check amount was entered." << std::endl;
        std::exit(1);
    }

}


int Check::get_num() {
    return num;
}
double Check::get_amount() {
    return amount.get_value();
    //returns double value. the true value is stored as an int and returning the money data type would not return the amount but the object
}
bool Check::get_isCashed() {
    return isCashed;
}
void Check::set_num(const int& userNum) {
    num = userNum;
}
void Check::set_amount(const double& userAmount) {
    Money newAmount(userAmount);
    amount = newAmount;
}
void Check::set_isCashed(const bool& userCashed) {
    isCashed = userCashed;
}

std::istream& operator >>(std::istream& ins, Check& checkInfo) {
    int checkNum = 0;
    double checkAmount = 0.0;
    bool checkCashed = false;
    ins >> checkNum;
    if (checkNum < -1) { // a checkNum of -1 signifies the end of creating an array of checks.
        std::cout << "An incorrect check number was entered." << std::endl;
        std::exit(1);
    }
    checkInfo.num = checkNum;
    ins >> checkAmount;
    if (checkAmount <= 0) {
        std::cout << "An incorrect check amount was entered." << std::endl;
        std::exit(1);
    }
    Money temp(checkAmount);
    checkInfo.amount = temp; //why cant i do checkInfo.amount(checkAmount)?
    ins >> checkCashed;
    if (checkCashed != 1 && checkCashed != 0) {
        std::cout << "An incorrect input was entered." << std::endl;
        std::exit(1);
    }
    checkInfo.isCashed = checkCashed;



    return ins;
}

std::ostream& operator <<(std::ostream& out, const Check& checkInfo) {
    out << "Check number: " << checkInfo.num << " Check amount $" << checkInfo.amount.get_value() <<
        " Check cashed: ";
    if (checkInfo.isCashed == true) {
        out << "Yes";
    }
    else {
        out << "No";
    }
    return out;
}

bool operator <=(const Check& checkInfo1, const Check& checkInfo2) {
    if (checkInfo1.num <= checkInfo2.num) {
        return true;
    }
    return false;
}

bool operator <(const Check& checkInfo1, const Check& checkInfo2) {
    if (checkInfo1.num < checkInfo2.num) {
        return true;
    }
    return false;
}

bool operator >(const Check& checkInfo1, const Check& checkInfo2) {
    if (checkInfo1.num > checkInfo2.num) {
        return true;
    }
    return false;
}


//////////////////////////////////////////////// General Non-member Function Defintions /////////////////////////////////////////////////


void reSizeArrPtr(Check*& checkArr, int& size) {
    const int arrSizeInc = 2;
    int newSize = size * arrSizeInc;
    Check* tempArr = new Check[newSize];
    for (int i = 0; i < size; i++) {
        tempArr[i] = checkArr[i];
    }
    delete[] checkArr;
    checkArr = tempArr;
    size = newSize;
}




void createArrayPtr(Check*& checkArr, int& size) {
    //the destructor must exists outside of the function
    Check checkInfo;
    if (size <= 0) {
        size = 1;
    }
    int curPos = 0;
    int maxSize = size;
    checkArr = new Check[size];
    std::cout << "Enter check information in the format: Number Amount Cashed. Ex. 900 34.23 1" << std::endl;
    std::cout << "Check number should be equal to or above 0. Check Amount should be above 0. If the check has been cashed enter 1, and " <<
        "if the check has not been cashed enter a 0. Start each check on a new line." << std::endl;
    std::cout << "Enter -1 2 0 when you are done." << std::endl;
    std::cin >> checkInfo;
    while (checkInfo.get_num() != -1) {
        checkArr[curPos] = checkInfo;
        curPos++;
        if (curPos == maxSize) {
            //code to double the size of the array
            reSizeArrPtr(checkArr, maxSize);
        }
        std::cin >> checkInfo;

    }
    size = curPos; //when the while loop ends the curPos will be one number higher than the number of space actually filled in the array
}

double totalAmount(Check* checkArr, const int& size) { //total amount of checks cashed
    double total = 0;
    for (int i = 0; i < size; i++) {
        if (checkArr[i].get_isCashed() == 1) {
            total += checkArr[i].get_amount();
        }
    }
    return total;
}

void reSizeArrPtr(double*& depositArr, int& size) {
    const int arrSizeInc = 2;
    int newSize = size * arrSizeInc;
    double* tempArr = new double[newSize];
    for (int i = 0; i < size; i++) {
        tempArr[i] = depositArr[i];
    }
    delete[] depositArr;
    depositArr = tempArr;
    size = newSize;
}

void createArrayPtr(double*& depositArr, int& size) {
    //the destructor must exists outside of the function
    double deposit;
    if (size <= 0) {
        size = 1;
    }
    int curPos = 0;
    int maxSize = size;
    depositArr = new double[size];
    std::cout << "Enter each deposit on a new line. ex: 23.23" << std::endl;
    std::cout << "Enter -1." << std::endl;
    std::cin >> deposit;
    while (deposit != -1) {
        depositArr[curPos] = deposit;
        curPos++;
        if (curPos == maxSize) {
            //code to double the size of the array
            reSizeArrPtr(depositArr, maxSize);
        }
        std::cin >> deposit;

    }
    size = curPos; //when the while loop ends the curPos will be one number higher than the number of space actually filled in the array
}


double totalAmount(double* depositArr, const int& size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += depositArr[i];
    }
    return total;
}

void leastToGreatest(Check*& checkList, const int& size) {

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (checkList[i] > checkList[j]) {
                Check temp = checkList[i];
                checkList[i] = checkList[j];
                checkList[j] = temp;
            }
        }
    }
}

void checkListPrint(Check* checkList, const int& size) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "List of cashed checks:\n";
    int numCashed = 0;
    for (int i = 0; i < size; i++) {
        if (checkList[i].get_isCashed() == 1) {
            std::cout << "\t" << checkList[i] << std::endl;
            numCashed++;
        }

    }
    if (numCashed == 0) {
        std::cout << "\tThere were no cashed checks." << std::endl;
    }

    std::cout << "\nList of uncashed checks:\n";
    int numNotCashed = 0;
    for (int i = 0; i < size; i++) {
        if (checkList[i].get_isCashed() == 0) {
            std::cout << "\t" <<  checkList[i] << std::endl;
            numNotCashed++;
        }
    }
    if (numNotCashed == 0) {
        std::cout << "\tThere were no uncashed checks." << std::endl;
    }
}

