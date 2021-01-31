//File Name: dl4111_hw4_q5.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 5
//Description: Program to print hour-glass stars.
//Last Change: January 31, 2021
#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"Please enter a positive integer n: ";
    cin>>n;

    int lineCount, starCount, spaceCount;

    for (lineCount = 1; lineCount <= n; lineCount += 1){
        for (spaceCount = 0; spaceCount < (lineCount - 1); spaceCount += 1){
            cout<<" ";
        }
        for (starCount = 0; starCount < ((n - lineCount) * 2 + 1); starCount += 1){
            cout<<"*";
        }
        cout<<"\n";
    }

    for(lineCount = 1; lineCount <= n; lineCount += 1){
        for (spaceCount = 0; spaceCount < (n-lineCount); spaceCount += 1){
            cout<<" ";
        }
        for (starCount = 0; starCount < (2 * lineCount - 1); starCount += 1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
