#include <iostream>
using namespace std;

int main() {

    char lowerCaseLetter, upperCaseLetter;
    int offset;

    cout<<"Please enter a lower case letter:"<<endl;

    cin>>lowerCaseLetter;

    offset = (int)(lowerCaseLetter - 'a');

    upperCaseLetter = (char)(offset + 'A');

    cout<<"The upper case version of "<<lowerCaseLetter<<" is "<<upperCaseLetter<<endl;

    return 0;
}
