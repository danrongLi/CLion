#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>
class vQueue{
public:

    explicit vQueue(vector<T> newData = vector<T>(), T* newStart = nullptr, T* newEnd = nullptr, int newSize = 0){
        data = newData;
        start = newStart;
        end = newEnd;
        size = newSize;
    }

    void enqueue(T newItem);
    void dequeue();
    bool isEmpty() {return size == 0;}
    void clear() {size = 0; data.clear(); start = nullptr; end = nullptr;}
    T top() {return *start;}
    int getSize() {return size;}

private:
    vector<T> data;
    T* start;
    T* end;
    int size;
};

template <class T>
void vQueue<T>::enqueue(T newItem) {
    data.push_back(newItem);
    start = &(data[0]);
    end = &(data[-1]);
    size += 1;
}

template <class T>
void vQueue<T>::dequeue() {
    if (size == 0 && start == nullptr && end == nullptr){
        cout<<"you cant dequeue an empty queue"<<endl;
        exit(1);
    }
    else {
        size -= 1;
        if (size == 0){
            clear();
        }
        else {
            start += 1;
        }
    }
}

int main(){

    vQueue<int> myQueue;
    myQueue.enqueue(100);
    myQueue.enqueue(200);
    myQueue.enqueue(300);
    myQueue.enqueue(400);
    myQueue.enqueue(500);
    myQueue.enqueue(600);

    cout<<myQueue.getSize()<<endl;

    while (!myQueue.isEmpty()){
        cout<<myQueue.top()<<" ";
        myQueue.dequeue();
    }
    cout<<endl;

    cout<<myQueue.getSize()<<endl;

    return 0;
}