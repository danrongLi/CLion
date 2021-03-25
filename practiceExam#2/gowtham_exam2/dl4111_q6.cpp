#include <iostream>
using namespace std;

int findFirstPosition(int arr[], int arrSize, int elem);

int main(){

    int arr[10] = {2, 15, 3, 8, 3, 10, 6, 23, 12, 32};
    int arrSize = 10;
    cout<<findFirstPosition(arr, arrSize, 3)<<endl;
    cout<<findFirstPosition(arr, arrSize, 7)<<endl;

    return 0;
}

int findFirstPosition(int arr[], int arrSize, int elem){

    int previousResult;

    if (arrSize == 1){
        if (arr[arrSize-1] == elem){
            return arrSize-1;
        }
        else {
            return -1;
        }
    }
    else {
        previousResult = findFirstPosition(arr, arrSize-1, elem);
        if (previousResult == -1){
            if (arr[arrSize-1] == elem){
                return arrSize-1;
            }
            else {
                return -1;
            }
        }
        else {
            return previousResult;
        }
    }



}