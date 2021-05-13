#include <stack>
#include <iostream>

using namespace std;


class Node{
public:
    Node(Node* newL = nullptr, Node* newR = nullptr){left = newL; right = newR;}
    virtual double calculateValue() = 0;

    Node* getLeft() {return left;}
    Node* getRight(){return right;}
    void setLeft(Node* newL){left = newL;}
    void setRight(Node* newR){right = newR;}
protected:
    Node* left;
    Node* right;
};

class ExpressionTree{
public:
    ExpressionTree(Node* newRoot){
        root = newRoot;
    }
    double CalculateValue(){
        return root->calculateValue();
    }
private:
    Node* root;
};

class OperatorNode: public Node{
public:
    OperatorNode(char newVal = ' '){ val = newVal;}
    virtual double calculateValue(){
        switch (val) {
            case '+':
                return ((left->calculateValue())+(right->calculateValue()));
            case '-':
                return ((left->calculateValue())-(right->calculateValue()));
            case '*':
                return ((left->calculateValue())*(right->calculateValue()));
            case '/':
                return ((left->calculateValue())/(right->calculateValue()));
        }
    }
private:
    char val;
};

class OperandNode: public Node{
public:
    OperandNode(int newVal = 0){val = newVal;}
    virtual double calculateValue(){
        return val;
    }
private:
    int val;
};


int main() {
    Node* root = new OperatorNode('*');
    root->setLeft(new OperatorNode('+'));
    root->setRight(new OperandNode(7));
    root->getLeft()->setLeft(new OperandNode(2));
    root->getLeft()->setRight(new OperandNode(3));


    ExpressionTree t(root);
    cout<<t.CalculateValue()<<endl;

    return 0;
}

