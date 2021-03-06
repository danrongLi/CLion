//File Name: dl4111_hw4_q3.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 3
//Description: Program to convert decimal to binary.
//Last Change: January 31, 2021
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int decimalInteger;

    cout<<"Enter decimal number:"<<endl;
    cin>>decimalInteger;

    int currentNumberTemp = decimalInteger;
    int powerOf2Index = 0;

    while (currentNumberTemp > 1){
        currentNumberTemp = currentNumberTemp / 2;
        powerOf2Index += 1;
    }

    int initialBinaryNumber = 0;

    int currentPosition;
    int currentNumber = decimalInteger;

    while (powerOf2Index >= 0){
        currentPosition = pow(2, powerOf2Index);
        if (currentNumber >= currentPosition){
            currentNumber -= currentPosition;
            initialBinaryNumber += pow(10, powerOf2Index);
            powerOf2Index -= 1;
        }
        else {
            powerOf2Index -= 1;
        }
    }
    cout<<"The binary representation of "<<decimalInteger<<" is "<<initialBinaryNumber;
    return 0;
}
