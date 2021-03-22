#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main() {

    cout<<"part a:"<<endl;
    printTriangle(4);
    cout<<"part b:"<<endl;
    printOpositeTriangles(4);
    cout<<"part c:"<<endl;
    printRuler(4);

    return 0;
}

void printTriangle(int n){
    if (n == 1){
        cout<<"*";
    }
    else {
        printTriangle(n-1);
        for (int i = 0; i <= (n-1); i += 1){
            cout<<"*";
        }
    }
    cout<<endl;
}

void printOpositeTriangles(int n){
    if (n == 0){
        return;
    }
    else {
        for (int i = 0; i <= (n-1); i += 1){
            cout<<"*";
        }
        cout<<endl;
        printOpositeTriangles(n - 1);
        for (int i = 0; i <= (n-1); i += 1){
            cout<<"*";
        }
    }
    cout<<endl;
}
void printRuler(int n){
    if (n == 1){
        cout<<"- "<<endl;
    }
    else {
        printRuler(n-1);
        for (int i = 1; i <= n; i += 1){
            cout<<"- ";
        }
        cout<<endl;
        printRuler(n-1);
    }
}