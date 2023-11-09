// Exam_3_Practice_17week.cpp

#include <iostream>


/*
Question 1:C
Question 2:C
Question 3:A
Question 4: 23+465-*+
Question 5: 1 (assuming this is done in the compiler)
//go over this again Question 6: Given a binary search tree of ints i wouuld do an in order traversal where I would search
for the element that is half the size of the largest size parameter of the tree, which i assume is the root node
//probably got the above wrong

//so basically if the size parameter is the poistion of the node in sorted order i should 
//recursively go to the left or right of a node depending if the size of the node is greater 
//or less than N/2 where is the total number of elements, until i find the node that matches
this is another way but there are issues here with multiple nodes that have a median rank










Question 7: I can create a stack, take the data from the head of the list, add it to the stack
the delete/remove the head which would make its next pointer the head, and then continue this process
until the list was empty. If i needed the information to be in a list I would just do everything in reverse 
except I would add each top of the stack to the end of the list, maintaing the reverse order

//the better answer:
nitialize three pointers: prev (initialized to nullptr), current (initialized to the head of the list), and next (initialized to nullptr).

Traverse the linked list by updating the current pointer while maintaining the prev and next pointers.

In each iteration, update the next pointer to point to the next node in the list.

Then, update the current node's next pointer to point to the prev node (reverse the direction of the pointer).

Move the prev pointer to the current node and the current pointer to the next node.

Continue this process until you reach the end of the list (i.e., the current pointer becomes nullptr).

Finally, update the head of the list to point to the last node (which is now the new head), and the list will be reversed.
*/

//Question 8
#include <fstream>
#include <iostream>
#include <string>
#include <set>

/*int main1() {
    std::ifstream inputFile;
    inputFile.open("names.txt");
    std::string name;
    std::set<std::string> cleanNames;
    while (getline(inputFile, name)) {
        cleanNames.insert(name);
    }
    inputFile.close();
    std::ofstream outputFile;
    outputFile.open("cleanNames.txt");
    for (std::set<std::string>::iterator i = cleanNames.begin(); i != cleanNames.end(); i++) {
        outputFile << *i << std::endl;
    }
    outputFile.close();
}*/

//Question 9:

//Two ways of doing this code
//1st way
//template<class T>
/*void sortedOrderList(BSTNode* root, list<T>& sortedList) {
    if (root == nullptr) {
        return;
    }
    sortedOrderList(root->left, sortedList);
    sortedList.push(root->data);
    sortedOrderList(root->right, sortedList);
}

//2nd way uses a helper function (keep in mind i can use helper functions)
if i really need to return something but i want to write the code in a different way
i can create a fucntion that takes the code in the way i want and then write a 
driver function that returns in the way the question asks
template<class T>
void sortedOrderList(BSTNode* root, list<T>& sortedList) {
    if (root == nullptr) {
        return;
    }
    sortedOrderList(root->left, sortedList);
    sortedList.push(root->data);
    sortedOrderList(root->right, sortedList);
}
template<class T>
list<T> sortedOrderList(BSTNode* root){//driver
    list<T> sortedList;
    sortedOrderList(root, sortedList);
    return soretedList;

}


*/

//Question 10:
#include <vector>
class Furniture {
public:
    virtual void display() = 0;
};

class Chair : public Furniture {
public:
    void display() { std::cout << "chair" << std::endl; }
};

int main2() {
    Chair a1;
    Chair a2;
    Chair a3;
    a1.display();
    a2.display();
    a3.display();
    std::vector<Furniture*> furnitureVec;
    furnitureVec.push_back(&a1);
    furnitureVec.push_back(&a2);
    furnitureVec.push_back(&a3);

    for (Furniture* chair : furnitureVec) {
        chair->display();
    }
    return 0;
}


int main()
{
    std::cout << "Hello World!\n";
}

