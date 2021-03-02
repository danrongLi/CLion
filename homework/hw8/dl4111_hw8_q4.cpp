#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int DIGIT = 5;
const int DIGITS = 10;
const int MY_PIN[DIGIT] = {1,2,3,4,5};
void getMyNum(int digitsNum, int outMyNum[]);
void printMyNum(int digitsNum, int myNum[]);
void readUserNum(int digitNum, int outUserNum[]);
bool checkMyUser(int myNum[], int userNum[], int digitNum);

int main() {

    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN:\t"<<"0 1 2 3 4 5 6 7 8 9"<<endl;
    cout<<"NUM:\t";

    srand(time(0));

    int myNum[DIGITS];
    getMyNum(DIGITS, myNum);
    printMyNum(DIGITS, myNum);

    int userNum[DIGIT];
    readUserNum(DIGIT, userNum);

    bool correctPin = checkMyUser(myNum, userNum, DIGIT);
    if (correctPin){
        cout<<"Your PIN is correct"<<endl;
    }
    else {
        cout<<"You PIN is not correct"<<endl;
    }

    return 0;

}

bool checkMyUser(int myNum[], int userNum[], int digitNum){
    bool isCorrect = true;
    int i = 0;
    while (isCorrect && (i < digitNum)){
        if (myNum[MY_PIN[i]] != userNum[i]){
            isCorrect = false;
        }
        i += 1;
    }
    return isCorrect;
}

void readUserNum(int digitNum, int outUserNum[]){
    int inputTotal;
    cin>>inputTotal;
    int currentDiv = inputTotal / 10;
    int currentMod;
    int i = 0;
    while ((currentDiv > 0) && (i < digitNum)){
        currentMod = inputTotal % 10;
        currentDiv = inputTotal / 10;
        inputTotal = currentDiv;
        outUserNum[digitNum-(i+1)] = currentMod;
        i += 1;
    }

}

void printMyNum(int digitsNum, int myNum[]){
    for (int i = 0; i < digitsNum; i += 1){
        cout<<myNum[i]<<" ";
    }
    cout<<endl;
}

void getMyNum(int digitsNum, int outMyNum[]){
    for (int i = 0; i < digitsNum; i += 1){
        outMyNum[i] = (rand() % 3) + 1;
    }
}
