#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {

    int arr[10] = {2, -1 , 3, 10};
    int arrSize = 4;

    int sumSqr = sumOfSquares(arr, arrSize);
    cout<<"part a, sum of squares is: "<<sumSqr<<endl;

    bool ifSorted = isSorted(arr, arrSize);
    if (ifSorted){
        cout<<"part b, elements are sorted in ascending order"<<endl;
    }
    else {
        cout<<"part b, elements are NOT sorted in ascending order"<<endl;
    }

    return 0;
}
int sumOfSquares(int arr[], int arrSize){
    int currentSumOfSquare;
    if (arrSize == 1){
        return pow(arr[0],2);
    }
    else {
        currentSumOfSquare = sumOfSquares(arr, arrSize-1);
        currentSumOfSquare += pow(arr[arrSize-1], 2);
        return currentSumOfSquare;
    }
}
bool isSorted(int arr[], int arrSize){
    bool ifSorted;
    if (arrSize == 1){
        return true;
    }
    else {
        ifSorted = isSorted(arr, arrSize-1);
        if (!ifSorted){
            return false;
        }
        else {
            if (arr[arrSize-1] >= arr[arrSize-2]){
                return true;
            }
            else {
                return false;
            }
        }
    }
}