#include <iostream>
using namespace std;

void splitNumberByParity(int num, int& outEvenDigitsNum, int& outOddDigitsNum);

int main() {
    int num;
    int evenDigitsNum, oddDigitsNum;

    cout<<"Please enter a positive integer"<<endl;
    cin>>num;

    splitNumberByParity(num, evenDigitsNum, oddDigitsNum);

    cout<<"Your even-digits number is: "<<evenDigitsNum<<endl;
    cout<<"Your odd-digits number is: "<<oddDigitsNum<<endl;
    cout<<"Their sum is: "<<evenDigitsNum + oddDigitsNum<<endl;

    return 0;
}

void splitNumberByParity(int num, int& outEvenDigitsNum, int& outOddDigitsNum){
    int evenWeight, oddWeight;
    int evenDigitsNum, oddDigitsNum;
    int currDig;

    evenWeight = 1;
    oddWeight = 1;
    evenDigitsNum = 0;
    oddDigitsNum = 0;
    while(num > 0){
        currDig = num % 10;
        if((currDig % 2) == 0){
            evenDigitsNum += currDig * evenWeight;
            evenWeight *= 10;
        }
        else{
            oddDigitsNum += currDig * oddWeight;
            oddWeight *= 10;
        }
        num = num / 10;
    }

    outEvenDigitsNum = evenDigitsNum;
    outOddDigitsNum = oddDigitsNum;
}