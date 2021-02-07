//File Name: dl4111_hw4_q5.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 5
//Description: Program to print hour-glass stars.
//Last Change: Feb 7th, 2021

/*
 Please enter a positive integer
 4
 Hourglass

 ******* row 1, 0 space 7 stars
  #####  row 2, 1 space 5 hashes
   ***   row 3, 2 space 3 stars
    #    row 4, 3 space 1 star
   ***   row 1, 2 space 3 stars
  #####  row 2, 1 space 5 stars
 ******* row 3, 0 space 7 stars

 */

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
            if (lineCount % 2 == 0)
                cout<<"#";
            else
                cout<<"*";
        }
        cout<<"\n";
    }

    for(lineCount = 1; lineCount <= (n-1); lineCount += 1){
        for (spaceCount = 1; spaceCount < (n-lineCount); spaceCount += 1){
            cout<<" ";
        }
        for (starCount = 0; starCount < (2 * lineCount + 1); starCount += 1){
            if (lineCount % 2 == 0)
                cout<<"#";
            else
                cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
