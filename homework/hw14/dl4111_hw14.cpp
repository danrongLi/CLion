#include <iostream>
#include <vector>

using namespace std;

const int MINMAX_COUNT = 2;

vector<int> findMinMax(const vector<int>& myInput, int start, int end);

int main() {

    vector<int> myInput = {7,9,6,4,5,3,1};

    vector<int> result = findMinMax(myInput, 0, 6);

    for (int i = 0; i < result.size(); i += 1){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}
vector<int> findMinMax(const vector<int>& myInput, int start, int end){
    vector<int> result;
    result.resize(MINMAX_COUNT);
    if (start == end){
        result[0] = myInput[start];
        result[1] = myInput[end];
        return result;
    }
    else if ((end-start) == 1){
        if (myInput[start] <= myInput[end]){
            result[0] = myInput[start]; //min
            result[1] = myInput[end]; //max
        }
        else {
            result[0] = myInput[end];
            result[1] = myInput[start];
        }
        return result;
    }
    else {
        int split = (end+start) / 2;
        vector<int> firstHalf = findMinMax(myInput, start, split);
        vector<int> secondHalf = findMinMax(myInput, split+1, end);
        if (firstHalf[0] <= secondHalf[0]){
            result[0] = firstHalf[0];
        }
        else {
            result[0] = secondHalf[0];
        }
        if (firstHalf[1] >= secondHalf[1]){
            result[1] = firstHalf[1];
        }
        else {
            result[1] = secondHalf[1];
        }
        return result;
    }
}

