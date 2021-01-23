#include <iostream>
#include <string>
using namespace std;

int main() {

    string studentName;
    int graduationYear, currentYear;


    cout<<"Please enter your name: ";
    cin>>studentName;

    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;

    cout<<"Please enter current year: ";
    cin>>currentYear;

    if (graduationYear - currentYear >= 5){
        cout<<studentName<<", you are not in college yet"<<endl;
    }
    else if (graduationYear - currentYear == 4){
        cout<<studentName<<", you are a Freshman"<<endl;
    }
    else if (graduationYear - currentYear == 3){
        cout<<studentName<<", you are a Sophomore"<<endl;
    }
    else if (graduationYear - currentYear == 2){
        cout<<studentName<<", you are a Junior"<<endl;
    }
    else if (graduationYear - currentYear == 1){
        cout<<studentName<<", you are a Senior"<<endl;
    }
    else if (graduationYear == currentYear){
        cout<<studentName<<", you Graduated"<<endl;
    }

    return 0;
}
