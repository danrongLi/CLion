#include <iostream>
#include <list>
#include <stack>

using namespace std;

class MinStack{
public:
    MinStack(){
        myS = stack<int>();
        min = stack<int>();
    }
    void push(int x){
        if (myS.empty() || x <= min.top()){
            min.push(x);
        }
        myS.push(x);
    }
    void pop(){
        if (myS.empty()){return;}
        if (myS.top() == min.top()){
            min.pop();
        }
        myS.pop();
    }
    int top(){
        if (myS.empty()){return -1;}
        return myS.top();
    }
    int getMin(){
        if (myS.empty()){
            return -1;
        }
        return min.top();
    }
private:
    stack<int> myS;
    stack<int> min;
};

int main(){
    MinStack obj;
    obj.push(5);
    obj.push(13);
    obj.push(1);
    obj.push(14);
    obj.pop();
    int param_3 = obj.top();
    int param_4 = obj.getMin();
    cout<<param_3<<" "<<param_4<<endl;


    return 0;
}