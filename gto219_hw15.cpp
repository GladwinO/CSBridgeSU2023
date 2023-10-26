// gto219_hw15.cpp : 

#include <iostream>
#include<fstream>
#include <string>
#include<vector>
#include <cmath>
#include <iomanip>

//information for each person
class Person {
private:
    std::string name;
    double amountPaid;
    double amountOwed;
public:
    Person(std::string pName, double moneyPaid, double moneyOwed);
    std::string getName() const { return name; }
    double getAmountPaid() const { return amountPaid; }
    double getAmountOwed() const { return amountOwed; }
    void setName(std::string pName) { name = pName; }
    void setAmountPaid(double moneyPaid);
    void setAmountOwed(double moneyOwed) { amountOwed = moneyOwed; }
    Person& operator-(double avgPay);
    Person& operator-=(double avgPay);
    friend double operator+(const Person& person, const double& moneyPaid);
    friend double operator+=(double& lhs, const Person& person);
    friend std::ifstream& operator>>(std::ifstream& ins, Person& person);
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
    T getData() { return data; }
    LListNode<T>* getNext() { return next; }
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
    bool isEmpty() const { return head == nullptr; }
    int getSize() const { return size; }
    LListNode<T>* getHead() const { return head; }
    void calOwed(const double& avgPay);
};

///////////////////////// General Function Declaration ////////////////////////////

void openInputFile(std::ifstream& inputFile);

template<class T>
void readInputFile(LList<T>& personList);

template<class T>
void avgPay(const LList<T>& list, double& avgPay);

/*template<class T>
void calOwed(const LList<T>& list, const double& avgPay);*/

/*template<class T>
void createListVec(const LList<T>& list, std::vector<T>& listVec);

void categorizePeople(const std::vector<Person>& listVec, std::vector<Person>& vecOwed, std::vector<Person>& vecOwes);

void printPayArrang(std::vector<Person> vecOwed, std::vector<Person> vecOwes, double avgPay);*/


