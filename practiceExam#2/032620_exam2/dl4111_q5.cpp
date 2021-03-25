//#include <iostream>
//using namespace std;
//
//void makeDifferenceArray(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN);
//void printArray(int arr[], int arrSize);
//int main() {
//
//    int srtArr1[6] = {1,2,3,5,7,8};
//    int srtArr2[4] = {2,5,6,9};
//    int* differenceArr;
//    int differenceArrSize;
//
//    makeDifferenceArray(srtArr1, 6, srtArr2, 4, differenceArr, differenceArrSize);
//    cout<<"srtArr1: ";
//    printArray(srtArr1, 6);
//
//    cout<<"srtArr2: ";
//    printArray(srtArr2, 4);
//
//    cout<<"differenceArr: ";
//    printArray(differenceArr, differenceArrSize);
//
//    delete [] differenceArr;
//    differenceArr = nullptr;
//
//
//    return 0;
//}
//
//void makeDifferenceArray(int* srtArr1, int n1, int* srtArr2, int n2, int*& outDifferenceArr, int& outN){
//
//    int sizeTemp1 = srtArr1[n1-1];
//    int sizeTemp2 = srtArr2[n2-1];
//    int newTempSize = sizeTemp1;
//
//    int* temp1Arr = new int[sizeTemp1];
//    int* temp2Arr = new int[sizeTemp2];
//    int* newTempArr = new int[newTempSize];
//
//    for (int i = 0; i < sizeTemp1; i += 1){
//        temp1Arr[i] = 0;
//    }
//    for (int i = 0; i < sizeTemp2; i += 1){
//        temp2Arr[i] = 0;
//    }
//    for (int i = 0; i < newTempSize; i += 1){
//        newTempArr[i] = 0;
//    }
//
//    for (int i = 0; i < n1; i += 1){
//        if (temp1Arr[srtArr1[i]-1] == 0){
//            temp1Arr[srtArr1[i]-1] = -1;
//        }
//    }
//
//    for (int i = 0; i < n2; i += 1){
//        if (temp2Arr[srtArr2[i]-1] == 0){
//            temp2Arr[srtArr2[i]-1] = -1;
//        }
//    }
//    int countFound = 0;
//    for (int i = 0; i < newTempSize; i += 1){
//        if ((temp1Arr[i] == -1) && (temp2Arr[i] == 0)){
//            newTempArr[i] = -1;
//            countFound += 1;
//        }
//    }
//
//    int* foundArr = new int[countFound];
//    int currentIndex = 0;
//    for (int i = 0; i < newTempSize; i += 1){
//        if (newTempArr[i] == -1){
//            foundArr[currentIndex] = (i+1);
//            currentIndex += 1;
//        }
//    }
//
//    outN = countFound;
//    outDifferenceArr = foundArr;
//
//    delete [] temp1Arr;
//    delete [] temp2Arr;
//    delete [] newTempArr;
//    temp2Arr = nullptr;
//    temp1Arr = nullptr;
//    newTempArr = nullptr;
//
//}
//void printArray(int arr[], int arrSize){
//    for (int i = 0; i < arrSize; i += 1){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//}

/*
Make a function that takes two sorted arrays and in linear time (n1 + n2) constructs an XOR array.
*/

#include <iostream>

using namespace std;

void makeXORArray(int* srtArr1, int* srtArr2, int n1, int n2, int** outXORArr, int* outN) {
    // First off we know that the maximum physical size of this array possible is if both input arrays are unique, thus n1 + n2.
    int* outArr = new int[n1 + n2];
    // Logical size starts off at zero.
    int size = 0;
    // Logic essentially follows that we just go through each array and if at any point both numbers are same, we skip over them. Else we add to the array.
    int s1 = 0, s2 = 0;
    while(s1 < n1 && s2 < n2) {
        // If the second array has a larger item, we increment the first array position and copy over that item.
        if(srtArr1[s1] < srtArr2[s2]) {
            outArr[size++] = srtArr1[s1++];
        } else if(srtArr1[s1] > srtArr2[s2]) {
            outArr[size++] = srtArr2[s2++];
        } else { // They are both equal.
            s1++;
            s2++;
        }
    }
    // Process any remaining numbers.
    while(s1 < n1){
        outArr[size++] = srtArr1[s1++];
    }
    while(s2 < n2){
        outArr[size++] = srtArr2[s2++];
    }
    // Copy over the size.
    *outN = size;
    *outXORArr = outArr;
    outArr = nullptr;
}

void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int a1[] = {1, 2, 3, 5, 7, 8};
    int a2[] = {2, 5, 6, 9};
    print(a1, 6);
    print(a2, 4);
    int out;
    int* res;
    makeXORArray(a1, a2, 6, 4, &res, &out);
    print(res, out);
    return 0;
}