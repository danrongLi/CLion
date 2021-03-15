#include <iostream>
using namespace std;

bool areAllEven(int arr[], int n);
int main(){

    int arr[4] = {14, 2, 4, 6};
    if (areAllEven(arr,4)){
        cout<<"yes"<<endl;
    }
    else {
        cout<<"nope"<<endl;
    }

    return 0;
}
bool areAllEven(int arr[], int n){
    bool res;
    if (n == 1){
        return (arr[0]%2 == 0);
    }
    else {
        res = areAllEven(arr, n-1);
        if (res){
            return (arr[n-1]%2 == 0);
        }
        else {
            return false;
        }

    }
}