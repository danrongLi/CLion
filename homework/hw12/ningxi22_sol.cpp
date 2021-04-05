#include <iostream>
#include <vector>
using namespace std;

class Money{
public:
    Money(double dollars);
    Money();
    double getValue() const;
    friend istream& operator >>(istream& ins, Money& amount);
private:
    double money;
};

Money:: Money(double dollars){
    if (dollars<0){
        cout<<"Illegal value\n";
        exit(1);
    }
    money = dollars;
}

Money:: Money(): money(0){}

double Money:: getValue() const{
    return money;
}

istream& operator >>(istream& ins, Money& amount){
    ins>>amount.money;
    return ins;
}

class Check{
public:
    Check(Money check);
    Check();

    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check); //returns check number and its amount
    double getAmount() const;
    void setAmount(Money amount);
    void checkCashed();
    bool cashedStatus() const;
    void setCheckNum(int number);

private:
    int checkNum;
    Money checkAmount;
    bool cashed;
};

Check:: Check(Money check):checkAmount(0){
    checkAmount = check.getValue();
    cashed = false;
}

Check:: Check(): checkAmount(0), cashed(false){};

void Check:: checkCashed(){
    cashed = true;
}

bool Check:: cashedStatus() const{
    return cashed;
}

void Check:: setAmount(Money amount){
    checkAmount = amount.getValue();
}

void Check:: setCheckNum(int number){
    checkNum = number;
}

double Check:: getAmount() const{
    return checkAmount.getValue();
}

istream& operator >>(istream& ins, Check& check){
    ins>>check.checkAmount;
    return ins;
}

ostream& operator <<(ostream& outs, const Check& check){
    outs<<"Check number "<<check.checkNum<<": amount $"<<check.checkAmount.getValue();
    return outs;
}

void sort(double* arr, int size);

int main(){
    double oldBalance, newBalance, totalDeposits=0, totalCashed=0, bankBalance, deposit;
    char cash;
    Money curr;
    int totalChecks, checksCashed=0, numDeposits;

    cout<<"Without dollar sign, enter your bank account balance last time it was balanced:\n";
    cin>>oldBalance;
    cout<<"How many checks in total have you written since last time you balanced your account?\n";
    cin>>totalChecks;
    Check checkBook[totalChecks];
    cout<<"One by one, enter these "<<totalChecks<<" amounts of checks and a 'y' to indicate if a check has been cashed";
    cout<<" or a 'n' to indicate it hasn't. Hit 'enter' each time you finish an amount or a character\n";
    vector<Check> cashedChecks;
    vector<Check> nonCashedChecks;
    for (int i=0; i<totalChecks; i++){
        cin>>curr;
        checkBook[i].setAmount(curr);
        checkBook[i].setCheckNum(i+1);
        cin>>cash;
        if (cash == 'y'){
            checkBook[i].checkCashed();
            totalCashed+= checkBook[i].getAmount();
            cashedChecks.push_back(checkBook[i]);
            checksCashed++;
        }
        else{
            nonCashedChecks.push_back(checkBook[i]);
        }
    }

    vector<double> deposits;
    cout<<"How many deposits have you made since you last balanced your account?\n";
    cin>>numDeposits;
    cout<<"Enter the "<<numDeposits<<" amounts you've deposited since last account rebalance:\n";
    for (int i=0; i<numDeposits; i++){
        cin>>deposit;
        deposits.push_back(deposit);
    }

    cout<<"\nThe checks you've written that have been cashed and their associated numbers are as follows:\n";
    for (Check i: cashedChecks)
        cout<<i<<" "<<endl;

    for (int i=0; i<deposits.size(); i++)
        totalDeposits+= deposits[i];
    bankBalance = oldBalance+totalDeposits-totalCashed;
    newBalance = oldBalance+totalDeposits;
    for (int i=0; i<totalChecks; i++)
        newBalance-= checkBook[i].getAmount();

    cout<<"\nThe total amount of checks cashed, total amount of deposits, new balance, ";
    cout<<"and bank balance are as as follows, in that order:\n";
    cout<<"$"<<totalCashed<<", $"<<totalDeposits<<", $"<<newBalance<<", $"<<bankBalance<<endl;
    cout<<"The number that should be your new balance differs from your current bank balance ";
    cout<<"by $"<<bankBalance-newBalance<<" because of the checks you wrote that haven't been cashed yet.\n";

    double arr[checksCashed];
    for (int i=0; i<checksCashed; i++)
        arr[i] = cashedChecks[i].getAmount();
    double arr1[totalChecks-checksCashed];
    for (int i=0; i<totalChecks-checksCashed; i++)
        arr1[i] = nonCashedChecks[i].getAmount();
    sort(arr, checksCashed);
    sort(arr1, totalChecks-checksCashed);
    cout<<"\nIn summary, the list of checks cashed, sorted in ascending order, is as follows:\n";
    for (double i: arr)
        cout<<"$"<<i<<" ";
    cout<<"\nThe list of checks not cashed, sorted in ascending order, is as follows:\n";
    for (double i: arr1)
        cout<<"$"<<i<<" ";
    return 0;
}

void sort(double* arr, int size){
    for (int i=0; i<size; i++)
        for (int j=0; j<i; j++)
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
}
