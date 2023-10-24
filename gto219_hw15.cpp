// gto219_hw15.cpp : 

#include <iostream>
#include <string>
#include<vector>
#include <cmath>

//information for each person
class Person {
private:
    std::string name;
    double amountPaid;
    double amountOwed;
public:
    Person(std::string pName = "", double moneyPaid = 0, double moneyOwed = 0);
    std::string getName() const { return name; }
    double getAmountPaid() const { return amountPaid; }
    double getAmountOwed() const { return amountOwed; }
    void setName(std::string pName) { name = pName; }
    void setAmountPaid(double moneyPaid);
    void setAmountOwed(double moneyOwed) { amountOwed = moneyOwed; }
    void operator-(int avgPay);
    friend double operator+(const Person& person1, const Person& person2);
};

//LListNode class
template <class T>
class LList;

template<class T> 
class LListNode {
private:
    T data;
    LListNode<T>* next;
public:
    LListNode(T newData = T(), LListNode<T>* newNext = nullptr) : data(newData), next(newNext) {}
    friend class LList<T>;
};

//LList class
template<class T>
class LList {
private:
    int size;
    LListNode<T>* head;
    LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
    LList() : size(0), head(nullptr) {}
    //copy constructor
    LList(const LList& rhs) : size(0), head(nullptr) { *this = rhs; }
    //assignment op.
    LList<T>& operator=(const LList<T>& rhs);
    //destructor
    ~LList() { clear(); }
    void insertAtHead(T newData);
    T removeFromHead();
    void clear();
    void insertAtEnd(T newData);
    bool isEmpty() { return head == nullptr; }
};


int main()
{
    std::cout << "Hello World!\n";
}


////////////////////// Definitions for Person Class /////////////////////////////

Person::Person(std::string pName = "", double moneyPaid = 0, double moneyOwed = 0) :
    name(pName), amountPaid(moneyPaid), amountOwed(moneyOwed) {
    if (moneyPaid < 0) {
        std::cout << "Amount paid is less than $0.00 and has been set equal to $0.00." << std::endl;
        amountPaid = 0;
    }
    if (moneyOwed < 0) {
        std::cout << "Amount owed is less than $0.00 and has been set equal to $0.00." << std::endl;
        amountOwed = 0;
    }
}

void Person::setAmountPaid(double moneyPaid) {
    if (moneyPaid < 0) {
        std::cout << "Amount paid is less than $0.00 and has been set equal to $0.00." << std::endl;
        amountPaid = 0;
        return;
    }
    amountPaid = moneyPaid;
}

void Person::operator-(int avgPay) {
    //tHose who paid more than the avg will be postive 
    //those who paid less than the avs will be negative
    amountOwed = amountPaid - avgPay;
}

double operator+(const Person& person1, const Person& person2) {
    return person1.amountPaid + person2.amountPaid;
}

////////////////////// Definitions for LList Class /////////////////////////////
template<class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs) {
    if (rhs == nullptr) {
        return nullptr;
    }
    return new LListNode<T>(rhs->data, recursiveCopy(rhs->next));
    //will go to end of list then recursively go back, creating new dynamic memmory
    //and creating a new list of pointers
}

template<class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
    //checks for self-assignment
    if (this == &rhs) {
        return *this;//returns the current object
    }
    //if no self-assignment it clears the left hand side in case anything was there
    clear();
    //if right List is empty assign left list to nullptr
    if (rhs.isEmpty()) {
        head = nullptr;
        return *this;
    }
    //recursively creates new pointers, "adds" them to a new list in order, then assigns
    //it to left side list
    head = recursiveCopy(rhs.head);
    size = rhs.size;
    return *this;
}

template<class T>
void LList<T>::insertAtHead(T newData) {
    //will make new head's next pointer point to the old head
    //and then update the List's head pointer
    head = new LListNode<T>(newData, head);
    size = size + 1;
}

template<class T>
T LList<T>::removeFromHead() {
    if (isEmpty()) {
        return T();
    }
    LListNode<T>* tempPtr = head;
    T tempData = tempPtr->data;
    head = tempPtr->next;
    delete tempPtr;
    size = size - 1;
    return tempData;
}

template<class T>
void LList<T>::clear() {
    while (head != nullptr) {
        LListNode<T>* next = head->next;
        delete head;
        size = size - 1;
        head = next;
    }
}

template<class T>
void LList<T>::insertAtEnd(T newData) {
    size = size + 1;
    if (isEmpty()) {
        insertAtHead(newData);
        return;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = new LListNode<T>(newData);
}