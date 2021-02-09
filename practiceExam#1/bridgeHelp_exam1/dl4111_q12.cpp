#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    int currentDiv = n;
    int currentRem = n;
    int sumOfDigits = 0;

    while (currentDiv > 0){
        currentRem = currentDiv % 10;
        currentDiv = currentDiv / 10;
        int productOfCurrentDigit = 1;
        int currentDigit = currentRem;
        while (currentDigit > 0){
            productOfCurrentDigit *= currentDigit;
            currentDigit -= 1;
        }
        sumOfDigits += productOfCurrentDigit;
    }
    if (sumOfDigits == n){
        cout<<n<<" is a factorion"<<endl;
    }
    else {
        cout<<n<<" is not a factorion"<<endl;
    }

    return 0;
}


