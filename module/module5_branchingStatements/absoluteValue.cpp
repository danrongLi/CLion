#include <iostream>
using namespace std;

int main() {

    int userInput, absValue;

    cout<<"Please enter an integer: "<<endl;
    cin>>userInput;
    absValue = userInput;

    if (userInput < 0)
        absValue = userInput * (-1);

    cout<<"|"<<userInput<<"| = "<<absValue<<endl;

    return 0;
}
