#include <iostream>
using namespace std;

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
const int CENTS_PER_DOLLAR = 100;

int main() {

    int numberOfQuarters;
    int numberOfDimes;
    int numberOfNickels;
    int numberOfPennies;

    cout<<"Please enter number of coins:"<<endl;
    cout<<"# of quarters: ";
    cin>>numberOfQuarters;
    cout<<"# of dimes: ";
    cin>>numberOfDimes;
    cout<<"# of nickels: ";
    cin>>numberOfNickels;
    cout<<"# of pennies: ";
    cin>>numberOfPennies;

    int equivalentCentsFromQuarters;
    int equivalentCentsFromDimes;
    int equivalentCentsFromNickels;
    int equivalentCentsFromPennies;

    equivalentCentsFromQuarters = numberOfQuarters * CENTS_PER_QUARTER;
    equivalentCentsFromDimes = numberOfDimes * CENTS_PER_DIME;
    equivalentCentsFromNickels = numberOfNickels * CENTS_PER_NICKEL;
    equivalentCentsFromPennies = numberOfPennies * CENTS_PER_PENNY;

    int combinedCents = (equivalentCentsFromQuarters + equivalentCentsFromDimes
            + equivalentCentsFromNickels + equivalentCentsFromPennies);

    int dollarAmount = combinedCents / CENTS_PER_DOLLAR;
    int centAmount = combinedCents % CENTS_PER_DOLLAR;

    cout<<"The total is "<<dollarAmount<<" dollars and "<<centAmount<<" cents"<<endl;

    return 0;
}

