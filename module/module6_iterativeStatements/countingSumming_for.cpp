#include <iostream>
using namespace std;

int main() {

    int num, currentDigit;
    int sumDigit = 0;
    int countDigit = 0;

    cout<<"Please enter a positive integer: ";
    cin>>num;

    int originalNum = num;

    while(num > 0){
        currentDigit = num % 10;
        countDigit += 1;
        sumDigit += currentDigit;
        num = num / 10;
    }

    cout<<originalNum<<" has "<<countDigit<<" digits, and the sum is: ";
    cout<<sumDigit<<endl;

    return 0;
}
