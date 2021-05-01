#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>
class Queue{
public:
    Queue(){data = vector<T>(); start = nullptr; end = nullptr; size = 0;}
    void enqueue(T newItem);
    void dequeue();
    T top() const {return *start;}
    bool isEmpty() const {return size==0;}
    void clear() {data.clear(); start = nullptr; end = nullptr; size = 0;}
private:
    vector<T> data;
    T* start;
    T* end;
    int size;
};

template <class T>
void Queue<T>::enqueue(T newItem) {
    if (start == nullptr && end == nullptr && size == 0){
        data.push_back(newItem);
        start = &(data[0]);
        end = &(data[0]);
        size += 1;
    }
    else {
        data.push_back(newItem);
        end = &(data.back());
        size += 1;
    }
}
template <class T>
void Queue<T>::dequeue() {
    if (start == nullptr && end == nullptr && size == 0){
        cout<<"You cannot dequeue an empty queue!"<<endl;
        exit(1);
    }
    else {
        size -= 1;
        start += 1;
    }
}

int main() {
    Queue<int> vq;
    vq.enqueue(10);
    vq.enqueue(20);
    vq.enqueue(30);
    vq.enqueue(100);
    vq.enqueue(2);
    vq.enqueue(3);
    while(!vq.isEmpty()){
        cout<<vq.top()<<" ";
        vq.dequeue();
    }
    cout<<endl;


    return 0;
}