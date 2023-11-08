// Exam_3_practice_spring_2023.cpp : 


/*
Question 1: C //this is because of operator precedence and associativity (the dot operator has a higher precedence than the derefrence operator
Question 2: D
Question 3: D
Question 4: std::cout << ptr->head->data << std::endl;
Question 5: We must include the copy constructor, the assignement operator, and the destructor
Question 6: For the stack class the push function should be used when adding a new element onto the stack
that the value gets added to the top of the stack.
Question 7: (look at how the search function works for BST) (terrible answer, think of answering these types of questions using one of the traversal methods)
   //everything here is wrong
   I would create a function that starts at the root node and compares the value I have with the root nodes
    data value. If the root nodes data value is equal to the given data value I will recursively add all the 
    data values for all the pointers to the right of the root node to a queue. if the root node is greater than
    the give data value then i would make a recursive call to the left and right children of the root node, and I 
    will continue going left until I find a node whose data value is less than or equal to the given data value and then
    recursively go back up to the root and go to the right of the root and add all those values to the queue. 
    If the root node is less than the given value I will go down the right side of the root node and print print all 
    the right side nodes that are greater than the val.

Question 8:
    A. abc+*d-
    B. ab+cd*+
    C. abc*d*-


*/

#include <iostream>
#include <fstream>
#include <set>
#include <string>

//for this code I assume the there are no spaces before or after the names

//Question 9

/*int testMain1() {

    std::ifstream inputFile;
    inputFile.open("students.txt");
    std::string studentName;
    std::set<std::string> studentNamesSet;
    while (getline(inputFile, studentName)) {
        studentNamesSet.insert(studentName);
    }
    inputFile.close();
    std::ofstream outputFile;
    outputFile.open("students.txt");
    for (std::set<std::string>::iterator i = studentNamesSet.begin(); i != studentNamesSet.end(); i++)
    {
        outputFile << *i << std::endl;
    }
    outputFile.close();

    return 0;
}*/

#include <vector>

//Question 10
class Coffee {
private:
    int size;
    bool cream;
    bool sugar;
public: 
    Coffee(int newSize = 0, bool isCream = false, bool isSugar = false) : size(newSize), cream(isCream), 
        sugar(isSugar){}
    virtual double cost() = 0;// maybe I will not make this pure virtual //is polymorphism possible with a pure virtual base class?
    virtual void addSugar() { sugar = true; }
    virtual void addCream() { cream = true; }
    int getSize() { return size; }
    bool isCream() { return cream; }
    bool isSugar() { return sugar; }

};

class IcedCoffee : public Coffee {
private:
    int numIce;
    
public:
    IcedCoffee(int newSize = 0, int amountIce = 5) : Coffee(newSize) {
        if (amountIce >= 1 && amountIce <= 10) {
            numIce = amountIce;
        }
        else {
            std::cout << "You asked for the wrong amount of ice!" << std::endl;
            numIce = 1;
        }
    }
    void addSugar() {
        Coffee::addSugar();
    }
    void addCream() {
        Coffee::addCream();
    }
    double cost() {
        double coffeeCost = 3.00;
        if (getSize() > 32) {
            coffeeCost += 1.00;
        }
        if (isCream()) {
            coffeeCost += 0.50;
        }
        if (isSugar()) {
            coffeeCost += 0.25;
        }
        if (numIce > 5) {
            coffeeCost += 0.50;
        }
        return coffeeCost;
    }
};

class HotCoffee : public Coffee {
private: 
    double temp;
    
public:
    HotCoffee(int newSize = 0, double newTemp = 195.5) : Coffee(newSize), temp(newTemp) {}
    void addSugar() {
        Coffee::addSugar();
    }
    void addCream() {
        Coffee::addCream();
    }
    double cost() {
        double coffeeCost = 2.50;
        if (getSize() > 16) {
            coffeeCost += 1.00;
        }
        if (isCream()) {
            coffeeCost += 0.25;
        }
        if (isSugar()) {
            coffeeCost += 0.15;
        }
        if (temp > 210) {
            coffeeCost += 0.25;
        }
        return coffeeCost;
    }
};

class Order {
private:
    double totalCost = 0;
    std::vector<Coffee*> coffeeOrder;
public:
    Order(double cost = 0) : totalCost(cost) {}
    void addCoffee(Coffee* coffee) {
        coffeeOrder.push_back(coffee);
    }
    double cost() {
        for (Coffee* coffee : coffeeOrder) {
            totalCost += coffee->cost();
        }
        return totalCost;
    }
};


















#include <iostream>

int main()
{
    Order newOrder;
    HotCoffee h1(32, 190);
    h1.addSugar();
    HotCoffee h2(8, 215);
    h2.addCream();
    IcedCoffee i1(39, 7);
    i1.addCream();
    i1.addSugar();
    std::cout << "h1 cost: " << h1.cost() << std::endl;
    std::cout << "h2 cost: " << h2.cost() << std::endl;
    std::cout << "i1 cost: " << i1.cost() << std::endl;
    newOrder.addCoffee(&h1);
    newOrder.addCoffee(&h2);
    newOrder.addCoffee(&i1);
    std::cout << "Order total: " << newOrder.cost() << std::endl;
}

