#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUM = 10;
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNum2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNum3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printResult1(int arrSize, int outPosArr1Size, int * arr1);
void printResult2(int arrSize, int* outPosArrSizePtr, int * arr2);
void printResult3(int arrSize, int outPosArrSize, int * arr3);
void printResult4(int arrSize, int* arr4, int outPosArr4Size);

int main() {

//    test input
    int arrSize = 6;
    int arrBefore[MAX_NUM] = {3, -1, -3, 0, 6, 4};

//    function 1
    int outPosArr1Size;
    int* arr1 = getPosNums1(arrBefore, arrSize, outPosArr1Size);
    printResult1(arrSize, outPosArr1Size, arr1);

//    function 2
    int outPosArr2Size;
    int* arr2 = getPosNum2(arrBefore, arrSize, &outPosArr2Size);
    printResult2(arrSize, &outPosArr2Size, arr2);

//    function 3
    int* arr3 = nullptr;
    int outPosArr3Size;
    getPosNum3(arrBefore, arrSize, arr3, outPosArr3Size);
    printResult3(arrSize, outPosArr3Size, arr3);

//    function 4
    int* arr4 = nullptr;
    int outPosArr4Size;
    getPosNums4(arrBefore,arrSize, &arr4, &outPosArr4Size);
    printResult4(arrSize, arr4, outPosArr4Size);

//    deleting ptr
    delete[] arr1;
    arr1 = nullptr;
    delete[] arr2;
    arr2 = nullptr;
    delete[] arr3;
    arr3 = nullptr;
    delete[] arr4;
    arr4 = nullptr;

    return 0;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int countPos = 0;
    int* posArr = nullptr;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    posArr = new int[countPos];
    int countAgain = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[countAgain] = arr[i];
            countAgain += 1;
        }
    }
    *outPosArrPtr = posArr;
    *outPosArrSizePtr = countPos;
}

void getPosNum3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int countPos = 0;
    int* posArr = nullptr;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    posArr = new int[countPos];
    int countAgain = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[countAgain] = arr[i];
            countAgain += 1;
        }
    }

    outPosArr = posArr;
    outPosArrSize = countPos;
}

int* getPosNum2(int* arr, int arrSize, int* outPosArrSizePtr){
    int countPos = 0;
    int* posArr = nullptr;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    posArr = new int[countPos];
    int countAgain = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[countAgain] = arr[i];
            countAgain += 1;
        }
    }
    *outPosArrSizePtr = countPos;
    return posArr;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int countPos = 0;
    int* posArr = nullptr;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    posArr = new int[countPos];
    int countAgain = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[countAgain] = arr[i];
            countAgain += 1;
        }
    }
    outPosArrSize = countPos;
    return posArr;
}
void printResult4(int arrSize, int* arr4, int outPosArr4Size){
    cout<<endl;
    cout<<"function 4 result"<<endl;
    cout << "original size: " << arrSize << endl;
    cout<<"new size: "<<outPosArr4Size<<endl;
    cout<<"new array: ";
    for (int i = 0; i < outPosArr4Size; i += 1){
        cout<<arr4[i]<<" ";
    }
    cout<<endl;
}
void printResult3(int arrSize, int outPosArrSize, int * arr3){
    cout<<endl;
    cout<<"function 3 result"<<endl;
    cout << "original size: " << arrSize << endl;
    cout<<"new size: "<<outPosArrSize<<endl;
    cout<<"new array: ";
    for (int i = 0; i < outPosArrSize; i += 1){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}

void printResult2(int arrSize, int* outPosArrSizePtr, int * arr2){
    cout<<endl;
    cout<<"function 2 result"<<endl;
    cout << "original size: " << arrSize << endl;
    cout<<"new size: "<<*outPosArrSizePtr<<endl;
    cout<<"new array: ";
    for (int i = 0; i < *outPosArrSizePtr; i += 1){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
}

void printResult1(int arrSize, int outPosArr1Size, int * arr1){
    cout<<"function 1 result"<<endl;
    cout << "original size: " << arrSize << endl;
    cout<<"new size: "<<outPosArr1Size<<endl;
    cout<<"new array: ";
    for (int i = 0; i < outPosArr1Size; i += 1){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}