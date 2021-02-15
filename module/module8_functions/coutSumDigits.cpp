#include <iostream>
using namespace std;

int analyzeDits(int num, int& outSum);

int main(){
    int num, countDigs, sumDigs;
    cout<<"Please enter a positive integer: "<<endl;
    cin>>num;
    countDigs = analyzeDits(num, sumDigs);
    cout<<num<<" has "<<countDigs<<" digits and the sum is "<<sumDigs<<endl;
    return 0;
}

int analyzeDits(int num, int& outSum){
    int count, sum, currDig;
    count = 0;
    sum = 0;
    while (num > 0){
        currDig = num % 10;
        count += 1;
        sum += currDig;
        num /= 10;
    }
    outSum = sum;
    return count;
}