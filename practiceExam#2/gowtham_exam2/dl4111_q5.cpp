#include <iostream>
using namespace std;

double findMedian(int arr[], int n);
int main(){

    int arr[10] = {3,5,3,7,1,7,6};
    int n = 7;
    double median = findMedian(arr, n);
    cout<<median<<endl;

    return 0;
}
double findMedian(int arr[], int n){
    int* tempArr = new int[n];
    for (int i = 0; i < n; i += 1){
        tempArr[i] = 0;
    }
    int countFound = 0;
    for (int i = 0; i < n; i += 1){
        if (tempArr[arr[i]-1] == 0){
            tempArr[arr[i]-1] = -1;
            countFound += 1;
        }
    }
    int currentIndex = 0;
    int* medianArr = new int[countFound];
    for (int i = 0; i < n; i += 1){
        if (tempArr[i] == -1){
            medianArr[currentIndex] = (i+1);
            currentIndex += 1;
        }
    }

    int medianPos = n/2;
    double median = medianArr[medianPos-1];
    delete [] tempArr;
    delete [] medianArr;
    medianArr = nullptr;
    tempArr = nullptr;

    return median;
}