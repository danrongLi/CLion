#include <iostream>
#include <cmath>
using namespace std;

void intToBitsArr(int num, int** outBitsArr, int& outBitsArrSize);
void printArray(int arr[], int arrSize);
const int TWO = 2;
int main() {
    int* bitsArr;
    int bitsArrSize;
    intToBitsArr(38, &bitsArr, bitsArrSize);
    cout<<"bitsArr: ";
    printArray(bitsArr, bitsArrSize);
    delete [] bitsArr;
    bitsArr = nullptr;

    return 0;
}
void intToBitsArr(int num, int** outBitsArr, int& outBitsArrSize){
    int currentDiv = num;
    int countBits = 0;
    while (currentDiv > 0){
        currentDiv = currentDiv / TWO;
        countBits += 1;
    }

    int* bitsArr = new int[countBits];
    int numToDiv = num;
    int initialPow = countBits-1;
    for (int i = 0; i < countBits; i += 1){
        if (numToDiv >= pow(TWO, initialPow)){
            bitsArr[i] = 1;
            numToDiv -= pow(TWO, initialPow);
            initialPow -= 1;
        }
        else if (numToDiv < pow(TWO, initialPow)){
            bitsArr[i] = 0;
            initialPow -= 1;
        }
    }
    *outBitsArr = bitsArr;
    outBitsArrSize = countBits;
}
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i += 1){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}