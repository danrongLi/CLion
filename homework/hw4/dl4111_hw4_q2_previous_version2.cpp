//File Name: dl4111_hw4_q2.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 2
//Description: Program to represent positive integers with Roman Numerals Systems.
//Last Change: January 30, 2021
#include <iostream>
#include <string>
using namespace std;

const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5;
const int I = 1;

const int DLV_COUNT = 1;
const int CXI_COUNT = 4;

int main() {

    int decimalNumber, currentDiv, currentRem;
    string currentRoman;

    cout<<"Enter decimal number:"<<endl;
    cin>>decimalNumber;

    int currentNumber = decimalNumber;

    if (currentNumber >= M){
        currentDiv = currentNumber / M;
        currentRem = currentNumber % M;
        currentNumber = currentRem;
        int temp = currentDiv;
        while (temp > 0){
            currentRoman += "M";
            temp -= 1;
        }
    }
    else if (currentNumber >= D){
        currentNumber -= D * DLV_COUNT;
        currentRoman += "D";
    }
    else if (currentNumber >= C){
        currentDiv = currentNumber / C;
        currentRem = currentNumber % C;
        if (currentDiv >= CXI_COUNT){
            currentDiv = CXI_COUNT;
            currentRem = currentNumber - currentDiv * C;
        }
        currentNumber = currentRem;
        int temp = currentDiv;
        while (temp > 0){
            currentRoman += "C";
            temp -= 1;
        }
    }
    if (currentNumber >= L){
        currentNumber -= L * DLV_COUNT;
        currentRoman += "L";
    }
    if (currentNumber >= X){
        currentDiv = currentNumber / X;
        currentRem = currentNumber % X;
        if (currentDiv >= CXI_COUNT){
            currentDiv = CXI_COUNT;
            currentRem = currentNumber - currentDiv * X;
        }
        currentNumber = currentRem;
        int temp = currentDiv;
        while (temp > 0){
            currentRoman += "X";
            temp -= 1;
        }
    }
    if (currentNumber >= V){
        currentNumber -= V * DLV_COUNT;
        currentRoman += "V";
    }
    if (currentNumber >= I){
        currentDiv = currentNumber / I;
        currentRem = currentNumber % I;
        if (currentDiv >= CXI_COUNT){
            currentDiv = CXI_COUNT;
            currentRem = currentNumber - currentDiv * I;
        }
        currentNumber = currentRem;
        int temp = currentDiv;
        while (temp > 0){
            currentRoman += "I";
            temp -= 1;
        }
    }
    cout<<decimalNumber<<" is "<<currentRoman<<endl;
    return 0;
}