// Danrong Li dl4111
#include <iostream>
using namespace std;

int palindromeDistance(int* arr, int n);
int main() {

    int arr[10] = {1,3,6,6,5,2};
    int n = 6;

    int resPal = palindromeDistance(arr, n);

    cout<<resPal<<endl;

    return 0;
}
int palindromeDistance(int* arr, int n){
    int previousResult;
    if (n == 2){
        if (arr[0] == arr[1]){
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        previousResult = palindromeDistance(arr+1, n-2);
        if (arr[0] == arr[n-1]){
            return previousResult;
        }
        else {
            return previousResult+1;
        }
    }
}