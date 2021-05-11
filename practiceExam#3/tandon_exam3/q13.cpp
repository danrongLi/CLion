#include <iostream>
#include <list>

using namespace std;

class MinStack{
public:
    MinStack(){
        data = list<int>();
    }
    void push(int x){
        data.push_front(x);
    }
    void pop(){
        data.pop_front();
    }
    int top(){
        return *data.begin();
    }
    int getMin(){
        int current = top();
        return current;
    }
private:
    list<int> data;
};

int main(){
    MinStack obj;
    obj.push(5);
    obj.pop();
    int param_3 = obj.top();
    int param_4 = obj.getMin();


    return 0;
}