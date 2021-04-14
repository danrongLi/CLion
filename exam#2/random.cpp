// Danrong Li dl4111
#include <iostream>
using namespace std;

int* first10Squares(){
    int* arr = new int[10];
    for (int i = 0; i < 10; i ++){
        arr[i] = (i+1)*(i+1);
    }
    return arr;
}
int main(){
    int* arr;
    arr = first10Squares();

    for (int i = 0; i < 10; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete[] arr;
    arr = nullptr;
    return 0;
}