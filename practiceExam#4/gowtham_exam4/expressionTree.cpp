#include <iostream>
using namespace std;

template <class T>
class ExpressionTreeNode{
public:
    ExpressionTreeNode(ExpressionTreeNode* newLeft = nullptr, ExpressionTreeNode* newRight = nullptr, T newD = nullptr){
        left = newLeft;
        right = newRight;
        data = newD;
    }

    virtual double getValue() = 0;
    ExpressionTreeNode* getLeft() const {return left;}
    ExpressionTreeNode* getRight() const {return right;}
    T getData() const {return data;}

private:
    ExpressionTreeNode* left;
    ExpressionTreeNode* right;
    T data;

};

template <class T>
class Operand: public ExpressionTreeNode<T>{
public:
    Operand() : ExpressionTreeNode<T>(){}
    Operand(double aDouble):ExpressionTreeNode<T>(aDouble){}
    virtual double getValue(){
        return this->getData();
    }
private:
};

template <class T>
class Operator: public ExpressionTreeNode<T>{
public:
    Operator(): ExpressionTreeNode<T>(){}
    Operator(char aChar): ExpressionTreeNode<T>(aChar){}
    virtual double getValue(){
        if (this->getData() == '+'){
            return (this->getLeft()->getValue())+(this->getRight()->getValue());
        }
        else if (this->getData() == '*'){
            return (this->getLeft()->getValue() * this->getRight()->getValue());
        }
    }
private:
    char data;

};
template <class T>
class ExpressionTree{
public:
    ExpressionTree(ExpressionTreeNode<T>* newHead = nullptr){
        head = newHead;
    }
    double getValue(){
        if (head != nullptr){
            return head->getValue();
        }
    }
private:
    ExpressionTreeNode<T>* head;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
