#include <stack>
#include <iostream>

using namespace std;

class Node;

class ExpressionTree{
public:
    double CalculateValue(Node* root);
private:
    Node* root;
};

class Node{
public:

private:
    int num;
    char opt;
};

int main(){

    return 0;
}