#include <iostream>
using namespace std;

void resizeArray(int*& arr, int currentSize, int newSize);

int main() {

    int size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i += 1){
        arr[i] = i * 10;
    }
    int oneMore = 110;
    int newSize = size * 2;
    resizeArray(arr, size, newSize);
    size = newSize;
    arr[size++] = oneMore;

    return 0;
}

void resizeArray(int*& arr, int currentSize, int newSize){
    int *temp = new int[newSize];
    for (int i = 0; i < currentSize; i += 1){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
