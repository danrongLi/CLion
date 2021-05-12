#include <stack>
#include <iostream>
//Theta(n^2)
using namespace std;

int main(){

    stack<int> myS;
    myS.push(3);
    myS.push(7);
    myS.push(4);
    myS.push(2);
    myS.push(1);
    myS.push(9);
    myS.push(8);

    stack<int> temp;

    while(!myS.empty()){
        int curr = myS.top();
        myS.pop();
        while(!temp.empty() && temp.top() > curr){
            myS.push(temp.top());
            temp.pop();
        }
        temp.push(curr);
    }

    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;

    return 0;
}