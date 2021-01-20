#include <iostream>
using namespace std;

int main() {

    int userInput;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>userInput;

    if (userInput % 2 == 0)
        cout<<userInput<<" is even"<<endl;
    else
        cout<<userInput<<" is odd"<<endl;

    return 0;
}
