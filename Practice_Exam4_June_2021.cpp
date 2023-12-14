// Practice_Exam4_June_2021.cpp:

#include <iostream>
#include <vector>

void createTreeVec(std::vector<int>& newVec, BSTNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    createTreeVec(newVec, root->left);
    newVec.push_back(root->val);
    createTreeVec(newVec, root->right);
}

bool treeMatchVec(const std::vector<int>& userVec, BSTNode<int>* root) {
    std::vector<int> treeVec;
    createTreeVec(treeVec, root);
    if (treeVec == userVec) {
        return true;
    }
    return false;
}


int main()
{
    std::cout << "Hello World!\n";
}