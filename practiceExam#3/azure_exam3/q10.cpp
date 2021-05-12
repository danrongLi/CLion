#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class BSTNode{
public:
    BSTNode(int newData){ data = newData;}

    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;

private:
};
bool ifCorrect(BSTNode* X){
    BSTNode* Y = X->parent;
    if (Y == nullptr){
        return true;
    }
    else {
        if (Y->right == X){
            if (Y->left != nullptr){
                return ifCorrect(Y->left);
            }
            else {
                return ifCorrect(Y);
            }
        }
        else if (Y->left == X){
            return ifCorrect(Y);
        }
        else {
            return false;
        }
    }

}
int main(){

    BSTNode* leaf = new BSTNode(1);
    leaf->parent = new BSTNode(2);
    leaf->parent->left = leaf;
    leaf->parent->right = new BSTNode(3);
    BSTNode* rightLeaf = leaf->parent->right;
    rightLeaf->parent = leaf->parent;

    if (ifCorrect(leaf)){
        cout<<"Correct"<<endl;
    }
    else {
        cout<<"Not correct"<<endl;
    }


    return 0;
}
