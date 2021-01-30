//File Name: dl4111_hw4_q1.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 1
//Description: Program to print the first n even numbers.
//Last Change: January 30, 2021

#include <iostream>
using namespace std;

int main() {

    int n;
    int count;
    int firstEven;

    cout<<"Please enter a positive integer: ";
    cin>>n;

    cout<<"section a"<<endl;
    count = 1;
    firstEven = 2;

    while(count <= n){
        cout<<firstEven<<endl;
        firstEven += 2;
        count += 1;
    }

    cout<<"section b"<<endl;
    for(count = 1, firstEven = 2; count <= n; firstEven += 2, count += 1){
        cout<<firstEven<<endl;
    }

    return 0;
}
