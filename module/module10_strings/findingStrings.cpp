#include <iostream>
#include <string>
using namespace std;

int main() {

    string str = "abcdbcdefg";

    cout<<str.find("de")<<endl;

    if (str.find("xy") == string::npos){
        cout<<"Not Found"<<endl;
    }
    else {
        cout<<"Found"<<endl;
    }

    cout<<str.find("cd")<<endl;

    return 0;
}


