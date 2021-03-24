#include <iostream>

using namespace std;
void printArray(int arr[], int arrSize);
int* firstPosIntsArr(int n, int* arrSizePtr);
int main() {

    int n;
    int* arr;
    int arrSize;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    arr = firstPosIntsArr(n, &arrSize);

    cout<<"The first "<<arrSize<<" positive integers are: ";
    printArray(arr, arrSize);
    cout<<endl;

    delete [] arr;
    arr = nullptr;
    return 0;
}
int* firstPosIntsArr(int n, int* arrSizePtr){
    int* posArr = new int[n];
    for (int i = 0; i < n; i += 1){
        posArr[i] = i+1;
    }
    *arrSizePtr = n;
    return posArr;

}
void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i += 1){
        cout<<arr[i]<<" ";
    }
}
