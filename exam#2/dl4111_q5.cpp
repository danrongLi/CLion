// Danrong Li dl4111
#include <iostream>
#include <vector>
using namespace std;

void createVector(vector<int>& studentID, vector<int>& studentGrade);
void findResult(vector<int>studentGrade, vector<int> studentID);

int main() {

    cout<<"Please enter a non-empty sequence of lines."<<endl;
    cout<<"Each line should have a student ID and their grade (0-100), separated by a space."<<endl;
    cout<<"To indicate the end of the input, enter -1 as a student ID:"<<endl;


    vector<int> studentID;
    vector<int> studentGrade;
    createVector(studentID, studentGrade);
    findResult(studentGrade, studentID);

    return 0;
}

void createVector(vector<int>& studentID, vector<int>& studentGrade) {
    int stuID;
    int stuGrade;
    bool seenEndOfLine = false;


    while(!seenEndOfLine){
        cin>>stuID;
        if (stuID == -1){
            seenEndOfLine = true;
        }
        else{cin>>stuGrade;}
        cin.ignore(1);

        studentID.push_back(stuID);
        studentGrade.push_back(stuGrade);

    }
}

void findResult(vector<int>studentGrade, vector<int> studentID){
    int highestScore = 0;
    for (int i = 0; i < studentGrade.size(); i += 1){
        if (studentGrade[i] > highestScore){
            highestScore = studentGrade[i];
        }
    }
    vector<int> highestStudent;
    for (int i = 0; i < studentID.size(); i += 1){
        if (studentGrade[i] == highestScore){
            highestStudent.push_back(studentID[i]);
        }
    }

    cout<<"The highest grade is "<<highestScore<<"."<<endl;
    cout<<"The students with grade "<<highestScore<<" are:";
    for (int i = 0; i < highestStudent.size(); i += 1){
        if (highestStudent[i] != -1){
            cout<<" "<<highestStudent[i];
        }
    }
    cout<<"."<<endl;
}
