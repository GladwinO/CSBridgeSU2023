// gto219_Real_Exam_3_Test_Question.cpp :

#include <iostream>
#include<stack>
#include<queue>
#include<string>

void inToPostFixConv(const std::string& inFix, std::queue<char>& queueBuffer);

int postFixToValConv(std::queue<char> postFix);
int postFixToVal(std::queue<char> postFix);

int main()
{
    std::string inFix = "a+b*c+(d*e+f)*g";
    std::queue<char> postFix;
    int val;
    //inToPostFixConv(inFix, postFix);
    std::string postFixStr = "6523+8*+3+*";
    for (char c : postFixStr) {
        postFix.push(c);
    }
    val = postFixToVal(postFix);
    //val = postFixToValConv(postFix);
    std::cout << val;
    /*while (!postFix.empty()) {//this test inFix to postFix conversion
        std::cout << postFix.front();
        postFix.pop();
    }*/
}

//adding a getPrecedence function could make the code more concise
/*int getPrecedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}*/

void inToPostFixConv(const std::string& inFix, std::queue<char>& queueBuffer) {
    std::stack<char> stackBuffer;
    int inFixSize = inFix.size();
    for (char c : inFix) {
        if (c != '(' && c != ')' && c != '*' && c != '/' && c != '+' && c != '-') {
            inFixSize--;
            queueBuffer.push(c);
        }
        else if (c == '(' || c == ')' || c == '*' || c == '/' || c == '+' || c == '-') {
            inFixSize--;
            if (stackBuffer.empty()) {
                stackBuffer.push(c);
            }
            else if (c == '(') {
                stackBuffer.push(c);
            }
            else if (c == ')') {
                char top = stackBuffer.top();
                while (top != '(') {
                    queueBuffer.push(top);
                    stackBuffer.pop();
                    if (!stackBuffer.empty()) {
                        top = stackBuffer.top();
                    }
                    else {
                        break;
                    }
                }
                if (!stackBuffer.empty()) {
                    stackBuffer.pop();//when the while loop stops, if it stops because top = '(' then '(' should be popped
                }
            }
            else if (c == '*' || c == '-') {
                char top = stackBuffer.top();
                while (top == '*' || top == '/') {
                    queueBuffer.push(top);
                    stackBuffer.pop();
                    if (!stackBuffer.empty()) {
                        top = stackBuffer.top();
                    }
                    else {
                        break;
                    }
                }
                stackBuffer.push(c);
            }
            else if (c == '+' || c == '-') {
                char top = stackBuffer.top();
                while (top != '(') {
                    queueBuffer.push(top);
                    stackBuffer.pop();
                    if (!stackBuffer.empty()) {
                        top = stackBuffer.top();
                    }
                    else {
                        break;
                    }
                }
                stackBuffer.push(c);
            }
        }
    }
    while (!stackBuffer.empty() && inFixSize == 0) {
        char top = stackBuffer.top();
        queueBuffer.push(top);
        stackBuffer.pop();
    }
}


int postFixToValConv(std::queue<char> postFix) {
    std::stack<int> stackBuffer;
    char front = ' ';
    if (!postFix.empty()) {
        front = postFix.front();
    }
    while (!postFix.empty()) {
        while (front != '*' && front != '/' && front != '+' && front != '-') {
            int num = front - '0';
            stackBuffer.push(num);
            postFix.pop();
            if (!postFix.empty()) {
                front = postFix.front();
            }
            else {
                break;
            }
        }
        while ((front == '*' || front == '/' || front == '+' || front == '-') && !stackBuffer.empty() && !postFix.empty()) {
            int operandLeft = 0, operandRight = 0;
            operandRight = stackBuffer.top();
            stackBuffer.pop();
            if (!stackBuffer.empty()) {
                operandLeft = stackBuffer.top();
                stackBuffer.pop();
            }
            if (front == '*') {
                postFix.pop();
                stackBuffer.push(operandLeft * operandRight);
                if (!postFix.empty()) {
                    front = postFix.front();
                }
            }
            else if (front == '/') {
                postFix.pop();
                stackBuffer.push(operandLeft / operandRight);
                if (!postFix.empty()) {
                    front = postFix.front();
                }
            }
            else if (front == '+') {
                postFix.pop();
                stackBuffer.push(operandLeft + operandRight);
                if (!postFix.empty()) {
                    front = postFix.front();
                }
            }
            else if (front == '-') {
                postFix.pop();
                stackBuffer.push(operandLeft - operandRight);
                if (!postFix.empty()) {
                    front = postFix.front();
                }
            }
        }
    }
    if (stackBuffer.size() == 1) {
        return stackBuffer.top();
    }
    return 0;
}

int postFixToVal(std::queue<char> postFix) {//this one is faster to right so better for the test
    std::stack<int> stackBuffer;
    char front = ' ';
    while (!postFix.empty()) {
        front = postFix.front();
        postFix.pop();
        if (front != '*' && front != '/' && front != '+' && front != '-') {
            int num = front - '0';
            stackBuffer.push(num);
        }
        else {
            if (stackBuffer.size() < 2) {
                return 0;
            }
            int operandRight = stackBuffer.top();
            stackBuffer.pop();
            int operandLeft = stackBuffer.top();
            stackBuffer.pop();
            if (front == '*') {
                stackBuffer.push(operandLeft * operandRight);
            }
            else if (front == '/') {
                stackBuffer.push(operandLeft / operandRight);
            }
            else if (front == '+') {
                stackBuffer.push(operandLeft + operandRight);
            }
            else if (front == '-') {
                stackBuffer.push(operandLeft - operandRight);
            }
        }
    }
    if (stackBuffer.size() == 1) {
        return stackBuffer.top();
    }
    return 0;
}