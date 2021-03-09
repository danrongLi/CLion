#include <iostream>
using namespace std;

const int MAX_NUM = 10;
void oddsKeepEvensFlip(int arr[], int arrSize);
void printResult(int arrSize, int arrBefore[]);
int main() {

    int arrSize = 6;
    int arrBefore[MAX_NUM] = {5, 2, 11, 7, 6, 4};
    oddsKeepEvensFlip(arrBefore, arrSize);
    printResult(arrSize, arrBefore);

    return 0;
}
void printResult(int arrSize, int arrBefore[]){
    for(int i = 0; i < arrSize; i += 1){
        cout<<arrBefore[i]<<" ";
    }
    cout<<endl;
}
void oddsKeepEvensFlip(int arr[], int arrSize){
    int oddsCount = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] % 2 != 0){
            oddsCount += 1;
        }
    }

    int oddsArr[oddsCount];
    int currentIndexOdd = 0;
    for (int i = 0; i < arrSize; i += 1){
        if (arr[i] % 2 != 0){
            oddsArr[currentIndexOdd] = arr[i];
            currentIndexOdd += 1;
        }
    }
    int evensCount = arrSize - oddsCount;

    int evensArr[evensCount];
    int currentIndexEven = 0;
    for (int i = arrSize-1; i >= 0; i -= 1){
        if (arr[i] % 2 == 0){
            evensArr[currentIndexEven] = arr[i];
            currentIndexEven += 1;
        }
    }

    int arrSort[arrSize];
    for (int i = 0; i < oddsCount; i += 1){
        arrSort[i] = oddsArr[i];
    }
    for (int i = oddsCount; i < arrSize; i += 1){
        arrSort[i] = evensArr[i-oddsCount];
    }

    for (int i = 0; i < arrSize; i += 1){
        arr[i] = arrSort[i];
    }
}