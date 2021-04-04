#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money{
public:
    friend Money operator+(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount);
    friend bool operator==(const Money& amount1, const Money& amount2);
    friend bool operator<(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    friend istream& operator>>(istream& ins, Money& amount);
    friend ostream& operator<<(ostream& outs, const Money& amount);

private:
    long all_cents;
};

int digit_to_int (char c);

int main(){

    Money amount[5], max;
    int i;
    cout<<"Enter 5 amounts of money"<<endl;
    cin>>amount[0];
    max = amount[0];
    for ( i = 1; i < 5; i ++){
        cin>>amount[i];
        if (max < amount[i])
            max = amount[i];
    }
    Money difference[5];
    for ( i = 0; i < 5; i ++){
        difference[i] = max - amount[i];
    }
    cout<<"The highest amount is "<<max<<endl;
    cout<<"The amounts and their differences from the largest are:"<<endl;
    for ( i = 0; i < 5; i ++){
        cout<<amount[i]<<" off by "<<difference[i]<<endl;
    }

    return 0;
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0){
        cout<<"Illegal values for dollars and cents"<<endl;
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars): all_cents(dollars*100) {}

Money::Money(): all_cents(0){}

double Money::get_value() const {
    return (all_cents*0.01);
}

Money operator+(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}

bool operator<(const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}

Money operator-(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

istream& operator>>(istream& ins, Money& amount){
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins>>one_char;
    if(one_char == '-'){
        negative = true;
        ins>>one_char; // read '$
    }
    else {
        negative = false;
    }
    ins>>dollars>>decimal_point>>digit1>>digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout<<"error illegal from money input"<<endl;
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative){
        amount.all_cents = -amount.all_cents;
    }
    return ins;
}

int digit_to_int(char c){
    return (int(c) - int('0'));
}

ostream& operator<<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if(amount.all_cents < 0){
        outs<<"- $"<<dollars<<'.';
    }
    else
        outs<<"$"<<dollars<<'.';
    if (cents<10){
        outs<<'0';
    }
    outs<<cents;
    return outs;
}


