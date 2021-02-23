#include <iostream>
using namespace std;

const int MAX_CLASS_SIZE = 60;

int main() {
    int numOfStudents;
    int gradeList[MAX_CLASS_SIZE];
    int currentGrade;
    int ind;

    cout<<"Please enter the number of students in the class (No more than "<<MAX_CLASS_SIZE<<" ):"<<endl;
    cin>>numOfStudents;
    cout<<"Please enter the grades separated by a space:"<<endl;

    for (ind = 0; ind < numOfStudents; ind += 1){
        cin>>currentGrade;
        gradeList[ind] = currentGrade;
    }

    int sum = 0;
    for (ind = 0; ind < numOfStudents; ind += 1){
        sum += gradeList[ind];
    }

    double average = (double) sum / (double) numOfStudents;

    cout<<"The class average is: "<<average<<endl;
    cout<<"The grades above average are: ";

    for (ind = 0; ind < numOfStudents; ind += 1){
        if (gradeList[ind] > average){
            cout<<gradeList[ind]<<" ";
        }
    }

    return 0;
}
