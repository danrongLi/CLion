#include <iostream>
using namespace std;

int lowestCost(int arr[], int arrSize);
int getSmaller(int x, int y);

int main() {

    int arr[10] = {0, 56, 55, 54, 53, 52, 51, 50};
    int arrSize = 8;

    int lowCost = lowestCost(arr, arrSize);
    cout<<"The lowest cost is: "<<lowCost<<endl;

    return 0;
}

int getSmaller(int x, int y){
    if (x < y){
        return x;
    }
    else {
        return y;
    }
}

int lowestCost(int arr[], int arrSize){

    if (arrSize <= 3){
        return arr[arrSize-1];
    }

    return getSmaller(lowestCost(arr, arrSize-1), lowestCost(arr, arrSize-2)) + arr[arrSize-1];
}
