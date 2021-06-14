#include <iostream>
using namespace std;

class ExpressionTreeNode{
public:
    explicit ExpressionTreeNode(ExpressionTreeNode* newLeft = nullptr, ExpressionTreeNode* newRight = nullptr){
        left = newLeft;
        right = newRight;
    }

    virtual double getValue() = 0;
    ExpressionTreeNode* getLeft() const {return left;}
    ExpressionTreeNode* getRight() const {return right;}

private:
    ExpressionTreeNode* left;
    ExpressionTreeNode* right;


};

class Operand: public ExpressionTreeNode{
public:
    virtual double getValue(){
        return data;
    }
private:
    double data;
};

class Operator: public ExpressionTreeNode{
public:
    virtual double getValue(){
        if (data == '+'){
            return (getLeft()->getValue() + getRight()->getValue());
        }
        if (data == '*'){
            return (getLeft()->getValue() * getRight()->getValue());
        }
        else {
            cout<<"Only + and * are allowed here"<<endl;
        }
    }
private:
    char data;

};

class ExpressionTree{
public:
    ExpressionTree(ExpressionTreeNode* newHead = nullptr){
        head = newHead;
    }
    double getValue(){
        head->getValue();
    }
private:
    ExpressionTreeNode* head;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
