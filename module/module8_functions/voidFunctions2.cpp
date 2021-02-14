#include <iostream>
#include <cmath>
using namespace std;

void swap(int a, int b);
int main() {
    int a = 3, b = 4;
    cout<<"Before: a = "<<a<<" b = "<<b<<endl;
    swap(a, b);
    cout<<"After: a = "<<a<<" b = "<<b<<endl;
    return 0;
}

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


