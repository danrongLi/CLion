#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {

    int testArr[10] = {3,1,3,0,6,4};
    int testN = 6;
    int reArrSize;
    int* missingArr = findMissing(testArr, testN, reArrSize);

    cout<<"new size: "<<reArrSize<<endl;

    cout<<"array: ";

    for (int i = 0; i < reArrSize; i += 1){
        cout<<missingArr[i]<<" ";
    }
    cout<<endl;

    delete [] missingArr;
    missingArr = nullptr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int* missingArr = nullptr;
    int* allArr =  new int[n+1];
    for (int i = 0; i <= n; i += 1){
        allArr[i] = i;
    }

    int missingCount = n+1;
    for (int i = 0; i < n; i += 1){
        if (allArr[arr[i]] != -1){
            allArr[arr[i]] = -1;
            missingCount -= 1;
        }
    }


    missingArr = new int[missingCount];
    int missingIndex = 0;
    for ( int i = 0; i <= n; i += 1){
        if (allArr[i] != -1){
            missingArr[missingIndex] = allArr[i];
            missingIndex += 1;
        }
    }

    delete [] allArr;
    allArr = nullptr;

    resArrSize = missingCount;
    return missingArr;


}

