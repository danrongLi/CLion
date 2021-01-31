//File Name: dl4111_hw4_q2.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 2
//Description: Program to represent positive integers with Roman Numerals Systems.
//Last Change: January 31, 2021
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

    int decimalNumber;
    string currentRoman;

    cout<<"Enter decimal number:"<<endl;
    cin>>decimalNumber;

    int currentNumber = decimalNumber;
    int dCount = 0, cCount = 0, lCount = 0, xCount = 0, vCount = 0, iCount = 0;

    while (currentNumber > 0){
        if (currentNumber >= M){
            currentNumber -= M;
            currentRoman += "M";
        }
        else if ((currentNumber >= D) && (dCount < DLV_COUNT)){
            currentNumber -= D;
            currentRoman += "D";
            dCount += 1;
        }
        else if ((currentNumber >= C) && (cCount < CXI_COUNT)){
            currentNumber -= C;
            currentRoman += "C";
            cCount += 1;
        }
        else if ((currentNumber >= L) && (lCount < DLV_COUNT)){
            currentNumber -= L;
            currentRoman += "L";
            lCount += 1;
        }
        else if ((currentNumber >= X) && (xCount < CXI_COUNT)){
            currentNumber -= X;
            currentRoman += "X";
            xCount += 1;
        }
        else if ((currentNumber >= V) && (vCount < DLV_COUNT)){
            currentNumber -= V;
            currentRoman += "V";
            vCount += 1;
        }
        else if ((currentNumber >= I) && (iCount < CXI_COUNT)){
            currentNumber -= I;
            currentRoman += "I";
            iCount += 1;
        }
    }
    cout<<decimalNumber<<" is "<<currentRoman<<endl;

    return 0;
}
