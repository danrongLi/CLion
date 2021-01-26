#include <iostream>
using namespace std;

int main() {

    int number = 2;
    int valueAdd = number++;

    cout<<"number++ situation:"<<endl;
    cout<<"valueAdd = "<<valueAdd<<endl;
    cout<<"number = "<<number<<endl;
    cout<<"valueAdded used the previous number values in the operation."<<endl;
    cout<<"\n";

    int numberAnother = 2;
    int valueAddAnother = ++numberAnother;

    cout<<"++number situation:"<<endl;
    cout<<"valueAdd = "<<valueAddAnother<<endl;
    cout<<"number = "<<numberAnother<<endl;
    cout<<"valueAdded used the updated ++ values in the operation."<<endl;
    cout<<"\n";

    int numberMinus = 8;
    int valueMinus = numberMinus--;

    cout<<"number-- situation:"<<endl;
    cout<<"valueMinus = "<<valueMinus<<endl;
    cout<<"number = "<<numberMinus<<endl;
    cout<<"valueMinus used the previous number values in the operation."<<endl;
    cout<<"\n";

    int numberMinusAnother = 8;
    int valueMinusAnother = --numberMinusAnother;

    cout<<"--number situation:"<<endl;
    cout<<"valueMinus = "<<valueMinusAnother<<endl;
    cout<<"number = "<<numberMinusAnother<<endl;
    cout<<"valueMinus used the updated -- values in the operation."<<endl;

    return 0;
}
