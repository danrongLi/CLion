#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Money{
public:
    Money();
    Money(double amount);

    double getAmount() const;
    friend istream& operator >> (istream& ins, Money& inputMoney);
private:
    double amount;
};
Money::Money():amount(0.0) {}
Money::Money(double amount) {
    if (amount < 0){
        cout<<"Illegal money amount"<<endl;
        exit(1);
    }
    this->amount = amount;
}
double Money::getAmount() const {
    return amount;
}
istream& operator >> (istream& ins, Money& inputMoney){
    ins>>inputMoney.amount;
    return ins;
}

class Check{
public:
    Check();
    Check(Money inputCheckAmount, char checkStatus, int checkID);

    friend istream& operator >> (istream& ins, Check& check);
    friend ostream& operator << (ostream& outs, const Check& check);

    double getCheckAmount() const;
    bool getStatus() const;
    int getCheckID() const;

    void setStatus(char status);

private:
    int checkID;
    Money checkAmount;
    bool beingCashed;
};

bool Check::getStatus() const {
    return beingCashed;
}
int Check::getCheckID() const {
    return checkID;
}

void Check::setStatus(char status) {
    if (status == 'y' || status == 'Y'){
        beingCashed = true;
    }
    else if (status == 'n' || status == 'N'){
        beingCashed = false;
    }
    else {
        cout<<"Illegal check status"<<endl;
        exit(1);
    }
}
double Check::getCheckAmount() const {
    return checkAmount.getAmount();
}
istream& operator >> (istream& ins, Check& check){
    ins>>check.checkAmount>>check.checkID;
    return ins;
}
ostream& operator << (ostream& outs, const Check& check){
    outs<<"Check #"<<check.checkID<<" with $"<<check.checkAmount.getAmount()<<" with cashed status of: ";
    if (check.beingCashed){
        cout<<"Cashed"<<endl;
    }
    else {
        cout<<"Not Cashed"<<endl;
    }
    return outs;
}
Check::Check() {
    checkID = 0;
    checkAmount = 0.0;
    beingCashed = false;
}
Check::Check(Money inputCheckAmount, char checkStatus, int checkID) {
    this->checkID = checkID;
    if (checkStatus == 'y' || checkStatus == 'Y'){
        beingCashed = true;
    }
    else if (checkStatus == 'n' || checkStatus == 'N'){
        beingCashed = false;
    }
    else {
        cout<<"Illegal check status"<<endl;
        exit(1);
    }
    checkAmount = inputCheckAmount;
}
int main(){

    Money previousBalance;
    cout<<"tell me your bank balance, without dollar sign"<<endl;
    cin>>previousBalance;

    int numOfChecks;
    cout<<"how many checks you want to input today?"<<endl;
    cin>>numOfChecks;

    Check inputChecks[numOfChecks];
    vector<Check> cashedChecks;
    vector<Check> notCashedChecks;
    double totalCashedDollars = 0.0;
    double totalNotCashedDollars = 0.0;
    cout<<"enter check amount & check ID & whether check being cashed (y/n)"<<endl;
    char temp;
    for (int i = 0; i < numOfChecks; i += 1){
        cin>>inputChecks[i];
        cin>>temp;
        inputChecks[i].setStatus(temp);
        if (inputChecks[i].getStatus()){
            cashedChecks.push_back(inputChecks[i]);
            totalCashedDollars += inputChecks[i].getCheckAmount();
        }
        else {
            notCashedChecks.push_back(inputChecks[i]);
            totalNotCashedDollars += inputChecks[i].getCheckAmount();
        }
    }

    int numOfDeposits;
    cout<<"how many deposits you want to input today?"<<endl;
    cin>>numOfDeposits;

    Money inputDeposits[numOfDeposits];
    double totalDepositDollars = 0.0;
    cout<<"enter the deposit amount, without dollar sign"<<endl;
    for (int i = 0; i < numOfDeposits; i += 1){
        cin>>inputDeposits[i];
        totalDepositDollars += inputDeposits[i].getAmount();
    }

    double newCustomerBalance = totalDepositDollars + previousBalance.getAmount() - totalCashedDollars - totalNotCashedDollars;
    double newBankBalance = totalDepositDollars + previousBalance.getAmount() - totalCashedDollars;
    double difference = newBankBalance - newCustomerBalance;

    sort(cashedChecks.begin(), cashedChecks.end(), [](const Check& lhs, const Check& rhs){
        return lhs.getCheckID() < rhs.getCheckID();
    });

    sort(notCashedChecks.begin(), notCashedChecks.end(), [](const Check& lhs, const Check& rhs){
        return lhs.getCheckID() < rhs.getCheckID();
    });

    cout<<"here are some output for you:"<<endl<<endl;

    cout<<"total of the checks cashed: $"<<totalCashedDollars<<endl;

    cout<<"total of the deposits: $"<<totalDepositDollars<<endl;

    cout<<"the new balance should be: $"<<newCustomerBalance<<endl;

    cout<<"the bank might think it is: $"<<newBankBalance<<endl;

    cout<<"the difference due to the un-cashed checks is: $"<<difference<<endl<<endl;

    cout<<"the list of cashed checks with ascending check number:"<<endl;
    for (int i = 0; i < cashedChecks.size(); i += 1){
        cout<<cashedChecks[i];
    }
    cout<<endl;
    cout<<"the list of un-cashed checks with ascending check number:"<<endl;
    for (int i = 0; i < notCashedChecks.size(); i += 1){
        cout<<notCashedChecks[i];
    }
}
