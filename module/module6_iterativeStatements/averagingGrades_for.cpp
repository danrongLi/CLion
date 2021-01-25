#include <iostream>
using namespace std;

int main() {

    int numOfStudents, count, curr;

    cout<<"Please enter the number of students in the class: ";
    cin>>numOfStudents;

    int sum = 0;

    cout<<"Please enter the grades, separated by a space:"<<endl;
    for (count = 1; count <= numOfStudents; count++){
        cin>>curr;
        sum += curr;
    }

    double average = (double) sum / (double) numOfStudents;
    cout<<"The average of the grades is: "<<average<<endl;

    return 0;
}
