#include <iostream>
using namespace std;

int main() {

    char userCh;

    cout<<"Please enter a character: "<<endl;
    cin>>userCh;

    if (userCh >= 'a' && userCh <= 'z')
        cout<<userCh<<" is a lower case letter"<<endl;
    else if (userCh >= 'A' && userCh <= 'Z')
        cout<<userCh<<" is an upper case letter"<<endl;
    else if (userCh >= '0' && userCh <= '9')
        cout<<userCh<<" is a digit"<<endl;
    else
        cout<<userCh<<" is not a alpha-numeric character"<<endl;

    return 0;
}
