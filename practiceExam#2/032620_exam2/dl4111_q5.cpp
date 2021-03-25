#include <iostream>
using namespace std;

void makeDifferenceArray(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN);
void printArray(int arr[], int arrSize);
int main() {

    int srtArr1[6] = {1,2,3,5,7,8};
    int srtArr2[4] = {2,5,6,9};
    int* differenceArr;
    int differenceArrSize;

    makeDifferenceArray(srtArr1, 6, srtArr2, 4, differenceArr, differenceArrSize);

    cout<<"srtArr1: ";
    printArray(srtArr1, 6);

    cout<<"srtArr2: ";
    printArray(srtArr2, 4);

    cout<<"differenceArr: ";
    printArray(differenceArr, differenceArrSize);

    delete [] differenceArr;
    differenceArr = nullptr;


    return 0;
}
void makeDifferenceArray(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN){

    int sizeTemp1 = srtArr1[n1-1];
    int sizeTemp2 = srtArr2[n2-1];
    int newTempSize = sizeTemp1;

    int* temp1Arr = new int[sizeTemp1];
    int* temp2Arr = new int[sizeTemp2];
    int* newTempArr = new int[newTempSize];

    for (int i = 0; i < sizeTemp1; i += 1){
        temp1Arr[i] = 0;
    }
    for (int i = 0; i < sizeTemp2; i += 1){
        temp2Arr[i] = 0;
    }
    for (int i = 0; i < newTempSize; i += 1){
        newTempArr[i] = 0;
    }

    for (int i = 0; i < n1; i += 1){
        if (temp1Arr[srtArr1[i]-1] == 0){
            temp1Arr[srtArr1[i]-1] = -1;
        }
    }

    for (int i = 0; i < n2; i += 1){
        if (temp2Arr[srtArr2[i]-1] == 0){
            temp2Arr[srtArr2[i]-1] = -1;
        }
    }
    int countFound = 0;
    for (int i = 0; i < newTempSize; i += 1){
        if ((temp1Arr[i] == -1) && (temp2Arr[i] == 0)){
            newTempArr[i] = -1;
            countFound += 1;
        }
    }

    int* foundArr = new int[countFound];
    int currentIndex = 0;
    for (int i = 0; i < newTempSize; i += 1){
        if (newTempArr[i] == -1){
            foundArr[currentIndex] = (i+1);
            currentIndex += 1;
        }
    }

    outN = countFound;
    outDifferenceArr = foundArr;

    delete [] temp1Arr;
    delete [] temp2Arr;
    delete [] newTempArr;
    temp2Arr = nullptr;
    temp1Arr = nullptr;
    newTempArr = nullptr;

}
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i += 1){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}