int main()
{
    std::vector<Person> listVec;
    std::vector<Person> vecOwed;
    std::vector<Person> vecOwes;
    LList<Person> personList;
    readInputFile(personList);
    double averagePay = 0;
    avgPay(personList, averagePay);
    LListNode<Person>* iter;
    iter = personList.getHead();
    double amountPaid = iter->getData().getAmountPaid();
    double amountOwed = amountPaid - averagePay;
    iter->getData().setAmountOwed(amountOwed);
    std::cout << iter->getData().getAmountOwed();
    //calOwed(personList, averagePay);
    //createListVec(personList, listVec);

    /*for (const Person& person : listVec) {
        std::cout << person.getAmountOwed() << std::endl;
    }*/
    //categorizePeople(listVec, vecOwed, vecOwes);
    
    //printPayArrang(vecOwed, vecOwes, averagePay);

    return 0;
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

Person& Person::operator-(double avgPay) {
    //those who paid more than the avg will be postive 
    //those who paid less than the avg will be negative
    amountOwed = amountPaid - avgPay;
    return *this;
}

Person& Person::operator-=(double avgPay){
    amountOwed = amountPaid - avgPay;
    return *this;
}

double operator+(const Person& person, const double& moneyPaid) {
    return person.amountPaid + moneyPaid;
}

double operator+=(double& lhs, const Person& person) {
    lhs += person.amountPaid;
    return lhs;
}

std::ifstream& operator>>(std::ifstream& ins, Person& person) {
    double temp;
    ins >> temp;
    if (temp < 0) {
        person.amountPaid = 0;
    }
    else {
        person.amountPaid = temp;
    }
    return ins;
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
    if (isEmpty()) {
        insertAtHead(newData);
        return;
    }
    LListNode<T>* tempPtr = head;
    while (tempPtr->next != nullptr) {
        tempPtr = tempPtr->next;
    }
    tempPtr->next = new LListNode<T>(newData);
    size = size + 1;
}

template<class T>
void LList<T>::calOwed(const double& avgPay) { //i either update the member variables of the data or i create new data
    //iterates through the list updating the amountOwed for each object
    //using the overloaded '-' operator
    //those who paid more than the avg will be postive 
    //those who paid less than the avs will be negative
    if (!list.isEmpty()) {
        LListNode<T>* iter = head;
        while (iter != nullptr) {
            double amountOwed = iter->data.amountPaid - avgPay;
            iter->getData().setAmountOwed(amountOwed);
            std::cout << iter->getData().getAmountOwed() << std::endl;
            iter = iter->getNext();
        }
        return;
    }
    std::cout << "The list is empty." << std::endl;
}

///////////////////// General Function Definitions ///////////////////////
void openInputFile(std::ifstream& inputFile) {
    std::string  filename;
    std::cout << "Please provide the filename: ";
    std::cin >> filename;
    inputFile.open(filename);
    while (!inputFile) {
        std::cout << "Incorrect filename entered. Please enter a new filename." << std::endl;
        std::cout << "New filename: ";
        std::cin >> filename;
        inputFile.clear();
        inputFile.open(filename);
    }
}

template<class T>
void readInputFile(LList<T>& personList) {
    std::ifstream inputFile;
    openInputFile(inputFile);
    Person tempPerson;
    while (inputFile >> tempPerson) {
        inputFile.ignore(9999, ' ');
        std::string name;
        std::getline(inputFile, name);
        tempPerson.setName(name);
        personList.insertAtEnd(tempPerson);
    }
}

template<class T>
void avgPay(const LList<T>& list, double& avgPay) {
    if (!list.isEmpty()) {
        LListNode<T>* iter = list.getHead();
        while (iter != nullptr) {
            avgPay += iter->getData();
            iter = iter->getNext();
        }
        avgPay /= list.getSize();
        return;
    }
    std::cout << "The list is empty." << std::endl;
}

/*template<class T>
void calOwed(const LList<T>& list, const double& avgPay) {
    //iterates through the list updating the amountOwed for each object
    //using the overloaded '-' operator
    //those who paid more than the avg will be postive 
    //those who paid less than the avs will be negative
    if (!list.isEmpty()) {
        LListNode<T>* iter = list.getHead();
        while (iter != nullptr) {
            double amountOwed = iter->getData().getAmountPaid() - avgPay;
            iter->getData().setAmountOwed(amountOwed);
            std::cout << iter->getData().getAmountOwed() << std::endl;
            iter = iter->getNext();
        }
        return;
    }
    std::cout << "The list is empty." << std::endl;
}*/

/*template<class T>
void createListVec(const LList<T>& list, std::vector<T>& listVec) {
    //will iterate through the list and take Person objects and store them
    //in a new vector,those who paid more than the avg, who are owed, will be postive 
    if (!list.isEmpty()) {
        LListNode<T>* iter = list.getHead();
        while (iter != nullptr) {
            Person tempPerson = iter->getData();
            listVec.push_back(tempPerson);
            iter = iter->getNext();
        }
        return;
    }
    std::cout << "The list is empty." << std::endl;
    
}



void categorizePeople(const std::vector<Person>& listVec, std::vector<Person>& vecOwed, std::vector<Person>& vecOwes) {
    //will take those who are owed/paid exactly and store them in their own vector
    //those who paid more than the avg or paid the avg, who are owed, will be postive/0
    //I am including those who paid the exact amount here for memory space efficiency
    //those who paid less than the avg will be negative and added to vecOwes
    if (listVec.size() == 0) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    vecOwed.clear();
    vecOwes.clear();
    
    for (const Person& person : listVec) {
        double amountOwed = person.getAmountOwed();
        if ( amountOwed >= 0) {
            vecOwed.push_back(person);
        }
        else {
            //need to make amount owed positive
            vecOwes.push_back(person);
        }
    }
    
}

void printPayArrang(std::vector<Person> vecOwed, std::vector<Person> vecOwes, double avgPay) {
    for (Person& personOwed : vecOwed) {
        double amountOwed = personOwed.getAmountOwed();
        if (personOwed.getAmountOwed() == 0) {
            std::cout << personOwed.getName() << ", you do not need to do anything" << std::endl;
            continue;
        }
        for (Person& personOwes : vecOwes) {
            if (personOwes.getAmountOwed() == 0) {
                continue;
            }
            double amountOwes = std::fabs(personOwes.getAmountOwed());
            double additionalAmountPaid = amountOwed - amountOwes;
            if (additionalAmountPaid < 0) {
                additionalAmountPaid = amountOwed;
                personOwed.setAmountOwed(0);
                personOwes.setAmountOwed(amountOwes - amountOwed);
            }
            else {
                additionalAmountPaid = amountOwes;
                personOwed.setAmountOwed(amountOwed - amountOwes);
                personOwes.setAmountOwed(0);
            }
            std::cout << personOwes.getName() << ", you give " << personOwed.getName() <<
                " $" << std::showpoint << std::setprecision(2) << additionalAmountPaid << std::endl;
            if (personOwed.getAmountOwed() == 0) {
                break;
            }
        }
    }
    std::cout << "In the end, you should all have spent around $" << std::showpoint << std::setprecision(4) << avgPay << std::endl;
}*/