//File Name: dl4111_hw4_q4.cpp
//Author: Danrong Li
//Email Address: dl4111@nyu.edu
//Assignment Number: 4
//Description: Program to calculate the geometric mean.
//Last Change: January 31, 2021
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int lengthOfSequence;

    cout<<"section a"<<endl;

    cout<<"Please enter the length of the sequence: ";
    cin>>lengthOfSequence;

    int curr, count;
    int productOfSequence = 1;

    cout<<"Please enter your sequence:"<<endl;
    for (count = 0; count < lengthOfSequence; count += 1){
        cin>>curr;
        productOfSequence *= curr;
    }
    double geometricMean = pow((double) productOfSequence, 1.0 / (double) lengthOfSequence);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout<<"The geometric mean is: "<<geometricMean<<endl;

    cout<<"section b"<<endl;

    bool seenEndOfSequence = false;
    int currSecondVersion;
    int productOfSequenceSecondVersion = 1;
    int countSequence = 0;

    cout<<"Please enter a non-empty sequence of positive integers, "
        <<"each one in a separate line. End your"<<endl;
    cout<<"sequence by typing -1: "<<endl;

    while (!seenEndOfSequence){
        cin>>currSecondVersion;
        if (currSecondVersion == -1){
            seenEndOfSequence = true;
        }
        else {
            countSequence += 1;
            productOfSequenceSecondVersion *= currSecondVersion;
        }
    }

    double geometricMeanSecondVersion = pow((double) productOfSequenceSecondVersion, 1.0 / (double) countSequence);

    cout<<"The geometric mean is: "<<geometricMeanSecondVersion<<endl;

    return 0;
}
