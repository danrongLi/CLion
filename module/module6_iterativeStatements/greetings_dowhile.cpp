#include <iostream>
using namespace std;

int main() {

    char ans;

    do{
        cout<<"Hello"<<endl;
        cout<<"Do you want another greeting?"<<endl;
        cout<<"Press y for yes, n for no,"<<endl;
        cout<<"and then press return: ";
        cin>>ans;
    }while ((ans == 'y') || (ans == 'Y'));

    cout<<"GoodBye!"<<endl;

    return 0;
}
