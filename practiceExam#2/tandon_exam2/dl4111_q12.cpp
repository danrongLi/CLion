#include <iostream>
#include <algorithm>

using namespace std;

int maxZeroLength(int nums[], int len, int startIdx);
int maxZeroLength2(int nums[], int len, int startIdx);

int main() {

    int nums[10] = {0,0,0,0,1,0,1,0,0,1};

    int len = 10;

    int startIdx = 0;

    int maxNum = maxZeroLength2(nums, len, startIdx);

    cout<<maxNum;

    return 0;
}

int maxZeroLength(int nums[], int len, int startIdx){

    int currentMax = 0;
    int currentZeros = 0;
    bool newCount = false;
    int previousMax = 0;

    if (len == 1){
        if (nums[0] == 0){
            currentZeros += 1;
        }
        else {
            currentZeros = 0;
        }
        currentMax = std::max(currentZeros,currentMax);
        return currentMax;
    }
    if (len == 0){
        return currentMax;
    }

    else {
        for (int i = (len-1); (i >= 0) && (!newCount); i -= 1){
            if (nums[i] != 0){
                newCount = true;
                currentZeros += 0;
            }
            else {
                currentZeros += 1;
            }
        }
        currentMax = std::max(currentZeros, currentZeros);
        if (newCount){
            previousMax = maxZeroLength(nums, len-currentZeros-1, startIdx);
        }
        else {
            previousMax = maxZeroLength(nums, len-currentZeros, startIdx);
        }
        currentMax = std::max(currentMax, previousMax);
        return currentMax;
    }

}

int maxZeroLength2(int nums[], int len, int startIdx){

    int count = 0;
    int i = startIdx;

    while (nums[i] != 0 && i < len){
        i += 1;
    }
    while (nums[i] == 0 && i < len){
        count += 1;
        i += 1;
    }
    if (i >= len){
        return count;
    }
    return std::max(count, maxZeroLength2(nums, len, i));

}
