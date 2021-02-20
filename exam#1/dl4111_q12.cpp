#include <iostream>
using namespace std;

const int INCH_PER_FOOT = 12;
const int FOOT_PER_YARD = 3;
const int YARD_PER_INCH = 36;

int main() {

    int inchesTravelled;
    int daysCount = 1;

    cout<<"Enter the number of inches the snail traveled in day #"<<daysCount<<",\n"
          <<"or type -1 if they reached their destination:"<<endl;

    int currentInches;
    int totalInches = 0;

    cin>>currentInches;
    while (currentInches != -1){
        totalInches += currentInches;
        daysCount += 1;
        cout<<"Enter the number of inches the snail traveled in day #"<<daysCount<<",\n"
            <<"or type -1 if they reached their destination:"<<endl;
        cin>>currentInches;
    }
    int yardNum = totalInches / YARD_PER_INCH;
    int footNum = (totalInches % YARD_PER_INCH) / INCH_PER_FOOT;
    int inchNum = (totalInches % YARD_PER_INCH) % INCH_PER_FOOT;

    cout<<"In "<<daysCount-1<<" days, the snail travelled "
        <<yardNum<<" yards, and "<<footNum<<" feet "
        <<" and "<<inchNum<<" inches."<<endl;

    return 0;
}


