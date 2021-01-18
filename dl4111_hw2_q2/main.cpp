#include <iostream>
using namespace std;

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
const int CENTS_PER_DOLLAR = 100;

int main() {

    int dollarAmount, centAmount;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollarAmount>>centAmount;

    int combinedCents = dollarAmount * CENTS_PER_DOLLAR + centAmount;

    int quarterAmount = combinedCents / CENTS_PER_QUARTER;
    int dimeAmount = (combinedCents % CENTS_PER_QUARTER) / CENTS_PER_DIME;
    int nickelAmount = ((combinedCents % CENTS_PER_QUARTER) % CENTS_PER_DIME) / CENTS_PER_NICKEL;
    int pennyAmount = (((combinedCents % CENTS_PER_QUARTER) % CENTS_PER_DIME) % CENTS_PER_NICKEL) / CENTS_PER_PENNY;

    cout<<dollarAmount<<" dollars and "<<centAmount<<" cents are:"<<endl;
    cout<<quarterAmount<<" quarters, "<<dimeAmount<<" dimes, ";
    cout<<nickelAmount<<" nickels and "<<pennyAmount<<" pennies"<<endl;

    return 0;
}
