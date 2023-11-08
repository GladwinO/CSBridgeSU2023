// Practice_Exam_3_Summer_Extended_2020.cpp :



/*
Question 1: A
Question 2: you can replace *(one.x) with *one.x
Question 3: std::cout << root->children[1]->children[0] << std::endl; //the multifamily set up allows
for more than 2 children, but those children will also have vecotrs that contain their children to maintin the tree structure


Question 4: pure virtual function
Question 5: 4, 2, 5, 1, 6, 3, 7
Question 6: A
Question 7: B (or A) it is B //actually this one im not sure


*/

//Question 8:
#include <map>
#include <fstream>
#include <string>
#include <iostream>

int main1() {
    std::ifstream inputFile;
    std::string filename;
    std::cout << "Please provide a filename: ";
    std::cin >> filename;
    inputFile.open(filename);
    while (!inputFile) {
        std::cout << "Please enter a new filename: ";
        std::cin >> filename;
        inputFile.clear();
        inputFile.open(filename);
    }
    std::map<std::string, int> numWordsMap;

    std::string fileWord;
    while (inputFile >> fileWord) {
        if (numWordsMap.find(fileWord) == numWordsMap.end()) {
            numWordsMap.insert({ fileWord, 1 }); //I need to check how to insert in a map, and what functions return when something goes wrong
            //or i could use numWordsMap[fileWord] = 1; when using the operator like this will add fileWord to the map and assign 1 as its value
            //using the second option would make sense here since i alrady check if the key exists in the map
        }
        else {
            numWordsMap[fileWord]++;
        }
        
    }
    for (std::map<std::string, int>::iterator i = numWordsMap.begin(); i != numWordsMap.end(); i++) {
        //how do I output a key and value of a map?
        std::cout << i->first << " " << i->second << std::endl;
    }

    return 0;
}

//Question 9
/*
I woudld move all the data that is on the stack onto a RBT using the set library and then I would iterate 
through the set and read out the values to the console, which would be in sorted order. The overall big theta would be NlogN.
I know there is a difference between big theta and big O but Im just gonna equate the two
insert takes logN and there are N insertions into the set data strucutre of C++ STL so that sections runtime is NlogN
reading out fromt he list will be N

//Question 10
bool correctTree(BSTNode* root) {
    int numIncorConnect = numIncorrectConnections(root);
    return numIncorConnect == 0;
}
int numIncorrectConnections(BSTNode* root) { //this code is bad
    if (root == nullptr) {
        return 0;
    }
    int numLeftIncorrect = numIncorrectConnections(root->left);
    int numRightIncorrect = numIncorrectConnections(root->right);
    if (root->left != nullptr && root->left->parent != root) {//this condition is possible due to the short-circuiting nature of the && (and ||)
        numLeftIncorrect += 1;
    }
    if (root->right != nullptr && root->right->parent != root){//this condition is possible due to the short-circuiting nature of the && (and ||)
        numRightIncorrect += 1;
    }
    return numLeftIncorrect + numRightIncorrect;
        
}

//Question 11

class Node {
    Node* parent; //is this needed?//NO
    Node* left;
    Node* right;
public:
    Node(Node* newParent = nullptr, Node* newLeft = nullptr, Node* newRight = nullptr) : parent(newParent),
        left(newLeft), right(newRight) {}
    virtual int calculateValue() = 0;
    Node* getParent() const { return parent; }
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    Node* setParent(Node* newParent) { parent = newParent; }
    Node* setLeft(Node* newLeft) { left = newLeft; }
    Node* setRight(Node* newRight) { right = newRight; }
    
    ~Node(){}
};

class OperandNode : public Node {
private:
    int operand;
public:
    OperandNode(int newOperand = 0, Node* newParent = nullptr, Node* newLeft = nullptr, Node* newRight = nullptr) : operand(newOperand), Node(newParent, newLeft, newRight){}
    int calculateValue() const { return operand; }
};

class OperatorNode : public Node {
private:
    char oper;
public:
    OperatorNode(char newOperator = ' ', Node* newParent = nullptr, Node* newLeft = nullptr, Node* newRight = nullptr) : operand(newOperand), Node(newParent, newLeft, newRight) {} {}
    int calculateValue() const {
        if (getRight() == nullptr || getLeft() == nullptr) {
            return 0;
        }
        //honestly this section of the code below is mindboggling. The recursion stops if the recursive 
        //call uses the version of the function for a different class (the operand class) like who thinks of that
        //this code will continue to call itself and wont hit the switch statment area if both recursive calls
        //do not get called from the operand class instead of the operator class, becuase the operand class has the 
        //return, just like how recursion works in a single function now I can use the stop condition of another function
        //if the function exists in a different class that shares the same base class as this class. This is a 
        //revalation to me, its crazyyyyyyyyyy
        int leftValue = getLeft()->calculateValue();
        int rightValue = getRight()->calculateValue();

        switch (oper) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            }
            else {
                std::cout << "Division by zero impossible." << std::endl;
            }
        default:
            std::cout << "Incorrect operator entered." << std::endl;
            return 0;
        }
    }
};


class ExpressionTree {
private:
    Node* root;
public:
    ExpressionTree(Node* newRoot = nullptr) : root(newRoot){}
    int CalculateValue() {
        if (root != nullptr) {
            return root->calculateValue();//assume the root is not an operand
        }
        std::cout << "Empty tree" << std::endl;
        return 0;

    }
    
};



#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

