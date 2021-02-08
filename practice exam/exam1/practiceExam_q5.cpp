#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>n;

    int currentDiv = n, currentRem = n;
    int sumDigits = 0;

    while (currentDiv > 0){
        currentRem = currentDiv % 10;
        sumDigits += currentRem;
        currentDiv = currentDiv / 10;
    }

    cout<<sumDigits<<endl;

    return 0;
}
