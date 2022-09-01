#include<bits/stdc++.h>
using namespace std;

// 1 - finding one or more base cases
// 2 & 3 - calling the same function on the leftSubTree & rightSubTree
// 4 - joining the result  

int sum(Node *root) {
    if(root == NULL)
        return 0;
    
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return root->data + leftSum + rightSum;
}

int height(Node *root) {
    if(root == NULL)
        return 0;
    
    int leftSubTree = height(root->left);
    int rightSubTree = height(root->right);

    return 1 + max(leftSubTree, rightSubTree);
}

bool existsInTree(Node *root, int value) {
    if(root == NULL)
        return false;
    
    bool leftcheck = existsInTree(root->left);
    bool rightCheck = existsInTree(root->right);

    return root->data == value || leftcheck || rightCheck;
}

void reverseTree(Node *root) {
    if(root == NULL)
        return;

    reverseTree(root->left);
    reverseTree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return;
}

int main() {
    return 0;
}
