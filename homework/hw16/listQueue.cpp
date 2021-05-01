#include <iostream>
#include <list>

using namespace std;

template <class T>
class Queue{
public:
    void enqueue(T newItem) {data.push_back(newItem);}
    void dequeue() {data.pop_front();}
    T top() const {return *data.begin();}
    bool isEmpty() const {return data.empty();}
    int size() const {return data.size();}
    void clear() {data.clear();}
private:
    list<T> data;
};

int main() {

    Queue<int> q;
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(30);

    while(!q.isEmpty()){
        cout<<q.top()<<" ";
        q.dequeue();
    }
    cout<<endl;


    return 0;
}