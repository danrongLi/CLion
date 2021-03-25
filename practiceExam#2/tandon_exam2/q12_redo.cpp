#include <iostream>
#include <algorithm>
using namespace std;

int maxZeroLength(int nums[], int len, int startIdx);

int main() {

    int nums[10] = {0,0,0,0,1,0,1,0,0,1};

    int len = 10;

    int startIdx = 0;

    int result = maxZeroLength(nums, len, startIdx);
    cout<<result<<endl;

    return 0;
}

int maxZeroLength(int nums[], int len, int startIdx){
    int currentCount = 0;
    int currentIndex = startIdx;

    if (currentIndex >= len){
        return currentCount;
    }
    else {
        while (nums[currentIndex] != 0 && currentIndex < len){
            currentIndex += 1;
        }
        while (nums[currentIndex] == 0 && currentIndex < len){
            currentCount += 1;
            currentIndex += 1;
        }

        return std::max(currentCount, maxZeroLength(nums, len, currentIndex));
    }


}
