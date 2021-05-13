#include <iostream>
#include <list>

using namespace std;

class BSTNode{
public:
    int getVal() {return val;}
    BSTNode* getLeft() {return left;}
    BSTNode* getRight() {return right;}
    BSTNode* getParent() {return parent;}
    void setLeft(BSTNode* newL){left = newL;}
    void serRight(BSTNode* newR){right = newR;}
    void setParent(BSTNode* newP){parent = newP;}

    BSTNode(int newV = 0){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        val = newV;
    }

    list<int> getSmaller(BSTNode* root, int target){
        list<int> res;
        BSTNode* current = root;
        if (current->getLeft()== nullptr && current->getRight()== nullptr){
            if (current->getVal() <= target){
                res.push_back(current->getVal());
            }
            return res;
        }
        else {
            list<int> left = getSmaller(current->getLeft(), target);
            list<int> right = getSmaller(current->getRight(), target);
            if (current->getVal() <= target){
                res.push_back(current->getVal());
            }
            res.merge(left);
            res.merge(right);
        }
        return res;

    }

private:
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    int val;
};

int main(){
    BSTNode* root = new BSTNode(50);
    root->setLeft(new BSTNode(40));
    root->getLeft()->setLeft(new BSTNode(33));
    root->getLeft()->serRight(new BSTNode(42));
    root->serRight(new BSTNode(60));
    list<int> res = root->getSmaller(root, 41);
    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop_front();
    }
}


