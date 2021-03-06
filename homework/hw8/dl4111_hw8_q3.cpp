#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;

}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i += 1){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize){
    int frontCount = 0;
    int endCount = arrSize - 1;
    if ((arrSize % 2) == 0){
        while ((endCount - frontCount) >= 1){
            int temp = arr[frontCount];
            arr[frontCount] = arr[endCount];
            arr[endCount] = temp;
            endCount -= 1;
            frontCount += 1;
        }
    }
    else {
        while ((endCount - frontCount) >= 2){
            int temp = arr[frontCount];
            arr[frontCount] = arr[endCount];
            arr[endCount] = temp;
            endCount -= 1;
            frontCount += 1;
        }
    }
}
void removeOdd(int arr[], int& arrSize){
    int i;
    int outI = 0;
    for (i = 0; i < arrSize; i += 1){
        if ((arr[i] % 2 == 0)){
            arr[outI] = arr[i];
            outI += 1;
        }
    }
    arrSize = outI;
}
void splitParity(int arr[], int arrSize){
    int frontCount = 0;
    int endCount = arrSize - 1;
    while (frontCount < endCount){
        if ((arr[frontCount] % 2 == 0) && (arr[endCount] % 2 != 0)){
            int temp = arr[frontCount];
            arr[frontCount] = arr[endCount];
            arr[endCount] = temp;
        }
        else if ((arr[frontCount] % 2 == 0) && (arr[endCount] % 2 == 0)){
            endCount -= 1;
        }
        else {
            frontCount += 1;
            endCount -= 1;
        }
    }
}