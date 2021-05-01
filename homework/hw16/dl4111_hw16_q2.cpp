#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>
class vQueue{
public:
    vQueue(){ vdata = vector<T>(); start = nullptr; end = nullptr; size = 0;}
    void enqueue(T newItem);
    void dequeue();
    T top() const {return *start;}
    bool isEmpty() const {return size==0;}
    void clear() {vdata.clear(); start = nullptr; end = nullptr; size = 0;}
private:
    vector<T> vdata;
    T* start;
    T* end;
    int size;
};

template <class T>
void vQueue<T>::enqueue(T newItem) {
        vdata.push_back(newItem);
        start = &(vdata[0]);
        end = &(vdata[-1]);
        size += 1;
}
template <class T>
void vQueue<T>::dequeue() {
    if (start == nullptr && end == nullptr && size == 0){
        cout<<"You cannot dequeue an empty queue!"<<endl;
        exit(1);
    }
    else {
        size -= 1;
        if(size == 0){
            clear();
        }
        else {
            start += 1;
        }
    }
}

int main() {
    vQueue<int> vq;
    vq.enqueue(10);
    vq.enqueue(20);
    vq.enqueue(30);
    vq.enqueue(40);
    vq.enqueue(50);
    vq.enqueue(60);
    vq.enqueue(10);
    vq.enqueue(20);
    vq.enqueue(30);
    vq.enqueue(40);
    vq.enqueue(50);
    vq.enqueue(60);
    vq.enqueue(100);
    vq.enqueue(200);
    vq.enqueue(300);
    vq.enqueue(400);
    vq.enqueue(500);
    vq.enqueue(600);

    while(!vq.isEmpty()){
        cout<<vq.top()<<endl;
        vq.dequeue();
    }

    return 0;
}