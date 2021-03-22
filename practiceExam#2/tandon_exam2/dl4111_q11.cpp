#include <iostream>

using namespace std;

void moveZeroes(int nums[], int numSize);

int main() {

    int nums[10] = {0,2,0,1,0};
    int numSize = 5;

    moveZeroes(nums, numSize);

    for (int i = 0; i < numSize; i += 1){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}

void moveZeroes(int nums[], int numSize){
    int frontCount = 0;
    int endCount = numSize-1;

    while ((endCount-frontCount) > 1){
        if (nums[frontCount] == 0){
            int temp = nums[frontCount];
            nums[frontCount] = nums[endCount];
            nums[endCount] = temp;
            endCount -= 1;
        }
        else {
            frontCount += 1;
        }
    }
}