#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main() {

    int userInput;

    cout<<"please enter a positive integer >= 2: ";
    cin>>userInput;

    printDivisors(userInput);

    return 0;
}

void printDivisors(int num){

    int count;

    for (count = 1; count <= sqrt(num); count += 1){
        if (num % count == 0){
            cout<<count<<" ";
        }
    }

    for (count = (sqrt(num)+1); count <= num; count += 1){
        if (num % count == 0){
            cout<<count<<" ";
        }
    }

    cout<<endl;
}