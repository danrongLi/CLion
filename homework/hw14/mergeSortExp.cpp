#include <iostream>
#include <vector>

using namespace std;

vector<int> findMinMax(const vector<int>& input, int start, int end);

int main() {

    vector<int> myInput = {7,9,6,4,5,3,1};

    vector<int> minMaxResult = findMinMax(myInput, 0, 6);

    for (int i = 0; i < minMaxResult.size(); i += 1){
        cout<<minMaxResult[i]<<" ";
    }
    cout<<endl;

    return 0;
}
void merge(vector<int>& v, vector<int>& temp, int start, int mid, int end) {
    int leftpos = start;
    int rightpos = mid + 1;
    int temppos = start;
    while (leftpos <= mid && rightpos <= end) {
        if (v[leftpos] < v[rightpos])
            temp[temppos++] = v[leftpos++];
        else
            temp[temppos++] = v[rightpos++];
    }
    while (leftpos <= mid)
        temp[temppos++] = v[leftpos++];
    while (rightpos <= mid)
        temp[temppos++] = v[rightpos++];
    for (int i = start; i <= end; i++)
        v[i] = temp[i];

}
void mergeSort(vector<int>& v, vector<int>& temp, int start, int end) {//Theta (N log N)
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(v, temp, start, mid); //sort the two halves, recursively
        mergeSort(v, temp, mid + 1, end);
        merge(v, temp, start, mid, end);
    }
}
void mergeSort(vector<int>& v) { //driver
    vector<int> temp;
    temp.resize(v.size());
    mergeSort(v, temp, 0, v.size() - 1);
}

