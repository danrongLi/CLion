#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double aValue, bValue, cValue;

    cout<<"Please enter value of a: ";
    cin>>aValue;
    cout<<"Please enter value of b: ";
    cin>>bValue;
    cout<<"Please enter value of c: ";
    cin>>cValue;

    if ((aValue == 0) && (bValue == 0) && (cValue == 0)){
        cout<<"This equation has infinite number of solutions"<<endl;
    }
    else if ((aValue == 0) && (bValue == 0) && (cValue != 0)){
        cout<<"This equation has no solution"<<endl;
    }
    else if ((bValue * bValue - 4 * aValue * cValue) < 0){
        cout<<"This equation has no real solution"<<endl;
    }
    else if ((bValue * bValue - 4 * aValue * cValue) == 0){
        double xResult = (-bValue) / (2 * aValue);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout<<"This equation has a single real solution x="<<xResult<<endl;
    }
    else if ((bValue * bValue - 4 * aValue * cValue) > 0){
        double xResult1 = (-bValue + (sqrt(bValue * bValue - 4 * aValue * cValue))) / (2 * aValue);
        double xResult2 = (-bValue - (sqrt(bValue * bValue - 4 * aValue * cValue))) / (2 * aValue);
        cout<<"This equation has two real solutions"<<endl;
        cout<<"x1 = "<<xResult1<<endl;
        cout<<"x2 = "<<xResult2<<endl;
    }

    return 0;
}
