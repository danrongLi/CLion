//File Name: dl4111_hw4_q2.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 2
//Description: Program to represent positive integers with Roman Numerals Systems.
//Last Change: January 30, 2021
#include <iostream>
using namespace std;

const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5;
const int I = 1;

const int D_COUNT = 1;
const int L_COUNT = 1;
const int V_COUNT = 1;

const int C_COUNT = 4;
const int X_COUNT = 4;
const int I_COUNT = 4;

int main() {

    int enteredValue;
    int cCount, lCount, xCount, vCount, iCount;

    cout<<"Enter decimal number:"<<endl;
    cin>>enteredValue;
    cout<<enteredValue<<" is ";

    int mCount = enteredValue / M;
    while (mCount > 0){
        cout<<"M";
        mCount -= 1;
    }

    int dCount = (enteredValue % M) / D;
    int dRemaining;
    if (dCount > 0){
        cout<<"D";
        dRemaining = enteredValue % M;
        cCount = (dRemaining - D * D_COUNT) / C;
    }
    else {
        dRemaining = enteredValue % M;
        cCount = dRemaining / C;
    }

    int cRemaining;
    int cCounter = C_COUNT;
    if (cCount >= C_COUNT){
        cRemaining = dRemaining - C * C_COUNT;
        lCount = cRemaining / L;
        while (cCounter > 0){
            cout<<"C";
            cCounter -= 1;
        }
    }
    else{
        cRemaining = dRemaining - C * cCount;
        lCount = cRemaining / L;
        while (cCount > 0){
            cout<<"C";
            cCount -= 1;
        }
    }

    int lRemaining;
    if (lCount > 0){
        cout<<"L";
        lRemaining = cRemaining - L * L_COUNT;
        xCount = lRemaining / X;
    }
    else {
        lRemaining = cRemaining;
        xCount = lRemaining / X;
    }

    int xRemaining;
    int xCounter = X_COUNT;
    if (xCount >= X_COUNT){
        xRemaining = lRemaining - X * X_COUNT;
        vCount = xRemaining / V;
        while (xCounter > 0){
            cout<<"X";
            xCounter -= 1;
        }
    }
    else{
        xRemaining = lRemaining - X * xCount;
        vCount = xRemaining / V;
        while (xCount > 0){
            cout<<"X";
            xCount -= 1;
        }
    }

    int vRemaining;
    if (vCount > 0){
        cout<<"V";
        vRemaining = xRemaining - V * V_COUNT;
        iCount = vRemaining / I;
    }
    else {
        vRemaining = xRemaining;
        iCount = vRemaining / I;
    }


    int iCounter = I_COUNT;
    if (iCount >= I_COUNT){
        while (iCounter > 0){
            cout<<"I";
            iCounter -= 1;
        }
    }
    else{
        while (iCount > 0){
            cout<<"I";
            iCount -= 1;
        }
    }
    cout<<"\n";

    return 0;
}
