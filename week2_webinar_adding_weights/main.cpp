#include <iostream>
using namespace std;

const int OUNCES_PER_POUND = 16;
int main() {
    int item1Pounds, item1Ounces;
    int item2Pounds, item2Ounces;
    int combinedPounds, combinedOunces;
    int totalOfOunces, carriedOverPounds;

    cout<<"Please enter the weight of two items."<<endl;
    cout<<"For each item, give its weight in pounds and ounces, ";
    cout<<"separated by a space"<<endl;
    cout<<"Item #1: ";
    cin>>item1Pounds>>item1Ounces;
    cout<<"Item #2: ";
    cin>>item2Pounds>>item2Ounces;

    totalOfOunces = item1Ounces + item2Ounces;
    combinedOunces = totalOfOunces % OUNCES_PER_POUND;
    carriedOverPounds = totalOfOunces / OUNCES_PER_POUND;
    combinedPounds = carriedOverPounds + item1Pounds + item2Pounds;

    cout<<"The combined weight is "<<combinedPounds<<" pounds and ";
    cout<<combinedOunces<<" ounces."<<endl;

    return 0;
}