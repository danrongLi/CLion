#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Money{
public:
    explicit Money(double newAmount = 0.0){
        if(newAmount < 0){
            cout<<"Illegal amount"<<endl;
            exit(1);
        }
        else {
            amount = newAmount;
        }
    }
    double getAmount() const {return amount;}
    friend istream& operator>> (istream& ins, Money& inputMoney);
    friend ostream& operator<< (ostream& outs, const Money& inputMoney);
private:
    double amount;
};
istream& operator>> (istream& ins, Money& inputMoney){
    ins >> inputMoney.amount;
    return ins;
}
ostream& operator<< (ostream& outs, const Money& inputMoney){
    outs<<inputMoney.getAmount();
    return outs;
}

class Check{
public:
    Check(int newNumber = 0, Money newAmount = Money(), bool newIfChecked = false){
        checkNumber = newNumber; checkAmount = newAmount; isChecked = newIfChecked;}
    int getCheckNumber() const {return checkNumber;}
    Money getCheckAmount() const {return checkAmount;}
    bool getWhetherChecked() const {return isChecked;}
    void setStatus(char status);
    friend istream& operator>>(istream& ins, Check& inputCheck);
    friend ostream& operator<<(ostream& outs, const Check& inputCheck);
private:
    int checkNumber;
    Money checkAmount;
    bool isChecked;
};
istream& operator>>(istream& ins, Check& inputCheck){
    ins>>inputCheck.checkNumber>>inputCheck.checkAmount;
    return ins;
}
ostream& operator<<(ostream& outs, const Check& inputCheck){
    if (inputCheck.getWhetherChecked()){
        outs<<"Cashed ";
    }
    else {
        outs<<"Un-cashed ";
    }
    outs<<"Check# "<<inputCheck.getCheckNumber()<<" $"<<inputCheck.getCheckAmount();
    return outs;
}
void Check::setStatus(char status) {
    if (status == 'y' || status == 'Y'){
        isChecked = true;
    }
    else if (status == 'n' || status == 'N'){
        isChecked = false;
    }
    else {
        cout<<"Illegal status"<<endl;
        exit(1);
    }
}

int main(){
    Money previousBalance;
    cout<<"Enter your previous balance without dollar sign"<<endl;
    cin>>previousBalance;
    int checkNum;
    cout<<"Enter number of checks"<<endl;
    cin>>checkNum;

    Check inputCheck[checkNum];
    vector<Check> cashedCheck;
    vector<Check> unCashedCheck;
    double totalCashed = 0.0;
    double totalUnCashed = 0.0;

    cout<<"Enter check number & check amount & whether being cashed (y/n)"<<endl;
    char temp;
    for (int i = 0; i < checkNum; i += 1){
        cin>>inputCheck[i];
        cin>>temp;
        inputCheck[i].setStatus(temp);
        if (inputCheck[i].getWhetherChecked()){
            cashedCheck.push_back(inputCheck[i]);
            totalCashed += inputCheck[i].getCheckAmount().getAmount();
        }
        else {
            unCashedCheck.push_back(inputCheck[i]);
            totalUnCashed += inputCheck[i].getCheckAmount().getAmount();
        }
    }
    cout<<"Here are the checks you entered"<<endl;
    for (int i = 0; i < checkNum; i += 1){
        cout<<inputCheck[i]<<endl;
    }
    cout<<"These are the cashed checks"<<endl;
    for (int i = 0; i < cashedCheck.size(); i += 1){
        cout<<cashedCheck[i]<<endl;
    }
    cout<<"These are the un-cashed checks"<<endl;
    for (int i = 0; i < unCashedCheck.size(); i += 1){
        cout<<unCashedCheck[i]<<endl;
    }
    cout<<"Total cashed dollar: $"<<totalCashed<<endl;
    cout<<"Total un-cashed dollar: $"<<totalUnCashed<<endl;
}