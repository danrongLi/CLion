//Danrong Li
//dl4111

#include <iostream>
using namespace std;

int main() {
    int currentNumber;

    cout<<"Please enter a sequence of positive integers, each one in a separate line."<<endl;
    cout<<"End your sequence by typing -1:"<<endl;

    bool seenEndOfInput = false;
    int currentDiv, currentRem;
    int moreEvenCount = 0;

    while (seenEndOfInput == false){
        cin>>currentNumber;
        if (currentNumber == -1){
            seenEndOfInput = true;
        }
        currentDiv = currentNumber;
        currentRem = currentNumber;
        int evensCount = 0;
        int oddsCount = 0;
        while (currentDiv > 0){
            currentRem = currentDiv % 10;
            currentDiv = currentDiv / 10;
            if (currentRem%2 == 0){
                evensCount += 1;
            }
            else {
                oddsCount += 1;
            }
        }
        if (evensCount > oddsCount){
            moreEvenCount += 1;
        }
    }
    cout<<"You entered "<<moreEvenCount<<" more-even numbers"<<endl;

    return 0;
}
