#include <iostream>
using namespace std;

double calcArrayAverage(int arr[], int arrSize);
void printAboveValue(int arr[], int arrSize, double value);
int readArrayData(int outArr[], int outArrPhysicalSize);
const int MAX_NUMBER_OF_VALUES = 5;
int main() {
    int valuesArray[MAX_NUMBER_OF_VALUES];
    int valuesArraySize;
    double average;

    // read data (will be implemented last)
    valuesArraySize = readArrayData(valuesArray, MAX_NUMBER_OF_VALUES);

    // calculate average
    average = calcArrayAverage(valuesArray, valuesArraySize);
    cout<<"The average is "<<average<<endl;

    // print above average
    printAboveValue(valuesArray, valuesArraySize, average);

    return 0;
}

int readArrayData(int outArr[], int outArrPhysicalSize){
    int i;
    int outArrSize;

    cout<<"Please enter the number of values (no more than "<<outArrPhysicalSize<<")"<<endl;
    cin>>outArrSize;

    cout<<"Enter "<<outArrSize<<" positive integers separated by a space"<<endl;
    for(i = 0; i < outArrSize; i += 1)
        cin>>outArr[i];

    return outArrSize;
}


double calcArrayAverage(int arr[], int arrSize){
    int i;
    int sum;
    double average;

    sum = 0;
    for(i = 0; i < arrSize; i += 1)
        sum += arr[i];

    average = (double)sum / (double)arrSize;
    return average;
}

void printAboveValue(int arr[], int arrSize, double value){
    int i;

    cout<<"The values above "<<value<<" are ";
    for(i = 0; i < arrSize; i += 1){
        if(arr[i] > value)
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}