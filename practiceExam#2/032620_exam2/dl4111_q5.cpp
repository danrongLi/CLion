#include <iostream>
using namespace std;

void makeDifferenceArray1(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN);
void makeDifferenceArray2(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN);
void printArray(int arr[], int arrSize);
int main() {

    int srtArr1[6] = {1,2,3,5,7,8};
    int srtArr2[4] = {2,5,6,9};
    int* differenceArr;
    int differenceArrSize;

    makeDifferenceArray2(srtArr1, 6, srtArr2, 4, differenceArr, differenceArrSize);
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
void makeDifferenceArray2(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN){

    int* tempArr = new int[n1+n2];
    int* onlyArr1 = new int[n1];
    int* onlyArr2 = new int[n2];

    int logicalSize = 0;
    int s1 = 0;
    int s2 = 0;

    int currentIndex1 = 0;
    int currentIndex2 = 0;

    while ((s1<n1) && (s2<n2)){
        if (srtArr1[s1] < srtArr2[s2]){
            tempArr[logicalSize] = srtArr1[s1];
            onlyArr1[currentIndex1] = srtArr1[s1];
            currentIndex1 += 1;
            logicalSize += 1;
            s1 += 1;
        }
        else if (srtArr2[s2] < srtArr1[s1]){
            tempArr[logicalSize] = srtArr2[s2];
            onlyArr2[currentIndex2] = srtArr2[s2];
            currentIndex2 += 1;
            s2 += 1;
            logicalSize += 1;
        }
        else {
            s1 += 1;
            s2 += 1;
        }
    }
    while (s1<n1){
        tempArr[logicalSize] = srtArr1[s1];
        onlyArr1[currentIndex1] = srtArr1[s1];
        currentIndex1 += 1;
        s1 += 1;
        logicalSize += 1;
    }
    while (s2<n2){
        tempArr[logicalSize] = srtArr2[s2];
        onlyArr2[currentIndex2] = srtArr2[s2];
        currentIndex2 += 1;
        s2 += 1;
        logicalSize += 1;
    }

    outDifferenceArr = onlyArr1;
    outN = currentIndex1;

}
void makeDifferenceArray1(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN){

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
