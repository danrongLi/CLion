#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


//class MyClass{
//public:
//    MyClass(){val = 0;}
//    MyClass(int nval){val = 0; setVal(nval);}
//    virtual void setVal(int nVal) = 0;
//    virtual int getVal() const {return val;}
//private:
//    int val;
//};


class Discount{
public:
    virtual double calculateFinalDiscount(double price) = 0;
private:
};

class SinglePercentDiscount: public Discount{
public:
    SinglePercentDiscount(double newPercentage = 0.0){percentage = newPercentage;}
    virtual double calculateFinalDiscount(double price){
        return price*percentage;
    }
private:
    double percentage;
};

class SingleValueDiscount: public Discount{
public:
    SingleValueDiscount(double newAmount = 0.0){amount = newAmount;}
    virtual double calculateFinalDiscount(double price){
//        cout<<amount<<endl;
        return amount;
    }
private:
    double amount;
};
class MultiDiscount: public Discount{
public:
    MultiDiscount(double newP = 0.0, double newA = 0.0){percentage = newP; amount = newA;}
    virtual double calculateFinalDiscount(double price){
        double newP = price - amount;
//        cout<<"new price "<<newP<<endl;
//        cout<<newP*percentage<<" after pr"<<endl;
        return newP*percentage+amount;
    }
private:
    double percentage;
    double amount;
};

class Order{
public:
    Order(vector<double> newP = vector<double>(), vector<Discount*> newD = vector<Discount*>()){price = newP; discount = newD;}
    double totalCost(){
        double sum = 0.0;
        for (int i = 0; i < price.size(); i += 1){
            double current;
            if (discount[i] == nullptr){
                current = price[i];
            }
            else {
                current = price[i]-discount[i]->calculateFinalDiscount(price[i]);
            }
//            cout<<current<<" current"<<endl;
            sum += current;
        }
        return sum;
    }
    void addItem(double addPrice, Discount* addDiscount){
        price.push_back(addPrice);
        discount.push_back(addDiscount);
    }
private:
    vector<double> price;
    vector<Discount*> discount;
};
int main(){
//    MyClass *m = new MyClass(10);
//    m->setVal(10);
//    cout<<m->getVal()<<endl;

    Order firstOrder;
    SinglePercentDiscount spd5(0.5);
    SingleValueDiscount svd10(10);
    MultiDiscount md(0.102, 5.5);
    firstOrder.addItem(20, &svd10);
//    cout<<firstOrder.totalCost()<<endl;
    firstOrder.addItem(100, &spd5);
//    cout<<firstOrder.totalCost()<<endl;
    firstOrder.addItem(20, &md);
//    cout<<firstOrder.totalCost()<<endl;
    firstOrder.addItem(20, nullptr);
    cout<<firstOrder.totalCost()<<endl;
}