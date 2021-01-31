//File Name: dl4111_hw4_q6.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 6
//Description: Program to print numbers with more even digits.
//Last Change: January 31, 2021
#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Enter a positive integer: ";
    cin>>n;

    int currentInteger;

    for (currentInteger = 1; currentInteger <= n; currentInteger += 1){
        int oddCount = 0, evenCount = 0;
        int remAfterDiv = currentInteger;
        int currentNum = currentInteger;
        while (currentNum > 0){
            remAfterDiv = currentNum % 10;
            currentNum /= 10;
            if ((remAfterDiv % 2 == 0) || (remAfterDiv == 0)){
                evenCount += 1;
            }
            else {
                oddCount += 1;
            }
        }
        if (evenCount > oddCount){
            cout<<currentInteger<<endl;
        }
    }

    return 0;
}
