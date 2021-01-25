#include <iostream>
using namespace std;

int main() {

    cout<<"Enter grades, separated by a space."<<endl;
    cout<<"End the sequence by typing -1:"<<endl;

    bool seenEndOfInput = false;
    int sum = 0;
    int numOfStudents = 0;
    int curr;

    while (seenEndOfInput == false){
        cin>>curr;
        if (curr == -1){
            seenEndOfInput = true;
        }
        else{
            sum += curr;
            numOfStudents += 1;
        }
    }
    double average = (double) sum / (double) numOfStudents;
    cout<<"The class average is: "<<average<<endl;

    return 0;
}
