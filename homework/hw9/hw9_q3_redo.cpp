#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main(){

    int arr[10] = {3,-1,-3,0,6,4};
    int arrSize = 6;

    int outPosArr1;
    int* resultArr1 = getPosNums1(arr, arrSize, outPosArr1);
    for (int i  = 0; i < outPosArr1; i += 1){
        cout<<resultArr1[i]<<" ";
    }
    cout<<endl;
    delete [] resultArr1;
    resultArr1 = nullptr;

    int outPosArr2;
    int* resultArr2 = getPosNums2(arr, arrSize, &outPosArr2);
    for (int i = 0; i < outPosArr2; i += 1){
        cout<<resultArr2[i]<<" ";
    }
    cout<<endl;
    delete [] resultArr2;
    resultArr2 = nullptr;

    int* resultArr3 = nullptr;
    int outPosArr3;
    getPosNums3(arr, arrSize, resultArr3, outPosArr3);
    for (int i = 0; i < outPosArr3; i += 1){
        cout<<resultArr3[i]<<" ";
    }
    cout<<endl;
    delete [] resultArr3;
    resultArr3 = nullptr;

    int* resultArr4 = nullptr;
    int outPosArr4;
    getPosNums4(arr, arrSize, &resultArr4, &outPosArr4);
    for (int i = 0; i < outPosArr4; i += 1){
        cout<<resultArr4[i]<<" ";
    }
    cout<<endl;
    delete [] resultArr4;
    resultArr4 = nullptr;

    return 0;
}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int countPos = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    int* posArr = new int[countPos];
    int currentIndex = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[currentIndex] = arr[i];
            currentIndex += 1;
        }
    }
    *outPosArrPtr = posArr;
    *outPosArrSizePtr = countPos;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int countPos = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    int* posArr = new int[countPos];
    int currentIndex = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[currentIndex] = arr[i];
            currentIndex += 1;
        }
    }
    outPosArr = posArr;
    outPosArrSize = countPos;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int countPos = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    int* posArr = new int[countPos];
    int currentIndex = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[currentIndex] = arr[i];
            currentIndex += 1;
        }
    }
    arr = posArr;
    *outPosArrSizePtr = countPos;
    return arr;
}


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int countPos = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            countPos += 1;
        }
    }
    int* posArr = new int[countPos];
    int currentIndex = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] > 0){
            posArr[currentIndex] = arr[i];
            currentIndex += 1;
        }
    }
    arr = posArr;
    outPosArrSize = countPos;
    return arr;
}