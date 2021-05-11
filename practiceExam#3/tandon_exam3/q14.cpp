#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    TreeNode* pLeft= p->left;
    TreeNode* qLeft= q->left;
    while (pLeft != nullptr){
        if (pLeft->val != qLeft->val){
            return false;
        }
        else {
            pLeft = pLeft->left;
            qLeft = qLeft->left;
        }
    }
    if (qLeft != nullptr){
        return false;
    }
    TreeNode* pRight=p->right;
    TreeNode* qRight= q->right;
    while (pRight != nullptr){
        if (pRight->val != qRight->val){
            return false;
        }
        else {
            pRight = pRight->right;
            qRight = qRight->right;
        }
    }
    if (qRight != nullptr){
        return false;
    }
    return true;
}

bool isSymmetric(TreeNode* root){

}

void levelOrder(TreeNode* root){
    queue<TreeNode*> readyToPrint;
    TreeNode* current = root;
    readyToPrint.push(current);
    while (!readyToPrint.empty()){
        TreeNode* temp = readyToPrint.front();
        readyToPrint.pop();
        cout<<temp->val<<" ";
        if (temp->left != nullptr){
            readyToPrint.push(temp->left);
        }
        if (temp->right != nullptr){
            readyToPrint.push(temp->right);
        }
    }
}
