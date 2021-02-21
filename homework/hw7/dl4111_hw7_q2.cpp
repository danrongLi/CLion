#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {

    int inputM;
    cout<<"Please enter a positive >= 2 integer:"<<endl;
    cin>>inputM;

    int currentInt;
    cout<<"Perfect numbers between 2 and "<<inputM<<":"<<endl;
    for (currentInt = 2; currentInt <= inputM; currentInt += 1){
        if (isPerfect(currentInt)){
            cout<<currentInt<<" ";
        }
    }
    cout<<endl;
    cout<<"Amicable numbers between 2 and "<<inputM<<":"<<endl;
    for (currentInt = 2; currentInt <= inputM; currentInt += 1){
        int countDivs, sumDivs;
        analyzeDividors(currentInt, countDivs, sumDivs);
        if ((sumDivs >= currentInt) && (sumDivs <= inputM)){
            int countDivs1, sumDivs1;
            analyzeDividors(sumDivs, countDivs1, sumDivs1);
            if ((currentInt == sumDivs1) && (currentInt != sumDivs)){
                cout<<currentInt<<" ";
                cout<<sumDivs<<endl;
            }
        }
    }

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){

    int countDivs = 0;
    int currentDivs;
    int sumDivs = 0;

    for (currentDivs = 1; currentDivs <= (int) sqrt(num); currentDivs += 1){
        if (num%currentDivs == 0){
            countDivs += 1;
            sumDivs += currentDivs;
        }
    }
    for (currentDivs = ((int) sqrt(num)+1); currentDivs < num; currentDivs += 1){
        if (num%currentDivs == 0){
            countDivs += 1;
            sumDivs += currentDivs;
        }
    }

    outCountDivs = countDivs;
    outSumDivs = sumDivs;

}

bool isPerfect(int num){

    int countDivs, sumDivs;

    analyzeDividors(num, countDivs, sumDivs);

    if (num == sumDivs){
        return true;
    }
    else {
        return false;
    }
}
