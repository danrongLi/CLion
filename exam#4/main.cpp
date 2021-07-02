#include <iostream>
#include <vector>

using namespace std;

template <class T>
class BSTNode<T>{
public:
    BSTNode(BSTNode<T>* nL = nullptr, BSTNode<T>* nR = nullptr, BSTNode<T>* nP = nullptr){left = nL;right = nR;parent = nP;}
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;
    T value;
private:

};

BSTNode<int>* getLeft(BSTNode<int>* current){
    BSTNode<int>* temp = current;
    while(temp != nullptr && temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}
BSTNode<int>* getRight(BSTNode<int>* current){
    BSTNode<int>* temp = current;
    while(temp != nullptr && temp->right != nullptr){
        temp = temp->right;
    }
    return temp;
}

bool treeMatchesVector(const vector<int> v, BSTNode<int>* root) {
//    This is in-order ! Left, Middle, Right
   int count = 0;
   BSTNode<int>* current = root;
   while (count < v.size() && current != nullptr){
       BSTNode<int>* currentLeft = getLeft(current);
       BSTNode<int>* currentMid = currentLeft->parent;
       if (v[count] != currentLeft->value){
           return false;
       }
       else {
           count += 1;
           if (v[count] != currentMid->value){
               return false;
           }
           else {
               count += 1;
           }
       }

       BSTNode<int>* currentRight = currentMid->right;
       if (currentRight != nullptr && currentRight->left == nullptr && currentRight->right == nullptr){
           if (currentRight->value != v[count]){
               return false;
           }
           else {
               count += 1;
               current = currentMid->parent;
               if (current->value != v[count]){
                   return false;
               }
               else {
                   count += 1;
                   current = current->right;
               }
           }
       }
   }
   return true;

}

BSTNode<int>* recursiveGet(BSTNode<int>* current){
    if (current->left == nullptr){
        cout<<current->value<<endl;
        cout<<current->parent->value<<endl;
        cout<<current->parent->right->value<<endl;
    }
    else {
        current = recursiveGet(current);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

