// gto219_Real_Exam_3_Test_Question.cpp :

#include <iostream>
#include<stack>
#include<queue>
#include<string>

void inToPostFixConv(const std::string& inFix, std::queue<char>& queueBuffer);

int main()
{
    std::string inFix = "a+b*c+(d*e+f)*g";
    std::queue<char> postFix;
    inToPostFixConv(inFix, postFix);
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