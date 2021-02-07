#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
const double NEAREST_INTEGER_THRESHOLD = 0.5;

int main() {

    double realNumber;
    int roundingMethod;

    cout<<"Please enter a Real number:"<<endl;
    cin>>realNumber;

    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    cin>>roundingMethod;

    if(realNumber == int(realNumber)){
        cout<<int(realNumber)<<endl;
    }

    else if (realNumber>=0){
        switch (roundingMethod) {

            case FLOOR_ROUND:
                cout<<int(realNumber)<<endl;
                break;

            case CEILING_ROUND:
                cout<<int(realNumber)+1<<endl;
                break;

            case ROUND:
                if ((realNumber - int(realNumber)) >= NEAREST_INTEGER_THRESHOLD){
                    cout<<int(realNumber)+1<<endl;
                    break;
                }
                else if ((realNumber - int(realNumber)) < NEAREST_INTEGER_THRESHOLD){
                    cout<<int(realNumber)<<endl;
                    break;
                }
        }
    }
    else{
        switch (roundingMethod) {

            case FLOOR_ROUND:
                cout<<int(realNumber)-1<<endl;
                break;

            case CEILING_ROUND:
                cout<<int(realNumber)<<endl;
                break;

            case ROUND:
                if ((-realNumber + int(realNumber)) >= NEAREST_INTEGER_THRESHOLD){
                    cout<<int(realNumber)-1<<endl;
                    break;
                }
                else if ((-realNumber + int(realNumber)) < NEAREST_INTEGER_THRESHOLD){
                    cout<<int(realNumber)<<endl;
                    break;
                }
        }
    }



    return 0;
}
