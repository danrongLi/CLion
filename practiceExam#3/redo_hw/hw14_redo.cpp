#include <iostream>
#include <vector>

using namespace std;

vector<int> findMinMax(vector<int> numbers, int startIndex, int endIndex);

int main(){
    vector<int> numbers = {7,9,6,4,5,3,1};

    vector<int> result = findMinMax(numbers, 0, numbers.size()-1);

    for (int i = 0; i < result.size(); i += 1){
        cout<<result[i]<<" ";
    }
    cout<<endl;

}
vector<int> findMinMax(vector<int> numbers, int startIndex, int endIndex){
    vector<int> result; // min max
    if (startIndex == endIndex){
        result.push_back(numbers[startIndex]);
        result.push_back(numbers[startIndex]);
        return result;
    }
    else if (endIndex-startIndex == 1){
        if (numbers[startIndex] > numbers[endIndex]){
            result.push_back(numbers[endIndex]);
            result.push_back(numbers[startIndex]);
            return result;
        }
        else {
            result.push_back(numbers[startIndex]);
            result.push_back(numbers[endIndex]);
            return result;
        }
    }
    else {
        int middle = (endIndex+startIndex)/2;
        vector<int> firstResult = findMinMax(numbers, startIndex, middle);
        vector<int> secondResult = findMinMax(numbers, middle+1, endIndex);
        if (firstResult[0] < secondResult[0]){
            result.push_back(firstResult[0]);
        }
        else {
            result.push_back(secondResult[0]);
        }
        if (firstResult[1] > secondResult[1]){
            result.push_back(firstResult[1]);
        }
        else {
            result.push_back(secondResult[1]);
        }
        return result;
    }

}