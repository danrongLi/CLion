#include <iostream>
#include <string>
using namespace std;

int main() {

    string firstName, middleName, lastName;

    cout<<"Please enter your name in the format: Fist name Middle name Last name:"<<endl;
    cin>>firstName>>middleName>>lastName;

    cout<<lastName<<", "<<firstName<<" "<<middleName[0]<<"."<<endl;

    return 0;

}
