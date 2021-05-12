#include <iostream>
#include <vector>
#include <string>

using namespace std;
void swap(int& a, int& b);

class Sorting{
public:
    virtual void sort(vector<int>& data) = 0;
    virtual string worst_case_runtime() = 0;

protected:
    vector<int> data;
};

class InsertionSort: public Sorting{
public:
    virtual void sort(vector<int>& data);
    virtual string worst_case_runtime(){return "O(n^2)";}
private:

};

void InsertionSort::sort(vector<int>& data) {
    for (int iterator = 1; iterator < data.size(); iterator += 1){
        int current = data[iterator];
        int indexPred = iterator - 1;
        while (indexPred >= 0 && data[indexPred] > current){
            data[iterator] = data[indexPred];
            iterator -= 1;
            indexPred -= 1;
        }
        data[indexPred+1] = current;
    }
    for (int i = 0; i < data.size(); i += 1){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

class QuickSort: public Sorting{
public:
    virtual void sort(vector<int>& data){quickSort(data, 0, data.size()-1);}
    virtual string worst_case_runtime(){return "O(n^2)";}

    void quickSort(vector<int>& data, int low, int high){
        if (low < high){
            int partitionIndex = partition(data, low, high);
            quickSort(data, 0, partitionIndex-1);
            quickSort(data, partitionIndex+1, high);
        }
    }

    int partition(vector<int>& test, int low, int high){
        int i = low-1;
        int pivot = test[high];
        for (int j = low; j <= high-1; j += 1){
            if(test[j] <= pivot){
                i += 1;
                swap(test[i],test[j]);
            }
        }
        swap(test[i+1], test[high]);
        return i+1;
    }
private:
};

class MergeSort: public Sorting{
public:
    virtual void sort(vector<int>& data){mergeSort(data, 0, data.size()-1);}
    virtual string worst_case_runtime(){return "O(n*(log(n)))";}

    void mergeSort(vector<int>& data, int low, int high){
        if (low < high){
            int middle = (high+low)/2;
            mergeSort(data, low, middle);
            mergeSort(data, middle+1, high);
            merge(data, low, middle, high);
        }
    }
    void merge(vector<int>& data, int low, int middle, int high){
        int n1 = middle - low + 1;
        int n2 = high - middle;

        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = data[low + i];
        for (int j = 0; j < n2; j++)
            R[j] = data[middle + 1 + j];

        int i = 0;
        int j = 0;
        int index = low;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                data[index] = L[i];
                i++;
                index++;
            }
            else {
                data[index] = R[j];
                j++;
                index++;
            }

        }
        while (i < n1) {
            data[index] = L[i];
            i++;
            index++;
        }
        while (j < n2) {
            data[index] = R[j];
            j++;
            index++;
        }
    }
private:
};

class BubbleSort : public Sorting{
public:
    virtual void sort(vector<int>& data){
        bool swapHappened;
        do{
            swapHappened = false;
            for (int i = 1; i < data.size(); i += 1){
                if (data[i-1] > data[i]){
                    swap(data[i-1], data[i]);
                    swapHappened = true;
                }
            }
        }while(swapHappened);
    }
    virtual string worst_case_runtime() {return "O(n^2)";}
private:
};

class SelectionSort : public Sorting{
public:
    virtual void sort(vector<int>& data){
        int sortedIndex = 0;
        int unsortedIndex = 0;
        while (sortedIndex < data.size()){
            int currentMin = data[unsortedIndex];
            int minIndex;
            for (int i = unsortedIndex+1; i < data.size(); i += 1){
                if (data[i] < currentMin){
                    currentMin = data[i];
                    minIndex = i;
                }
            }
            swap(data[minIndex],data[sortedIndex]);
            sortedIndex += 1;
            unsortedIndex += 1;
        }
    }
    virtual string worst_case_runtime() {return "O(n^2)";}
private:
};


int main(){
    vector<int> test = {4,3,2,10,12,1,5,6};
    vector<int> test2 = {4,3,2,10,12,1,5,6};
    vector<int> test3 = {4,3,2,10,12,1,5,6};
    vector<int> test4 = {4,3,2,10,12,1,5,6};
    vector<int> test5 = {4,3,2,10,12,1,5,6};

    InsertionSort insertionTest;
    cout<<"Insertion Sort"<<endl;
    insertionTest.sort(test);
    cout<<insertionTest.worst_case_runtime()<<endl;

    QuickSort quickTest;
    cout<<"Quick Sort"<<endl;
    quickTest.sort(test2);
    for (int i = 0; i < test2.size(); i += 1){
        cout<<test2[i]<<" ";
    }
    cout<<endl;
    cout<<quickTest.worst_case_runtime()<<endl;

    MergeSort mergeTest;
    cout<<"Merge Sort"<<endl;
    mergeTest.sort(test3);
    for (int i = 0; i < test3.size(); i += 1){
        cout<<test3[i]<<" ";
    }
    cout<<endl;
    cout<<mergeTest.worst_case_runtime()<<endl;

    BubbleSort bubbleTest;
    cout<<"Bubble Sort"<<endl;
    bubbleTest.sort(test4);
    for (int i = 0; i < test4.size(); i += 1){
        cout<<test4[i]<<" ";
    }
    cout<<endl;
    cout<<bubbleTest.worst_case_runtime()<<endl;

    SelectionSort selectTest;
    cout<<"Selection Sort"<<endl;
    selectTest.sort(test5);
    for (int i = 0; i < test5.size(); i += 1){
        cout<<test5[i]<<" ";
    }
    cout<<endl;
    cout<<selectTest.worst_case_runtime()<<endl;

    return 0;
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}
