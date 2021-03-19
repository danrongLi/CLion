#include <iostream>
using namespace std;

int lowestCost(int arr[], int arrSize);

int main() {

    int arr[10] = {0,3,80,6,57,10};
    int arrSize = 6;

    int lowCost = lowestCost(arr, arrSize);
    cout<<"The lowest cost is: "<<lowCost<<endl;

    return 0;
}

int lowestCost(int arr[], int arrSize){
    int currentLowest;
    if (arrSize == 1){
        return arr[0];
    }
    if (arrSize == 2){
        return arr[1];
    }

    else {
        if (arr[arrSize-1] < arr[arrSize-2]){
            currentLowest = lowestCost(arr, arrSize-2);
        }
        else {
            currentLowest = lowestCost(arr, arrSize-1);
        }
        currentLowest += arr[arrSize-1];
        return currentLowest;
    }
}