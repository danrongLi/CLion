#include <iostream>
using namespace std;

void makeXorArray(int* srtArr1, int n1, int* srtArr2, int n2, int** outXorArr, int* outN);
void printArray(int arr[], int arrSize);
//    Assuming the array elements all <= 10
const int MAX_ELEMENT = 10;

int main() {

    int srtArr1[6] = {1, 2, 3, 5, 7, 8};
    int srtArr2[4] = {2, 5, 6, 9};
    int* xorArr;
    int xorArrSize;
    makeXorArray(srtArr1, 6, srtArr2, 4, &xorArr, &xorArrSize);
    cout<<"srtArr1:  ";
    printArray(srtArr1, 6);
    cout<<"srtArr2:  ";
    printArray(srtArr2, 4);
    cout<<"xorArr:  ";
    printArray(xorArr, xorArrSize);
    delete []xorArr;
    xorArr = nullptr;

    return 0;
}
void makeXorArray(int* srtArr1, int n1, int* srtArr2, int n2, int** outXorArr, int* outN){

    int* tempArr = new int[MAX_ELEMENT];
    for (int i = 0; i < MAX_ELEMENT; i += 1){
        tempArr[i] = 0;
    }
    int countFound = 0;
    for (int i = 0; i < n1; i += 1){
        if (tempArr[srtArr1[i]-1] == 0){
            tempArr[srtArr1[i]-1] = -1;
            countFound += 1;
        }
    }

    for (int i = 0; i < n2; i += 1){
        if (tempArr[srtArr2[i]-1] == -1){
            tempArr[srtArr2[i]-1] = -2;
            countFound -= 1;
        }
        else {
            tempArr[srtArr2[i]-1] = -1;
            countFound += 1;
        }
    }


    int* foundArr = new int[countFound];
    int currentIndex = 0;
    for (int i = 0; i < MAX_ELEMENT; i += 1){
        if (tempArr[i] == -1){
            foundArr[currentIndex] = (i+1);
            currentIndex += 1;
        }
    }

    *outXorArr = foundArr;
    *outN = countFound;

    delete [] tempArr;
    tempArr = nullptr;

}
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i += 1){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}