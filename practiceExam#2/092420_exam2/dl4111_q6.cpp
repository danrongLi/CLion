#include <iostream>
#include <cmath>
using namespace std;

const int TWO = 2;
int bitsArrToInt(int* bitsArr, int bitsArrSize);

int main() {

    int bitsArr[10] = {1,0,0,1,1,0};
    int bitsArrSize = 6;
    int num = bitsArrToInt(bitsArr, bitsArrSize);
    cout<<num<<endl;
    return 0;
}
int bitsArrToInt(int* bitsArr, int bitsArrSize) {

    int previousSum;

    if (bitsArrSize == 1){
        if (bitsArr[0] == 0){
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        previousSum = bitsArrToInt(bitsArr+1, bitsArrSize-1);
        if (bitsArr[0] == 0){
            return previousSum;
        }
        else {
            int currentVal = pow(TWO, bitsArrSize-1);
            return previousSum+currentVal;
        }
    }

}