// GitHub_Exam3_Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

/*
* Question 1
* c. int DLL::getFirstValue() const
* 
* Question 2
* b. an abstract class
* 
* Question 3
* 345+*2/
* 
* Question 4
* a. Class constructor
* b. overloaded assignment operator
* c. destructor (if MyClass has dynamic memory in the class that needs to be deleted)
* 
*Question 5
*output in post-order: 2, 8, 5, 4, 3, 9 ,7 (wrong)
* Correct answer 2,5,4,3,8,9,7
* Reason
 Here's why:

Insert 7: The tree has just one node, so the post-order traversal of this node is 7.

Insert 9: 9 is greater than 7, so it goes to the right subtree. The post-order traversal of the right subtree is 9. The root node (7) comes next.

Insert 3: 3 is less than 7, so it goes to the left subtree. The post-order traversal of the left subtree is 3. The root node (7) comes next.

Insert 4: 4 is greater than 3, so it goes to the right subtree of the left subtree. The post-order traversal of the right subtree (of 3) is 4. The left subtree's root (3) comes next, and then the root of the entire tree (7).

Insert 5: 5 is greater than 4, so it goes to the right subtree. The post-order traversal of the right subtree (of 4) is 5. The left subtree's root (3) comes next, and then the root of the entire tree (7).

Insert 8: 8 is greater than 7, so it goes to the right subtree. The post-order traversal of the right subtree is 8. The root node (7) comes next.

Insert 2: 2 is less than 7, so it goes to the left subtree. The post-order traversal of the left subtree is 2. The root node (7) comes next.

So, the post-order traversal of the entire BST is 2, 5, 4, 3, 8, 9, 7.
*/















//////////////////////////////////////////////////////////////////////////////

// Question 6 of winter 2021 extended exam 3 //////////
bool bussesTooClose(std::string busLine);
//std::vector<double> getBusLineInfo(std::string busLine) this will return a vector double
//of distances for all buses on the same line

bool bussesTooClose(std::string busLine) {
    //what getBusLine(busLine) will return example
    // actually the code would look like testVec = getBusLine(busLine);
    std::vector<double> testVec = { 14, 0, 5.2, 3.1, 7 };
    double currComp = 0;
    double compDoub = 0;
    double distComp = 0;
    if (testVec.size() < 2) {
        return false;
    }
    for (int i = 0; i < testVec.size(); i++) {
        currComp = testVec[i];
        int j = i + 1;
        for (j; j < testVec.size(); j++) {
            compDoub = testVec[j];
            distComp = std::fabs(currComp - compDoub);
            if (distComp < 1) {
                return true;
            }
        }
    }
    return false;

}


///////////////////////////  chatgpt better more efficient algo first sort the vector then searches
/*#include <vector>
#include <algorithm>

bool bussesTooClose(std::string busLine) {
    std::vector<double> busDistances = getBusLineInfo(busLine);

    // Sort the distances in ascending order
    std::sort(busDistances.begin(), busDistances.end());

    for (int i = 1; i < busDistances.size(); i++) {
        if (busDistances[i] - busDistances[i - 1] < 1.0) {
            return true;  // Two buses are too close
        }
    }

    return false;
}*/

///////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////

///////////////// Question 7 of Winter 2021 Exam 3 /////////////////////////////////////////////
/*template<class T>
void fixList(LListNode<T>* pointer);

template<class T>
void fixList(LListNode<T>* pointer) {
    //i should definitely check that the pointer does not pointer to null first
    if (pointer == nullptr) {
        return;
    }
    if (pointer->next == nullptr) {
        return;
    }
    int curPos = 1;
    ListNode<T>* temp;
    ListNode<T>* prev;
    
    temp = pointer;
    while (temp->next != nullptr && temp->previous != nullptr) {
        curPos++;
        temp = temp->next;
        if (curPos % 2 == 0) {
            prev = temp->next;
            temp->next = temp->previous;
            temp->previous = prev;

        }
    }
    if (temp->previous != nullptr) {
        prev = temp->next;
        temp->next = temp->previous;
        temp->previous = prev;
    }


}*/

///////////////////////////////////////////////////////////////////////////////////////////////////////

////////////  Question 8 //////////////////////

class Discount {
private:
    double discountVal;
public:
    Discount(double newDiscount = 0) : discountVal(newDiscount){}
    virtual double calculateFinalDiscount(double price) {
        return price;
    }
    double getDiscount() const { return discountVal; }
    void setDiscount(double newDiscount) { discountVal = newDiscount; }

};

class SingleValueDiscount : public Discount {
public:
    SingleValueDiscount(double newDiscount = 0) : Discount(newDiscount){}
    double calculateFinalDiscount(double price) {
        return Discount::getDiscount();
    }
};

class SinglePercentDiscount : public Discount {
public:
    SinglePercentDiscount(double newDiscount = 0) : Discount(newDiscount){}
    double calculateFinalDiscount(double price) {
        int dollarDisc = price * Discount::getDiscount();
        return dollarDisc;
    }
};

class MultiDiscount : public Discount {
private:
    double secDiscount;
public:
    MultiDiscount(double firDiscount, double secondDiscount) : Discount(firDiscount),
        secDiscount(secondDiscount){}
    double calculateFinalDiscount(double price) {
        int dollarDisc = Discount::getDiscount();
        price -= dollarDisc;
        dollarDisc += (price * secDiscount);
        return dollarDisc;
    }
};

class Order {
private:
    std::vector<double> priceVec;
    std::vector<Discount*> discountVec;
public:
    void addItem(double newPrice, Discount* newDiscount) {
        priceVec.push_back(newPrice);
        discountVec.push_back(newDiscount);
    }
    double totalCost() {
        double totalSum;
        if ((priceVec.size() == discountVec.size()) && priceVec.size() > 0) {
            for (int i = 0; i < priceVec.size(); i++) {
                if (discountVec[i] == nullptr) {
                    totalSum += priceVec[i];
                }
                else {
                    totalSum += priceVec[i] - discountVec[i]->calculateFinalDiscount(priceVec[i]);
                }
            }
        }
        return totalSum;
    }

};

int main()
{

}