#include <queue>
#include <iostream>

using namespace std;

template <class T>
class Stack{
public:
    void push(T newItem);
    void pop();
    int getSize();
    bool isEmpty();
    T front();
    void clear();

private:
    queue<T> data;
};

template <class T>
void Stack<T>::push(T newItem) {
    data.front() = newItem;
}

template <class T>
void Stack<T>::clear() {
    data.clear();
}

template <class T>
void Stack<T>::pop() {
    data.pop();
}

template <class T>
int Stack<T>::getSize() {
    data.size();
}

template <class T>
bool Stack<T>::isEmpty() {
    return (data.size() == 0);
}

template <class T>
T Stack<T>::front() {
    return data.front();
}


int main(){
    return 0;
}