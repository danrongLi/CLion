#include <iostream>
#include <string>
using namespace std;

const double BETWEEN_BIZHOUR_MF_RATE = 0.40;
const double NOT_BIZHOUR_MF_RATE = 0.25;
const double WEEKENDS_RATE = 0.15;
const int START_BIZHOUR = 8;
const int END_BIZHOUR = 18;

int main() {

    int hour24, minute24, lengthOfCall;
    char temp;
    string dayOfWeek;

    cout<<"Please the day of the week (format: Mo, Tu, We, Th, Fr, Sa, Su): "<<endl;
    cin>>dayOfWeek;

    cout<<"Please enter the time the call started with 24-hour format: "<<endl;
    cin>>hour24>>temp>>minute24;

    cout<<"Please enter the length of the call in minutes as positive integers: "<<endl;
    cin>>lengthOfCall;

    double costOfCall;

    if ((dayOfWeek == "Sa") || (dayOfWeek == "Su")){
        costOfCall = lengthOfCall * WEEKENDS_RATE;
    }
    else{
        if ((hour24 < START_BIZHOUR) || ((hour24 > END_BIZHOUR) || ((hour24 == END_BIZHOUR) && (minute24 != 0)))){
            costOfCall = lengthOfCall * NOT_BIZHOUR_MF_RATE;
        }
        else
            costOfCall = lengthOfCall * BETWEEN_BIZHOUR_MF_RATE;
    }

    cout<<"cost of the call: $"<<costOfCall<<endl;

    return 0;
}
