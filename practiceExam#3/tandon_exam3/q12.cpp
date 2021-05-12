#include <queue>
#include <iostream>

using namespace std;

template <class T>
class Stack{
public:
    Stack(){currentSize = 0;}
    void push(T newItem){
        q1.push(newItem);
        currentSize += 1;
    }
    void pop(){
        if (q1.empty()){
            return;
        }
        while (q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        currentSize -= 1;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    T top(){
        if (q1.empty()){
            return -1;
        }
        while (q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        T topped = q1.front();
        q1.pop();
        q2.push(topped);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return topped;
    }
    int getSize(){return currentSize;}

private:
    queue<T> q1;
    queue<T> q2;
    int currentSize;
};


int main(){

    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.getSize()<<endl;
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;

    return 0;
}