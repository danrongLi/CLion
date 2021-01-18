#include <iostream>
using namespace std;

int main() {

    int firstInteger, secondInteger;

    cout<<"Please enter two positive integers, separated by a space:"<<endl;
    cin>>firstInteger>>secondInteger;

    int addResult = firstInteger + secondInteger;
    int subtractResult = firstInteger - secondInteger;
    int multiplyResult = firstInteger * secondInteger;
    double divideResult = (double) firstInteger / (double) secondInteger;
    int divResult = firstInteger / secondInteger;
    int modResult = firstInteger % secondInteger;

    cout<<firstInteger<<" + "<<secondInteger<<" = "<<addResult<<endl;
    cout<<firstInteger<<" - "<<secondInteger<<" = "<<subtractResult<<endl;
    cout<<firstInteger<<" * "<<secondInteger<<" = "<<multiplyResult<<endl;
    cout<<firstInteger<<" / "<<secondInteger<<" = "<<divideResult<<endl;
    cout<<firstInteger<<" div "<<secondInteger<<" = "<<divResult<<endl;
    cout<<firstInteger<<" mod "<<secondInteger<<" = "<<modResult<<endl;

    return 0;
}
