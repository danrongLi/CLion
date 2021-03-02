#include <iostream>
using namespace std;

const int ARR_PHYSICAL_SIZE = 20;
int minInArray(int arr[], int arrSize);
void printMiniIndices(int arr[], int arrSize, int miniValueInArr);
void readArrayData(int outArr[], int arrSize);

int main() {

    int userIntArr[ARR_PHYSICAL_SIZE];
    readArrayData(userIntArr, ARR_PHYSICAL_SIZE);
    int miniValueInArr = minInArray(userIntArr, ARR_PHYSICAL_SIZE);
    printMiniIndices(userIntArr, ARR_PHYSICAL_SIZE, miniValueInArr);
    return 0;

}
int minInArray(int arr[], int arrSize){
    int currentMini = arr[0];
    int i;
    for (i = 0; i < arrSize; i += 1){
        if (arr[i] < currentMini){
            currentMini = arr[i];
        }
    }
    return currentMini;
}

void printMiniIndices(int arr[], int arrSize, int miniValueInArr){
    cout<<"The minimum value is "<<miniValueInArr
        <<", and it is located in the following indices: ";
    int i;
    for (i = 0; i < arrSize; i += 1){
        if (arr[i] == miniValueInArr){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
void readArrayData(int outArr[], int arrSize){
    int i;
    cout << "Please enter " << arrSize << " integers separated by a space:" << endl;

    for (i = 0; i < arrSize; i += 1){
        cin >> outArr[i];
    }
}