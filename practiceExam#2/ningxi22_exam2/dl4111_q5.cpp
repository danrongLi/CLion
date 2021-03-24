#include <iostream>

int* findCommon(int arr1[], int arr2[], int n, int& outArrSize);

using namespace std;

int main() {

    int arr1[10] = {3,1,3,2,6,4};
    int arr2[10] = {5,4,4,3,3,3};
    int n = 6;
    int outArrSize;

    int* commonArr = findCommon(arr1, arr2, n, outArrSize);

    for (int i = 0; i < outArrSize; i += 1){
        cout<<commonArr[i]<<" ";
    }
    cout<<endl;

    delete [] commonArr;
    commonArr = nullptr;

    return 0;
}

int* findCommon(int arr1[], int arr2[], int n, int& outArrSize){
    int* tempArr = new int[n];
    for (int i = 0; i < n; i += 1){
        tempArr[i] = 0;
    }

    for (int i = 0; i < n; i += 1){
        if (tempArr[arr1[i]-1] == 0){
            tempArr[arr1[i]-1] = -1;
        }
    }

    int countCommon = 0;
    for (int i = 0; i < n; i += 1){
        if (tempArr[arr2[i]-1] == -1){
            tempArr[arr2[i]-1] = -2;
            countCommon += 1;
        }
    }

    int* commonArr = new int[countCommon];
    int currentIndex = 0;
    for (int i = 0; i < n; i += 1){
        if (tempArr[i] == -2){
            commonArr[currentIndex] = (i+1);
            currentIndex += 1;
        }
    }

    outArrSize = countCommon;
    delete [] tempArr;
    tempArr = nullptr;

    return commonArr;
}